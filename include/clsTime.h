#ifndef CLSTIME_H
#define CLSTIME_H

#include <clsTimer.h>
#include <clsScreen.h>
#include <clsError.h>
#include <clsText.h>

class clsTime
{
    protected:
        clsScreen *screen;
        clsTimer timer;
        clsError error;
        clsText text;
        char timeString[20];
        char timeItoa[5];
        int timeLeft, timeLimit, t;

    public:
        int init(clsScreen*, int);
        int run();
        void pause();
        void printTime();
        int readyTimer();
        int getTime();
};

#endif // CLSTIME_H
