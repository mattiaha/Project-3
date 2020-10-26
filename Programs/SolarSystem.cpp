#include "Solar.h"



void SolarSystem::writetofile(vec x, vec y,vec z, vec KE, vec PE, string filename, int N){
	ofstream ofile;
	ofile.open(filename);
	// we write out the values to our selected file;
	ofile << "    N   =   " << N << endl;
	ofile << setiosflags(ios::showpoint | ios::uppercase);
	ofile << "      x:            y:             z:          PE:            KE:"          << endl;
	for (int i = 0; i <= N - 1; i++) {
		ofile << setw(15) << setprecision(8) << x(i);
		ofile << setw(15) << setprecision(8) << y(i);
		ofile << setw(15) << setprecision(8) << z(i); 
		ofile << setw(15) << setprecision(8) << PE(i);
		ofile << setw(15) << setprecision(8) << KE(i) << endl;;
		

	}
	ofile.close();
}

void SolarSystem::calc_energy(double mass, double r, double v, double& ke, double& pe) {
	ke = 0.5*mass*v*v;
	pe = -(G * mass) / r;
}


void SolarSystem::force(double x, double y, double z, double r, double& Fx, double& Fy, double& Fz, double m, double M) {
	Fx = -G * M * m * x / (r * r * r);
	Fy = -G * M * m * y / (r * r * r);
	Fz = -G * M * m * z / (r * r * r);
}

void SolarSystem::force2(cube pos, cube& force, double m, double M, int i, int j) {
	for (int k = 0; k < 3; k++) {
		force(j, k, i) = -G * M * m * pos(j, k, i) / (pos(j, 3, i) * pos(j, 3, i) * pos(j, 3, i));
	}

}
void SolarSystem::earthcirc(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 1.; //AU
	y = 0; //AU
	z = 0;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = 0; // AU/year
	vy = 6.28; // AU/year
	vz = 0; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 2.986E-6;//Solar masses
	string body = "Earth";

}

void SolarSystem::sun(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = -6.0787E-3; //AU
	y = 6.44E-3; //AU
	z = 8.80639E-5;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = -2.66E-3; // AU/year
	vy = -1.8455E-3; // AU/year
	vz = 7.9755E-5; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 1.;//Solar masses
	string body = "Sun";
}

void SolarSystem::jupiter(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 2.5308; //AU
	y = -4.445; //AU
	z = -3.1818E-2;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = 2.3596; // AU/year
	vy = 1.4933; // AU/year
	vz = -0.05898; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 9.5E-4;//Solar masses
	string body = "Jupiter";
}

void SolarSystem::earth(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 0.93848; //AU
	y = 0.32874; //AU
	z = 6.8143E-5;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = -2.1311; // AU/year
	vy = 5.91957; // AU/year
	vz = -3.263E-4; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 2.986E-6;//Solar masses
	string body = "Earth";

}

void SolarSystem::mercury(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 0.328827; //AU
	y = -0.203788; //AU
	z = -4.7812E-2;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = 3.44; // AU/year
	vy = 9.1651; // AU/year
	vz = 0.4334; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 1.65E-7;//Solar masses
	string body = "Mercury";
}

void SolarSystem::venus(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = -0.14220; //AU
	y = 0.7123; //AU
	z = 0.0176;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = -7.274; // AU/year
	vy = -1.4407; // AU/year
	vz = 0.4; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 2.45E-6;//Solar masses
	string body = "Venus";
}
void SolarSystem::mars(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 1.3263; //AU
	y = 0.48091; //AU
	z = -0.02265;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = -1.52; // AU/year
	vy = 5.245; // AU/year
	vz = 0.1472; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 3.3E-7;//Solar masses
	string body = "Mars";
}
void SolarSystem::saturn(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 5.12613; //AU
	y = -8.57511; //AU
	z = -5.4976E-2;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = 1.6345; // AU/year
	vy = 1.0397; // AU/year
	vz = -0.0832; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 2.75E-4;//Solar masses
	string body = "Saturn";
}
void SolarSystem::uranus(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 15.544; //AU
	y = 12.233; //AU
	z = -0.15594;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = -0.8983; // AU/year
	vy = 1.0612; // AU/year
	vz = 0.01559; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 4.4E-5;//Solar masses
	string body = "Uranus";
}
void SolarSystem::neptune(double& x, double& y, double& z, double& r, double& vx, double& vy, double& vz, double& v, double& m) {
	x = 29.41; //AU
	y = -5.47749; //AU
	z = -0.5649;//AU
	r = sqrt(x * x + y * y + z * z); //AU
	vx = 0.202; // AU/year
	vy = 1.1333; // AU/year
	vz = -0.0279; // AU/year
	v = sqrt(vx * vx + vy * vy + vz * vz);
	m = 5.15E-5;//Solar masses
	string body = "Neptune";
}





void SolarSystem::energy_test(double ke, double pe, double E0, double tol) {

	if (abs((abs(ke + pe) - E0) / E0) > tol) {
		cout << "Total energy is not conserved" << endl;
		exit(1);
	}

}

void SolarSystem::orbit_test(double ke, double pe) {
	if (ke > pe) {
		cout << "Orbit is not bound" << endl;
		exit(2);
	}
}


void SolarSystem::RadiusTest(double r0, double r) {
	if (abs(r) > 10 * r0) {
		cout << "r too large relative to initial value" << endl;
		exit(4);

	}
}