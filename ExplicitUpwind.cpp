#include "ExplicitUpwind.h"

ExplicitUpwind::ExplicitUpwind(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix ExplicitUpwind::solve(Matrix solution) {
	int m = (xmax / dx), n = (tmax / dt);
	double a = u * dt / dx;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m - 1; j++) {
			solution[i][j] = solution[i - 1][j] * (1 - a) + solution[i - 1][j - 1] * a;
		}
	}

	return solution;
}
