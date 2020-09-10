#ifndef CLSSCORE_H
#define CLSSCORE_H

#include <clsScreen.h>
#include <clsError.h>
#include <clsText.h>
#include <clsBackground.h>
#include <clsEvent.h>

struct scoreStruct
{
    char name[4];
    int points;
};

class clsScore
{
    protected:
        clsScreen *screen;
        clsEvent *event;
        clsBackground *background;
        clsError error;
        clsText text;
        struct scoreStruct highscores[10];
        int scoreInt, scoreCont, l;
        char scoreItoa[5], name[4];

    public:
        int init(clsScreen*, clsEvent*, clsBackground*);
        void printScore(int, int);
        void printName(int, int);
        void scoreIncrease();
        void readHighscores();
        void saveHighscores();
        int sortHighscores(struct scoreStruct);
        void printLowScore();
        void writeHighscores();
        void getName();
        void getNameRefresh();
        void printHighscores(int);
};

#endif // CLSSCORE_H
