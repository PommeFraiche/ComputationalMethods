#include "Scheme.h"

class FTCS :public Scheme {
public:
	FTCS(double deltaX, double deltaT, double u, int maxX, int maxT);
	Matrix solveFTCS(Matrix solve);

private:

};
