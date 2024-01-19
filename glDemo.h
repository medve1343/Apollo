/**************************************************************
 * Header File:
 *  glDemo.h
 * Author:
 *  Gergo Medveczky
 * Summary:
 * Just a simple program to demonstrate how to create an Open GL window,
 * draw something on the window, and accept simple user input
 **************************************************************/
#pragma once
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "Star.h"
#include "Lander.h"
#include <string>

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
	// Non-Default constructor
	Simulator(const Point& ptUpperRight) : ground(ptUpperRight){}

	// this is just for test purposes.  Don't make member variables public!
	Lander lander;			// Create a lander.
	Point ptUpperRight;	// size of the screen.
	Ground ground;			// Create ground.
	Star stars[250];		// Create stars.

	// Draws items for simulation.
	void draw(const Interface& pUI, ogstream& gout);

	// handles user input
	void handleInput(const Interface& ui);

	// Advances the simulator
	void advance();
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
	// Instantiate openGL
	ogstream gout;

	// the first step is to cast the void pointer into a game object. This
	// is the first step of every single callback function in OpenGL. 
	Simulator* pDemo = (Simulator*)p;

	//Call Demo advance.
	pDemo->advance();
	pDemo->handleInput(*pUI);
	pDemo->draw(*pUI, gout);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PWSTR pCmdLine,
	_In_ int nCmdShow)
#else // !_WIN32
int main()
#endif // !_WIN32
{
	// Initialize OpenGL
	Point ptUpperRight(1280.0, 720.0);
	Interface ui(0, NULL,
		"Open GL Demo",
		ptUpperRight);

	// Initialize the game class
	Simulator demo(ptUpperRight);

	// set everything into action
	ui.run(callBack, &demo);
	return 0;
}
