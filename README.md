# Project-3
The C++ program is saved in the folder programs. The main file is main.cpp, and this uses the classes that are included in the file. Make sure they all are in the same repository before running the program. 
The program uses the Armadillo library for C++, so make sure to have this installed before running the code. 
main.cpp allows us to choose between running the two-body problem, three-body problem or to simulate the solar system. We have only made the program run the two and three-body problems for Earth, but we can easily choose another planet by changing the class we use to initiate the position and velocity, as well as select the mass. Every planet has their values stored as a class, so one can swap the earth class in the solver classes with the planet of our choice.

If one wishes to look at the two-body problem for high values of the step-size h, it is recommended to comment out the call for the energy test in the euler-cromer and velocity verlet-classes. This test stops the program from running if the total energy at any time differs with more than the tolerance of 1E-4 from the initial total energy.

The position and energy is written out for the two-body problem and three-body problem. The position can be plotted in the x and y-dimension using the python script plot_earth1.py, by simply writing in the txt-file with the position values we wish to visualize. If we wish to plot in three dimensions, we can use the script plot_ej.py and read the txt-files of our choice. If we only want to plot one body in three dimensions, we can simply comment out the code concerning the second body.

The script plotenergy.py can be used to plot the kinetic, potential and total energy for any planet of our choice, by writing in the txt-file as with the other scripts. 
Finally, the script plotsystem.py will plot the orbits of each of the planets in the solar system, as well as the sun. It can easily be modified if we want to add or subtract bodies to observe.

The txt-files used for the figures are found in TextFiles, and figures are placed in figures.
