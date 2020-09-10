#include "clsHit.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicia valores necesarios para el funcionamiento de la clase
// PARAMETROS: Puntero a clase de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsHit::init(clsScreen *scr)
{
    error.set(0);
    this->screen = scr;
    setItems(17);
    char n[3];
    char path[30];
    for(int i=0; i<16; i++)
    {
        setI(i);
        itoa(i, n, 10);
        strcpy(path, "./ASSETS/Images/Hit/");
        strcat(path, n);
        strcat(path, ".png");
        error.set(load(path));
        if(error.get()) return error.get();
    }
    return error.get();
}

//===========================================================================
// FUNCION   : hit
// ACCION    : Muestra por pantalla un efecto de impacto
// PARAMETROS: Coordenadas x e y para imprimir
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsHit::hit(int x, int y)
{
    setX(x-20);
    setY(y-20);
    for(int i=1; i<16; i++)
    {
        setI(0);
        paste(screen->getPtr());
        setI(i);
        paste(screen->getPtr());
        screen->refresh();
        timer.wait(10);
    }
}
