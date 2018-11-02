#ifndef DEF_SCHEME
#define DEF_SCHEME

#include <vector>;
#include "matrix.h";

class Scheme{
	public:
		Scheme();
		Scheme(double dx, double dt, double u, double xmax, double tmax);
		double ErrorNorm1(Matrix analitical, Matrix approx);
		double ErrorNorm2(Matrix analitical, Matrix approx);
		double ErrorNormInf(Matrix analitical, Matrix approx);
		Matrix boundary();
		Matrix analitical();

	protected:
		double dx;
		double dt;
		double u;
		double xmax;
		double tmax;
		double C = u * dt / dx;
};

#endif


