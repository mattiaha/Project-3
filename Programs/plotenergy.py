# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 18:54:07 2020

@author: matti
"""

import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("10000circ_body_EC.txt", skiprows=2)
PE  = data[:,3]
KE = data[:,4]
data2 = np.loadtxt("10000circ_body.txt", skiprows=2)
PE2  = data2[:,3]
KE2 = data2[:,4]
N = np.size(KE)
t = np.linspace(0,N,N)
"""
plt.plot(t,PE)
plt.xlabel("$\Delta$ t")
plt.ylabel("PE[(M)($AU)^{2}$/$(year)^{2}$]")
plt.title("Potential energy for circular orbit")
plt.show()
"""
plt.plot(t,PE, label=  "Euler-Cromer")
plt.show()
plt.plot(t,PE2, label = "Velocity-Verlet")
plt.xlabel("$\Delta$ t")
plt.ylabel("KE[(M)($AU)^{2}$/$(year)^{2}$]")
plt.title("Potential energy for circular orbit")

plt.legend()
plt.show()

"""
totE = np.zeros(N)
for i in range(N):
    totE[i] = PE[i] + KE[i]

plt.plot(t,totE)
plt.xlabel("$\Delta$ t")
plt.ylabel("Total E [(M)($AU)^{2}$/$(year)^{2}$]")
plt.axis([0,5000,0,0.08])
plt.title("Total energy for Earth, $M_{J}$ = 1000")
plt.show()
"""
