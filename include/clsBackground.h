#ifndef CLSBACKGROUND_H
#define CLSBACKGROUND_H

#include <clsSprite.h>


class clsBackground: public clsSprite
{
    protected:
        void inherit(){};

    public:
        int init();
        void setHello();
        void setMenu();
        void setGame();
        void setExit();
        void setScore();
        void setHighscores();
        void setGoodbye();
};

#endif // CLSBACKGROUND_H
