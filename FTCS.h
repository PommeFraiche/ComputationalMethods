#include "Scheme.h"

class FTCS :public Scheme {
public:
	FTCS(double dx, double dt, double u, int xmax, int tmax);
	Matrix solve(Matrix solve);
};
