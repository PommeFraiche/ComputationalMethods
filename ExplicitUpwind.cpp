#include "ExplicitUpwind.h"

ExplicitUpwind::ExplicitUpwind(double dX, double dT, double u, int mX, int mT) {
	Scheme( dX,  dT,  u,  mX,  mT);
}

Matrix ExplicitUpwind::solveUpwind(Matrix solution) {
	int width = (xmax / dx) + 1;
	int length = (tmax / dt) + 1;
	double a= u*dt/dx;
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			 solution[i][j] = solution[i-1][j] * (1 - a) + solution[i-1][j-1] * a;
		}
	}
	
	return solution;
}
