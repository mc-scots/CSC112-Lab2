#ifndef TOBLERONE.H
#define TOBLERIONE.H
#include "shapes.h"

class Toblerone : public Shape {

    private:
    int _ex, _ey;
    int pointCount;


    public:
    //required widget functions.
    virtual void display();
    virtual void handleEvent(Event *e);

    //shape specific functions.
    virtual bool isComplete();
    virtual void addPoint(int _x, int _y);

    //return the ending x and y.
    virtual int ex();
    virtual int ey();
};