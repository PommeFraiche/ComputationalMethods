#include <iostream>
#include <vector>
#include "matrix.h"
#include "ExplicitUpwind.h"
#include "ImplicitUpwind.h"
#include "FTCS.h"
#include "LaxWendroff.h"

using namespace std;

//Problem
double dx = 5, dt = 0.02, xmax = 405, tmax = 0.5+dt, u = 250;
Matrix boundary, solution, analitical;

int main() {
	


	ExplicitUpwind ExpUp(dx, dt, u, xmax, tmax);
	boundary = ExpUp.boundary();
	solution = ExpUp.solve(boundary);
	analitical = ExpUp.analitical();

	ExpUp.printSolution(solution);

	//Errors
	cout << "Err1: "<< ExpUp.ErrorNorm1(analitical, solution)<<endl;
	cout << "Err2: " << ExpUp.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ExpUp.ErrorNormInf(analitical, solution) << endl;
	

	
	ImplicitUpwind ImpUp(dx, dt, u, xmax, tmax);
	boundary = ImpUp.boundary();
	solution = ImpUp.solve(boundary);
	analitical = ImpUp.analitical();

	ImpUp.printSolution(solution);

	//Errors
	cout << "Err1: " << ImpUp.ErrorNorm1(analitical, solution) << endl;
	cout << "Err2: " << ImpUp.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ImpUp.ErrorNormInf(analitical, solution) << endl;
	

	
	FTCS ftcs(dx, dt, u, xmax, tmax);
	boundary = ftcs.boundary();
	solution = ftcs.solve(boundary);
	analitical = ftcs.analitical();

	ftcs.printSolution(solution);

	//Errors
	cout << "Err1: " << ftcs.ErrorNorm1(analitical, solution) << endl;
	cout << "Err2: " << ftcs.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ftcs.ErrorNormInf(analitical, solution) << endl;
	

	LaxWendroff Lax(dx, dt, u, xmax, tmax);
	boundary = Lax.boundary();
	solution = Lax.solve(boundary);
	analitical = Lax.analitical();

	Lax.printSolution(solution);

	//Errors
	cout << "Err1: " << Lax.ErrorNorm1(analitical, solution) << endl;
	cout << "Err2: " << Lax.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << Lax.ErrorNormInf(analitical, solution) << endl;

	Lax.printSolution(analitical);
	
	return 0;
}
