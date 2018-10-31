#include <vector>;
#include "matrix.h";

using namespace std;

class Scheme
{
public:
	Scheme();
	Scheme(double deltaX,double deltaT,double u,double maxX,double maxT);
	double ErrorNorme1(vector<double> analitical, vector<double> approx);
	double ErrorNorme2(vector<double> analitical, vector<double> approx);
	double ErrorNormeInf(vector<double> analitical, vector<double> approx);
	Matrix init();


protected:
	double deltaX;
	double deltaT;
	double u;
	double maxX;
	double maxT;
	double Cst=u*deltaT/deltaX;
	//int width = (maxX / deltaX) + 1;
	//int length = (maxT / deltaT) + 1;
	//Matrix waveEvolution(width, length);

};





