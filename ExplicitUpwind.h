#include "Scheme.h"

class ExplicitUpwind :public Scheme {
public:
	ExplicitUpwind(double dx, double dt, double u, int xmax, int tmax);
	Matrix solveUpwind(Matrix solution);

private:

};