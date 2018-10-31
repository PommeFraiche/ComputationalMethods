#include "ExplicitUpwind.h"

ExplicitUpwind::ExplicitUpwind(double dX, double dT, double u, double mX, double mT) {
	Scheme( dX,  dT,  u,  mX,  mT);
}

Matrix ExplicitUpwind::solveUpwind(Matrix solution) {
	int width = (maxX / deltaX) + 1;
	int length = (maxT / deltaT) + 1;
	double a= u*deltaT/deltaX;
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width-2; j++) {
			 solution[i][j] = solution[i-1][j] * (1 - a) + solution[i-1][j-1] * a;
		}
	}
	
	return solution;
}
