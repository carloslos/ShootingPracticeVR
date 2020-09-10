#include "clsHello.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicializa valores necesarios para el funcionamiento de la clase
// PARAMETROS: Puntero a clase de pantalla, eventos y fondos de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsHello::init(clsScreen *scr, clsEvent *ev, clsBackground *bg)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    this->background = bg;

    return error.get();
}

//===========================================================================
// FUNCION   : run
// ACCION    : Ejecuta las acciones principales de la clase
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsHello::run()
{
    error.set(0);
    background->setHello();
    bool exit = false;
    screen->clean(BLACK);
    background->paste(screen->getPtr());
    screen->refresh();
    while(!exit)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                 keyCommand(&exit,event->getKey());
            }
        }
    }
    return error.get();
}

//===========================================================================
// FUNCION   : keyCommand
// ACCION    : Decide que accion tomar dependiendo de una tecla apretada
// PARAMETROS: Bool para salir de la pantalla y tecla apretada
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsHello::keyCommand(bool *exit, Uint16 key)
{
    error.set(0);
    switch(key)
    {
        case KEY_ESCAPE:
        case KEY_SPACE:
        case KEY_ENTER:
            *exit = true;
            break;
    }
    return error.get();
}
