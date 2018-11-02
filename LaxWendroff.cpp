#include "LaxWendroff.h"

LaxWendroff::LaxWendroff(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix LaxWendroff::solve(Matrix solution) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m-1; j++) {
			solution[i][j] = solution[i - 1][j] * (1 - C * C) + solution[i - 1][j + 1]*(C*C-C)/2 + solution[i - 1][j - 1] * (C*C + C) / 2  ;
		}
	}

	return solution;
}
