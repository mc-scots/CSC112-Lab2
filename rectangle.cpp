#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "rectangle.h"

//Rectangle functions by Luke Koch, Jinming Chen and Austin Vinyard

using namespace std;

Rectangle::Rectangle()
{
    //we start an incomplete rectangle!
    _ex = -1;
    _ey = -1;
    pointCount = 0;
}


//display the rectangle
void
Rectangle::display()
{
    //do not draw incomplete rectangle
    if(not isComplete()) {
	return;
    }

    //the rectangle is complete!  Draw it!
    double px=x(), py=y();  //the current points
    int h_steps, v_steps;  //the number of steps needed to draw the rectangle
    double dx, dy; //deltas for x and y

    //work out the number of points along the rectangle and the deltas
    dx = ex() - x();
    dy = ey() - y();
    h_steps = abs(dx);
    v_steps = abs(dy);
    
    if(h_steps) {
	dx /= h_steps;
    }
    if(v_steps){
	dy /= v_steps;
    }

	  
    //we'll rig the game by drawing the end point
    cout << cursorPosition(ex(), ey()) << "#";

    //and now we'll connect them!
    for(int i=0; i< h_steps; i++) {
	// print the point and update to the next position
	cout << cursorPosition(int(px), int(py)) << "#";
	px += dx;
    }
    for(int j=0; j < v_steps; j++){
        cout << cursorPosition(int (px), int(py)) << "#";
        py+=dy;
    }
    for(int i=0; i < h_steps; i++){
        cout << cursorPosition(int(px), int(py)) << "#";
        px -=dx;
    }
    for(int j=0; j < v_steps; j++){
        cout << cursorPosition(int(px), int(py)) << "#";
        py -=dy;
    }
    

    cout.flush();
}


void
Rectangle::handleEvent(Event *e)
{
    //do nothing
}


//Returns true if the shape is complete
bool
Rectangle::isComplete()
{
    return pointCount == 2;
}



void
Rectangle::addPoint(int _x, int _y)
{
    //don't add to a completed rectangle
    if(isComplete()) return;

    //set the endpoint and mark ourselves complete
    if(pointCount == 0) {
	//set the first end point
	x(_x);
	y(_y);
    } else {
	_ex = _x;
	_ey = _y;
    }

    //we added a point!
    pointCount++;
    
}


//return ex
int
Rectangle::ex()
{
    return _ex;
}


//return ey
int
Rectangle::ey()
{
    return _ey;
}
