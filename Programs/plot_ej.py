# -*- coding: utf-8 -*-
"""
Created on Sat Oct 24 18:54:54 2020

@author: matti
"""

import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits import mplot3d

data1 = np.loadtxt("earth3body.txt", skiprows=2)
data2 = np.loadtxt("jupiter3body.txt", skiprows=2)
sun = np.zeros([3,1])
x1  = data1[:,0]
y1 = data1[:,1]
z1 = data1[:,2]
x2  = data2[:,0]
y2 = data2[:,1]
z2 = data2[:,2]

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.set_xlabel('X[AU]')
ax.set_ylabel('Y[AU]')
ax.set_zlabel('Z[AU]')
ax.plot3D(x1,y1,z1, label='Earth')
ax.plot3D(sun[0],sun[1],sun[2], 'x')
ax.plot3D(x2,y2,z2, label='Jupiter')
ax.set_xlim3d(-5, 5)
ax.set_ylim3d(-5, 5)
ax.set_zlim3d(-5,5)
ax.set_title("Orbit of Earth and Jupiter")
ax.legend()

