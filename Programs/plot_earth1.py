# -*- coding: utf-8 -*-
"""
Created on Fri Oct 16 16:10:08 2020

@author: matti
"""

import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("10000circ_body.txt", skiprows=2)
x  = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.plot(0,0, "x")
plt.xlim(-1.5, 1.5)
plt.ylim(-1.5, 1.5)

plt.xlabel("x [AU]")
plt.ylabel("y[AU]")
plt.title("Earth, circular orbit")
plt.gca().set_aspect('equal', adjustable='box')
plt.draw()