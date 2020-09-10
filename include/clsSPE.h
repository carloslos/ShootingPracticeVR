#ifndef CLSSPE_H
#define CLSSPE_H
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsTimer.h>
#include <clsHello.h>
#include <clsGoodbye.h>
#include <clsBackground.h>
#include <clsAudio.h>
#include <clsMenu.h>
#include <clsMusic.h>

class clsSPE
{
    protected:
        clsMode mode;
        clsError error;
        clsScreen screen;
        clsMenu menu;
        clsMusic music;
        clsBackground background;
        clsAudio musicAudio;
        clsTimer timer;
        clsEvent event;
        clsHello hello;
        clsGoodbye goodbye;

    public:
        int init();
        int run();
        int keyCommand(bool*,Uint16);
};

#endif // CLSMOTOR_H
