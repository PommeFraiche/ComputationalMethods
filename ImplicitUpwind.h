#include "Scheme.h"

class ImplicitUpwind :public Scheme {
public:
	ImplicitUpwind(double deltaX, double deltaT, double u, double maxX, double maxT);
	Matrix solveUpwind(Matrix solve);

private:

};