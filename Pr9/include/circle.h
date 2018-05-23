#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <graphics.h>

#include "Shape.h"

class Circle : public Shape
{
    int r;

public:
    Circle() :
        r(25)
    {}
    Circle(int x, int y, int r = 25, int color = 15) :
        Shape(x, y, color),
        r(r)
    {}
    virtual ~Circle(){ show(false); }

    int get_r() { return r; }
    void set_r(int r)
    {
        show(false);
        this->r = r;
        show(true);
    }

    virtual void show(bool enable = true)
    {
        int tc = getcolor();
        if (enable) setcolor(get_color());
        else setcolor(0);
        circle(get_x(), get_y(), get_r());
        setcolor(tc);
    }

};

#endif // CIRCLE_H_INCLUDED
