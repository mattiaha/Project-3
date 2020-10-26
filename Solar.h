#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <armadillo>
#include <time.h>
#include <vector>
using namespace std;
using namespace arma;

class SolarSystem {
public:
	void writetofile(vec x, vec y, vec z,  vec PE, vec KE, string filename, int N);
	

	void calc_energy(double mass, double v, double r, double& ke, double& pe);
	void energy_test(double ke, double pe, double E0, double e_tol);
	void force(double x, double y, double z, double  r, double& Fx, double& Fy, double& Fz, double m, double M);
	void force2(cube pos, cube& force, double m, double M, int i, int j); 
	void sun(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void mercury(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void venus(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void earth(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void mars(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void jupiter(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void saturn(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void uranus(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	void neptune(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	double G = 38.7; //gravitational constant
	clock_t start, end;
	void RadiusTest(double r0, double r);
	void orbit_test(double ke, double pe);
	void earthcirc(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m);
	
};
class TwoBody: public SolarSystem{
public:
	
	void euler_chromer(vec& x, vec& y, vec& z, vec& r, vec& vx, vec& vy, vec& vz, vec& v, vec& KE, vec& PE, int N, double m, double t_max);
	void velocity_verlet_2body(vec& x, vec& y, vec& z, vec& r, vec& vx, vec& vy, vec& vz, vec& v, vec& KE, vec& PE, int N, double m, double t_max);


};
class ThreeBody: public SolarSystem {
public:
	void three_body_velocityverlet(int N, double t_max, string filename);
	void RelativePosition(int i, mat pos1, mat pos2, mat& rel_pos);
	void write2file3body(mat pos, vec KE, vec PE, string filename, int N);
	void simulate_system(int N, double t_max, string filename);
	void initialize_system(cube& pos, cube& vel, cube& F, cube& relforce_jupiter, cube& relpos_jupiter, cube& relforce_sun, cube& relpos_sun, vec& mass);
	void RelativePositionSystem(int i, int j, int s, cube pos, cube& relpos);
	void write2filesolar(cube pos, string filename, int N);
};





#endif // SOLARSYSTEM_H