#include "Solar.h"

void TwoBody::velocity_verlet_2body(vec& x, vec& y, vec& z, vec& r, vec& vx, vec& vy, vec& vz, vec& v, vec& KE, vec& PE, int N, double m, double t_max) {
	double h = t_max / double(N);
	vec Fx(N), Fy(N), Fz(N);
	double M = 1.;
	
	force(x(0), y(0), z(0), r(0), Fx(0), Fy(0), Fz(0), m, M);
	double tol = 1E-4;
	calc_energy(m, r(0), v(0), KE(0), PE(0));
	double E0 = abs(KE(0) + PE(0));

	for (int i = 0; i < N - 1; i++) {
		x(i + 1) = x(i) + h * vx(i) + 0.5 * h * h * Fx(i) / m;
		y(i + 1) = y(i) + h * vy(i) + 0.5 * h * h * Fy(i) / m;
		z(i + 1) = z(i) + h * vz(i) + 0.5 * h * h * Fz(i) / m;
		r(i + 1) = sqrt(x(i + 1) * x(i + 1) + y(i + 1) * y(i + 1) + z(i + 1) * z(i + 1));
		force(x(i + 1), y(i + 1), z(i + 1), r(i + 1), Fx(i + 1), Fy(i + 1), Fz(i + 1), m, M);


		vx(i + 1) = vx(i) + 0.5 * h * (Fx(i + 1) + Fx(i)) / m;
		vy(i + 1) = vy(i) + 0.5 * h * (Fy(i + 1) + Fy(i)) / m;
		vz(i + 1) = vz(i) + 0.5 * h * (Fz(i + 1) + Fz(i)) / m;
		v(i + 1) = sqrt(vx(i + 1) * vx(i + 1) + vy(i + 1) * vy(i + 1) + vz(i + 1) * vz(i + 1));
		calc_energy(m, r(i + 1), v(i + 1), KE(i + 1), PE(i + 1));
		energy_test(KE(i + 1), PE(i + 1), E0, tol);
		
	}


}

void TwoBody::euler_chromer(vec& x, vec& y, vec& z, vec& r, vec& vx, vec& vy, vec& vz, vec& v, vec& KE, vec& PE, int N, double m, double t_max) {
	double h = t_max / double(N);
	double E0 = abs(KE(0) + PE(0));
	double tol = 1E-4;
	calc_energy(m, r(0), v(0), KE(0), PE(0));
	for (int i = 0; i < N - 1; i++) {
		r(i) = sqrt(x(i) * x(i) + y(i) * y(i) + z(i) * z(i));
		double a = -G / (r(i) * r(i));
		vx(i + 1) = vx(i) + h * (a * x(i) / r(i));
		vy(i + 1) = vy(i) + h * (a * y(i) / r(i));
		vz(i + 1) = vz(i) + h * (a * z(i) / r(i));
		x(i + 1) = x(i) + h * vx(i + 1);
		y(i + 1) = y(i) + h * vy(i + 1);
		z(i + 1) = z(i) + h * vz(i + 1);
		v(i + 1) = sqrt(vx(i + 1) * vx(i + 1) + vy(i + 1) * vy(i + 1) + vz(i + 1) * vz(i + 1));
		calc_energy(m, r(i), v(i), KE(i), PE(i));
		energy_test(KE(i+1), PE(i+1), E0, tol);
		a = 0;

	}
};


void perihelion_mercury() {

}