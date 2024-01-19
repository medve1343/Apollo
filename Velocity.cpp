/**************************************************************
 * Source file:
 *  Velocity.h
 * Author:
 *  Gergo Medveczky 
 * Summary:
 *  Source for the function in velocity class.
 **************************************************************/
#include "Velocity.h"

/***********************************
 * VELOCITY DEFAULT CONSTRUCTOR
 ***********************************/
Velocity ::Velocity()
{
    setDx(0);
    setDy(0);
}

/***********************************
 * VELOCITY NON-DEFAULT CONSTRUCTOR
 ***********************************/
Velocity ::Velocity(float dx, float dy)
{
    setDx(dx);
    setDy(dy);
}

/***********************************
 * ADD DX
 * Calculates the DX value based on
 * current speed, angle, and thrust.
 ***********************************/
double Velocity::addDx(double radians, double thrust)
{
   dx = dx + (0.5 * ((sin(radians)) * (thrust * .1)));
   return dx;
}

/***********************************
 * ADD DY
 * Calculates the DX value based on
 * current speed, angle, and thrust.
 ***********************************/
double Velocity::addDy(double radians, double thrust)
{
   dy = dy + (0.5 * ((cos(radians)) * (thrust * .1)));
   return dy;
}
