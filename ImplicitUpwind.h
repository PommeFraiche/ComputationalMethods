#include "Scheme.h"

class ImplicitUpwind :public Scheme {
public:
	ImplicitUpwind(double dx, double dt, double u, double xmax, double tmax);
	Matrix solve(Matrix solution);
};