#include "Solar.h"



int main(int argc, char const* argv[]) {
	int N;
	int func;
	cout << "Enter value for N" << endl;
	cin >> N;
	cout << "(1) for solar system, (2) for two-body problem, (3) for three-body problem" << endl;;
	cin >> func ;
	
	double t_max = 300.;
	clock_t start, end;
	if (func == 1) {
		if (N > 10000) {
			cout << "N cannot exceed 10000 for this problem" << endl;
			exit(0);
		}
		ThreeBody solver;
		string filename = to_string(t_max) + "year_solarsystem.txt";
		solver.simulate_system(N, t_max, filename);
	
	
	
	}
	else if (func == 2) {
		vec x(N), y(N), z(N), r(N), vx(N), vy(N), vz(N), v(N), t(N), Fx(N), Fy(N), Fz(N), KE(N), PE(N), totE(N);
		double m;
		string filename = to_string(N) + "circ_body.txt";
		TwoBody Solar;
		SolarSystem ss;
		ss.earthcirc(x(0), y(0), z(0), r(0), vx(0), vy(0), vz(0), v(0), m);
		start = clock();
		Solar.velocity_verlet_2body(x, y, z, r, vx, vy, vz, v, KE, PE, N, m, t_max);
		end = clock();
		ss.writetofile(x, y, z, KE, PE, filename, N);
		
		cout << scientific << "VV CPU time (sec) : " << ((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	
	
		string filename_ec = to_string(N) + "circ_body_ec.txt";
		ss.earthcirc(x(0), y(0), z(0), r(0), vx(0), vy(0), vz(0), v(0), m);
		start = clock();
		Solar.euler_chromer(x, y, z, r, vx, vy, vz, v, KE, PE, N, m, t_max);
		end = clock();
		cout << scientific << "EC CPU time (sec) : " << ((double)end - (double)start) / CLOCKS_PER_SEC << endl;
		ss.writetofile(x, y, z, KE, PE, filename_ec, N);
	}
	
	else if (func == 3) {
		ThreeBody solver;
		string filename_3 = "3body.txt";
		solver.three_body_velocityverlet(N, t_max, filename_3);

	}
	else {
		cout << "No valid function entered" << endl;
		exit(6);
	}
	
	
}


