#include "clsTime.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicia valores necesarios para el funcionamiento de la clase
// PARAMETROS: Puntero a clase de pantalla y un int que contiene el tiempo deseado
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsTime::init(clsScreen *scr, int t)
{
    this->screen = scr;

    error.set(text.init());
    if(error.get())return error.get();

    this->t=t;
    timer.start();

    return error.get();
}

//===========================================================================
// FUNCION   : run
// ACCION    : Establece el tiempo al que se tiene que llegar para que transcurra el tiempo deseado
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsTime::run()
{
    text.setFontColor(CYAN);
    error.set(text.loadFont("FONTS/VT323.ttf",50));
    if(error.get())return error.get();
    timeLimit=t+timer.getTicks()/1000;
    return error.get();
}

//===========================================================================
// FUNCION   : printTime
// ACCION    : Muestra por pantalla el tiempo restante
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsTime::printTime()
{
    strcpy(timeString, "TIME: ");
    itoa(timeLeft, timeItoa, 10);
    strcat(timeString, timeItoa);
    text.write(timeString, 152, 528, screen->getPtr());
}

//===========================================================================
// FUNCION   : pause
// ACCION    : Restablece el tiempo al que se tiene que llegar para que transcurra el tiempo deseado
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsTime::pause()
{
    timeLimit=timer.getTicks()/1000+timeLeft;
}

//===========================================================================
// FUNCION   : readyTimer
// ACCION    : Muestra por pantalla un timer para prepararse al juego
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsTime::readyTimer()
{

    text.setFontColor(RED);
    error.set(text.loadFont("FONTS/VT323.ttf",120));
    if(error.get())return error.get();
    char c[2];
    for(int i=3; i>0; i--)
    {
        screen->clean(BLACK);
        itoa(i, c, 10);
        text.centredWrite(c, 250, screen->getPtr());
        screen->refresh();
        timer.wait(600);
    }
    text.setFontColor(CYAN);
    error.set(text.loadFont("FONTS/VT323.ttf",50));
    if(error.get())return error.get();
}

int clsTime::getTime()
{
    timeLeft=timeLimit-timer.getTicks()/1000;
    return timeLeft;
}
