#ifndef MATRIX_H  //include guard
#define MATRIX_H

#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exceptions
#include <vector>  //we use Vector in Matrix code


/**
*  A matrix class for data storage of a 2D array of doubles
*  \n The implementation is derived from the standard container vector std::vector
*  \n We use private inheritance to base our vector upon the library version whilst
*  \nallowing usto expose only those base class functions we wish to use - in this
*  \ncase the array access operator []
*
* The Matrix class provides:
* \n-basic constructors for creating a matrix object from other matrix object,
* \nor by creating empty matrix of a given size,
* \n-input and oput operation via >> and << operators using keyboard or file
* \n-basic operations like access via [] operator, assignment and comparision
*/
class Matrix : private std::vector<std::vector<double> > {
	typedef std::vector<std::vector<double> > vec;
public:
	using vec::operator[];  // make the array access operator public within Matrix

	// CONSTRUCTORS
	/**
	* Default constructor.  Intialize an empty Matrix object
	* @see Matrix(int Nrows, int Ncols)
	* @see Matrix(const Matrix& m)
	*/
    Matrix();

	/**
	* Alternate constructor.
	* build a matrix Nrows by Ncols
	* @see Matrix()
	* @see Matrix(const Matrix& m)
	* @exception invalid_argument ("matrix size negative or zero")
	*/
    Matrix(int Nrows /**< int. number of rows in matrix */, int Ncols /**< int. number of columns in matrix  */); 

	// ACCESSOR METHODS
	/**
	* Normal public get method.
	* get the number of rows
	* @see int getNcols()const
	* @return int. number of rows in matrix
	*/
	int getNrows() const; // get the number of rows

	/**
	* Normal public get method.
	* get the number of columns
	* @see int getNrows()const
	* @return int. number of columns in matrix
	*/
	int getNcols() const; // get the number of cols

	/**
	* Overloaded ifstream >> operator. File input
	* the file output operator is compatible with file input operator,
	* ie. everything written can be read later.
	* @see operator>>(std::ifstream& ifs, Matrix& m)
	* @see operator<<(std::ofstream& ofs, const Matrix& m)
	* @see operator<<(std::ostream& os, const Matrix& m)
	* @return std::ifstream&. The ifstream object
	*/
	friend std::ifstream& operator >> (std::ifstream& ifs, /**< Input file stream with opened matrix file */
		Matrix& m /**< Matrix to write into */
		);// file input
};

#endif