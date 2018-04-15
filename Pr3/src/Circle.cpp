#include "Circle.h"

Circle::Circle()
{
    X = 0;
    Y = 0;
    BorderColor = WHITE;
    InnerColor = BLACK;
    BackgroundColor = getPixel(X, Y);
}

Circle::Circle(int x, int y, int radius, int bw, int bc, int ic) :
    Radius(radius)
{
    X = x;
    Y = y;
    BorderWidth = bw;
    BorderColor = bc;
    InnerColor = ic;
    BackgroundColor = getPixel(X, Y);
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw(int borderColor, int InnerColor)
{
    int lastColor = getcolor();
    fillsettingstype lastFillSettings;
    linesettingstype lastLineSettings;
    getfillsettings(&lastFillSettings);
    getlinesettings(&lastLineSettings);

    switch (borderColor)
    {
        case BLACK: setcolor(WHITE); break;
        case BLUE: setcolor(LIGHTBLUE); break;
        case GREEN: setcolor(LIGHTGREEN); break;
        case CYAN: setcolor(LIGHTCYAN); break;
        case RED: setcolor(LIGHTRED); break;
        case MAGENTA: setcolor(LIGHTMAGENTA); break;
        case BROWN: setcolor(YELLOW); break;
        case LIGHTGRAY: setcolor(DARKGRAY); break;

        case WHITE: setcolor(BLACK); break;
        case LIGHTBLUE: setcolor(BLUE); break;
        case LIGHTGREEN: setcolor(GREEN); break;
        case LIGHTCYAN: setcolor(CYAN); break;
        case LIGHTRED: setcolor(RED); break;
        case LIGHTMAGENTA: setcolor(MAGENTA); break;
        case YELLOW: setcolor(BROWN); break;
        case DARKGRAY: setcolor(LIGHTGRAY); break;
    }
    setlinestyle(0, 0, BorderWidth);
    circle(X, Y, Radius);
    setcolor(borderColor);
    circle(X, Y, Radius);
    setfillstyle(1, InnerColor);
    floodfill(X, Y, borderColor);

    setcolor(lastColor);
    setfillstyle(lastFillSettings.pattern, lastFillSettings.color);
    setlinestyle(lastLineSettings.linestyle, lastLineSettings.upattern, lastLineSettings.thickness);
}

int Circle::getPixel(int x, int y)
{
    return getpixel(x, y);
}

int Circle::radius()
{
    return Radius;
}

void Circle::setRadius(int r)
{
    Radius = r;
    draw(BackgroundColor, BackgroundColor);
    draw(BorderColor, InnerColor);
}

