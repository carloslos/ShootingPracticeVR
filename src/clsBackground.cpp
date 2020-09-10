#include "clsBackground.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Carga imagenes para usar en el programa
// PARAMETROS: Ninungo
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsBackground::init()
{
    error.set(0);
    setItems(7);
    setI(0);
    error.set(load("./ASSETS/Images/Hello.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("./ASSETS/Images/Menu.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("./ASSETS/Images/Game.png"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("./ASSETS/Images/Exit.png"));
    if(error.get()) return error.get();

    setI(4);
    error.set(load("./ASSETS/Images/Score.png"));
    if(error.get()) return error.get();

    setI(5);
    error.set(load("./ASSETS/Images/Highscores.png"));
    if(error.get()) return error.get();

    setI(6);
    error.set(load("./ASSETS/Images/Goodbye.png"));
    if(error.get()) return error.get();

    setX(0);
    setY(0);

    return error.get();
}

//===========================================================================
// FUNCION   : setHello
// ACCION    : Selecciona el fondo de pantalla de bienvenida
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setHello()
{
    setI(0);
}

//===========================================================================
// FUNCION   : setMenu
// ACCION    : Selecciona el fondo de pantalla del menu
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setMenu()
{
    setI(1);
}

//===========================================================================
// FUNCION   : setGame
// ACCION    : Selecciona el fondo de pantalla del juego
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setGame()
{
    setI(2);
}

//===========================================================================
// FUNCION   : setExit
// ACCION    : Selecciona el fondo de pantalla del cartel de salir
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setExit()
{
    setI(3);
}

//===========================================================================
// FUNCION   : setScore
// ACCION    : Selecciona el fondo de pantalla al finalizar el juego
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setScore()
{
    setI(4);
}

//===========================================================================
// FUNCION   : setHighscores
// ACCION    : Selecciona el fondo de pantalla de mejores puntajes
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setHighscores()
{
    setI(5);
}

//===========================================================================
// FUNCION   : setGoodbye
// ACCION    : Selecciona el fondo de pantalla de despedida
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsBackground::setGoodbye()
{
    setI(6);
}
