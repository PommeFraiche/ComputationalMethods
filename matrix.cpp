
#include "matrix.h"

// CONSTRUCTORS
/*
 *Default constructor (empty matrix)
 */
Matrix::Matrix() : std::vector<std::vector<double> >()  {}

/*
 * Alternate constructor - creates a matrix with the given values
 */
Matrix::Matrix(int Nrows, int Ncols) : std::vector<std::vector<double> >()
{
    //check input
    if(Nrows < 0 || Ncols < 0) throw std::invalid_argument("matrix size negative");
    
	// set the size for the rows
	(*this).resize(Nrows);
	// set the size for the columns
	for (int i = 0; i < Nrows; i++) (*this)[i].resize(Ncols);

	// initialise the matrix to contain zero
	for (int i = 0; i < Nrows; i++)
		for (int j = 0; j < Ncols; j++) (*this)[i][j] = 0.0;
}


// ACCESSOR METHODS
/*
* accessor method - get the number of rows
*/
int Matrix :: getNrows() const
{
	return size();
}

/*
* accessor method - get the number of columns
*/
int Matrix::getNcols() const
{
	return (*this)[0].size();
}









// INPUT AND OUTPUT FUNCTIONS
/*
 * insert a value in a specique position
 */
void insertValue(double& value, Matrix& m, int n , int x) {
	
	m[n][x] = value;

}

/*
* file input - raw data, compatible with file writing operator
*/
std::ifstream& operator>>(std::ifstream& ifs, Matrix& m) {
	
	int nrows, ncols;

    // read size from the file
    ifs >> nrows; ifs>> ncols;
    //check input sanity
    if(nrows < 0 || ncols < 0) throw std::invalid_argument("file read error - negative matrix size");

    // prepare the vector to hold n elements
    m = Matrix(nrows, ncols);

    // input the elements
    for (int i=0; i<nrows; i++) 
		for (int j=0; j<ncols; j++) ifs >> m[i][j];

    // return the stream object
    return ifs;
}



