#include "Scheme.h"
#include <cmath>
#include <iomanip>

using namespace std;

double PI = 4 * atan(1);

Scheme::Scheme() : dx(5), dt(0.02), u(250), xmax(405), tmax(0.5+dt) {

}

Scheme::Scheme(double dx, double dt, double u, double xmax, double tmax) {
	this->dx = dx;
	this->dt = dt;
	this->u = u;
	this->xmax = xmax;
	this->tmax = tmax;
}

double Scheme::ErrorNorm1(Matrix analitical, Matrix approx) {
	int k = analitical.getNrows(), l = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			error += abs(analitical[i][j] - approx[i][j]);
		}
	}

	return error / (k*l);
};

double Scheme::ErrorNorm2(Matrix analitical, Matrix approx) {
	int k = analitical.getNrows(), l = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			error += (analitical[i][j] - approx[i][j])*(analitical[i][j] - approx[i][j]);
		}
	} 
	error = sqrt(error);

	return error/(k*l);
};

double Scheme::ErrorNormInf(Matrix analitical, Matrix approx) {
	int k = analitical.getNrows(), l = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (abs(analitical[i][j] - approx[i][j]) > error) {
				error = abs(analitical[i][j] - approx[i][j]);
			}
		}
	}

	return error;
};

Matrix Scheme::boundary() {
	Matrix initial(n, m);

	//boundary
	for (int i = 0; i < n; i++) {
		initial[i][0] = 0;
		initial[i][m - 1] = 0;
	}

	//initial condition 
	double x;
	for (int i = 1; i < m - 1; i++) {
		x = i * dx;
		if (x <= 50)initial[0][i] = 0;
		else if (50 < x && x < 110)initial[0][i] = 100 * sin(PI*((x - 50) / 60));
		else if (110 <= x && x <= xmax)initial[0][i] = 0;
	}

	return initial;
};

Matrix Scheme::analitical() {
	Matrix analitical(n, m);
	analitical = boundary();
	double t;
	for (int i = 1; i < n; i++) {
		t = i * dt;
		double x = 0;
		for (int j = 1; j < m - 1; j++) { 
			x = i * dx;
			if (0 <= x <= 50 + 250 * t)analitical[i][j] = 0;
			else if (50 + 250 * t < x && x <= 110 + 250 * t)analitical[i][j] = 100 * sin(PI*(x - 50 - 250 * t) / 60);
			else if (110 + 250 / t < x && x <= xmax)analitical[i][j] = 0;
		}
	}
	
	return analitical;
};

void Scheme::printSolution(Matrix solution) {
	ofstream output;
	output.open("ftcs.txt");
	cout << "t'\'x ";
	output << fixed << setprecision(4);
	if (output.is_open()) {
		output << left << setw(8) << setfill(' ') << " ";
		for (double x = 0; x < xmax; x += dx) {
			cout << x << "	";
			output << left << setw(10) << setfill(' ') << x;
		}
		output << endl;
		double t = 0;
		for (int i = 0; i < n; i++) {
			cout << t << "	";
			output << t << "  ";
			for (int j = 0; j < m; j++) {
				cout << solution[i][j] << "	";
				output << left << setw(10) << setfill(' ') << solution[i][j];
			}
			cout << endl;
			output << endl;
			t += dt;
		}
	}
	output.close();
}