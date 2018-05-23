#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    int x, y;
    int color;

public:
    Shape() :
        x(0),
        y(0),
        color(15)
    {}
    Shape(int x, int y, int color) :
        x(x),
        y(y),
        color(color)
    {}
    virtual ~Shape(){};

    int get_color() { return color; }
    void set_color(int color)
    {
        show(false);
        this->color = color;
        show(true);
    }

    int get_x() { return x; }
    void set_x(int x)
    {
        show(false);
        this->x = x;
        show(true);
    }

    int get_y(){ return y; }
    void set_y(int y)
    {
        show(false);
        this->y = y;
        show(true);
    }

    void move(int dx, int dy)
    {
        show(false);
        x += dx;
        y += dy;
        show(true);
    }

    void moveto(int x, int y)
    {
        show(false);
        this->x = x;
        this->y = y;
        show(true);
    }

    virtual void show(bool) = 0;

};

#endif // SHAPE_H
