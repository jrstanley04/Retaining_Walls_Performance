#include <SPI.h>
#include <Math.h>

#define MEAS                (uint8_t)0x00
#define RWTR                (uint8_t)(1 << 3)
#define STX                 (uint8_t)(1 << 3 | 1 << 2 | 1 << 1)
#define STY                 (uint8_t)(1 << 3 | 1 << 2 | 1 << 1 | 1 << 0)
#define RDAX                (uint8_t)(1 << 4)
#define RDAY                (uint8_t)(1 << 4 | 1 << 0)
#define SENSITIVITY         3277.0
#define CS                  10
#define MAX_WINDOW_SIZE     40

volatile uint8_t data[2] = {0x00, 0x00};
double v[5];
volatile unsigned int t_array[MAX_WINDOW_SIZE];
volatile unsigned int x_array[MAX_WINDOW_SIZE];
volatile unsigned int y_array[MAX_WINDOW_SIZE];
volatile uint8_t index = 0;

volatile double x = 0;
volatile double y = 0;
volatile long t = 0;

volatile float actualTemp = 0.0;
volatile double actualTilt = 0.0;

void setup () {
    Serial.begin(9600);
    pinMode(CS , OUTPUT);
    digitalWrite(CS, HIGH);
    SPI.begin();
    SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
    /*put the chip into measurement mode*/
    SCA103_data_transfer(MEAS);
    /*wait for the chip to set up*/
    delay(100);
}

void add_to_window(int temp, unsigned int dataX, unsigned int dataY){
    t_array[index] = temp;
    x_array[index] = dataX;
    y_array[index] = dataY;

    index++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x += x_array[i];
        y += y_array[i];
        t += t_array[i];
    }
    x = x / MAX_WINDOW_SIZE;
    y = y / (double)MAX_WINDOW_SIZE;
    t = t / (double)MAX_WINDOW_SIZE;

    actualTemp = ((float)(t) - 197.0) / -1.083;
    
    actualTilt = asin((double)(x - y) / (double)3277.0) * (double)180.0 / (double)3.14;

    actualTilt = step(actualTilt);

    if (index == MAX_WINDOW_SIZE) {
        index = 0;
    }
}


void loop () {
    /*first read the temperature value*/
    SCA103_data_transfer(RWTR);
    int temp = data[0];
    /*read data x*/
    SCA103_data_transfer(RDAX);
    unsigned int dataX = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer(RDAY);
    unsigned int dataY = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window(temp, dataX, dataY);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.println(x-y);
    /*delay so terminal can be read slowly*/
}

void SCA103_data_transfer(uint8_t command) {
    /*CS low*/
    digitalWrite(CS, LOW);
    /*SPI transfer command*/
    SPI.transfer(command);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS, HIGH);
}

//Band pass bessel filter order=2 alpha1=0.006 alpha2=0.01 

double step(double x) //class II 
{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = (3.543607099781854043e-6 * x)
				 + (-0.99468272748089303636 * v[0])
				 + (1.99466855305249390895 * v[1]);
			return 
				 (v[0] + v[2])
				+2 * v[1];

}
