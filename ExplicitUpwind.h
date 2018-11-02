#include "Scheme.h"
//class Scheme;

class ExplicitUpwind :public Scheme {
public:
	ExplicitUpwind(double dx, double dt, double u, double xmax, double tmax, int n, int m);
	Matrix solve(Matrix solution);

};