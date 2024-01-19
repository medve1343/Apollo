/**************************************************************
 * Header File:
 *  Velocity.h
 * Author:
 *  Gergo Medveczky
 * Summary:
 *  velocity class to determine x and y momentum.
 **************************************************************/
#ifndef Velocity_h
#define Velocity_h
#include <stdio.h>
#include <cmath>

/*************************
 * Velocity class to store
 * velocity attributes
 * for the lander.
 *************************/
class Velocity
{
private:
	double dx;
	double dy;
public:
	// Default constructor
	Velocity();

	// Non-default constructor
	Velocity(float dx, float dy);

	// Getters
	double getDx()		const { return dx;		}
	double getDy()		const { return dy;		}

	// Setters
	void setDx(float dx)		{ this->dx = dx;	}
	void setDy(float dy)		{ this->dy = dy;	}

	// Add velocities
	double addDx(double radians, double thrust);
	double addDy(double radians, double thrust);
};
#endif /* Velocity_hpp */
