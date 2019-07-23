#include <SPI.h>
#include <Math.h>

#define MEAS                (uint8_t)0x00
#define RWTR                (uint8_t)(1 << 3)
#define STX                 (uint8_t)(1 << 3 | 1 << 2 | 1 << 1)
#define STY                 (uint8_t)(1 << 3 | 1 << 2 | 1 << 1 | 1 << 0)
#define RDAX                (uint8_t)(1 << 4)
#define RDAY                (uint8_t)(1 << 4 | 1 << 0)
#define SENSITIVITY         6554.0
#define CS53                27
#define CS23                26
#define CS22                25
#define CS21                53
#define CS20                49
#define CS19                48
#define CS18                47
#define CS17                46
#define CS16                45
#define CS15                28
#define CS14                29
#define CS13                44
#define CS12                43
#define CS11                42
#define CS10                41
#define CS9                 42
#define CS8                 40
#define CS7                 39
#define CS6                 38
#define CS5                 37
#define CS4                 36
#define CS3                 35
#define CS2                 34
#define CS1                 33

#define MAX_WINDOW_SIZE     40

volatile uint8_t data[2] = {0x00, 0x00};
double v[5];
volatile unsigned int t_23_array[MAX_WINDOW_SIZE];
volatile unsigned int x_23_array[MAX_WINDOW_SIZE];
volatile unsigned int y_23_array[MAX_WINDOW_SIZE];
volatile unsigned int t_22_array[MAX_WINDOW_SIZE];
volatile unsigned int x_22_array[MAX_WINDOW_SIZE];
volatile unsigned int y_22_array[MAX_WINDOW_SIZE];
volatile unsigned int t_21_array[MAX_WINDOW_SIZE];
volatile unsigned int x_21_array[MAX_WINDOW_SIZE];
volatile unsigned int y_21_array[MAX_WINDOW_SIZE];
volatile unsigned int t_20_array[MAX_WINDOW_SIZE];
volatile unsigned int x_20_array[MAX_WINDOW_SIZE];
volatile unsigned int y_20_array[MAX_WINDOW_SIZE];
volatile unsigned int t_19_array[MAX_WINDOW_SIZE];
volatile unsigned int x_19_array[MAX_WINDOW_SIZE];
volatile unsigned int y_19_array[MAX_WINDOW_SIZE];
volatile unsigned int t_18_array[MAX_WINDOW_SIZE];
volatile unsigned int x_18_array[MAX_WINDOW_SIZE];
volatile unsigned int y_18_array[MAX_WINDOW_SIZE];
volatile unsigned int t_17_array[MAX_WINDOW_SIZE];
volatile unsigned int x_17_array[MAX_WINDOW_SIZE];
volatile unsigned int y_17_array[MAX_WINDOW_SIZE];
volatile unsigned int t_16_array[MAX_WINDOW_SIZE];
volatile unsigned int x_16_array[MAX_WINDOW_SIZE];
volatile unsigned int y_16_array[MAX_WINDOW_SIZE];
volatile unsigned int t_15_array[MAX_WINDOW_SIZE];
volatile unsigned int x_15_array[MAX_WINDOW_SIZE];
volatile unsigned int y_15_array[MAX_WINDOW_SIZE];
volatile unsigned int t_14_array[MAX_WINDOW_SIZE];
volatile unsigned int x_14_array[MAX_WINDOW_SIZE];
volatile unsigned int y_14_array[MAX_WINDOW_SIZE];
volatile unsigned int t_13_array[MAX_WINDOW_SIZE];
volatile unsigned int x_13_array[MAX_WINDOW_SIZE];
volatile unsigned int y_13_array[MAX_WINDOW_SIZE];
volatile unsigned int t_12_array[MAX_WINDOW_SIZE];
volatile unsigned int x_12_array[MAX_WINDOW_SIZE];
volatile unsigned int y_12_array[MAX_WINDOW_SIZE];
volatile unsigned int t_11_array[MAX_WINDOW_SIZE];
volatile unsigned int x_11_array[MAX_WINDOW_SIZE];
volatile unsigned int y_11_array[MAX_WINDOW_SIZE];
volatile unsigned int t_10_array[MAX_WINDOW_SIZE];
volatile unsigned int x_10_array[MAX_WINDOW_SIZE];
volatile unsigned int y_10_array[MAX_WINDOW_SIZE];
volatile unsigned int t_9_array[MAX_WINDOW_SIZE];
volatile unsigned int x_9_array[MAX_WINDOW_SIZE];
volatile unsigned int y_9_array[MAX_WINDOW_SIZE];
volatile unsigned int t_8_array[MAX_WINDOW_SIZE];
volatile unsigned int x_8_array[MAX_WINDOW_SIZE];
volatile unsigned int y_8_array[MAX_WINDOW_SIZE];
volatile unsigned int t_7_array[MAX_WINDOW_SIZE];
volatile unsigned int x_7_array[MAX_WINDOW_SIZE];
volatile unsigned int y_7_array[MAX_WINDOW_SIZE];
volatile unsigned int t_6_array[MAX_WINDOW_SIZE];
volatile unsigned int x_6_array[MAX_WINDOW_SIZE];
volatile unsigned int y_6_array[MAX_WINDOW_SIZE];
volatile unsigned int t_5_array[MAX_WINDOW_SIZE];
volatile unsigned int x_5_array[MAX_WINDOW_SIZE];
volatile unsigned int y_5_array[MAX_WINDOW_SIZE];
volatile unsigned int t_4_array[MAX_WINDOW_SIZE];
volatile unsigned int x_4_array[MAX_WINDOW_SIZE];
volatile unsigned int y_4_array[MAX_WINDOW_SIZE];
volatile unsigned int t_3_array[MAX_WINDOW_SIZE];
volatile unsigned int x_3_array[MAX_WINDOW_SIZE];
volatile unsigned int y_3_array[MAX_WINDOW_SIZE];
volatile unsigned int t_2_array[MAX_WINDOW_SIZE];
volatile unsigned int x_2_array[MAX_WINDOW_SIZE];
volatile unsigned int y_2_array[MAX_WINDOW_SIZE];
volatile unsigned int t_1_array[MAX_WINDOW_SIZE];
volatile unsigned int x_1_array[MAX_WINDOW_SIZE];
volatile unsigned int y_1_array[MAX_WINDOW_SIZE];
volatile uint8_t index_23 = 0;
volatile uint8_t index_22 = 0;
volatile uint8_t index_21 = 0;
volatile uint8_t index_20 = 0;
volatile uint8_t index_19 = 0;
volatile uint8_t index_18 = 0;
volatile uint8_t index_17 = 0;
volatile uint8_t index_16 = 0;
volatile uint8_t index_15 = 0;
volatile uint8_t index_14 = 0;
volatile uint8_t index_13 = 0;
volatile uint8_t index_12 = 0;
volatile uint8_t index_11 = 0;
volatile uint8_t index_10 = 0;
volatile uint8_t index_9 = 0;
volatile uint8_t index_8 = 0;
volatile uint8_t index_7 = 0;
volatile uint8_t index_6 = 0;
volatile uint8_t index_5 = 0;
volatile uint8_t index_4 = 0;
volatile uint8_t index_3 = 0;
volatile uint8_t index_2 = 0;
volatile uint8_t index_1 = 0;

volatile double x_23 = 0;
volatile double y_23 = 0;
volatile long t_23 = 0;
volatile double x_22 = 0;
volatile double y_22 = 0;
volatile long t_22 = 0;
volatile double x_21 = 0;
volatile double y_21 = 0;
volatile long t_21 = 0;
volatile double x_20 = 0;
volatile double y_20 = 0;
volatile long t_20 = 0;
volatile double x_19 = 0;
volatile double y_19 = 0;
volatile long t_19 = 0;
volatile double x_18 = 0;
volatile double y_18 = 0;
volatile long t_18 = 0;
volatile double x_17 = 0;
volatile double y_17 = 0;
volatile long t_17 = 0;
volatile double x_16 = 0;
volatile double y_16 = 0;
volatile long t_16 = 0;
volatile double x_15 = 0;
volatile double y_15 = 0;
volatile long t_15 = 0;
volatile double x_14 = 0;
volatile double y_14 = 0;
volatile long t_14 = 0;
volatile double x_13 = 0;
volatile double y_13 = 0;
volatile long t_13 = 0;
volatile double x_12 = 0;
volatile double y_12 = 0;
volatile long t_12 = 0;
volatile double x_11 = 0;
volatile double y_11 = 0;
volatile long t_11 = 0;
volatile double x_10 = 0;
volatile double y_10 = 0;
volatile long t_10 = 0;
volatile double x_9 = 0;
volatile double y_9 = 0;
volatile long t_9 = 0;
volatile double x_8 = 0;
volatile double y_8 = 0;
volatile long t_8 = 0;
volatile double x_7 = 0;
volatile double y_7 = 0;
volatile long t_7 = 0;
volatile double x_6 = 0;
volatile double y_6 = 0;
volatile long t_6 = 0;
volatile double x_5 = 0;
volatile double y_5 = 0;
volatile long t_5 = 0;
volatile double x_4 = 0;
volatile double y_4 = 0;
volatile long t_4 = 0;
volatile double x_3 = 0;
volatile double y_3 = 0;
volatile long t_3 = 0;
volatile double x_2 = 0;
volatile double y_2 = 0;
volatile long t_2 = 0;
volatile double x_1 = 0;
volatile double y_1 = 0;
volatile long t_1 = 0;

volatile float actualTemp = 0.0;
volatile double actualTilt = 0.0;

void setup () {
    Serial.begin(250000);
    pinMode(CS53, OUTPUT);
    pinMode(CS23, OUTPUT);
    pinMode(CS22, OUTPUT);
    pinMode(CS21, OUTPUT);
    pinMode(CS20, OUTPUT);
    pinMode(CS19, OUTPUT);
    pinMode(CS18, OUTPUT);
    pinMode(CS17, OUTPUT);
    pinMode(CS16, OUTPUT);
    pinMode(CS15, OUTPUT);
    pinMode(CS14, OUTPUT);
    pinMode(CS13, OUTPUT);
    pinMode(CS12, OUTPUT);
    pinMode(CS11, OUTPUT);
    pinMode(CS10, OUTPUT);
    pinMode(CS9, OUTPUT);
    pinMode(CS8, OUTPUT);
    pinMode(CS7, OUTPUT);
    pinMode(CS6, OUTPUT);
    pinMode(CS5, OUTPUT);
    pinMode(CS4, OUTPUT);
    pinMode(CS3, OUTPUT);
    pinMode(CS2, OUTPUT);
    pinMode(CS1, OUTPUT);
    digitalWrite(CS53, HIGH);
    digitalWrite(CS23, HIGH);
    digitalWrite(CS22, HIGH);
    digitalWrite(CS21, HIGH);
    digitalWrite(CS20, HIGH);
    digitalWrite(CS19, HIGH);
    digitalWrite(CS18, HIGH);
    digitalWrite(CS17, HIGH);
    digitalWrite(CS16, HIGH);
    digitalWrite(CS15, HIGH);
    digitalWrite(CS14, HIGH);
    digitalWrite(CS13, HIGH);
    digitalWrite(CS12, HIGH);
    digitalWrite(CS11, HIGH);
    digitalWrite(CS10, HIGH);
    digitalWrite(CS9, HIGH);
    digitalWrite(CS8, HIGH);
    digitalWrite(CS7, HIGH);
    digitalWrite(CS6, HIGH);
    digitalWrite(CS5, HIGH);
    digitalWrite(CS4, HIGH);
    digitalWrite(CS3, HIGH);
    digitalWrite(CS2, HIGH);
    digitalWrite(CS1, HIGH);
    SPI.begin();
    SPI.beginTransaction(SPISettings(500000, MSBFIRST, SPI_MODE0));
    /*put the chip into measurement mode*/
    SCA103_data_transfer_23(MEAS);
    delay(100);
    SCA103_data_transfer_22(MEAS);
    delay(100);
    SCA103_data_transfer_21(MEAS);
    delay(100);
    SCA103_data_transfer_20(MEAS);
    delay(100);
    SCA103_data_transfer_19(MEAS);
    delay(100);
    SCA103_data_transfer_18(MEAS);
    delay(100);
    SCA103_data_transfer_17(MEAS);
    delay(100);
    SCA103_data_transfer_16(MEAS);
    delay(100);
    SCA103_data_transfer_15(MEAS);
    delay(100);
    SCA103_data_transfer_14(MEAS);
    delay(100);
    SCA103_data_transfer_13(MEAS);
    delay(100);
    SCA103_data_transfer_12(MEAS);
    delay(100);
    SCA103_data_transfer_11(MEAS);
    delay(100);
    SCA103_data_transfer_10(MEAS);
    delay(100);
    SCA103_data_transfer_9(MEAS);
    delay(100);
    SCA103_data_transfer_8(MEAS);
    delay(100);
    SCA103_data_transfer_7(MEAS);
    delay(100);
    SCA103_data_transfer_6(MEAS);
    delay(100);
    SCA103_data_transfer_5(MEAS);
    delay(100);
    SCA103_data_transfer_4(MEAS);
    delay(100);
    SCA103_data_transfer_3(MEAS);
    delay(100);
    SCA103_data_transfer_2(MEAS);
    delay(100);
    SCA103_data_transfer_1(MEAS);
    delay(100);
    /*wait for the chip to set up*/
}

void add_to_window_23(int temp_23, unsigned int dataX_23, unsigned int dataY_23){
    t_23_array[index_23] = temp_23;
    x_23_array[index_23] = dataX_23;
    y_23_array[index_23] = dataY_23;

    index_23++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_23 += x_23_array[i];
        y_23 += y_23_array[i];
        t_23 += t_23_array[i];
    }
    x_23 = x_23 / MAX_WINDOW_SIZE;
    y_23 = y_23 / (double)MAX_WINDOW_SIZE;
    t_23 = t_23 / (double)MAX_WINDOW_SIZE;

    if (index_23 == MAX_WINDOW_SIZE) {
        index_23 = 0;
    }
}

void add_to_window_22(int temp_22, unsigned int dataX_22, unsigned int dataY_22){
    t_22_array[index_22] = temp_22;
    x_22_array[index_22] = dataX_22;
    y_22_array[index_22] = dataY_22;

    index_22++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_22 += x_22_array[i];
        y_22 += y_22_array[i];
        t_22 += t_22_array[i];
    }
    x_22 = x_22 / MAX_WINDOW_SIZE;
    y_22 = y_22 / (double)MAX_WINDOW_SIZE;
    t_22 = t_22 / (double)MAX_WINDOW_SIZE;

    if (index_22 == MAX_WINDOW_SIZE) {
        index_22 = 0;
    }
}

void add_to_window_21(int temp_21, unsigned int dataX_21, unsigned int dataY_21){
    t_21_array[index_21] = temp_21;
    x_21_array[index_21] = dataX_21;
    y_21_array[index_21] = dataY_21;

    index_21++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_21 += x_21_array[i];
        y_21 += y_21_array[i];
        t_21 += t_21_array[i];
    }
    x_21 = x_21 / MAX_WINDOW_SIZE;
    y_21 = y_21 / (double)MAX_WINDOW_SIZE;
    t_21 = t_21 / (double)MAX_WINDOW_SIZE;

    if (index_21 == MAX_WINDOW_SIZE) {
        index_21 = 0;
    }
}

void add_to_window_20(int temp_20, unsigned int dataX_20, unsigned int dataY_20){
    t_20_array[index_20] = temp_20;
    x_20_array[index_20] = dataX_20;
    y_20_array[index_20] = dataY_20;

    index_20++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_20 += x_20_array[i];
        y_20 += y_20_array[i];
        t_20 += t_20_array[i];
    }
    x_20 = x_20 / MAX_WINDOW_SIZE;
    y_20 = y_20 / (double)MAX_WINDOW_SIZE;
    t_20 = t_20 / (double)MAX_WINDOW_SIZE;

    if (index_20 == MAX_WINDOW_SIZE) {
        index_20 = 0;
    }
}

void add_to_window_19(int temp_19, unsigned int dataX_19, unsigned int dataY_19){
    t_19_array[index_19] = temp_19;
    x_19_array[index_19] = dataX_19;
    y_19_array[index_19] = dataY_19;

    index_19++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_19 += x_19_array[i];
        y_19 += y_19_array[i];
        t_19 += t_19_array[i];
    }
    x_19 = x_19 / MAX_WINDOW_SIZE;
    y_19 = y_19 / (double)MAX_WINDOW_SIZE;
    t_19 = t_19 / (double)MAX_WINDOW_SIZE;

    if (index_19 == MAX_WINDOW_SIZE) {
        index_19 = 0;
    }
}

void add_to_window_18(int temp_18, unsigned int dataX_18, unsigned int dataY_18){
    t_18_array[index_18] = temp_18;
    x_18_array[index_18] = dataX_18;
    y_18_array[index_18] = dataY_18;

    index_18++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_18 += x_18_array[i];
        y_18 += y_18_array[i];
        t_18 += t_18_array[i];
    }
    x_18 = x_18 / MAX_WINDOW_SIZE;
    y_18 = y_18 / (double)MAX_WINDOW_SIZE;
    t_18 = t_18 / (double)MAX_WINDOW_SIZE;

    if (index_18 == MAX_WINDOW_SIZE) {
        index_18 = 0;
    }
}

void add_to_window_17(int temp_17, unsigned int dataX_17, unsigned int dataY_17){
    t_17_array[index_17] = temp_17;
    x_17_array[index_17] = dataX_17;
    y_17_array[index_17] = dataY_17;

    index_17++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_17 += x_17_array[i];
        y_17 += y_17_array[i];
        t_17 += t_17_array[i];
    }
    x_17 = x_17 / MAX_WINDOW_SIZE;
    y_17 = y_17 / (double)MAX_WINDOW_SIZE;
    t_17 = t_17 / (double)MAX_WINDOW_SIZE;

    if (index_17 == MAX_WINDOW_SIZE) {
        index_17 = 0;
    }
}

void add_to_window_16(int temp_16, unsigned int dataX_16, unsigned int dataY_16){
    t_16_array[index_16] = temp_16;
    x_16_array[index_16] = dataX_16;
    y_16_array[index_16] = dataY_16;

    index_16++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_16 += x_16_array[i];
        y_16 += y_16_array[i];
        t_16 += t_16_array[i];
    }
    x_16 = x_16 / MAX_WINDOW_SIZE;
    y_16 = y_16 / (double)MAX_WINDOW_SIZE;
    t_16 = t_16 / (double)MAX_WINDOW_SIZE;

    if (index_16 == MAX_WINDOW_SIZE) {
        index_16 = 0;
    }
}

void add_to_window_15(int temp_15, unsigned int dataX_15, unsigned int dataY_15){
    t_15_array[index_15] = temp_15;
    x_15_array[index_15] = dataX_15;
    y_15_array[index_15] = dataY_15;

    index_15++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_15 += x_15_array[i];
        y_15 += y_15_array[i];
        t_15 += t_15_array[i];
    }
    x_15 = x_15 / MAX_WINDOW_SIZE;
    y_15 = y_15 / (double)MAX_WINDOW_SIZE;
    t_15 = t_15 / (double)MAX_WINDOW_SIZE;

    if (index_15 == MAX_WINDOW_SIZE) {
        index_15 = 0;
    }
}

void add_to_window_14(int temp_14, unsigned int dataX_14, unsigned int dataY_14){
    t_14_array[index_14] = temp_14;
    x_14_array[index_14] = dataX_14;
    y_14_array[index_14] = dataY_14;

    index_14++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_14 += x_14_array[i];
        y_14 += y_14_array[i];
        t_14 += t_14_array[i];
    }
    x_14 = x_14 / MAX_WINDOW_SIZE;
    y_14 = y_14 / (double)MAX_WINDOW_SIZE;
    t_14 = t_14 / (double)MAX_WINDOW_SIZE;

    if (index_14 == MAX_WINDOW_SIZE) {
        index_14 = 0;
    }
}
void add_to_window_13(int temp_13, unsigned int dataX_13, unsigned int dataY_13){
    t_13_array[index_13] = temp_13;
    x_13_array[index_13] = dataX_13;
    y_13_array[index_13] = dataY_13;

    index_13++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_13 += x_13_array[i];
        y_13 += y_13_array[i];
        t_13 += t_13_array[i];
    }
    x_13 = x_13 / MAX_WINDOW_SIZE;
    y_13 = y_13 / (double)MAX_WINDOW_SIZE;
    t_13 = t_13 / (double)MAX_WINDOW_SIZE;

    if (index_13 == MAX_WINDOW_SIZE) {
        index_13 = 0;
    }
}
void add_to_window_12(int temp_12, unsigned int dataX_12, unsigned int dataY_12){
    t_12_array[index_12] = temp_12;
    x_12_array[index_12] = dataX_12;
    y_12_array[index_12] = dataY_12;

    index_12++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_12 += x_12_array[i];
        y_12 += y_12_array[i];
        t_12 += t_12_array[i];
    }
    x_12 = x_12 / MAX_WINDOW_SIZE;
    y_12 = y_12 / (double)MAX_WINDOW_SIZE;
    t_12 = t_12 / (double)MAX_WINDOW_SIZE;

    if (index_12 == MAX_WINDOW_SIZE) {
        index_12 = 0;
    }
}
void add_to_window_11(int temp_11, unsigned int dataX_11, unsigned int dataY_11){
    t_11_array[index_11] = temp_11;
    x_11_array[index_11] = dataX_11;
    y_11_array[index_11] = dataY_11;

    index_11++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_11 += x_11_array[i];
        y_11 += y_11_array[i];
        t_11 += t_11_array[i];
    }
    x_11 = x_11 / MAX_WINDOW_SIZE;
    y_11 = y_11 / (double)MAX_WINDOW_SIZE;
    t_11 = t_11 / (double)MAX_WINDOW_SIZE;

    if (index_11 == MAX_WINDOW_SIZE) {
        index_11 = 0;
    }
}

void add_to_window_10(int temp_10, unsigned int dataX_10, unsigned int dataY_10){
    t_10_array[index_10] = temp_10;
    x_10_array[index_10] = dataX_10;
    y_10_array[index_10] = dataY_10;

    index_10++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_10 += x_10_array[i];
        y_10 += y_10_array[i];
        t_10 += t_10_array[i];
    }
    x_10 = x_10 / MAX_WINDOW_SIZE;
    y_10 = y_10 / (double)MAX_WINDOW_SIZE;
    t_10 = t_10 / (double)MAX_WINDOW_SIZE;

    if (index_10 == MAX_WINDOW_SIZE) {
        index_10 = 0;
    }
}

void add_to_window_9(int temp_9, unsigned int dataX_9, unsigned int dataY_9){
    t_9_array[index_9] = temp_9;
    x_9_array[index_9] = dataX_9;
    y_9_array[index_9] = dataY_9;

    index_9++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_9 += x_9_array[i];
        y_9 += y_9_array[i];
        t_9 += t_9_array[i];
    }
    x_9 = x_9 / MAX_WINDOW_SIZE;
    y_9 = y_9 / (double)MAX_WINDOW_SIZE;
    t_9 = t_9 / (double)MAX_WINDOW_SIZE;

    if (index_9 == MAX_WINDOW_SIZE) {
        index_9 = 0;
    }
}

void add_to_window_8(int temp_8, unsigned int dataX_8, unsigned int dataY_8){
    t_8_array[index_8] = temp_8;
    x_8_array[index_8] = dataX_8;
    y_8_array[index_8] = dataY_8;

    index_8++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_8 += x_8_array[i];
        y_8 += y_8_array[i];
        t_8 += t_8_array[i];
    }
    x_8 = x_8 / MAX_WINDOW_SIZE;
    y_8 = y_8 / (double)MAX_WINDOW_SIZE;
    t_8 = t_8 / (double)MAX_WINDOW_SIZE;

    if (index_8 == MAX_WINDOW_SIZE) {
        index_8 = 0;
    }
}

void add_to_window_7(int temp_7, unsigned int dataX_7, unsigned int dataY_7){
    t_7_array[index_7] = temp_7;
    x_7_array[index_7] = dataX_7;
    y_7_array[index_7] = dataY_7;

    index_7++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_7 += x_7_array[i];
        y_7 += y_7_array[i];
        t_7 += t_7_array[i];
    }
    x_7 = x_7 / MAX_WINDOW_SIZE;
    y_7 = y_7 / (double)MAX_WINDOW_SIZE;
    t_7 = t_7 / (double)MAX_WINDOW_SIZE;

    if (index_7 == MAX_WINDOW_SIZE) {
        index_7 = 0;
    }
}

void add_to_window_6(int temp_6, unsigned int dataX_6, unsigned int dataY_6){
    t_6_array[index_6] = temp_6;
    x_6_array[index_6] = dataX_6;
    y_6_array[index_6] = dataY_6;

    index_6++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_6 += x_6_array[i];
        y_6 += y_6_array[i];
        t_6 += t_6_array[i];
    }
    x_6 = x_6 / MAX_WINDOW_SIZE;
    y_6 = y_6 / (double)MAX_WINDOW_SIZE;
    t_6 = t_6 / (double)MAX_WINDOW_SIZE;

    if (index_6 == MAX_WINDOW_SIZE) {
        index_6 = 0;
    }
}

void add_to_window_5(int temp_5, unsigned int dataX_5, unsigned int dataY_5){
    t_5_array[index_5] = temp_5;
    x_5_array[index_5] = dataX_5;
    y_5_array[index_5] = dataY_5;

    index_5++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_5 += x_5_array[i];
        y_5 += y_5_array[i];
        t_5 += t_5_array[i];
    }
    x_5 = x_5 / MAX_WINDOW_SIZE;
    y_5 = y_5 / (double)MAX_WINDOW_SIZE;
    t_5 = t_5 / (double)MAX_WINDOW_SIZE;

    if (index_5 == MAX_WINDOW_SIZE) {
        index_5 = 0;
    }
}

void add_to_window_4(int temp_4, unsigned int dataX_4, unsigned int dataY_4){
    t_4_array[index_4] = temp_4;
    x_4_array[index_4] = dataX_4;
    y_4_array[index_4] = dataY_4;

    index_4++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_4 += x_4_array[i];
        y_4 += y_4_array[i];
        t_4 += t_4_array[i];
    }
    x_4 = x_4 / MAX_WINDOW_SIZE;
    y_4 = y_4 / (double)MAX_WINDOW_SIZE;
    t_4 = t_4 / (double)MAX_WINDOW_SIZE;

    if (index_4 == MAX_WINDOW_SIZE) {
        index_4 = 0;
    }
}
void add_to_window_3(int temp_3, unsigned int dataX_3, unsigned int dataY_3){
    t_3_array[index_3] = temp_3;
    x_3_array[index_3] = dataX_3;
    y_3_array[index_3] = dataY_3;

    index_3++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_3 += x_3_array[i];
        y_3 += y_3_array[i];
        t_3 += t_3_array[i];
    }
    x_3 = x_3 / MAX_WINDOW_SIZE;
    y_3 = y_3 / (double)MAX_WINDOW_SIZE;
    t_3 = t_3 / (double)MAX_WINDOW_SIZE;

    if (index_3 == MAX_WINDOW_SIZE) {
        index_3 = 0;
    }
}
void add_to_window_2(int temp_2, unsigned int dataX_2, unsigned int dataY_2){
    t_2_array[index_2] = temp_2;
    x_2_array[index_2] = dataX_2;
    y_2_array[index_2] = dataY_2;

    index_2++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_2 += x_2_array[i];
        y_2 += y_2_array[i];
        t_2 += t_2_array[i];
    }
    x_2 = x_2 / MAX_WINDOW_SIZE;
    y_2 = y_2 / (double)MAX_WINDOW_SIZE;
    t_2 = t_2 / (double)MAX_WINDOW_SIZE;

    if (index_2 == MAX_WINDOW_SIZE) {
        index_2 = 0;
    }
}
void add_to_window_1(int temp_1, unsigned int dataX_1, unsigned int dataY_1){
    t_1_array[index_1] = temp_1;
    x_1_array[index_1] = dataX_1;
    y_1_array[index_1] = dataY_1;

    index_1++;

    for (int i = 0; i < MAX_WINDOW_SIZE; i++) {
        x_1 += x_1_array[i];
        y_1 += y_1_array[i];
        t_1 += t_1_array[i];
    }
    x_1 = x_1 / MAX_WINDOW_SIZE;
    y_1 = y_1 / (double)MAX_WINDOW_SIZE;
    t_1 = t_1 / (double)MAX_WINDOW_SIZE;

    if (index_1 == MAX_WINDOW_SIZE) {
        index_1 = 0;
    }
}


void loop () {
    /*first read the temperature value*/
    SCA103_data_transfer_23(RWTR);
    int temp_23 = data[0];
    /*read data x*/
    SCA103_data_transfer_23(RDAX);
    unsigned int dataX_23 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_23(RDAY);
    unsigned int dataY_23 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_23(temp_23, dataX_23, dataY_23);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_23 - y_23);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_22(RWTR);
    int temp_22 = data[0];
    /*read data x*/
    SCA103_data_transfer_22(RDAX);
    unsigned int dataX_22 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_22(RDAY);
    unsigned int dataY_22 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_22(temp_22, dataX_22, dataY_22);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_22 - y_22);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_21(RWTR);
    int temp_21 = data[0];
    /*read data x*/
    SCA103_data_transfer_21(RDAX);
    unsigned int dataX_21 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_21(RDAY);
    unsigned int dataY_21 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_21(temp_21, dataX_21, dataY_21);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_21 - y_21);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/
    
    /*first read the temperature value*/
    SCA103_data_transfer_20(RWTR);
    int temp_20 = data[0];
    /*read data x*/
    SCA103_data_transfer_20(RDAX);
    unsigned int dataX_20 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_20(RDAY);
    unsigned int dataY_20 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_20(temp_20, dataX_20, dataY_20);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_20 - y_20);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_19(RWTR);
    int temp_19 = data[0];
    /*read data x*/
    SCA103_data_transfer_19(RDAX);
    unsigned int dataX_19 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_19(RDAY);
    unsigned int dataY_19 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_19(temp_19, dataX_19, dataY_19);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_19 - y_19);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_18(RWTR);
    int temp_18 = data[0];
    /*read data x*/
    SCA103_data_transfer_18(RDAX);
    unsigned int dataX_18 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_18(RDAY);
    unsigned int dataY_18 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_18(temp_18, dataX_18, dataY_18);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_18 - y_18);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/
    
    /*first read the temperature value*/
    SCA103_data_transfer_17(RWTR);
    int temp_17 = data[0];
    /*read data x*/
    SCA103_data_transfer_17(RDAX);
    unsigned int dataX_17 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_17(RDAY);
    unsigned int dataY_17 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_17(temp_17, dataX_17, dataY_17);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_17 - y_17);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_16(RWTR);
    int temp_16 = data[0];
    /*read data x*/
    SCA103_data_transfer_16(RDAX);
    unsigned int dataX_16 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_16(RDAY);
    unsigned int dataY_16 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_16(temp_16, dataX_16, dataY_16);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_16 - y_16);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_15(RWTR);
    int temp_15 = data[0];
    /*read data x*/
    SCA103_data_transfer_15(RDAX);
    unsigned int dataX_15 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_15(RDAY);
    unsigned int dataY_15 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_15(temp_15, dataX_15, dataY_15);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_15 - y_15);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_14(RWTR);
    int temp_14 = data[0];
    /*read data x*/
    SCA103_data_transfer_14(RDAX);
    unsigned int dataX_14 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_14(RDAY);
    unsigned int dataY_14 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_14(temp_14, dataX_14, dataY_14);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_14 - y_14);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_13(RWTR);
    int temp_13 = data[0];
    /*read data x*/
    SCA103_data_transfer_13(RDAX);
    unsigned int dataX_13 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_13(RDAY);
    unsigned int dataY_13 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_13(temp_13, dataX_13, dataY_13);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_13 - y_13);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_12(RWTR);
    int temp_12 = data[0];
    /*read data x*/
    SCA103_data_transfer_12(RDAX);
    unsigned int dataX_12 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_12(RDAY);
    unsigned int dataY_12 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_12(temp_12, dataX_12, dataY_12);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_12 - y_12);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_11(RWTR);
    int temp_11 = data[0];
    /*read data x*/
    SCA103_data_transfer_11(RDAX);
    unsigned int dataX_11 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_11(RDAY);
    unsigned int dataY_11 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_11(temp_11, dataX_11, dataY_11);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_11 - y_11);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/
 
    /*first read the temperature value*/
    SCA103_data_transfer_10(RWTR);
    int temp_10 = data[0];
    /*read data x*/
    SCA103_data_transfer_10(RDAX);
    unsigned int dataX_10 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_10(RDAY);
    unsigned int dataY_10 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_10(temp_10, dataX_10, dataY_10);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_10 - y_10);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_9(RWTR);
    int temp_9 = data[0];
    /*read data x*/
    SCA103_data_transfer_9(RDAX);
    unsigned int dataX_9 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_9(RDAY);
    unsigned int dataY_9 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_9(temp_9, dataX_9, dataY_9);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_9 - y_9);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_8(RWTR);
    int temp_8 = data[0];
    /*read data x*/
    SCA103_data_transfer_8(RDAX);
    unsigned int dataX_8 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_8(RDAY);
    unsigned int dataY_8 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_8(temp_8, dataX_8, dataY_8);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_8 - y_8);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/
    
    /*first read the temperature value*/
    SCA103_data_transfer_7(RWTR);
    int temp_7 = data[0];
    /*read data x*/
    SCA103_data_transfer_7(RDAX);
    unsigned int dataX_7 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_7(RDAY);
    unsigned int dataY_7 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_7(temp_7, dataX_7, dataY_7);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_7 - y_7);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_6(RWTR);
    int temp_6 = data[0];
    /*read data x*/
    SCA103_data_transfer_6(RDAX);
    unsigned int dataX_6 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_6(RDAY);
    unsigned int dataY_6 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_6(temp_6, dataX_6, dataY_6);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_6 - y_6);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_5(RWTR);
    int temp_5 = data[0];
    /*read data x*/
    SCA103_data_transfer_5(RDAX);
    unsigned int dataX_5 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_5(RDAY);
    unsigned int dataY_5 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_5(temp_5, dataX_5, dataY_5);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_5 - y_5);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_4(RWTR);
    int temp_4 = data[0];
    /*read data x*/
    SCA103_data_transfer_4(RDAX);
    unsigned int dataX_4 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_4(RDAY);
    unsigned int dataY_4 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_4(temp_4, dataX_4, dataY_4);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_4 - y_4);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_3(RWTR);
    int temp_3 = data[0];
    /*read data x*/
    SCA103_data_transfer_3(RDAX);
    unsigned int dataX_3 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_3(RDAY);
    unsigned int dataY_3 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_3(temp_3, dataX_3, dataY_3);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_3 - y_3);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_2(RWTR);
    int temp_2 = data[0];
    /*read data x*/
    SCA103_data_transfer_2(RDAX);
    unsigned int dataX_2 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_2(RDAY);
    unsigned int dataY_2 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_2(temp_2, dataX_2, dataY_2);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_2 - y_2);Serial.print(",");
    delay(10);
    /*delay so terminal can be read slowly*/

    /*first read the temperature value*/
    SCA103_data_transfer_1(RWTR);
    int temp_1 = data[0];
    /*read data x*/
    SCA103_data_transfer_1(RDAX);
    unsigned int dataX_1 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    /*read data y*/
    SCA103_data_transfer_1(RDAY);
    unsigned int dataY_1 = (data[0] << 2) | (data[1] >> 5); /*significant byte then 3 bits = 11 bit data*/
    add_to_window_1(temp_1, dataX_1, dataY_1);
    /*Print to console to see if data is read*/
    //Serial.print("Raw temperature (dec): "); Serial.print(t); Serial.print(" Uncalibrated temperature (C): "); Serial.println(actualTemp);
    //Serial.print("DataX_raw: "); Serial.println(x);
    //Serial.print("DataY_raw: "); Serial.println(y);
    //Serial.print("Raw angle: "); Serial.print(actualTilt, 3); Serial.print(" raw data out: "); Serial.println(x - y, 3);
    //Serial.print(actualTilt, 3); Serial.print(",");Serial.print(x - y, 3); Serial.println(",");
    Serial.print(x_1 - y_1);Serial.println(" ");
    delay(10);
    /*delay so terminal can be read slowly*/
}

void SCA103_data_transfer_23(uint8_t command_23) {
    /*CS low*/
    digitalWrite(CS23, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_23);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS23, HIGH);
}

void SCA103_data_transfer_22(uint8_t command_22) {
    /*CS low*/
    digitalWrite(CS22, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_22);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS22, HIGH);
}

void SCA103_data_transfer_21(uint8_t command_21) {
    /*CS low*/
    digitalWrite(CS21, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_21);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS21, HIGH);
}

void SCA103_data_transfer_20(uint8_t command_20) {
    /*CS low*/
    digitalWrite(CS20, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_20);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS20, HIGH);
}

void SCA103_data_transfer_19(uint8_t command_19) {
    /*CS low*/
    digitalWrite(CS19, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_19);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS19, HIGH);
}

void SCA103_data_transfer_18(uint8_t command_18) {
    /*CS low*/
    digitalWrite(CS18, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_18);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS18, HIGH);
}

void SCA103_data_transfer_17(uint8_t command_17) {
    /*CS low*/
    digitalWrite(CS17, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_17);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS17, HIGH);
}

void SCA103_data_transfer_16(uint8_t command_16) {
    /*CS low*/
    digitalWrite(CS16, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_16);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS16, HIGH);
}

void SCA103_data_transfer_15(uint8_t command_15) {
    /*CS low*/
    digitalWrite(CS15, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_15);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS15, HIGH);
}

void SCA103_data_transfer_14(uint8_t command_14) {
    /*CS low*/
    digitalWrite(CS14, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_14);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS14, HIGH);
}

void SCA103_data_transfer_13(uint8_t command_13) {
    /*CS low*/
    digitalWrite(CS13, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_13);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS13, HIGH);
}

void SCA103_data_transfer_12(uint8_t command_12) {
    /*CS low*/
    digitalWrite(CS12, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_12);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS12, HIGH);
}

void SCA103_data_transfer_11(uint8_t command_11) {
    /*CS low*/
    digitalWrite(CS11, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_11);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS11, HIGH);
}

void SCA103_data_transfer_10(uint8_t command_10) {
    /*CS low*/
    digitalWrite(CS10, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_10);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS10, HIGH);
}

void SCA103_data_transfer_9(uint8_t command_9) {
    /*CS low*/
    digitalWrite(CS9, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_9);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS9, HIGH);
}

void SCA103_data_transfer_8(uint8_t command_8) {
    /*CS low*/
    digitalWrite(CS8, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_8);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS8, HIGH);
}

void SCA103_data_transfer_7(uint8_t command_7) {
    /*CS low*/
    digitalWrite(CS7, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_7);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS7, HIGH);
}

void SCA103_data_transfer_6(uint8_t command_6) {
    /*CS low*/
    digitalWrite(CS6, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_6);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS6, HIGH);
}

void SCA103_data_transfer_5(uint8_t command_5) {
    /*CS low*/
    digitalWrite(CS5, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_5);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS5, HIGH);
}

void SCA103_data_transfer_4(uint8_t command_4) {
    /*CS low*/
    digitalWrite(CS4, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_4);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS4, HIGH);
}

void SCA103_data_transfer_3(uint8_t command_3) {
    /*CS low*/
    digitalWrite(CS3, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_3);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS3, HIGH);
}

void SCA103_data_transfer_2(uint8_t command_2) {
    /*CS low*/
    digitalWrite(CS2, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_2);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS2, HIGH);
}

void SCA103_data_transfer_1(uint8_t command_1) {
    /*CS low*/
    digitalWrite(CS1, LOW);
    /*SPI transfer command*/
    SPI.transfer(command_1);
    data[0] = SPI.transfer(0xFF);
    data[1] = SPI.transfer(0xFF);
    digitalWrite(CS1, HIGH);
}
