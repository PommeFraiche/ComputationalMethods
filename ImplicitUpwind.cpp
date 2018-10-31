#include "ImplicitUpwind.h"


ImplicitUpwind::ImplicitUpwind(double dX, double dT, double u, double mX, double mT) {
	Scheme(dX, dT, u, mX, mT);
}

Matrix ImplicitUpwind::solveUpwind2(Matrix solve) {
	int width = maxX / deltaX ;
	int length = maxT / deltaT ;
	Matrix A(length, width);
	vector<double> B(width), X(width);
	
	double a = u * deltaT / deltaX, m;
	
	// The problem can be represent the equation of matrix A*X=B
	//declaration of the matrix A values
	for (int i = 0 ; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == j) A[i][j] = -1 - a;
			if (i==j && i!=0)A[i][j - 1] = a;
			else  A[i][j] = 0;
		}
	}

	//solve for each time (line of solve matrix)
	for (int i = 0; i <= length; i++) {

		//declaration of vector B value
		for (int k = 0; k < width; k++)B[k] = solve[i][k];

		//Thomas Algorithm 
		for (int k = 1; k < width; k++) {
			m = A[k][k - 1] / A[k - 1][k - 1];
			A[k][k] -= (m*A[k - 1][k]);
			B[k] -= (m*B[k - 1]);
		}
		X[width - 1] = B[width - 1] / A[width - 1][width - 1];
		for (int k = width - 2; k >= 0; k--) {
			X[k] = (B[k] - A[k][k + 1] * X[k + 1]) / A[k][k];
		}

		//set the result in solve and restart for the next time 
		for (int k = 0; k < width; k++)solve[i + 1][k] = X[k];
	}

	return solve;
}