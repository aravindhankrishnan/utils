#!/usr/bin/python

import sys
import decimal
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt


inputfile_str = "/home/aravindhan/projects/lidarmapping/build/mapper/gps-trajectory.txt"

inputfile = open (inputfile_str)

x = []
y = []
z = []

counter = 0

while True:
    s = ''
    s = inputfile.readline ()

    if not s:
        break

    tokens = s.split ()

    if counter == 0:
        ix = decimal.Decimal (tokens[0]);
        iy = decimal.Decimal (tokens[1]);
        iz = decimal.Decimal (tokens[2]);
        counter = counter + 1;

    x.append (decimal.Decimal (tokens[0]) - ix)
    y.append (decimal.Decimal (tokens[1]) - iy)
    z.append (decimal.Decimal (tokens[2]) - iz)

mpl.rcParams['legend.fontsize'] = 10
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot(x, y, z, label='Curve')
ax.legend()

plt.show()
