#include "AbstractFigure.h"

AbstractFigure::AbstractFigure() :
    X(0), Y(0), BorderWidth(1), BorderColor(0), InnerColor(0), Visible(false), Changed(true)
{
}

int AbstractFigure::x()
{
    return X;
}

int AbstractFigure::y()
{
    return Y;
}

int AbstractFigure::borderWidth()
{
    return BorderWidth;
}


int AbstractFigure::borderColor()
{
    return BorderColor;
}

int AbstractFigure::innerColor()
{
    return InnerColor;
}

void AbstractFigure::setX(int x)
{
    if (X == x) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    X = x;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::setY(int y)
{
    if (Y == y) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    Y = y;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::moveTo(int x, int y)
{
    if (X == x && Y == y) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    X = x;
    Y = y;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::setDX(int dx)
{
    if (!dx) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    X += dx;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::setDY(int dy)
{
    if (!dy) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    Y += dy;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::move(int dx, int dy)
{
    if (!dx && !dy) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    X += dx;
    Y += dy;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}

void AbstractFigure::setBorderWidth(int w)
{
    if (BorderWidth == w) return;
    if (Visible) draw(BackgroundColor, BackgroundColor);
    BorderWidth = w;
    BackgroundColor = getPixel(X, Y);
    if (Visible) draw(BorderColor, InnerColor);
}


void AbstractFigure::setBorderColor(int bordercolor)
{
    if (BorderColor == bordercolor) return;
    BorderColor = bordercolor;
    draw(BackgroundColor, BackgroundColor);
    draw(BorderColor, InnerColor);
}

void AbstractFigure::setInnnerColor(int innerColor)
{
    if (InnerColor == innerColor) return;
    InnerColor = innerColor;
    draw(BackgroundColor, BackgroundColor);
    draw(BorderColor, InnerColor);
}

void AbstractFigure::setColor(int borderColor, int innerColor)
{
    if (BorderColor == borderColor && InnerColor == innerColor) return;
    BorderColor = borderColor;
    InnerColor = innerColor;
    draw(BackgroundColor, BackgroundColor);
    draw(BorderColor, InnerColor);
}

void AbstractFigure::show()
{
    Visible = true;
    draw(BorderColor, InnerColor);
}

void AbstractFigure::hide()
{
    Visible = false;
    draw(BackgroundColor, BackgroundColor);
}

bool AbstractFigure::isVisible()
{
    return Visible;
}

