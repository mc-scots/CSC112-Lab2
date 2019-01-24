//Rectangle class, draw a rectangle between two points 
//by Luke Koch, Jinming Chen, Austin Vinyard
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(); //public constructor

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


    
