#include <vector>;
#include "matrix.h";

using namespace std;

class Scheme{
public:
	Scheme();
	Scheme(double dx,double dt,double u,double xmax,double tmax);
	double ErrorNorm1(Matrix analitical, Matrix approx);
	double ErrorNorm2(Matrix analitical, Matrix approx);
	double ErrorNormInf(Matrix analitical, Matrix approx);
	Matrix boundary();


protected:
	double dx;
	double dt;
	double u;
	int xmax;
	int tmax;
	double C=u*dt/dx;

};




