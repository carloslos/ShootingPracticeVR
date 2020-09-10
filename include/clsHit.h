#ifndef CLSHIT_H
#define CLSHIT_H

#include <clsSprite.h>
#include <clsTimer.h>
#include <clsScreen.h>


class clsHit: public clsSprite
{
    protected:
        void inherit(){};
        clsTimer timer;
        clsScreen *screen;

    public:
        int init(clsScreen*);
        void hit(int, int);
};

#endif // CLSHIT_H
