#include <vector>;
#include "matrix.h";

using namespace std;

class Scheme
{
public:
	Scheme();
	Scheme(double dx,double dt,double u,double xmax,double tmax);
	double ErrorNorm1(vector<double> analitical, vector<double> approx);
	double ErrorNorm2(vector<double> analitical, vector<double> approx);
	double ErrorNormInf(vector<double> analitical, vector<double> approx);
	Matrix boundary();


protected:
	double dx;
	double dt;
	double u;
	int xmax;
	int tmax;
	double C=u*dt/dx;
	//int width = (xmax / dx) + 1;
	//int length = (tmax / dt) + 1;
	//Matrix waveEvolution(width, length);

};





