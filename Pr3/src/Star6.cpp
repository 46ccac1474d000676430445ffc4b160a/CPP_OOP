#include "Star6.h"

Star6::Star6()
{
    //ctor
}

Star6::Star6(int x, int y, int radius, int bw, int bc, int ic)
{
    Radius = radius;
    X = x;
    Y = y;
    BorderWidth = bw;
    BorderColor = bc;
    InnerColor = ic;
    BackgroundColor = getPixel(X, Y);
}

Star6::~Star6()
{
    //dtor
}
void Star6::draw(int borderColor, int InnerColor)
{
    int lastColor = getcolor();
    fillsettingstype lastFillSettings;
    linesettingstype lastLineSettings;
    getfillsettings(&lastFillSettings);
    getlinesettings(&lastLineSettings);

    int tempColor;
    switch (borderColor)
    {
        case BLACK: tempColor = WHITE; break;
        case BLUE: tempColor = LIGHTBLUE; break;
        case GREEN: tempColor = LIGHTGREEN; break;
        case CYAN: tempColor = LIGHTCYAN; break;
        case RED: tempColor = LIGHTRED; break;
        case MAGENTA: tempColor = LIGHTMAGENTA; break;
        case BROWN: tempColor = YELLOW; break;
        case LIGHTGRAY: tempColor = DARKGRAY; break;

        case WHITE: tempColor = BLACK; break;
        case LIGHTBLUE: tempColor = BLUE; break;
        case LIGHTGREEN: tempColor = GREEN; break;
        case LIGHTCYAN: tempColor = CYAN; break;
        case LIGHTRED: tempColor = RED; break;
        case LIGHTMAGENTA: tempColor = MAGENTA; break;
        case YELLOW: tempColor = BROWN; break;
        case DARKGRAY: tempColor = LIGHTGRAY; break;
    }

    {
        int lx = round(X - Radius * 0.87);
        int rx = round(X + Radius * 0.87);
        int ty = round(Y + Radius / 2.);
        int coords[8] = { X, Y - Radius, rx, ty, lx, ty, X, Y - Radius };

        setlinestyle(0, 0, BorderWidth);
        setcolor(tempColor);
        drawpoly(4, coords);
        setfillstyle(1, InnerColor);
        floodfill(X, Y, tempColor);
        setcolor(borderColor);
        drawpoly(4, coords);
    }
    {
        int lx = round(X - Radius * 0.87);
        int rx = round(X + Radius * 0.87);
        int ty = round(Y - Radius / 2.);
        int coords[8] = { X, Y + Radius, rx, ty, lx, ty, X, Y + Radius };

        setlinestyle(0, 0, BorderWidth);
        setcolor(tempColor);
        drawpoly(4, coords);
        setfillstyle(1, InnerColor);
        floodfill(X, Y, tempColor);
        setcolor(borderColor);
        drawpoly(4, coords);
    }

    setcolor(lastColor);
    setfillstyle(lastFillSettings.pattern, lastFillSettings.color);
    setlinestyle(lastLineSettings.linestyle, lastLineSettings.upattern, lastLineSettings.thickness);
}

int Star6::getPixel(int x, int y)
{
    return getpixel(x, y);
}
