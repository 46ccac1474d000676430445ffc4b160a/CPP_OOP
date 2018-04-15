#include <ctime>
#include <graphics.h>
#include "Circle.h"
#include "Star6.h"

int main()
{
    srand(time(0));

    int wwidth = 960, wheight = 480;
    initwindow(wwidth, wheight, "Lab3", 100);

    int x = rand() % wwidth, y = rand() % wheight;
    Star6 c1(x, y, 50, 3, GREEN, DARKGRAY);
    c1.show();


    int dx = 0, dy = 0;
    bool working = 1;
    while(working)
    {
        delay(50);
        while (kbhit())
            switch(getch())
            {
                case KEY_LEFT:
                {
                    dx = abs(dx) > 20 ? (dx > 10 ? dx - 2 : dx ) : dx - 2;
                } break;
                case KEY_UP:
                {
                    dy = abs(dy) > 20 ? (dy > 10 ? dy - 2 : dy ) : dy - 2;
                } break;
                case KEY_RIGHT:
                {
                    dx = abs(dx) > 20 ? (dx < 10 ? dx + 2 : dx ) : dx + 2;
                } break;
                case KEY_DOWN:
                {
                    dy = abs(dy) > 20 ? (dy < 10 ? dy + 2 : dy ) : dy + 2;
                } break;
                case 13:
                {
                    working = 0;
                } break;
            }

        dx = c1.x()>abs(dx) && c1.x()<wwidth-abs(dx) ? dx :  -dx;
        dy = c1.y()>abs(dy) && c1.y()<wheight-abs(dy) ? dy :  - dy;
        c1.move(dx, dy);
    }

    closegraph();

    return 0;
}
