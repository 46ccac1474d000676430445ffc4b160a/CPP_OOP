#ifndef CIRCLE_H
#define CIRCLE_H

#include <graphics.h>
#include "AbstractFigure.h"

class Circle : public AbstractFigure
{
protected:
    int Radius;

    virtual void draw(int borderColor, int InnerColor);
    virtual int getPixel(int x, int y);

public:
    Circle();
    Circle(int x, int y, int radius, int bw, int bc, int ic);
    virtual ~Circle();

    int radius();
    void setRadius(int r);

};

#endif // CIRCLE_H
