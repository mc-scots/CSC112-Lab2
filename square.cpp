#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "square.h"

using namespace std;

Square::Square()
{
    //we start an incomplete Square!
    _ex = -1;
    _ey = -1;
    pointCount = 0;
}


//display the Square
void
Square::display()
{
    //do not draw incomplete Squares
    if(not isComplete()) {
	return;
    }

    //the Square is complete!  Draw it!
    double px=x(), py=y();  //the current points
    int x_steps, y_steps;  //the number of steps needed to draw the square
    double dx, dy; //deltas for x and y

    //work out the number of points along the square and the deltas
    if(dx = ex() - x()){
        dx= dx/2;
        dy = dx;
        }
 else  if( dy = ey() - y()){
      dx = dy;
       }

    x_steps = abs(dx);
    y_steps = abs(dy);

    if(x_steps) {
	dx /= x_steps;
    }
    if(y_steps){
	dy /= y_steps;
    }

    //we'll rig the game by drawing the end point
    cout << cursorPosition(ex(), ey());

    //and now we'll connect them!
    for(int i=0; i< x_steps; i++) {
	// print the point and update to the next position
	cout << cursorPosition(int(px), int(py)) <<"#";
	px += dx;
    cout << cursorPosition(int(px), int(py)) <<" ";
	px += dx;
    }
    for(int j=0; j < y_steps; j++){
        cout << cursorPosition(int (px), int(py)) <<"#";
        py+=dy;
    }
    for(int i=0; i < x_steps; i++){
        cout << cursorPosition(int(px), int(py)) <<"#";
        px -=dx;
        cout << cursorPosition(int(px), int(py)) <<" ";
	    px -= dx;
    }
    for(int j=0; j < y_steps; j++){
        cout << cursorPosition(int(px), int(py)) <<"#";
        py -=dy;
    }
    cout.flush();
}


void
Square::handleEvent(Event *e)
{
    //do nothing
}


//Returns true if the shape is complete
bool
Square::isComplete()
{
    return pointCount == 2;
}



void
Square::addPoint(int _x, int _y)
{
    //don't add to a completed square
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
Square::ex()
{
    return _ex;
}


//return ey
int
Square::ey()
{
    return _ey;
}
