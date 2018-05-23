#include "shape.h"

int Shape::get_color()
{ return color; }

void Shape::set_color(int color)
{
    hide();
    this->color = color;
    show();
}

int Shape::get_x()
{ return x; }

int Shape::get_y()
{ return y; }

void Shape::set_x(int x)
{
    hide();
    this->x = x;
    show();
}

void Shape::sety(int y)
{
    hide();
    this->y = y;
    show();
}

void Shape::move(int dx, int dy)
{
    hide();
    x += dx;
    y += dy;
    show();
}

void Shape::moveto(int x, int y)
{
    hide();
    this->x = x;
    this->y = y;
    show();
}

