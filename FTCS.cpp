#include "FTCS.h"

FTCS::FTCS(double dx, double dt, double u, double xmax, double tmax, int n ,int m) {
	Scheme(dx, dt, u, xmax, tmax, n,m);
}

Matrix FTCS::solve(Matrix solve) {
	Matrix A(n, m);
	std::vector<double> B(m), X(m);

	double a = u * dt / dx, mm;

	// The problem can be represent the equation of matrix A*X=B
	//declaration of the matrix A values
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) A[i][j] = 1;
			else if (i == j && j != 0)A[i][j - 1] = a/2;
			else if (i == j && j != n-1)A[i][j + 1] = -a / 2;
			else  A[i][j] = 0;
		}
	}

	//solve for each time (line of solve matrix)
	for (int i = 0; i <= n; i++) {

		//declaration of vector B value
		for (int k = 0; k < m; k++)B[k] = solve[i][k];

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

		//set the result in solve and restart for the next time 
		for (int k = 0; k < m; k++)solve[i + 1][k] = X[k];
	}

	return solve;
}