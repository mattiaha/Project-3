#include "Solar.h"




void ThreeBody::write2file3body(mat pos, vec KE, vec PE, string filename, int N) {
	ofstream ofile;
	ofile.open(filename);
	// we write out the values to our selected file;
	ofile << "    N   =   " << N << endl;
	ofile << setiosflags(ios::showpoint | ios::uppercase);
	ofile << "      x:            y:             z:          PE:            KE:" << endl;
	for (int i = 0; i <= N - 1; i++) {
		ofile << setw(15) << setprecision(8) <<	pos(0,i);
		ofile << setw(15) << setprecision(8) << pos(1,i);
		ofile << setw(15) << setprecision(8) << pos(2,i);
		ofile << setw(15) << setprecision(8) << PE(i);
		ofile << setw(15) << setprecision(8) << KE(i) << endl;;


	}
	ofile.close();
}
void ThreeBody::write2filesolar(cube pos, string filename, int N) {
	//loop over number of bodies in system
	for (int j = 0; j < 9; j++) {
		ofstream ofile;
		string name_file = filename;
		name_file = to_string(j) + name_file;
		ofile.open(name_file);
		// we write out the values to our selected file;
		ofile << "    N   =   " << N << endl;
		ofile << setiosflags(ios::showpoint | ios::uppercase);
		ofile << "      x:            y:             z:          PE:            KE:" << endl;
		for (int i = 0; i < N; i++) {
			ofile << setw(15) << setprecision(8) << pos(j, 0, i);
			ofile << setw(15) << setprecision(8) << pos(j, 1, i);
			ofile << setw(15) << setprecision(8) << pos(j, 2, i) << endl;
			//ofile << setw(15) << setprecision(8) << PE(i);
			//ofile << setw(15) << setprecision(8) << KE(i) << endl;;

		}
		ofile.close();
	}
}
void ThreeBody::RelativePosition(int i, mat pos1, mat pos2, mat& rel_pos) {
	rel_pos(0, i) = pos1(0, i) - pos2(0, i); // x-position
	rel_pos(1, i) = pos1(1, i) - pos2(1, i); // y-position
	rel_pos(2, i) = pos1(2, i) - pos2(2, i); // z-position
	rel_pos(3, i) = sqrt(rel_pos(0, i)* rel_pos(0, i) + rel_pos(1, i)* rel_pos(1, i) + rel_pos(2, i)* rel_pos(2, i)); // r
}

void ThreeBody::RelativePositionSystem(int i, int j, int s, cube pos, cube& relpos) {
	for (int k = 0; k < 3; k++) {
		relpos(j, k, i) = pos(j,k,i)-pos(7+s,k,i);
	}
	relpos(j, 3, i) = sqrt(relpos(j, 0, i)* relpos(j, 0, i) + relpos(j, 1, i)* relpos(j, 1, i) + relpos(j, 2, i)* relpos(j, 2, i));
	
}
void ThreeBody::three_body_velocityverlet(int N, double t_max, string filename) {
	mat pos1(4, N), pos2(4, N), rel_pos(4,N),vel1(4, N), vel2(4, N), force1(3,N), force2(3,N), relforce(3,N),  energy1(3,N), energy2(3,N);
	double h = t_max / double(N);
	double M = 1.;
	double me, mj;
	vec PE1(N), PE2(N), KE1(N), KE2(N);
	string filename1 ="earth" +filename ;
	string filename2 = "jupiter" + filename;
	start = clock();
	

	
	earth(pos1(0,0),pos1(1,0),pos1(2,0),pos1(3,0),vel1(0,0),vel1(1,0),vel1(2,0),vel1(3,0),me);
	jupiter(pos2(0, 0), pos2(1, 0), pos2(2, 0), pos2(3, 0), vel2(0, 0), vel2(1, 0), vel2(2, 0), vel2(3, 0), mj);
	RelativePosition(0, pos1, pos2, rel_pos);

	force(rel_pos(0, 0), rel_pos(1, 0), rel_pos(2, 0), rel_pos(3, 0), relforce(0, 0), relforce(1, 0), relforce(2, 0), me, mj);
	force(pos1(0, 0), pos1(1, 0), pos1(2, 0), pos1(3, 0), force1(0, 0), force1(1, 0), force1(2, 0), me, M);
	force(pos2(0, 0), pos2(1, 0), pos2(2, 0), pos2(3, 0), force2(0, 0), force2(1, 0), force2(2, 0), mj, M);
	force1(0, 0) += relforce(0, 0);
	force1(1, 0) += relforce(1, 0); 
	force1(2, 0) += relforce(2, 0);
	force2(0, 0) += -relforce(0, 0);
	force2(1, 0) += -relforce(1, 0);
	force2(2, 0) += -relforce(2, 0);
	calc_energy(me, pos1(3,0), vel1(3,0), KE1(0), PE1(0));
	calc_energy(mj, pos2(3, 0), vel2(3, 0), KE2(0), PE2(0));
	for (int i = 0; i < N-1; i++) {

		pos1(0, i+1) = pos1(0,i) + h * vel1(0,i) + 0.5 * h * h * force1(0,i) / me; // x-position earth
		pos1(1, i+1) = pos1(1, i) + h * vel1(1, i) + 0.5 * h * h * force1(1, i) / me; // y-position eart
		pos1(2, i+1) = pos1(2, i) + h * vel1(2, i) + 0.5 * h * h * force1(2, i) / me; // z-position earth
		pos1(3, i+1) = sqrt(pos1(0, i+1) * pos1(0, i+1) + pos1(1, i+1) * pos1(1, i+1) + pos1(2, i+1) * pos1(2, i+1)); // r earth
		pos2(0, i+1) = pos2(0, i) + h * vel2(0, i) + 0.5 * h * h * force2(0, i) / mj; // x-position jupiter
		pos2(1, i+1) = pos2(1, i) + h * vel2(1, i) + 0.5 * h * h * force2(1, i) / mj;  // y-position jupiter
		pos2(2, i+1) = pos2(2, i) + h * vel2(2, i) + 0.5 * h * h * force2(2, i) / mj;  // z-position jupiter
		pos2(3, i+1) = sqrt(pos2(0, i+1) * pos2(0, i+1) + pos2(1, i+1) * pos2(1, i+1) + pos2(2, i+1) * pos2(2, i+1));  // r jupiter 
		RelativePosition(i + 1, pos1, pos2, rel_pos);
		force(rel_pos(0, i+1), rel_pos(1, i+1), rel_pos(2, i+1), rel_pos(3, i+1), relforce(0, i+1), relforce(1, i+1), relforce(2, i+1), me, mj);
		force(pos1(0, i+1), pos1(1, i+1), pos1(2, i+1), pos1(3, i+1), force1(0, i+1), force1(1, i+1), force1(2, i+1), me, M);
		force(pos2(0, i+1), pos2(1, i+1), pos2(2, i+1), pos2(3, i+1), force2(0, i+1), force2(1, i+1), force2(2, i+1), mj, M);
		force1(0, i+1) += relforce(0, i+1);
		force1(1, i+1) += relforce(1, i+1);
		force1(2, i+1) += relforce(2, i+1);
		force2(0, i+1) += -relforce(0, i+1);
		force2(1, i+1) += -relforce(1, i+1);
		force2(2, i+1) += -relforce(2, i+1);
		
		vel1(0, i+1) = vel1(0,i) + 0.5 * h * (force1(0,i + 1) + force1(0,i)) / me; // x-velocity earth
		vel1(1, i+1) = vel1(1, i) + 0.5 * h * (force1(1, i + 1) + force1(1, i)) / me; // y-velocity
		vel1(2, i+1) = vel1(2, i) + 0.5 * h * (force1(2, i + 1) + force1(2, i)) / me; // z-velocity
		vel1(3, i + 1) = sqrt(vel1(0, i+1) * vel1(0, i+1) + vel1(1, i+1) * vel1(1, i+1) + vel1(2, i+1) * vel1(2, i+1)); // velocity


		vel2(0, i + 1) = vel2(0, i) + 0.5 * h * (force2(0, i + 1) + force2(0, i)) / mj; // x-velocity
		vel2(1, i+1) = vel2(1, i) + 0.5 * h * (force2(1, i + 1) + force2(1, i)) / mj; // y-velocity
		vel2(2, i+1) = vel2(2, i) + 0.5 * h * (force2(2, i + 1) + force2(2, i)) / mj; // z-velocity
		vel2(3, i+1) = sqrt(vel2(0, i+1) * vel2(0, i+1) + vel2(1, i+1) * vel2(1, i+1) + vel2(2, i+1) * vel2(2, i+1)); // velocity
		
		calc_energy(me, pos1(3, i+1), vel1(3, i+1), KE1(i+1), PE1(i+1));
		calc_energy(mj, pos2(3, i+1), vel2(3, i+1), KE2(i+1), PE2(i+1));

	}
	end = clock();
	cout << scientific << "CPU time (sec) : " << ((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	write2file3body( pos1,  KE1,  PE1,  filename1,  N);
	write2file3body( pos2,  KE2,  PE2,  filename2,  N);
}



void ThreeBody::simulate_system(int N, double t_max, string filename) {
	cube pos(10, 4, N, fill::zeros), vel(10, 4, N, fill::zeros), F(10,4,N, fill::zeros), relforce_jupiter(7,4,N, fill::zeros),relpos_jupiter(7,4,N, fill::zeros), relforce_sun(8,4,N, fill::zeros), relpos_sun(8,4,N, fill::zeros);
	double h = t_max / double(N);
	vec mass(10);
	field<string> body(9);
	start = clock();


	
	initialize_system(pos, vel, F, relforce_jupiter, relpos_jupiter, relforce_sun,relpos_sun, mass);
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 3; k++) {
				pos(j, k, i + 1) = pos(j, k, i) + h * vel(j, k, i) + 0.5 * h * h * F(j, k, i) / mass(j);
			}
			pos(j, 3, i + 1) = sqrt(pos(j, 0, i+1) * pos(j, 0, i+1) + pos(j, 1, i+1) * pos(j, 1, i+1) + pos(j, 2, i+1) * pos(j, 2, i+1));
			RadiusTest(pos(j, 3, 0), pos(j, 3, i + 1));
		}
		for (int j = 0; j < 7; j++) {
			RelativePositionSystem(i+1, j, 0, pos, relpos_jupiter);
			RelativePositionSystem(i+1, j, 1, pos, relpos_sun);
			force2(relpos_jupiter, relforce_jupiter, mass(j), mass(7), i+1, j);
			force2(relpos_sun, relforce_sun, mass(j), mass(8), i+1, j);
			for (int k = 0; k < 3; k++) {
				F(j, k, i+1) = relforce_jupiter(j, k, i+1) + relforce_sun(j, k, i+1);
			}

		}
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 7; j++) {
				F(7, k, i+1) += -relforce_jupiter(j, k, i+1);
				F(8, k, i+1) += -relforce_sun(j, k, i+1);
			}
			RelativePositionSystem(i+1, 7, 1, pos, relpos_sun);

			force2(relpos_sun, relforce_sun, mass(7), mass(8), i+1, 7);
			F(7, k, i+1) += relforce_sun(7, k, i+1);
			F(8, k, i+1) += -relforce_sun(7, k, i+1);
		}

		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 3; k++) {
				vel(j, k, i + 1) = vel(j, k, i) + 0.5 * h * (F(j, k, i + 1) + F(j, k, i)) / mass(j);
			}
			vel(j, 3, i + 1) = sqrt(vel(j, 0, i + 1) * vel(j, 0, i + 1) + vel(j, 1, i + 1) * vel(j, 1, i + 1) + vel(j, 2, i + 1) * vel(j, 2, i + 1));
		}
	}
	end = clock();
	cout << scientific << "CPU time (sec) : " << ((double)end - (double)start) / CLOCKS_PER_SEC << endl;
	write2filesolar(pos, filename, N);
}

void ThreeBody::initialize_system(cube& pos, cube& vel, cube& F, cube& relforce_jupiter, cube& relpos_jupiter, cube& relforce_sun, cube& relpos_sun, vec& mass) {
	mercury(pos(0, 0, 0), pos(0, 1, 0), pos(0, 2, 0), pos(0, 3, 0), vel(0, 0, 0), vel(0, 1, 0), vel(0, 2, 0), vel(0, 3, 0), mass(0));
	venus(pos(1, 0, 0), pos(1, 1, 0), pos(1, 2, 0), pos(1, 3, 0), vel(1, 0, 0), vel(1, 1, 0), vel(1, 2, 0), vel(1, 3, 0), mass(1));
	earth(pos(2, 0, 0), pos(2, 1, 0), pos(2, 2, 0), pos(2, 3, 0), vel(2, 0, 0), vel(2, 1, 0), vel(2, 2, 0), vel(2, 3, 0), mass(2));
	mars(pos(3, 0, 0), pos(3, 1, 0), pos(3, 2, 0), pos(3, 3, 0), vel(3, 0, 0), vel(3, 1, 0), vel(3, 2, 0), vel(3, 3, 0), mass(3));
	saturn(pos(4, 0, 0), pos(4, 1, 0), pos(4, 2, 0), pos(4, 3, 0), vel(4, 0, 0), vel(4, 1, 0), vel(4, 2, 0), vel(4, 3, 0), mass(4));
	uranus(pos(5, 0, 0), pos(5, 1, 0), pos(5, 2, 0), pos(5, 3, 0), vel(5, 0, 0), vel(5, 1, 0), vel(5, 2, 0), vel(5, 3, 0), mass(5));
	neptune(pos(6, 0, 0), pos(6, 1, 0), pos(6, 2, 0), pos(6, 3, 0), vel(6, 0, 0), vel(6, 1, 0), vel(6, 2, 0), vel(6, 3, 0), mass(6));
	jupiter(pos(7, 0, 0), pos(7, 1, 0), pos(7, 2, 0), pos(7, 3, 0), vel(7, 0, 0), vel(7, 1, 0), vel(7, 2, 0), vel(7, 3, 0), mass(7));
	sun(pos(8, 0, 0), pos(8, 1, 0), pos(8, 2, 0), pos(8, 3, 0), vel(8, 0, 0), vel(8, 1, 0), vel(8, 2, 0), vel(8, 3, 0), mass(8));

	for (int j = 0; j < 7; j++) {
		RelativePositionSystem(0, j, 0, pos, relpos_jupiter);
		RelativePositionSystem(0, j, 1, pos, relpos_sun);
		force2(relpos_jupiter, relforce_jupiter, mass(j), mass(7), 0, j);
		force2(relpos_sun, relforce_sun, mass(j), mass(8), 0, j);
		for (int k = 0; k < 3; k++) {
			F(j, k, 0) = relforce_jupiter(j, k, 0) + relforce_sun(j, k, 0);
		}

	}
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 7; j++) {
			F(7, k, 0) += -relforce_jupiter(j, k, 0);
			F(8, k, 0) += -relforce_sun(j, k, 0);
		}
		RelativePositionSystem(0, 7, 1, pos, relpos_sun);
		
		force2(relpos_sun, relforce_sun, mass(7), mass(8), 0, 7);
		F(7, k, 0) += relforce_sun(7, k, 0);
		F(8, k, 0) += -relforce_sun(7, k, 0);
	}
	
}