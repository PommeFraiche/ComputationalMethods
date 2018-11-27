#ifndef DEF_SCHEME
#define DEF_SCHEME

/*!
 * \file Scheme.h
 * \brief Scheme de Base
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 * 
 * Contains the methode commun to each scheme such as the Normes, the boundary and initial result and the analytical result.
 *
 */


#include <vector>
#include "matrix.h"
#include <iomanip>

 /*! \class Scheme
 * \brief class of the basic scheme
 *
 *  This class generate the commun commandes alocate to each scheme .
 *
 */
class Scheme{
	public:
		/*!
	    *  \brief Default constructor
	    *
	    *  Default constructor of the Scheme Class.
	    *
	    */
		Scheme();

		/*!
	    *  \brief Constructor of the Scheme Class.
	    *
	    *  \param dt : time step
		*  \param dx : space step
		*  \param u : speed of sound 
		*  \param xmax : tube length 
		*  \param tmax : study duration  
	    */
		Scheme(double dx, double dt, double u, double xmax, double tmax);

		/*!
		*  \brief Calculate  norm1  error 
		*
		*  Method which allow us to caculate the error thank to the norm1. 
		*
		*  \param analitical : the analitical solution. Using as a reference .
		*  \param approx : the results generate by the scheme solution. Results whose we we want to compare. 
		*  \return the average error value between the "analical" and the "approx" results.  
		*/
		double ErrorNorm1(Matrix analitical, Matrix approx);

		/*!
		*  \brief Calculate  norm2  error
		*
		*  Method which allow us to caculate the error thank to the norm2.
		*
		*  \param analitical : the analitical solution. Using as a reference.
		*  \param approx : the results generate by the scheme solution. Results whose we we want to compare.
		*  \return the average error value between the "analical" and the "approx" results.
		*/
		double ErrorNorm2(Matrix analitical, Matrix approx);

		/*!
		*  \brief Calculate Infinit norm error
		*
		*  Method which allow us to caculate the error thank to the infint norm.
		*
		*  \param analitical : the analitical solution. Using as a reference.
		*  \param approx : the results generate by the scheme solution. Results whose we we want to compare.
		*  \return the maximum error value between the "analical" and the "approx" results.
		*/
		double ErrorNormInf(Matrix analitical, Matrix approx);

		/*!
		*  \brief Boundarty and initial condition
		*
		*  Method which initialize a matrix with the boundary and initial condition of the problem.
		*
		*  \return the matrix initialized.
		*/
		Matrix boundary();

		/*!
		*  \brief Analytical solution 
		*
		*  Method which generate the result of the analytical problem. 
		*
		*  \return a matrix with the solution.
		*/
		Matrix analitical();

		/*!
		*  \brief Show solution
		*
		*  Method which allow us to Show on the consol and generate a file txt with the solution
		*
		*  \param analitical : the solution calculate with the scheme.
		*/
		void printSolution(Matrix solution);

	protected:
		double dx;/*!< dx : space step*/
		double dt;/*!< dt : time step*/
		double u;/*!< u : speed of sound*/
		double xmax;/*!< xmax : tube length*/
		double tmax;/*!< tmax : study time*/
		double C = u * dt / dx;/*!< C : constant used in the equation*/
		int n = tmax / dt;/*!< n : number of line */
		int m = xmax / dx;/*!< m : number of colone */
};

#endif


