/**************************************************************
 * Source file:
 *  Lander.h
 * Author:
 *  Gergo Medveczky
 * Summary:
 *  Source for the function in lander class.
 **************************************************************/
#include "Lander.h"

 /*************************
  * APPLY THRUST LEFT
  * applies thrust on left
  * side to move right
  *************************/
void Lander::applyThrustLeft()
{
	angle = angle - 6.0;
	if (getAngle() <= -360)
		angle = 0;
	setFuel(getFuel() - 1);
}

/*************************
 * APPLY THRUST RIGHT
 * applies thrust on right
 * side to move left.
 *************************/
void Lander::applyThrustRight()
{
	angle = angle + 6.0;
	if (getAngle() >= 360)
		angle = 0;
	setFuel(getFuel() - 1);
}

/*************************
 * APPLY THRUST BOTTOM
 * applies thrust on bottom
 * to move upwards.
 *************************/
void Lander::applyThrustBottom()
{
	velocity.setDy(velocity.addDy(degreesToRadians(), thrust));
	velocity.setDx(velocity.addDx(degreesToRadians(), thrust));
	setFuel(getFuel() - 10);
}

/*************************
 * ADVANCE
 * function to call to
 * advance current x and y
 * coordinates based on
 * x and y velocity.
 *************************/
void Lander::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}

/*************************
 * CAN THRUST
 * checks if it is not
 * landed and still has
 * fuel to thrust.
 *************************/
bool Lander::canThrust() const
{
	if (getFuel() > 0 && !isLanded())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************
 * CALC SPEED
 * calculates speed based
 * on Dx and Dy.
 *************************/
float Lander::calcSpeed()
{
	return sqrt(pow(velocity.getDx(), 2) + pow(velocity.getDy(), 2));
}

/*************************
 * APPLY GRAVITY
 * applies gravity to the
 * landers dy.
 *************************/
void Lander::applyGravity()
{
	velocity.setDy(velocity.getDy() - GRAVITY);
}

/*************************
 * WRAPPING
 * changes point to other
 * side of screen.
 *************************/
void Lander::wrapping()
{
	if (point.getX() <= 0)
		point.setX(1280.0);
	else if (point.getX() >= 1280)
		point.setX(0.0);
}
