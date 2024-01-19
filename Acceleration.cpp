//
//  Acceleration.cpp
//  Created by Gergo Medveczky on 2/1/22.
//

#include "Acceleration.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

/***************************************************
 * DEFAULT CONSTRUCTOR.
 * (Sets every value to default when the object gets
 * instantiated.
 ***************************************************/
Acceleration::Acceleration()
{
    dx = 0;
    dy = 0;
    x = 0;
    y = 0;
    angle = 0;
    radians = 0;
    speed = 0;
    ddyt = 0;
    ddxt = 0;
}

/***************************************************
 *This function is going to perform all the mathematical tasks then,
 *update all the attributes, position and speed of the ship. Also it will
 *apply the thrust to slow down the moonlander.
 ***************************************************/
void Acceleration::applyThrust()
{
    degreesToRadian();
    calcddyt();
    calcddxt();
    newDx();
    newDy();
    
}

/***************************************************
 * DEGREES TO RADIAN
 * Converts the given angle to radians
 ***************************************************/
float Acceleration::degreesToRadian()
{
    radians = 2 * PI * (angle / 360);
    return radians;
}

/***************************************************
 * GET DY
 ***************************************************/
double Acceleration::getDy() const
{
    return dy;
}

/***************************************************
 * GET DX
 ***************************************************/
double Acceleration::getDx() const
{
    return dx;
}

/***************************************************
 * GET Y
 ***************************************************/
double Acceleration::getY() const
{
    return y;
}

/***************************************************
 * GET X
 ***************************************************/
double Acceleration::getX() const
{
    return x;
}

/***************************************************
 * GET ANGLE
 ***************************************************/
double Acceleration::getAngle() const
{
    return angle;
}

/***************************************************
 * GET SPEED
 ***************************************************/
double Acceleration::getSpeed() const
{
    return speed;
}

/***************************************************
 * GET DDXT
 ***************************************************/
double Acceleration::getDdxt()const
{
    return ddxt;
}

/***************************************************
 * GET DDYT
 ***************************************************/
double Acceleration::getDdyt()const
{
    return ddyt;
}

/***************************************************
 * GET RADIANS
 ***************************************************/
double Acceleration::getRadians() const
{
    return radians;
}

/***************************************************
 * CALC DDYT
 * Used to calculate the cos for ddyt used in dy.
 ***************************************************/
double Acceleration::calcddyt()
{
    ddyt = (cos(getRadians()) * acceleration);
    return ddyt;
}

/***************************************************
 * CALC DDXT
 * Used to calculate the sin for ddxt used in dx.
 ***************************************************/
double Acceleration::calcddxt()
{
    ddxt = (sin(getRadians()) * acceleration);
    return ddxt;
}

/***************************************************
 * NEW DY
 * calculates the new y velocity value (dy).
 ***************************************************/
double Acceleration::newDy()
{
    dy = dy + calcddyt();
    return dy;
}

/***************************************************
 * NEW DX
 * calculates the new x velocity value (dx).
 ***************************************************/
double Acceleration::newDx()
{
    dx = dx + getDdxt();
    return dx;
}

/***************************************************
 * SET DDYT
 ***************************************************/
void Acceleration::setDdyt(double ddyt)
{
    this->ddyt = ddyt;
}

/***************************************************
 * SET DDXT
 ***************************************************/
void Acceleration::setDdxt(double ddxt)
{
    this->ddxt = ddxt;
}

