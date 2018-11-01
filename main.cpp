#include <iostream>
#include <vector>
#include "matrix.h"
#include "ExplicitUpwind.h"

using namespace std;

void printSolution(Matrix solution);

//Problem
double dx = 5, dt = 0.1, xmax = 400, tmax = 0.5, u = 250;
int n = tmax / dt, m = xmax / dx;
Matrix boundary(n, m), solution(n, m), analitical(n, m);

int main() {
	ExplicitUpwind Explicit(dx, dt, u, xmax, tmax);
	boundary = Explicit.boundary();
	solution = Explicit.solve(boundary);
	analitical = Explicit.analitical();

	printSolution(solution);

	//Errors
	cout << Explicit.ErrorNorm1(analitical, solution)<<"/n";
	cout << Explicit.ErrorNorm2(analitical, solution) << "/n";
	cout << Explicit.ErrorNormInf(analitical, solution) << "/n";


	return 0;
}

void printSolution(Matrix solution) {
	std::cout << "t'\'x ";
	for (double x = 0; x < xmax; x += dx) {
		cout << x << "	";
	}
	double t = 0;
	for (int i = 0; i < n; i++) {
		cout << t << "	";
		for (int j = 0; j < m; j++) {
			cout << solution[i][j] << "	";
		}
		cout << "/n";
		t += dt;
	}
}
