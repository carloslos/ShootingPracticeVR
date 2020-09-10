#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <clsGame.h>
#include <clsText.h>
#include <clsBackground.h>
#include <clsSoundEffect.h>
#include <clsScore.h>

class clsMenu
{
  protected:
        clsScreen *screen;
        clsEvent *event;
        clsBackground *background;
        clsSoundEffect menu;
        clsGame game;
        clsError error;
        clsText text;
        clsScore score;

    public:
        int init(clsScreen*, clsEvent*, clsBackground*);
        int run();
        void displayHelp();
        int keyCommand(bool*,bool*,Uint16);
        void menuRefresh(int);
};

#endif // CLSMENU_H
