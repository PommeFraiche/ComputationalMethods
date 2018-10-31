#include "matrix.h"

// CONSTRUCTORS
//Default constructor (empty matrix)
Matrix::Matrix() : std::vector<std::vector<double> >()  {}

//Alternate constructor - creates a matrix with the given values
Matrix::Matrix(int Nrows, int Ncols) : std::vector<std::vector<double> >()
{
    if(Nrows < 0 || Ncols < 0) throw std::invalid_argument("matrix size negative");
	(*this).resize(Nrows);
	for (int i = 0; i < Nrows; i++) (*this)[i].resize(Ncols);
	for (int i = 0; i < Nrows; i++)
		for (int j = 0; j < Ncols; j++) (*this)[i][j] = 0.0;
}


// ACCESSOR METHODS
int Matrix :: getNrows() const
{
	return size();
}

int Matrix::getNcols() const
{
	return (*this)[0].size();
}


// INPUT AND OUTPUT FUNCTIONS
void insertValue(double& value, Matrix& m, int n , int x) {
	m[n][x] = value;
}

std::ifstream& operator>>(std::ifstream& ifs, Matrix& m) {
	int nrows, ncols;
    ifs >> nrows; ifs>> ncols;
    if(nrows < 0 || ncols < 0) throw std::invalid_argument("file read error - negative matrix size");
    m = Matrix(nrows, ncols);
    for (int i=0; i<nrows; i++) 
		for (int j=0; j<ncols; j++) ifs >> m[i][j];
    return ifs;
}



