#include "clsSPE.h"

//===========================================================================
// FUNCION   : sortHighscoes
// ACCION    : Guarda o no un puntaje entre los 10 mejores y los ordena
// PARAMETROS: Puntaje a guardar si esta entre los 10 mejores puntajes
// DEVUELVE  : Posicion del vector en que se guardo el puntaje, -1 si no se guardo
//---------------------------------------------------------------------------
int clsSPE::init()
{
    error.set(0);
    error.set(mode.init(842,630,16));
    if(error.get())return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get())return error.get();

    screen.setTitle("Shooting Practice VR");

    error.set(background.init());
    if(error.get())return error.get();

    error.set(hello.init(&screen, &event, &background));
    if(error.get())return error.get();

    error.set(menu.init(&screen, &event, &background));
    if(error.get())return error.get();

    error.set(goodbye.init(&screen, &event, &background));
    if(error.get())return error.get();

    error.set(musicAudio.init());
    if(error.get())return error.get();
    error.set(music.loadMusic("./ASSETS/Sounds/TrueSurvivor.mp3"));
    if(error.get())return error.get();

    return error.get();
}

//===========================================================================
// FUNCION   : run
// ACCION    : Ejecuta las acciones principales de la clase
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsSPE::run()
{
    error.set(0);

    music.playMusic(-1);

    error.set(hello.run());
    if(error.get())return error.get();

    error.set(menu.run());
    if(error.get())return error.get();

    error.set(goodbye.run());
    if(error.get())return error.get();

    musicAudio.closeAudio();

    return error.get();
}

