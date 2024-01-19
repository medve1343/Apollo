//
//  Acceleration.hpp
//
//  Created by Gergo Medveczky on 2/1/22.
//

#ifndef Acceleration_hpp
#define Acceleration_hpp
#include <stdio.h>
class Acceleration
{
private:
    // CONSTANTS
    const float WEIGHT = 15103;
    const float THRUST = 45000;
    const float GRAVITY = -1.625;

    // Calculate acceleration due to weight
    double acceleration = THRUST / WEIGHT;
    double angle;

    // Coordinates for current (x,y) and velocity(x,y)
    double dx;
    double dy;
    double x;
    double y;

    // Radians calculated
    double radians;
    double speed;
    double ddyt;
    double ddxt;
public:
    //DEFAULT CONSTRUCTOR
    Acceleration();

    //SETTERS
    void setDy(double dy);
    void setDx(double dx);
    void setAltitude(double altitude);
    void setAngle(double angle);
    void setY(double y);
    void setX(double x);
    void setRadians(double radians);
    void setDdyt(double ddyt);
    void setDdxt(double ddxt);
    void setSpeed(double speed);

    //GETTERS
    double getDy() const;
    double getDx() const;
    double getY() const;
    double getX() const;
    double getAngle() const;
    double getSpeed() const;
    double getDdxt() const;
    double getDdyt() const;
    double getRadians() const;
    double getAltitude() const;

    // Converts degrees to radians
    void applyThrust();
    float degreesToRadian();
    double calcddyt();
    double calcddxt();
    double newDy();
    double newDx();
    

};
#endif /* Acceleration_hpp */
