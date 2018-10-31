#include "Scheme.h"

class LaxWendrof :public Scheme {
public:
	LaxWendrof(double dx, double dt, double u, int xmax, int tmax);
	Matrix solve(Matrix solve);

private:

}; 
