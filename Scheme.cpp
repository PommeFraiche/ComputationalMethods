#include "Scheme.h"
#include <cmath>

double PI = 4 * atan(1);

Scheme::Scheme() : dx(5), dt(0.1), u(250), xmax(400), tmax(0.5), n(5), m(80) {

}

Scheme::Scheme(double dx, double dt, double u, double xmax, double tmax, int n, int m) {
	dx = dx;
	dt = dt;
	u = u;
	xmax = xmax;
	tmax = tmax;
	n = n;
	m = m;
}


double Scheme::ErrorNorm1(Matrix analitical, Matrix approx) {
	int n = analitical.getNrows(), m = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			error += abs(analitical[i][j] - approx[i][j]);
		}
	}

	return error;
};


double Scheme::ErrorNorm2(Matrix analitical, Matrix approx) {
	int n = analitical.getNrows(), m = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			error += (analitical[i][j] - approx[i][j])*(analitical[i][j] - approx[i][j]);
		}
	}
	error = sqrt(error);

	return error;
};


double Scheme::ErrorNormInf(Matrix analitical, Matrix approx) {
	int n = analitical.getNrows(), m = analitical.getNcols();
	double error = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (abs(analitical[i][j] - approx[i][j]) > error) {
				error = abs(analitical[i][j] - approx[i][j]);
			}
		}
	}

	return error;
};


Matrix Scheme::boundary() {
	int width = (xmax / dx), length = (tmax / dt);
	Matrix initial(length, width);

	//boundary
	for (int i = 0; i < length; i++) {
		initial[i][0] = 0;
		initial[i][width - 1] = 0;
	}

	//initial condition 
	double x = dx;
	for (int i = 1; i < width - 1; i++) {
		if (x <= 50)initial[0][i] = 0;
		else if (50 < x <= 110)initial[0][i] = 100 * sin(PI*((x - 50) / 60));
		else if (110 < x <= xmax)initial[0][i] = 0;
		x += dx;
	}

	return initial;
};

Matrix Scheme::analitical() {
	int n = (tmax / dt), m = (xmax / dx);
	Matrix analitical(n, m);
	analitical = boundary();
	double t = 0;
	for (int i = 1; i < n; i++) {
		t = i * dt;
		double x = 0;
		for (int j = 1; j < m - 1; j++) { /*###*/
			x = i * dx;
			if (0 <= x <= 50 + 250 * t)analitical[i][j] = 0;
			else if (50 + 250 * t < x <= 110 + 250 * t)analitical[i][j] = 100 * sin(PI*(x - 50 - 250 * t) / 60);
			else if (110 + 250 / t < x <= xmax)analitical[i][j] = 0;
		}
	}

	return analitical;
};