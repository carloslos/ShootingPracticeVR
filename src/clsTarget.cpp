#include "clsTarget.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicializa valores para el funcionamiento de la clase
// PARAMETROS: Puntero a clase de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsTarget::init(clsScreen *scr)
{
    error.set(0);
    this->screen = scr;
    setItems(1);
    setI(0);

    error.set(load("./ASSETS/Images/Target PS.png"));
    if(error.get()) return error.get();

    status=false;
    x=y=0;

    random.init();

    return error.get();
}

//===========================================================================
// FUNCION   : create
// ACCION    : Muetra un blanco por pantalla si es que no existe uno
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsTarget::create()
{
    if(status==false)
    {
        do
        {
            tx=random.getNumber(748)+17;
        }
        while(abs(x-tx)<=62);
        do
        {
            ty=random.getNumber(379)+18;
        }
        while(abs(y-ty)<=62);
        x=tx;
        y=ty;
        status=true;
    }
    setX(x);
    setY(y);
    paste(screen->getPtr());
    screen->refresh();
}

//===========================================================================
// FUNCION   : destroy
// ACCION    : Elimina el blanco en pantalla
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsTarget::destroy()
{
    status=false;
}

//===========================================================================
// FUNCION   : getStatus
// ACCION    : Indica si hay un blanco en pantalla o no
// PARAMETROS: Ninguno
// DEVUELVE  : Un bool que sera true si existe un blanco, false en caso contrario
//---------------------------------------------------------------------------
bool clsTarget::getStatus()
{
    return status;
}

//===========================================================================
// FUNCION   : getX
// ACCION    : Devuelve la coordenada X del blanco
// PARAMETROS: Ninguno
// DEVUELVE  : Un int con la coordenada X
//---------------------------------------------------------------------------
int clsTarget::getX()
{
    return x;
}

//===========================================================================
// FUNCION   : getY
// ACCION    : Devuelve la coordenada Y del blanco
// PARAMETROS: Ninguno
// DEVUELVE  : Un int con la coordenada Y
//---------------------------------------------------------------------------
int clsTarget::getY()
{
    return y;
}
