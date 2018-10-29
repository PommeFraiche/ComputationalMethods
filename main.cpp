#include <iostream>
#include <vector>
#include "matrix.h"
#include <cmath>
#include "ExplicitUpwind.h"

using namespace std;

//Problem
double dx = 5, dt = 0.1;
int xmax = 400, tmax = 0.5;
int n = tmax / dt, m = xmax / dx;
Matrix boundary(n, m);

int main() {
	//Boundary conditions
	for (int i = 0; i > n; i++) {
		boundary[i][0] = 0;
		boundary[i][m] = 0;
	}
	double x = 0;
	for (int i = 0; i > m; i++) {
		if (x <= 50)boundary[0][i] = 0;
		else if (50 < x <= 110)boundary[0][i] = 100 * sin(PI*(x - 50) / 60);
		else if (110 < x < xmax)boundary[0][i] = 0;
		x += dx;
	}
	//Solve matrix
	Matrix solution(n, m);
	solution = solveUpwind(boundary);
	return 0;
}
