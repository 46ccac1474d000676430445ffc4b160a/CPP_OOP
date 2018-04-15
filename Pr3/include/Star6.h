#ifndef STAR6_H
#define STAR6_H

#include "Circle.h"
#include <graphics.h>
#include <cmath>

class Star6 : public Circle
{
    virtual void draw(int borderColor, int InnerColor);
    virtual int getPixel(int x, int y);

public:
    Star6();
    Star6(int x, int y, int radius, int bw, int bc, int ic);
    ~Star6();

};

#endif // STAR6_H
