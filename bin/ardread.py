#!/usr/bin/python3

import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
print("here")
while 1: 
    if(ser.in_waiting >0):
        line = ser.readline()
        print(line)
