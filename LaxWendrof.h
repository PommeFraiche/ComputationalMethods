#include "Scheme.h"

class LaxWendrof :public Scheme {
public:
	LaxWendrof(double deltaX, double deltaT, double u, int maxX, int maxT);
	Matrix solveLax(Matrix solve);

private:

}; 
