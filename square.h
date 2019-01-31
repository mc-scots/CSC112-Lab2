//Authors: Colwyn, Ahmed, Aaron, Emily
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
public:
    Square(); //public constructor

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