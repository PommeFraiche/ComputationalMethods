#include "FTCS.h"

FTCS::FTCS(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix FTCS::solve(Matrix solution) {
	Matrix A(m, m);
	std::vector<double> B(m), X(m);

	double varThomas;

	// The problem can be represented as the matrix equation A*X=B
	//Declaration of matrix A values

	for (int i = 1; i < m-1; i++) {
		for (int j = 0; j < m; j++) {	
			 A[i][j] = 0;
		}
	}
	A[0][0] = A[m - 1][m - 1] = 1;
	A[0][1] = C / 2;
	A[m - 1][m - 2] = -C / 2;
	for (int k = 1; k < m - 1; k++) {
		A[k][k] = 1; 
		A[k][k - 1] = -C / 2; 
		A[k][k + 1] = C / 2; 
	}

	//Solve for each line of the matrix
	for (int i = 0; i < n - 1; i++) {

		//Declaration of vector B values
		for (int k = 0; k < m; k++)B[k] = solution[i][k];

		//Thomas Algorithm 
		for (int k = 1; k < m; k++) {
			varThomas = A[k][k - 1] / A[k - 1][k - 1];
			A[k][k] = A[k][k] - (varThomas*A[k - 1][k]);
			B[k] = B[k] - (varThomas*B[k - 1]);
		}
		X[m - 1] = B[m - 1] / A[m - 1][m - 1];
		for (int k = m - 2; k >= 0; k--) {
			X[k] = (B[k] - A[k][k + 1] * X[k + 1]) / A[k][k];
		}

		//Set the result in the matrix "solution" 
		for (int k = 0; k < m; k++) solution[i + 1][k] = X[k];
	}

	return solution;
}