/*!
* \file main.cpp
* \brief Main program  
* \autor Damien LIDA & Elise SUARD
* \version 1.0
* \date 17/11/2018
*
* Calculates and shows the result of the 4 schemes according the setting
*
*/



#include <iostream>
#include <vector>
#include "matrix.h"
#include "ExplicitUpwind.h"
#include "ImplicitUpwind.h"
#include "FTCS.h"
#include "LaxWendroff.h"

using namespace std;

//Problem
double dx = 5, dt = 0.02, xmax = 405, tmax = 0.5+dt, u = 250;/*!< Setting to generate the solution */
Matrix boundary; /*!< Matrix of the boundary and initial condition  */
Matrix solution; /*!< Matrix with the results   */
Matrix analitical;/*!< Matrix with the analytical results  */

int main() {
	


	ExplicitUpwind ExpUp(dx, dt, u, xmax, tmax); /*!< Object using the Explicit Up Wind Scheme to generation the approximated solutions*/
	boundary = ExpUp.boundary();
	solution = ExpUp.solve(boundary);
	analitical = ExpUp.analitical();

	ExpUp.printSolution(solution);

	//Errors
	cout << "Err1: "<< ExpUp.ErrorNorm1(analitical, solution)<<endl;
	cout << "Err2: " << ExpUp.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ExpUp.ErrorNormInf(analitical, solution) << endl;
	

	
	ImplicitUpwind ImpUp(dx, dt, u, xmax, tmax);/*!< Object using the Ixplicit Up Wind Scheme to generation the approximated solutions*/
	boundary = ImpUp.boundary();
	solution = ImpUp.solve(boundary);
	analitical = ImpUp.analitical();

	ImpUp.printSolution(solution);

	//Errors
	cout << "Err1: " << ImpUp.ErrorNorm1(analitical, solution) << endl;
	cout << "Err2: " << ImpUp.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ImpUp.ErrorNormInf(analitical, solution) << endl;
	

	
	FTCS ftcs(dx, dt, u, xmax, tmax); /*!< Object using the FTCS Scheme to generation the approximated solutions*/
	boundary = ftcs.boundary();
	solution = ftcs.solve(boundary);
	analitical = ftcs.analitical();

	ftcs.printSolution(solution);

	//Errors
	cout << "Err1: " << ftcs.ErrorNorm1(analitical, solution) << endl;
	cout << "Err2: " << ftcs.ErrorNorm2(analitical, solution) << endl;
	cout << "ErrInf: " << ftcs.ErrorNormInf(analitical, solution) << endl;
	
	
	LaxWendroff Lax(dx, dt, u, xmax, tmax); /*!< Object using the Lax Wendroff Scheme to generation the approximated solutions*/
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
