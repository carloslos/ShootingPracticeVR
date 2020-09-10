#ifndef CLSGOODBYE_H
#define CLSGOODBYE_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <clsBackground.h>

class clsGoodbye
{
    protected:
    clsScreen *screen;
    clsEvent *event;
    clsBackground *background;
    clsError error;

public:
    int init(clsScreen*, clsEvent*, clsBackground*);
    int run();
    int keyCommand(bool*,Uint16);
};

#endif // CLSGOODBYE_H
