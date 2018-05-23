#ifndef DSTAR_H_INCLUDED
#define DSTAR_H_INCLUDED

#include <math.h>

#include "circle.h"

class DStar : public Circle
{
public:
    DStar(int x, int y, int r = 25, int color = 15) :
        Circle(x, y, r, color)
    {}
    virtual ~DStar(){ show(false); }

    virtual void show(bool enable = true)
    {
        int tc = getcolor();
        if (enable) setcolor(get_color());
        else setcolor(0);

        int lx = round(get_x() - get_r() * 0.8666);
        int rx = round(get_x() + get_r() * 0.8666);
        int ty = round(get_y() + get_r() / 2.);
        int coords[8] = { get_x(), get_y() - get_r(), rx, ty, lx, ty, get_x(), get_y() - get_r() };

        drawpoly(4, coords);

        ty = round(get_y() - get_r() / 2.);
        coords[0] = get_x();
        coords[1] = get_y() + get_r();
        coords[2] = rx;
        coords[3] = ty;
        coords[4] = lx;
        coords[5] = ty;
        coords[6] = get_x();
        coords[7] = get_y() + get_r();

        drawpoly(4, coords);

        setcolor(tc);
    }
};

#endif // DSTAR_H_INCLUDED
