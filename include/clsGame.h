#ifndef CLSGAME_H
#define CLSGAME_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <clsBackground.h>
#include <clsScore.h>
#include <clsTime.h>
#include <clsSoundEffect.h>
#include <clsText.h>
#include <clsAudio.h>
#include <clsHit.h>
#include <clsTarget.h>

class clsGame
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsBackground *background;
        clsError error;
        clsAudio audio;
        clsText text;
        clsHit hit;
        clsSoundEffect shoot;
        clsSoundEffect point;
        clsTime time;
        clsScore score;
        bool targetStatus;
        clsTarget target;

    public:
        int init(clsScreen*, clsEvent*, clsBackground*);
        int run();
        bool confirmExit();
        int keyCommand(bool*,bool*,Uint16);
        void closeAudio();
        void refresh();
};

#endif // CLSGAME_H
