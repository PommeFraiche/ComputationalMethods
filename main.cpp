#include <iostream>
#include <vector>
#include "matrix.h"
#include "ExplicitUpwind.h"
#include "ImplicitUpwind.h"

using namespace std;

void printSolution(Matrix solution);

//Problem
double dx = 5, dt = 0.1, xmax = 400, tmax = 0.5, u = 250;
int n = tmax / dt, m = xmax / dx;
Matrix boundary(n, m), solution(n, m), analitical(n, m);

int main() {
	ImplicitUpwind Implicit(dx, dt, u, xmax, tmax, n, m);
	boundary = Implicit.boundary();
	solution = Implicit.solve(boundary);
	analitical = Implicit.analitical();

	printSolution(solution);

	//Errors
	cout << Implicit.ErrorNorm1(analitical, solution) << endl;
	cout << Implicit.ErrorNorm2(analitical, solution) << endl;
	cout << Implicit.ErrorNormInf(analitical, solution) << endl;

	cin >> dt;
	return 0;
}

void printSolution(Matrix solution) {
	cout << "t'\'x ";
	for (double x = 0; x < xmax; x += dx) {
		cout << x << "	";
	}
	double t = 0;
	for (int i = 0; i < n; i++) {
		cout << t << "	";
		for (int j = 0; j < m; j++) {
			cout << solution[i][j] << "	";
		}
		cout << endl;
		t += dt;
	}
}