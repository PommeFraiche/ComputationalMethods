#include "Scheme.h"

class FTCS :public Scheme {
public:
	FTCS(double dx, double dt, double u, double xmax, double tmax);
	Matrix solve(Matrix solve);
};
