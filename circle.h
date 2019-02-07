//Line class, draw a line between two points!
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(); //public constructor

    //required widget functions
    virtual void display();
    virtual void handleEvent(Event *e);

    //shape specific functions
    virtual bool isComplete();
    virtual void addPoint(int _x, int _y);

    //return the ending x and y
    virtual int ex();
    virtual int ey();
private:
    int _ex, _ey;
    int pointCount;
};

#endif



