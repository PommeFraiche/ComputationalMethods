#include "ImplicitUpwind.h"

ImplicitUpwind::ImplicitUpwind(double dX, double dT, double u, int mX, int mT) {
	Scheme(dX, dT, u, mX, mT);
}

Matrix ImplicitUpwind::solveUpwind(Matrix solve) {
	int width = (xmax / dx) + 1;
	int length = (tmax / dt) + 1;
	double a = u * dt / dx;
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			solve[i][j] = solve[i - 1][j] /(1 - a) + solve[i][j - 1] * a/(1+a);
		}
	}

	return solve;
}