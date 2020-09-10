#ifndef CLSTARGET_H
#define CLSTARGET_H

#include <clsScreen.h>
#include <clsRandom.h>
#include <clsSprite.h>

class clsTarget: public clsSprite
{
    protected:
        clsScreen *screen;
        clsRandom random;
        bool status;
        void inherit(){};
        int x, y, tx, ty;

    public:
        int init(clsScreen*);
        void create();
        void destroy();
        bool getStatus();
        int getX();
        int getY();
};

#endif // CLSTARGET_H
