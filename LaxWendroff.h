/*!
 * \file LaxWendroff.h
 * \brief Lax Wendroff Scheme
 * \author Damien LIDA & Elise SUARD
 * \version 0.1
 *
 * Class which contains the methode to calculate the solution thanks to the Lax Wendroff scheme.
 *
 */
#include "Scheme.h"

/*! 
*\class LaxWendroff
 * \brief class of the Lax Wendroff scheme
 *
 *  This class calculates the Lax Wendroff solutions.
 *
 */
class LaxWendroff :public Scheme {
public:
	/*!
	*  \brief Constructor of the LaxWendroff Class.
	*
	*  \param dt : time step
	*  \param dx : space step
	*  \param u : speed of sound
	*  \param xmax : tube length
	*  \param tmax : study duration
	*/
	LaxWendroff(double dx, double dt, double u, double xmax, double tmax);

	/*!
	*  \brief Lax Wendroff calculation
	*
	*  Method which allow us to caculate Lax Wendroff solutions.
	*
	*  \param solution : the boundary matrix containing the boundary and initial conditions.
	*  \return a matrix with the "approx" results using the Lax Wendroff scheme.
	*/
	Matrix solve(Matrix solution);
}; 
