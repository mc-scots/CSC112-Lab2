//authors Eric Breeden, Micah Tullia, Drew Johnson, and Bailey Walker

#include <iostream>
#include <iomanip>
#include <cmath>
#include "circle.h"
#include "shape.h"
#include "line.h"
#include "term.h"
#include "point.h"

using namespace std;

//
Circle::Circle() {
    //we start an incomplete Circle!
   int _ex = -1;
   int _ey = -1;
   int pointCount = 0;

}

//display the circle
void Circle::display() {
    //ensure not to draw an incomplete circle
    if (not isComplete()) {
        return;
    }

    //VARIABLES AND WHAT THEY MEAN
    int px = x(), py = y(); //point of x //point of y          //one point is equal to an x and a y coordinate
    double dx = ex() - x(); //delta x     //ex is endpoint of x
    double dy = ey() - y();//delta y      //ey is endpoint of y
    double d = dy / dx; //diameter (distance between the two points)
    double c = 3.14 * d; //c is equal to circumference
    
    //these are radius that will help make the circle
    int h_steps = abs(dx);
    int v_steps = abs(dy);
    int rx2 = 0;
    int ry1 = 0;
    int ry2 = 0;
    int ipoint = 0; // ipoint = initial point
    int cp = 0; //circle points: helps determine the number of points around the circle
//    cout << cursorPosition(ex(), ey()) << "#"; //prints point at end point
    /*
    for(int i = 0; i <= c; i++) 
    { //creates a line
        cout << cursorPosition(int (px), int (py)) << "#";
    }
    */
    if(h_steps) {
	dx /= h_steps;
    }
    
    if(v_steps){
	dy /= v_steps;
    }
    
    
    //prints out points
    cout << cursorPosition(px,py) << "#";
    cout << cursorPosition(ex(),ey()) << "#";
    
    //prints out rest of the circle
    //print for when cursor goes left and prints down
    for(int i=0; i < h_steps; i++) 
    {
	cout << cursorPosition(int(px), int(py)) << "#";
        if(ipoint <= h_steps/2)
        {
            
            
            py = py + 1;
            ipoint = ipoint + 1;
        }
        
        if(ipoint > h_steps/2)
        {
            py = py - 1;
            ipoint = ipoint + 1;
        }
        if(ipoint == (h_steps/2)-1)
        {
            ipoint = ipoint + 1;
        }
	px += dx;
    }
    //prints for when the cursor goes left or right and goes up
    ipoint = 0;
    for(int i=0; i < h_steps; i++) 
    {
	cout << cursorPosition(int(px), int(py)) << "#";
        if(ipoint <= h_steps/2)
        {
            
            
            py = py + 1;
            px = px - 1;
            ipoint = ipoint + 1;
        }
        
        if(ipoint > h_steps/2)
        {
            py = py - 1;
            ipoint = ipoint + 1;
        }
        if(ipoint == (h_steps/2)-1)
        {
            ipoint = ipoint + 1;
        }
	px += dx;
    }
    
    
    for(int j=0; j < v_steps; j++){
        ipoint = 0;
        cout << cursorPosition(int(px) + 1, int(py)) << "#";
        if(ipoint <= v_steps)
        {
            
            px = px + 1;
            ipoint = ipoint + 1;
        }
        py+=dy;
    }
    
   
    
    //debug stuff
    //cout << cursorPosition(dx,dy) << "#";
    cout.flush();
}

//
void Circle::handleEvent(Event *e) {
    //do nothing
}

//Returns true if the shape is complete
bool Circle::isComplete() {
    return pointCount == 2;
}

//
void Circle::addPoint(int _x, int _y) {
    //don't add to a completed circle
    if(isComplete()) return;

    //set the endpoint and mark ourselves complete
    if(pointCount == 0) {
        //set the first end point
        x(_x);
        y(_y);
    }
    else {
        _ex = _x;
        _ey = _y;
    }

    //we added a point!
    pointCount++;
}

//return ex
int Circle::ex() {
    return _ex;
}


//return ey
int Circle::ey() {
    return _ey;
}
