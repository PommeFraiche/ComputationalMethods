#include "LaxWendroff.h"

LaxWendroff::LaxWendrof(double dx, double dt, double u, int xmax, int tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix LaxWendroff::solve(Matrix solve) {
	int m = (xmax / dx), n = (tmax / dt);
	double a = u * dt / dx;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			solve[i][j] = solve[i - 1][j] * (1 - a * a) + solve[i - 1][j + 1] * (a*a - a) / 2 + solve[i - 1][j - 1] * (a*a + a) / 2;
		}
	}

	return solve;
}