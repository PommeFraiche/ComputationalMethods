/*!
 * \file ExplicitUpwind.h
 * \brief Explicit Upwind Scheme
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 *
 * Class which contains the methode to calculate the solution thanks to the Explicit Upwind scheme.
 *
 */
#include "Scheme.h"

 /*! \class ExplicitUpwind
  * \brief class of the Explicit Upwind scheme
  *
  *  This class calculates the Explicit Upwind solutions.
  *
  */
class ExplicitUpwind :public Scheme {

public:
	/*!
	*  \brief Constructor of the ExplicitUpwind Class.
	*
	*  \param dt : time step
	*  \param dx : space step
	*  \param u : speed of sound
	*  \param xmax : tube length
	*  \param tmax : study duration
	*/
	ExplicitUpwind(double dx, double dt, double u, double xmax, double tmax);

	/*!
	*  \brief Explicit Upwind calculation
	*
	*  Method which allow us to caculate Explicit Upwind solutions.
	*
	*  \param solution : the boundary matrix containing the boundary and initial conditions.
	*  \return a matrix with the "approx" results using the Explicit Upwind scheme.
	*/
	Matrix solve(Matrix solution);

};