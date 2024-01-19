/**************************************************************
 * Source file:
 *  glDemo.h
 * Author:
 *  Gergo Medveczky
 * Summary:
 *  Source for the function in glDemo class.
 **************************************************************/
#include "glDemo.h"

void Simulator::draw(const Interface& pUI, ogstream& gout)
{
	// makes it show 2 decimal places for screen values
	gout.setf(ios::fixed);
	gout.setf(ios::showpoint);
	gout.precision(2);

	// Draw the stars.
	for (int i = 0; i < 250; i++)
		stars[i].draw(gout);

	// Draw the ground
	ground.draw(gout);

	// wraps lander if outside of screen
	lander.wrapping();

	// Draw Lander
	gout.drawLander(lander.getPoint() /*position*/, lander.getAngle() / -57
	/*angle*/);

	// Draw lander flames
	if (lander.canThrust())
	{
		gout.drawLanderFlames(lander.getPoint(), lander.getAngle() / -57,
			pUI.isDown(), pUI.isLeft(), pUI.isRight());
	}

	// Checks if the lander crashed
	if (lander.isAlive() == false && lander.isLanded() == false)
	{
		gout.setPosition(Point(640, 360));
		gout << "You Crashed!!!\nPress space to restart.";
	}

	// Checks if the lander landed successfully
	if (lander.isAlive() == false && lander.isLanded() == true)
	{
		gout.setPosition(Point(640, 360));
		if (lander.calcSpeed() <= 1)
			gout << "Good Job Armstrong!\nPress space to restart.";
		else
			gout << "You landed\nPress space to restart.";
	}

	// put some text on the screen
	gout.setPosition(Point(7, 700));
	gout << "Fuel: " << lander.getFuel() << " lbs\n" << "Altitude: " <<
		ground.getElevation(lander.getPoint()) << " meters\n" << "Speed: " << lander.calcSpeed()
		<< "m/s\n" << endl;
}

/*************************************************************************
 * HANDLE INPUT
 * checks if the arrow keys are pressed and sends that data to have it
 * thrust in the proper direction.
 *************************************************************************/
void Simulator::handleInput(const Interface& ui)
{
	if (lander.isAlive() && !lander.isLanded() && lander.canThrust())
	{
		if (ui.isDown())
		{
			lander.applyThrustBottom();
		}
		if (ui.isLeft())
		{
			lander.applyThrustLeft();
		}
		if (ui.isRight())
		{
			lander.applyThrustRight();
		}
	}
	else
	{
		if (ui.isSpace())
		{
			main();
		}
	}
}

/*************************************************************************
 * ADVANCE
 * makes sure everything is still good and applies the movement based on
 * lander speed and applies gravity. Checks if the lander landed or crashed.
 *************************************************************************/
void Simulator::advance()
{
	if (lander.isAlive())
	{
		// advance the lander
		lander.advance();

		// Apply gravity
		lander.applyGravity();

		// check for just landed
		if (ground.onPlatform(lander.getPoint(),
			lander.getLanderWidth()))
		{
			if (lander.calcSpeed() <= 4.0 && lander.getAngle() < 7 && lander.getAngle() > -7)
			{
				lander.setLanded(true);
				lander.setAlive(false);
			}
			else
				lander.setLanded(false);
		}

		// check for crash
		if (ground.hitGround(lander.getPoint(), lander.getLanderWidth())
			&& lander.isLanded() == false)
		{
			lander.setAlive(false);
		}
	}
}
