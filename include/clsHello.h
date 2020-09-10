#ifndef CLSHELLO_H
#define CLSHELLO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsBackground.h>

class clsHello
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsBackground *background;
        clsError error;

    public:
        int init(clsScreen*, clsEvent*, clsBackground*);
        int run();
        int keyCommand(bool*, Uint16);
};

#endif // CLSHELLO_H
