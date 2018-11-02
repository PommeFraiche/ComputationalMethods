#ifndef DEF_SCHEME
#define DEF_SCHEME

#include <vector>;
#include "matrix.h";


class Scheme
{
	public:
		Scheme();
		Scheme(double dx,double dt,double u,double xmax,double tmax,int n ,int  m);
		double ErrorNorm1(Matrix analitical, Matrix approx);
		double ErrorNorm2(Matrix analitical, Matrix approx);
		double ErrorNormInf(Matrix analitical, Matrix approx);
		Matrix analitical();
		Matrix boundary();


	protected:
		double dx, dt, u,xmax, tmax;
		int n, m;
		double C=u*dt/dx;
};

#endif