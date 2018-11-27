#ifndef MATRIX_H  
#define MATRIX_H

/*!
 * \file Matrix.h
 * \brief Matrix object
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 *
 * Basic class to create our object Matrix.
 *
 */

#include <iostream>  
#include <fstream>   
#include <stdexcept> 
#include <vector>  

/*! \class Matrix
* \brief Class to generate a matrix (a vector of vector)
*/
class Matrix : private std::vector<std::vector<double> > {
	typedef std::vector<std::vector<double> > vec;
public:
	using vec::operator[]; 

	/*!
	*  \brief Default constructor
	*
	*  Default constructor of the Matrix Class.
	*
	*/
    Matrix();

	/*!
	*  \brief Constructor
	*
	*  Constructor of the Matrix Class.
	*
	*  \param Nrows : number of lines
	*  \param Ncols : number of colones
	*/
    Matrix(int Nrows , int Ncols); 

	/*!
	*  \brief getter lines
	*
	*  Get the number of lines
	*
	*/
	int getNrows() const; 

	/*!
	*  \brief getter colones
	*
	*  Get the number of colones
	*
	*/
	int getNcols() const; 


};

#endif