//implementation of toblerone's stack of toblerone's with no upside down toblerones.
//use F for Fabulous Toblerones...oh and fractals.
//use for delta \u0394        for upside down use \u25BC
#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "toblerone.h"

using namespace std;

Toblerone::Toblerone()
{
    //the Toblerone is not ready yet!
    _ex = -1;
    _ey = -1;
    pointCount = 0;
}

void
Toblerone::display()
{
    //do stack unfinished Toblerones
    if(not isComplete()) {
        return;
    }

    //the line is complete!  Draw it!
    double px=x(), py=y();  //the current points
    int steps;  //the number of steps needed to draw the line
    double dy; //deltas for y

    //work out the number of points along the line and the deltas
    dy = ey() - y();
    steps = dy;
    if(steps) {
        //px /= steps;
        dy /= steps;
    }


    //we'll rig the game by drawing the end point
    cout << cursorPosition(x(), y());// << "/\\";


    for (int i = 0; i < steps; i++)
    {
        int val = 1;
        cout << cursorPosition(px - i, py + i);
        for (int k = 0; k <= i; k++)
        {
            if((val % 2) == 0){
                cout << "  ";
            }else{
                cout << "/\\";
            }

            //cout << val;
            val = val * (i - k) / (k + 1);

        }

    }


    cout.flush();
}

void
Toblerone::addPoint(int _x, int _y)
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

void
Toblerone::handleEvent(Event *e)
{
    //We do??   No, we not do.
}

bool
Toblerone::isComplete()//is done now?
{
    return pointCount == 2;
}

//show end toblerone
int
Toblerone::ex()
{
    return _ex;
}


//showy end tobleroney
int
Toblerone::ey()
{
    return _ey;
}