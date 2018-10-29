#include "Scheme.h"
#include <cmath>

double PI = atan(1);

Scheme::Scheme() : dx(5), dt(0.1), u(250), xmax(400), tmax(0.5){

}

Scheme::Scheme(double dX, double dT, double v, int maX, int maT){
	dx=dX;
	dt=dT;
	u=v;
	xmax=maX;
	tmax=maT;
}


double Scheme::ErrorNorm1(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) error += abs(analitical[i] - approx[i]);
	return error;
};


double Scheme::ErrorNorm2(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) error += (analitical[i] - approx[i])*(analitical[i] - approx[i]);
	error = sqrt(error );
	return error;
};


double Scheme::ErrorNormInf(vector<double> analitical, vector<double> approx) {
	int size = analitical.size();
	double error = 0;
	for (int i = 0; i < size; i++) {
		if (abs(analitical[i] - approx[i]) > error)error = abs(analitical[i] - approx[i]);
	}
	return error;
};


Matrix Scheme::init() {
	int width = (xmax / dx)+1;
	int length = (tmax / dt)+1;
	Matrix initial(width , length);
	
	//boundary
	for (int i = 1; i <length; i++) {
		initial[i][0] = 0;
		initial[i][width] = 0;
	}

	//initial condition 
	for (int i = 1; i < width; i++) { 
		double x = (i * dx); 
		if (x <= 50)initial[0][i] = 0;
		else if (50 < x <= 110)initial[0][i] = 100 * sin(PI*((x-50)/60));
		else if (110 < x <= xmax)initial[0][i] = 0;
	}

	return initial;
};