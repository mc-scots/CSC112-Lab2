#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "line.h"

using namespace std;

Line::Line()
{
    //we start an incomplete line!
    _ex = -1;
    _ey = -1;
    pointCount = 0;
}


//display the line
void
Line::display()
{
    //do not draw incomplete lines
    if(not isComplete()) {
	return;
    }

    //the line is complete!  Draw it!
    double px=x(), py=y();  //the current points
    int steps;  //the number of steps needed to draw the line
    double dx, dy; //deltas for x and y

    //work out the number of points along the line and the deltas
    dx = ex() - x();
    dy = ey() - y();
    steps = int(sqrt(pow(dx, 2) + pow(dy, 2)));
    if(steps) {
	dx /= steps;
	dy /= steps;
    }


    //we'll rig the game by drawing the end point
    cout << cursorPosition(ex(), ey()) << "#";

    //and now we'll connect them!
    while(steps--) {
	// print the point and update to the next position
	cout << cursorPosition(int(px), int(py)) << "#";
	px += dx;
	py += dy;
    }

    cout.flush();
}


void
Line::handleEvent(Event *e)
{
    //do nothing
}


//Returns true if the shape is complete
bool
Line::isComplete()
{
    return pointCount == 2;
}



void
Line::addPoint(int _x, int _y)
{
    //don't add to a completed line
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
Line::ex()
{
    return _ex;
}


//return ey
int
Line::ey()
{
    return _ey;
}
