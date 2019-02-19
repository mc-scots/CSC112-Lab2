//Line class, draw a line between two points!
#ifndef TOBLERONE_H
#define TOBLERONE_H
#include "shape.h"

class Toblerone : public Shape
{
public:
    Toblerone(); //public constructor

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
