#include <iostream>
#include <vector>
#include "matrix.h"
#include <cmath>
#include "ExplicitUpwind.h"

using namespace std;

//Problem
double dx = 5, dt = 0.1, xmax = 400, tmax = 0.5, u = 250;
int n = tmax / dt, m = xmax / dx;
Matrix boundary(n, m), solution(n, m);

int main() {
	ExplicitUpwind Explicit(dx, dt, u, xmax, tmax);
	boundary = Explicit.boundary();
	solution = Explicit.solve(boundary);

	for (int i = 0; i < m; i++) {
		cout << solution[n - 1][i] << endl;
	}

	cin >> tmax;
	return 0;
}

void printSolution(float dx) {
	std::cout << "x " << "f'(x) " << "For " << "Back " << "Cent " << "\n";
	int count = 0;
	for (float x = 0.0; x < 1.1; x += dx) {
		std::cout << x << " ";
		std::cout << fp(x) << " ";
		std::cout << forward(x, dx) << " ";
		std::cout << backward(x, dx) << " ";
		std::cout << centered(x, dx) << "\n";
		errorFor += abs(forward(x, dx) - fp(x));
		errorBac += abs(backward(x, dx) - fp(x));
		errorCen += abs(centered(x, dx) - fp(x));
		count++;
	}
}

void printError() {
	float errorFor = 0;
	float errorBac = 0;
	float errorCen = 0;

	int count = 0;
	for (float x = 0.0; x < 1.1; x += dx) {
		errorFor += abs(forward(x, dx) - fp(x));
		errorBac += abs(backward(x, dx) - fp(x));
		errorCen += abs(centered(x, dx) - fp(x));
		count++;
	}
}