#include "Scheme.h"

class ExplicitUpwind :public Scheme {
public:
	ExplicitUpwind(double dx, double dt, double u, double xmax, double tmax);
	Matrix solveUpwind(Matrix solution);

private:

};