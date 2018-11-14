#include "Scheme.h"

class ExpliciteUpwind :public Scheme {
public:
	ExpliciteUpwind(double deltaX, double deltaT, double u, int maxX, int maxT);
	Matrix solveUpwind(Matrix solve);

private:

};