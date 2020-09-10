//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//                @@@@@@@           @    @  @@@@@        @@@  @@@            //
//               @      @           @    @@@    @@         @  @              //
//                @@@@@@@    @@@@@@@@    @       @          @@               //
//              @@      @   @@      @    @   14  @   @@@@   @@               //
//              @     @@@   @     @@@    @   11  @         @  @              //
//               @@@@@  @    @@@@@  @    @   12  @       @@@  @@@            //
//                                                                           //
//#############################################################################
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Avis Software es marca registrada.
//
// Este programa es software libre; puede redistribuirlo o modificarlo bajo los
// terminos de la Licencia Publica General de GNU tal como se publica por la
// Free Software Foundation; ya sea la version 3 de la Licencia, o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza de que le sea util, pero SIN
// NINGUNA GARANTIA; sin incluso la garantia implicita de MERCANTILIDAD o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU
// junto con este programa, si no es asi, escriba a la Free Software Foundation,
// Inc, 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.
//=============================================================================
// Que es Avis adn-X
//
//     Avis adn-X es un sistema de librerias de clases desarrolladas en c++, y
//     basadas en las SDL de Sam Lantinga.
//
//     El objetivo de adn-X, es introducir a los alumnos en la OOP (programa-
//     cion orientada a objeto.
//
//     Avis adn-X es un producto registrado de Avis SOFTWARE.
//
//#############################################################################
// ARCHIVO             : clsTimer.cpp
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : v. 14.11 estable.
// FECHA DE CREACION   : 12/11/2014.
// ULTIMA ACTUALIZACION: 12/11/2014.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la definicion de los metodos de la clase
//              "clsTimer".
//
//              "clsTimer" consta de los metodos necesarios para administrar
//              el clock y las pausas.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsTimer.h"

//=============================================================================
// METODO    : int getTicks()
// ACCION    : Devuelve la cantidad de milisegundos transcurridos desde el
//             momento en que se inicializo el modo grafico.
// PARAMETROS: NADA.
// DEVUELVE  : int -> cantidad de milisegundos.
//-----------------------------------------------------------------------------
int clsTimer::getTicks()
{
  return (int) SDL_GetTicks();
}

//=============================================================================
// METODO    : void wait(int mls)
// ACCION    : Hace una pausa de la cantidad de milisegundos establecidos como
//             parametro.
// PARAMETROS: int mls -> cantidad de millisegundos de duracion de la pausa.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::wait(int mls)
{
  SDL_Delay(mls);
}

//=============================================================================
// METODO    : void start()
// ACCION    : Pone en marcha el timer.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::start()
{
  initialtime=getTicks();
}

//=============================================================================
// METODO    : void update()
// ACCION    : Actualiza el tiempo transcurrido desde la puesta en marcha.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::update()
{
  now = getTicks() - initialtime;
}

//=============================================================================
// METODO    : int getState()
// ACCION    : Devuelve el estado actual del timer.
// PARAMETROS: NADA.
// DEVUELVE  : int -> diferencia entre tiempoActual y tiempoInicial.
//-----------------------------------------------------------------------------
int clsTimer::getState()
{
  update();
  return now;
}

//=============================================================================
// METODO    : void waitFor(Uint16 t)
// ACCION    : Hace una pausa hasta que se presiona una tecla pasada como para-
//             metro.
// PARAMETROS: Uint16 -> Tecla que debe ser presionada para terminar la pausa.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::waitForKey(Uint16 t)
{
    bool end=false;
    Uint16 key;
    do
    {
       if(event.wasEvent())
       {
            if(event.getEventType()==KEY_PRESSED)
            {
                key=event.getKey();
                if(key==t)
                {
                    end=true;
                }
            }
       }
    } while(!end);
}

//### FIN DE ARCHIVO ##########################################################
