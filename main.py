import struct
import tkinter as tk
import serial
import numpy
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasAgg
from serial.serialutil import Timeout

graph_y = []

def getdata():
    with serial.Serial('COM3', 9600, timeout=0.1) as s:
        for i in range(1000):
            data = s.readline().decode().rstrip()
            if len(data) == 5:
                graph_y.append(float(data))
            plt.plot(numpy.arange(len(graph_y)), graph_y)
            plt.pause(0.01)
