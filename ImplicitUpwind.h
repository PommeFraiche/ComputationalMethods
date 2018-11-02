#include "Scheme.h"
//class Scheme;

class ImplicitUpwind :public Scheme {
	public:
		ImplicitUpwind(double dx, double dt, double u, double xmax, double tmax);
		Matrix solve(Matrix solve);
};
