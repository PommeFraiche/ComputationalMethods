#ifndef MATRIX_H  
#define MATRIX_H

#include <iostream>  
#include <fstream>   
#include <stdexcept> 
#include <vector>  

class Matrix : private std::vector<std::vector<double> > {
	typedef std::vector<std::vector<double> > vec;
public:
	using vec::operator[]; 

    Matrix();
    Matrix(int Nrows , int Ncols); 
	int getNrows() const; 
	int getNcols() const; 
	friend std::ifstream& operator >> (std::ifstream& ifs, Matrix& m);
};

#endif