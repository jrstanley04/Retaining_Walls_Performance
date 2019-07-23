import serial
import numpy as np
import csv
import time
import matplotlib.pyplot as plt
from drawnow import *
from scipy import interpolate


ser = serial.Serial('COM3', baudrate =9600, timeout=1)

while 1:

    arduinoData = ser.readline()
    print(arduinoData)

    
