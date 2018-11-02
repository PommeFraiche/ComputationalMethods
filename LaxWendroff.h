#include "Scheme.h"

class LaxWendroff :public Scheme {
public:
	LaxWendroff(double dx, double dt, double u, double xmax, double tmax);
	Matrix solve(Matrix solution);
}; 
