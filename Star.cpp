/**************************************************************
 * Source file:
 *  Star.h
 * Author:
 *  Gergo Medveczky 
 * Summary:
 *  Source for the function in star class.
 **************************************************************/
#include "Star.h"

/**************************************************************
 * DRAW
 * draws each star and incriments the phase.
 **************************************************************/
void Star::draw(ogstream& gout)
{
	gout.drawStar(ptStar, phase++);
}
