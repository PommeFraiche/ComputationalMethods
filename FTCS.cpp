#include "FTCS.h"

FTCS::FTCS(double dx, double dt, double u, double xmax, double tmax) {
	Scheme(dx, dt, u, xmax, tmax);
}

Matrix FTCS::solve(Matrix solution) {
	Matrix A(n, m);
	std::vector<double> B(m), X(m);

	double mm;

	// The problem can be represented as the matrix equation A*X=B
	//Declaration of matrix A values
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) A[i][j] = 1;
			else if (i == j && j != 0)A[i][j - 1] = C / 2;
			else if (i == j && j != n - 1)A[i][j + 1] = -C / 2;
			else  A[i][j] = 0;
		}
	}

	//Solve for each line of the matrix
	for (int i = 0; i <= n; i++) {

		//Declaration of vector B values
		for (int k = 0; k < m; k++)B[k] = solution[i][k];

		//Thomas Algorithm 
		for (int k = 1; k < m; k++) {
			mm = A[k][k - 1] / A[k - 1][k - 1];
			A[k][k] -= (mm*A[k - 1][k]);
			B[k] -= (mm*B[k - 1]);
		}
		X[m - 1] = B[m - 1] / A[m - 1][m - 1];
		for (int k = m - 2; k >= 0; k--) {
			X[k] = (B[k] - A[k][k + 1] * X[k + 1]) / A[k][k];
		}

		//Set the result in the matrix "solution" 
		for (int k = 0; k < m; k++)solution[i + 1][k] = X[k];
	}

	return solution;
}