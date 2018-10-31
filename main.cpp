#include <iostream>
#include <vector>
#include "matrix.h"
#include <cmath>
#include "ExplicitUpwind.h"

using namespace std;

//Problem
double dx = 5, dt = 0.1 , u=250,xmax = 400, tmax = 0.5;
int width = (xmax / dx) + 1, length = int((tmax / dt) + 1);
Matrix initial(length, width), Result(length, width);

int main() {
	ExplicitUpwind Explicit(dx, dt, u, xmax, tmax) ;
	initial= Explicit.init();
	Result = Explicit.solveUpwind(initial);
	 
	for (int i = 0; i < width; i++) {
		cout<< Result[length - 1][i]<<endl;
	}
	
	cin >> tmax;
	return 0;
}
