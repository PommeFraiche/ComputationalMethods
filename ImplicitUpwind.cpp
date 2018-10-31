#include "ImplicitUpwind.h"


ImplicitUpwind::ImplicitUpwind(double dX, double dT, double u, double mX, double mT) {
	Scheme(dX, dT, u, mX, mT);
}

Matrix ImplicitUpwind::solveUpwind(Matrix solve) {
	int width = maxX / deltaX ;
	int length = maxT / deltaT ;
	Matrix A(length, width);
	vector<double> B(width), X(width);
	
	double a = u * deltaT / deltaX, m;


	for (int i = 0 ; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == j) A[i][j] = -1 - a;
			if (i==j && i!=0)A[i][j - 1] = a;
			else  A[i][j] = 0;
		}
	}

	for (int k = 1; k < width; k++) {
		m = A[k][k - 1] / A[k - 1][k - 1];
		A[k][k] -= (m*A[k - 1][k]);
		B[k] -= (m*B[k-1]);
	}

	//solve[i][j] = solve[i - 1][j] /(1 - a) + solve[i][j - 1] * a/(1+a);

	return solve;
}