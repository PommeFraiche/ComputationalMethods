#include "ImplicitUpwind.h"
using namespace std;

ImplicitUpwind::ImplicitUpwind(double dX, double dT, double u, double mX, double mT, int n , int m) {
	Scheme(dX, dT, u, mX, mT, n, m);
}

Matrix ImplicitUpwind::solve(Matrix solve) {

	Matrix A(m, m);
	vector<double> B(m), X(m);
	
	double a = u * dt / dx, varThomas;
	
	// The problem can be represent the equation of matrix A*X=B
	//declaration of the matrix A values
	A[0][0] = -a - 1;
	for (int i = 1 ; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) { A[i][j] = -a - 1; A[i][j - 1] = a; }
			else  A[i][j] = 0;
		}
	}

	//solve for each time (line of solve matrix)
	for (int i = 0; i < n-1; i++) {

		//declaration of vector B value
		for (int k = 0; k < m; k++)B[k] = solve[i][k]; 

		////Thomas Algorithm 
		for (int k = 1; k < m; k++) {
			varThomas = A[k][k - 1] / A[k - 1][k - 1];
			A[k][k] = A[k][k]-(varThomas*A[k - 1][k]);
			B[k] = B[k]-(varThomas*B[k - 1]);
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