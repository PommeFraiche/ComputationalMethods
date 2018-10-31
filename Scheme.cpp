#include "Scheme.h"
#include <cmath>

double PI = 4*atan(1);

Scheme::Scheme() : deltaX(5), deltaT(0.1), u(250), maxX(400), maxT(0.5){

}

Scheme::Scheme(double dX, double dT, double v, double maX, double maT){
	deltaX=dX;
	deltaT=dT;
	u=v;
	maxX=maX;
	maxT=maT;
}


double Scheme::ErrorNorme1(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) error += abs(analitical[i] - approx[i]);
	return error;
};


double Scheme::ErrorNorme2(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) error += (analitical[i] - approx[i])*(analitical[i] - approx[i]);
	error = sqrt(error );
	return error;
};


double Scheme::ErrorNormeInf(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) {
		if (abs(analitical[i] - approx[i]) > error)error = abs(analitical[i] - approx[i]);
	}
	return error;
};


Matrix Scheme::init() {
	int width = (maxX / deltaX)+1;
	int length = (maxT / deltaT)+1;
	Matrix initial(length , width);
	
	//boundary
	for (int i = 1; i <length; i++) {
		initial[i][0] = 0;
		initial[i][width-1] = 0;
	}

	//initial condition 
	for (int i = 1; i < width-1; i++) { 
		double x = (i * deltaX); 
		if (x <= 50)initial[0][i] = 0;
		else if (50 < x <= 110)initial[0][i] = 100 * sin(PI*((x-50)/60));
		else if (110 < x <= maxX)initial[0][i] = 0;
	}

	return initial;
};