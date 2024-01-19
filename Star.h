/**************************************************************
 * Source file:
 *  Star.h
 * Author:
 *  Gergo Medveczky 
 * Summary:
 *  Header file for the stars class.
 **************************************************************/
#ifndef Star_h
#define Star_h
#include "point.h"
#include <stdio.h>
#include "uiInteract.h"
#include "uiDraw.h"

/*************************
 * Star class to store
 * attributes about the
 * stars and draw them.
 *************************/
class Star
{
private:
   // Instantiate a point for the star
    Point ptStar;

    // Assign a phase to the star
    unsigned char phase;

public:
   // Default constructor
    Star()
    {
        phase = random(0,255);
        ptStar.setX(random(-1280,1280));
        ptStar.setY(random(150,720));
    }

    // draws stars
    void draw(ogstream& gout);
};

#endif /* Star_h */
