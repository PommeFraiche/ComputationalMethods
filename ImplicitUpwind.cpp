#include "ImplicitUpwind.h"
using namespace std;

ImplicitUpwind::ImplicitUpwind(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix ImplicitUpwind::solve(Matrix solution) {
	Matrix A(m, m);
	vector<double> B(m), X(m), a(m);

	double varThomas;

	// The problem can be represented as the matrix equation A*X=B
	//Declaration of matrix A values
	A[0][0] = C + 1;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) { A[i][j] = C + 1; A[i][j - 1] = -C; }
			else  A[i][j] = 0;
		}
	}

	//Solve for each line of the matrix
	for (int i = 0; i < n - 1; i++) {

		//Declaration of vector B values
		for (int k = 0; k < m; k++)B[k] = solution[i][k];
		//Declaration of the temporary vector a of Thomas Algorithm 
		for (int k = 0; k < m; k++)a[k] = A[k][k];

		//Thomas Algorithm 
		for (int k = 1; k < m; k++) {
			varThomas = A[k][k - 1] / A[k - 1][k - 1];
			a[k] = A[k][k] - (varThomas*A[k - 1][k]);
			B[k] = B[k] - (varThomas*B[k - 1]);
		}
		X[m - 1] = B[m - 1] / a[m - 1];
		for (int k = m - 2; k >= 0; k--) {
			X[k] = (B[k] - A[k][k + 1] * X[k + 1]) / a[k];

		}

		//Set the result in the matrix "solution" 
		for (int k = 0; k < m; k++)solution[i + 1][k] = X[k];
	}

	return solution;
}
