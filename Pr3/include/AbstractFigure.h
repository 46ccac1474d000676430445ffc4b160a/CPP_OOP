#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

class AbstractFigure
{
protected:
    int X, Y, BorderWidth, BorderColor, InnerColor, BackgroundColor;
    bool Visible, Changed;

    virtual void draw(int borderColor, int InnerColor) = 0;
    virtual int getPixel(int x, int y) = 0;

public:
    AbstractFigure();

    int x();
    int y();
    int borderWidth();
    int borderColor();
    int innerColor();

    void setX(int x);
    void setY(int y);
    void moveTo(int x, int y);

    void setDX(int dx);
    void setDY(int dy);
    void move(int dx, int dy);

    void setBorderWidth(int w);
    void setBorderColor(int bordercolor);
    void setInnnerColor(int innerColor);
    void setColor(int borderColor, int color);

    void show();
    void hide();

    bool isVisible();

};

#endif // ABSTRACTFIGURE_H
