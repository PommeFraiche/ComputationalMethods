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





