#ifndef HYBRID_H_INCLUDED
#define HYBRID_H_INCLUDED

#include "DStar.h"

class Hybrid : public DStar
{
public:
    Hybrid(int x, int y, int r = 25, int color = 15) :
        DStar(x, y, r, color)
    {}
    virtual ~Hybrid(){ show(false); }

    virtual void show(bool enable = true)
    {
        Circle::show(enable);
        DStar::show(enable);
    }
};

#endif // HYBRID_H_INCLUDED
