import serial
import numpy as np
import csv
import time
import matplotlib.pyplot as plt
from drawnow import *
import datetime
from ini_read import getINI

iniData = getINI()
numPoints = int(iniData['numPoints'])


#ser_0 = serial.Serial('/dev/ttyACM0', 9600, timeout = 5) #Create object named ser
#time.sleep(3)
ser_1 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_2 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_3 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_4 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_5 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_6 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_7 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_8 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_9 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_10 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_11 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_12 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_13 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
#ser_14 = serial.Serial('/dev/ttyUSB11', 9600, timeout = 5)
#time.sleep(3)
#ser_15 = serial.Serial('/dev/ttyUSB12', 9600, timeout = 5)
#time.sleep(3)
ser_16 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_17 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_18 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_19 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_20 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
ser_21 = serial.Serial('com4', 9600, timeout = 5)
time.sleep(3)
#ser_22 = serial.Serial('/dev/ttyACM0', 9600, timeout = 5)
#time.sleep(3)
#ser_23 = serial.Serial('/dev/ttyACM0', 9600, timeout = 5)
#time.sleep(3)

plt.ion()                                   #Tell matplotlib interactive mode to plot live data

#cnt_0=0
cnt_1=0
cnt_2=0
cnt_3=0
cnt_4=0
cnt_5=0
cnt_6=0
cnt_7=0
cnt_8=0
cnt_9=0
cnt_10=0
cnt_11=0
cnt_12=0
cnt_13=0
cnt_14=0
cnt_15=0
cnt_16=0
cnt_17=0
cnt_18=0
cnt_19=0
cnt_20=0
cnt_21=0
cnt_22=0
cnt_23=0

dataList=[0]*numPoints

#Node_0=[]
Node_1=[]
Node_2=[]
Node_3=[]
Node_4=[]
Node_5=[]
Node_6=[]
Node_7=[]
Node_8=[]
Node_9=[]
Node_10=[]
Node_11=[]
Node_12=[]
Node_13=[]
Node_14=[]
Node_15=[]
Node_16=[]
Node_17=[]
Node_18=[]
Node_19=[]
Node_20=[]
Node_21=[]
Node_22=[]
Node_23=[]

def makeFig_0(): #Create function that creates the plot
    plt.title('Live stream Sensor 0 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_0, 'yD-', label='Node 0 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_1(): #Create function that creates the plot
    plt.title('Live stream Sensor 1 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_1, 'b1-', label='Node 1 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_2(): #Create function that creates the plot
    plt.title('Live stream Sensor 2 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_2, 'g2-', label='Node 2 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_3(): #Create function that creates the plot
    plt.title('Live stream Sensor 3 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_3, 'r3-', label='Node 3 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_4(): #Create function that creates the plot
    plt.title('Live stream Sensor 4 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_4, 'c4-', label='Node 4 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_5(): #Create function that creates the plot
    plt.title('Live stream Sensor 5 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_5, 'mo-', label='Node 5 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_6(): #Create function that creates the plot
    plt.title('Live stream Sensor 6 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_6, 'y^-', label='Node 6 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_7(): #Create function that creates the plot
    plt.title('Live stream Sensor 7 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_7, 'k<-', label='Node 7 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_8(): #Create function that creates the plot
    plt.title('Live stream Sensor 8 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_8, 'b>-', label='Node 8 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_9(): #Create function that creates the plot
    plt.title('Live stream Sensor 9 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_9, 'gh-', label='Node 9 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_10(): #Create function that creates the plot
    plt.title('Live stream Sensor 10 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_10, 'rH-', label='Node 10 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_11(): #Create function that creates the plot
    plt.title('Live stream Sensor 11 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_11, 'c+-', label='Node 11 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_12(): #Create function that creates the plot
    plt.title('Live stream Sensor 12 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_12, 'm*-', label='Node 12 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_13(): #Create function that creates the plot
    plt.title('Live stream Sensor 13 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_13, 'ys-', label='Node 13 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_14(): #Create function that creates the plot
    plt.title('Live stream Sensor 14 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_14, 'bd-', label='Node 14 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_15(): #Create function that creates the plot
    plt.title('Live stream Sensor 15 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_15, 'gD-', label='Node 15 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_16(): #Create function that creates the plot
    plt.title('Live stream Sensor 16 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_16, 'rv-', label='Node 16 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_17(): #Create function that creates the plot
    plt.title('Live stream Sensor 17 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_17, 'cx-', label='Node 17 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_18(): #Create function that creates the plot
    plt.title('Live stream Sensor 18 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_18, 'mX-', label='Node 18 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_19(): #Create function that creates the plot
    plt.title('Live stream Sensor 19 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_19, 'c^-', label='Node 19 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_20(): #Create function that creates the plot
    plt.title('Live stream Sensor 20 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_20, 'y>-', label='Node 20 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_21(): #Create function that creates the plot
    plt.title('Live stream Sensor 21 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_21, 'r<-', label='Node 21 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_22(): #Create function that creates the plot
    plt.title('Live stream Sensor 22 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_22, 'g+-', label='Node 22 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend

def makeFig_23(): #Create function that creates the plot
    plt.title('Live stream Sensor 23 Data')            #Plot the title
    plt.grid(True)                                  #Turn grid on
    plt.ylabel('Differential Acc')                  #Set Y labels
    plt.plot(Node_23, 'mo-', label='Node 23 Acc')      #Plot the Node 10 Values
    plt.legend(loc='best')                          #plot the legend


def csvWrite(dataRow):
    with open('DataFile.csv', mode='a') as csvFile:
        csvWriter = csv.writer(csvFile, delimiter=',')
        csvWriter.writerow(dataRow)
    csvFile.close()

def getValues_0():
    ser_0.write(b'a')
    arduinoData = ser_0.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_1():
    ser_1.write(b'a')
    arduinoData = ser_1.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_2():
    ser_2.write(b'a')
    arduinoData = ser_2.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_3():
    ser_3.write(b'a')
    arduinoData = ser_3.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_4():
    ser_4.write(b'a')
    arduinoData = ser_4.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_5():
    ser_5.write(b'a')
    arduinoData = ser_5.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_6():
    ser_6.write(b'a')
    arduinoData = ser_6.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_7():
    ser_7.write(b'a')
    arduinoData = ser_7.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_8():
    ser_8.write(b'a')
    arduinoData = ser_8.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_9():
    ser_9.write(b'a')
    arduinoData = ser_9.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_10():
    ser_10.write(b'a')
    arduinoData = ser_10.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_11():
    ser_11.write(b'a')
    arduinoData = ser_11.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_12():
    ser_12.write(b'a')
    arduinoData = ser_12.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_13():
    ser_13.write(b'a')
    arduinoData = ser_13.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_14():
    ser_14.write(b'a')
    arduinoData = ser_14.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_15():
    ser_15.write(b'a')
    arduinoData = ser_15.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_16():
    ser_16.write(b'a')
    arduinoData = ser_16.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_17():
    ser_17.write(b'a')
    arduinoData = ser_17.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_18():
    ser_18.write(b'a')
    arduinoData = ser_18.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_19():
    ser_19.write(b'a')
    arduinoData = ser_19.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_20():
    ser_20.write(b'a')
    arduinoData = ser_20.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_21():
    ser_21.write(b'a')
    arduinoData = ser_21.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_22():
    ser_22.write(b'a')
    arduinoData = ser_22.readline().decode().split('\r\n')
    return arduinoData[0]

def getValues_23():
    ser_23.write(b'a')
    arduinoData = ser_23.readline().decode().split('\r\n')
    return arduinoData[0]


        
currentTime = datetime.datetime.now()
print (str(currentTime))


dataTime = open('DataFile.csv', 'a')
dataTime.write('\r\n')
dataTime.write(str(currentTime))
dataTime.write('\r\n')
dataTime.write('\r\n')
dataTime.close()

Title = ['DateTime','Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6', 'Sensor 7', 'Sensor 8', 'Sensor 9', 'Sensor 10', 'Sensor 11', 'Sensor 12', 'Sensor 13', 'Sensor 14', 'Sensor 15', 'Sensor 16', 'Sensor 17', 'Sensor 18', 'Sensor 19', 'Sensor 20', 'Sensor 21', 'Sensor 22']
csvWrite(Title)
   
while(1): #while loop that loops for ever

    for i in range(0,numPoints):
        if(i==0):
            currentTime = datetime.datetime.now()
            dataList[i] = currentTime
        if(i==1):
            data = getValues_1()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_1.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_1)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_1=cnt_1+1
            if(cnt_1>50):
                Node_1.pop(0)
            time.sleep(1)
        if(i==2):
            data = getValues_2()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_2.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_2)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_2=cnt_2+1
            if(cnt_2>50):
                Node_2.pop(0)
            time.sleep(1)
        if(i==3):
            data = getValues_3()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_3.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_3)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_3=cnt_3+1
            if(cnt_3>50):
                Node_3.pop(0)
            time.sleep(1)
        if(i==4):
            data = getValues_4()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_4.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_4)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_4=cnt_4+1
            if(cnt_4>50):
                Node_4.pop(0)
            time.sleep(1)
        if(i==5):
            data = getValues_5()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_5.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_5)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_5=cnt_5+1
            if(cnt_5>50):
                Node_5.pop(0)
            time.sleep(1)
        if(i==6):
            data = getValues_6()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_6.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_6)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_6=cnt_6+1
            if(cnt_6>50):
                Node_6.pop(0)
            time.sleep(1)
        if(i==7):
            data = getValues_7()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_7.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_7)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_7=cnt_7+1
            if(cnt_7>50):
                Node_7.pop(0)
            time.sleep(1)
        if(i==8):
            data = getValues_8()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_8.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_8)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_8=cnt_8+1
            if(cnt_8>50):
                Node_8.pop(0)
            time.sleep(1)
        if(i==9):
            data = getValues_9()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_9.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_9)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_9=cnt_9+1
            if(cnt_9>50):
                Node_9.pop(0)
            time.sleep(1)
        if(i==10):
            data = getValues_10()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_10.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_10)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_10=cnt_10+1
            if(cnt_10>50):
                Node_10.pop(0)
            time.sleep(1)
        if(i==11):
            data = getValues_11()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_11.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_11)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_11=cnt_11+1
            if(cnt_11>50):
                Node_11.pop(0)
            time.sleep(1)
        if(i==12):
            data = getValues_12()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_12.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_12)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_12=cnt_12+1
            if(cnt_12>50):
                Node_12.pop(0)
            time.sleep(1)
        if(i==13):
            data = getValues_13()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_13.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_13)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_13=cnt_13+1
            if(cnt_13>50):
                Node_13.pop(0)
            time.sleep(1)
        if(i==14):
            data = 0
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_14.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_14)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_14=cnt_14+1
            if(cnt_14>50):
                Node_14.pop(0)
            time.sleep(1)
        if(i==15):
            data = 0
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_15.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_15)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_15=cnt_15+1
            if(cnt_15>50):
                Node_15.pop(0)
            time.sleep(1)
        if(i==16):
            data = getValues_16()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_16.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_16)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_16=cnt_16+1
            if(cnt_16>50):
                Node_16.pop(0)
            time.sleep(1)
        if(i==17):
            data = getValues_17()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_17.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_17)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_17=cnt_17+1
            if(cnt_17>50):
                Node_17.pop(0)
            time.sleep(1)
        if(i==18):
            data = getValues_18()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_18.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_18)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_18=cnt_18+1
            if(cnt_18>50):
                Node_18.pop(0)
            time.sleep(1)
        if(i==19):
            data = getValues_19()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_19.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_18)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_19=cnt_19+1
            if(cnt_19>50):
                Node_19.pop(0)
            time.sleep(1)
        if(i==20):
            data = getValues_20()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_20.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_20)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_20=cnt_20+1
            if(cnt_20>50):
                Node_20.pop(0)
            time.sleep(1)
        if(i==21):
            data = getValues_21()
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_21.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_21)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_21=cnt_21+1
            if(cnt_21>50):
                Node_21.pop(0)
            time.sleep(1)
        if(i==22):
            data = 0
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_22.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_22)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_22=cnt_22+1
            if(cnt_22>50):
                Node_22.pop(0)
            time.sleep(1)
        if(i==23):
            data = 0
            print('Reading ' + str(i) + ' is: ' + str(data))
            dataFloat = float(data)
            dataList[i] = dataFloat
            Node_23.append(dataFloat)                  #Build the Node array by appending readings
            drawnow(makeFig_23)                        #Call draw now to update the live graph
            plt.pause(.000001)
            cnt_23=cnt_23+1
            if(cnt_23>50):
                Node_23.pop(0)
            time.sleep(1)


    csvWrite(dataList)
            
            

