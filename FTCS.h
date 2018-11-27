
/*!
 * \file FTCS.h
 * \brief FTCS Scheme
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 *
 * Class which contains the methode to calculate the solution thanks to the FTCS scheme.
 *
 */

#include "Scheme.h"


 /*! \class FTCS
 * \brief class of the FTCS scheme
 *
 *  This class calculates the FTCS solutions.
 *
 */
class FTCS :public Scheme {
public:

	/*!
	*  \brief Constructor of the FTCS Class.
	*
	*  \param dt : time step
	*  \param dx : space step
	*  \param u : speed of sound
	*  \param xmax : tube length
	*  \param tmax : study duration
	*/
	FTCS(double dx, double dt, double u, double xmax, double tmax);

	/*!
	*  \brief FTCS calculation
	*
	*  Method which allow us to caculate FTCS solutions.
	*
	*  \param solution : the boundary matrix containing the boundary and initial conditions.
	*  \return a matrix with the "approx" results using the FTCS scheme.
	*/
	Matrix solve(Matrix solution);
};
