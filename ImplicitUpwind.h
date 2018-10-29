#include "Scheme.h"

class ImplicitUpwind :public Scheme {
public:
	ImplicitUpwind(double dx, double dt, double u, int xmax, int tmax);
	Matrix solveUpwind(Matrix solve);

private:

};