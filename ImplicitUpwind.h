/*!
 * \file ImplicitUpwind.h
 * \brief Implicit Upwind Scheme
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 *
 * Class which contains the methode to calculate the solution thanks to the Implicit Upwind scheme.
 *
 */
#include "Scheme.h"

 /*! \class ImplicitUpwind
 * \brief class of the Implicit Upwind scheme
 *
 *  This class calculates the Implicit Upwind solutions.
 *
 */
class ImplicitUpwind :public Scheme {
public:
	/*!
	*  \brief Constructor of the ImplicitUpwind Class.
	*
	*  \param dt : time step
	*  \param dx : space step
	*  \param u : speed of sound
	*  \param xmax : tube length
	*  \param tmax : study duration
	*/
	ImplicitUpwind(double dx, double dt, double u, double xmax, double tmax);

	/*!
	*  \brief Implicit Upwind calculation
	*
	*  Method which allow us to caculate Implicit Upwind solutions.
	*
	*  \param solution : the boundary matrix containing the boundary and initial conditions.
	*  \return a matrix with the "approx" results using the Implicit Upwind scheme.
	*/
	Matrix solve(Matrix solution);
};