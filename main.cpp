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
Matrix boundary, solution, analytical;

int main() {
	


	ExplicitUpwind ExpUp(dx, dt, u, xmax, tmax);
	boundary = ExpUp.boundary();
	solution = ExpUp.solve(boundary);
	analytical = ExpUp.analytical();

	ExpUp.printSolution(solution);

	//Errors
	cout << "Err1: "<< ExpUp.ErrorNorm1(analytical, solution)<<endl;
	cout << "Err2: " << ExpUp.ErrorNorm2(analytical, solution) << endl;
	cout << "ErrInf: " << ExpUp.ErrorNormInf(analytical, solution) << endl;
	

	
	ImplicitUpwind ImpUp(dx, dt, u, xmax, tmax);
	boundary = ImpUp.boundary();
	solution = ImpUp.solve(boundary);
	analytical = ImpUp.analytical();

	ImpUp.printSolution(solution);

	//Errors
	cout << "Err1: " << ImpUp.ErrorNorm1(analytical, solution) << endl;
	cout << "Err2: " << ImpUp.ErrorNorm2(analytical, solution) << endl;
	cout << "ErrInf: " << ImpUp.ErrorNormInf(analytical, solution) << endl;
	

	
	FTCS ftcs(dx, dt, u, xmax, tmax);
	boundary = ftcs.boundary();
	solution = ftcs.solve(boundary);
	analytical = ftcs.analytical();

	ftcs.printSolution(solution);

	//Errors
	cout << "Err1: " << ftcs.ErrorNorm1(analytical, solution) << endl;
	cout << "Err2: " << ftcs.ErrorNorm2(analytical, solution) << endl;
	cout << "ErrInf: " << ftcs.ErrorNormInf(analytical, solution) << endl;
	

	LaxWendroff Lax(dx, dt, u, xmax, tmax);
	boundary = Lax.boundary();
	solution = Lax.solve(boundary);
	analytical = Lax.analytical();

	Lax.printSolution(solution);

	//Errors
	cout << "Err1: " << Lax.ErrorNorm1(analytical, solution) << endl;
	cout << "Err2: " << Lax.ErrorNorm2(analytical, solution) << endl;
	cout << "ErrInf: " << Lax.ErrorNormInf(analytical, solution) << endl;

	Lax.printSolution(analytical);
	
	return 0;
}
