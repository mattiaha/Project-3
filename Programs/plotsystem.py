# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 17:54:02 2020

@author: matti
"""

import matplotlib.pyplot as plt
import numpy as np

data0 = np.loadtxt("0body.txt", skiprows=2)
x0  = data0[:,0]
y0 = data0[:,1]
z0 = data0[:,2]
data1 = np.loadtxt("1body.txt", skiprows=2)
x1  = data1[:,0]
y1 = data1[:,1]
z1 = data1[:,2]
data2 = np.loadtxt("2body.txt", skiprows=2)
x2  = data2[:,0]
y2 = data2[:,1]
z2 = data2[:,2]
data3 = np.loadtxt("3body.txt", skiprows=2)
x3 = data3[:,0]
y3 = data3[:,1]
z3 = data3[:,2]
data4 = np.loadtxt("4body.txt", skiprows=2)
x4  = data4[:,0]
y4 = data4[:,1]
z4 = data4[:,2]
data5 = np.loadtxt("5body.txt", skiprows=2)
x5  = data5[:,0]
y5 = data5[:,1]
z5 = data5[:,2]
data6 = np.loadtxt("6body.txt", skiprows=2)
x6  = data6[:,0]
y6 = data6[:,1]
z6 = data6[:,2]
data7 = np.loadtxt("7body.txt", skiprows=2)
x7  = data7[:,0]
y7 = data7[:,1]
z7 = data7[:,2]
data8 = np.loadtxt("8body.txt", skiprows=2)
x8  = data8[:,0]
y8 = data8[:,1]
z8 = data8[:,2]

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.set_xlabel('X[AU]')
ax.set_ylabel('Y[AU]')
ax.set_zlabel('Z[AU]')
ax.plot3D(x0,y0,z0, label='Mercury')
ax.plot3D(x1,y1,z1, label='Venus')
ax.plot3D(x2,y2,z2, label='Earth')
ax.plot3D(x3,y3,z3, label='Mars')
ax.plot3D(x4,y4,z4, label='Saturn')
ax.plot3D(x5,y5,z5, label='Uranus')
ax.plot3D(x6,y6,z6, label='Neptune')
ax.plot3D(x7,y7,z7, label='Jupiter')
ax.plot3D(x8,y8,z8, label='Sun')
ax.set_xlim3d(-30, 30)
ax.set_ylim3d(-30, 30)
ax.set_zlim3d(-30,30)

ax.set_title("Solar System in 3 Dimensions")
ax.legend()

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.set_xlabel('X[AU]')
ax.set_ylabel('Y[AU]')
ax.set_zlabel('Z[AU]')
ax.plot3D(x0,y0,z0, label='Mercury')
ax.plot3D(x1,y1,z1, label='Venus')
ax.plot3D(x2,y2,z2, label='Earth')
ax.plot3D(x3,y3,z3, label='Mars')

ax.plot3D(x8,y8,z8, label='Sun')
ax.set_xlim3d(-1.5, 1.5)
ax.set_ylim3d(-1.5, 1.5)
ax.set_zlim3d(-1.5,1.5)
ax.set_title("Solar System in 3 Dimensions")
ax.legend()
