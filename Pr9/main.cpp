#include <ctime>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "hybrid.h"

const int WW = 960;
const int WH = 480;

class Wrapper
{
    Shape *shape;
    int dx, dy;

    Wrapper(){}
    Wrapper(Shape *s, int dx, int dy) :
        shape(s),
        dx(dx),
        dy(dy)
    {}

    static int rnd(int f, int t)
    {
        int r;
        do { r = f + rand() % (t-f); } while(!r);
        return r;
    }

public:
    void move();
    void deleteShape() { delete shape; }

    static Wrapper generate();
};

void Wrapper::move()
{
    if (shape->get_x() <= 0)
    {
        shape->set_x(0);
        dx = -dx;
    }
    if (shape->get_x() >= WW)
    {
        shape->set_x(WW);
        dx = -dx;
    }
    if (shape->get_y() <= 0)
    {
        shape->set_y(0);
        dy = -dy;
    }
    if (shape->get_y() >= WH)
    {
        shape->set_y(WH);
        dy = -dy;
    }
    shape->move(dx, dy);
}

Wrapper Wrapper::generate()
{
    switch (rand()%3)
    {
    case 0: return Wrapper(
                           new Circle(rnd(0, WW), rnd(0, WH), rnd(25, 75), rnd(1, 15) ),
                           rnd(-10, 10),
                           rnd(-10, 10)
                          );

    case 1: return Wrapper(
                           new DStar(rnd(0, WW), rnd(0, WH), rnd(25, 75), rnd(1, 15) ),
                           rnd(-10, 10),
                           rnd(-10, 10)
                          );

    case 2: return Wrapper(
                           new Hybrid(rnd(0, WW), rnd(0, WH), rnd(25, 75), rnd(1, 15) ),
                           rnd(-10, 10),
                           rnd(-10, 10)
                          );
    }
}

int main()
{
    initwindow(WW, WH);
    srand(time(0));

    std::vector<Wrapper> s_list;

    char numstr[25] = "Num of figures:   0 ";
    while(true)
    {
        if (kbhit())
        {
            char sw = getch();
            if (sw == 'n' && s_list.size() <= 999)
            {
                s_list.push_back(Wrapper::generate());
                sprintf(numstr, "Num of figures: %3d ", s_list.size());
            }
            else if (sw == 'd')
            {
                if (!s_list.empty())
                {
                    s_list.back().deleteShape();
                    s_list.pop_back();
                    sprintf(numstr, "Num of figures: %3d ", s_list.size());
                }
            }
            else break;
        }

        outtextxy(10, 10, numstr);
        if (s_list.size() <= 25) Sleep(50);

        for(int i = 0; i < s_list.size(); i++)
        {
            s_list[i].move();
        }
    }

    for(int i = 0; i < s_list.size(); i++)
    {
        s_list[i].deleteShape();
    }

    return 0;
}
