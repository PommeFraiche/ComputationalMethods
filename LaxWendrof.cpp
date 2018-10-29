#include "LaxWendrof.h"

LaxWendrof::LaxWendrof(double dX, double dT, double u, int mX, int mT) {
	Scheme(dX, dT, u, mX, mT);
}

Matrix LaxWendrof::solveLax(Matrix solve) {
	int width = (maxX / deltaX) + 1;
	int length = (maxT / deltaT) + 1;
	double a = u * deltaT / deltaX;
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			solve[i][j] = solve[i - 1][j] *(1 - a*a) + solve[i-1][j + 1] * (a*a - a)/2 + solve[i - 1][j - 1] * (a*a + a) / 2;
		}
	}

	return solve;
}