#include "ExplicitUpwind.h"

ExplicitUpwind::ExplicitUpwind(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix ExplicitUpwind::solve(Matrix solution) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m - 1; j++) {
			//explicit calcul
			solution[i][j] = solution[i - 1][j] * (1 - C) + solution[i - 1][j - 1] * C;
		}
	}

	return solution;
}