#include "Scheme.h"

class LaxWendroff :public Scheme {
public:
	LaxWendroff(double dx, double dt, double u, int xmax, int tmax);
	Matrix solve(Matrix solve);

private:

}; 
