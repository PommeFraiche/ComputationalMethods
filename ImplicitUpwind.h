#include "Scheme.h"
//class Scheme;

class ImplicitUpwind :public Scheme {
	public:
		ImplicitUpwind(double deltaX, double deltaT, double u, double maxX, double maxT, int n, int m);
		Matrix solve(Matrix solve);
};