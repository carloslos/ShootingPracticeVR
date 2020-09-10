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
// ARCHIVO             : clsEvent.cpp
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
// DESCRIPCION: Este archivo contiene las definiciones de los metodos de la
//              clase "clsEvent".
//
//              "clsEvent" consta de los metodos necesarios para administrar
//              los eventos de teclado y mouse.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsEvent.h"

//=============================================================================
// METODO    : bool wasEvent()
// ACCION    : Informa si se produjo o no un evento.
// PARAMETROS: NADA.
// DEVUELVE  : bool -> "true" si hubo evento o "false" si no lo hubo.
//-----------------------------------------------------------------------------
bool clsEvent::wasEvent()
{
  if (SDL_PollEvent(&event))
  {
    return true;
  }
  return false;
}

//=============================================================================
// METODO    : Uint8 getEvenType()
// ACCION    : Informa el tipo de evento producido.
// PARAMETROS: NADA.
// DEVUELVE  : Uint8 -> tipo de evento SDL producido.
//-----------------------------------------------------------------------------
Uint8 clsEvent::getEventType() {return event.type;}

//=============================================================================
// METODO    : Uint16 getKey()
// ACCION    : Informa la tecla presionada.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 --> Codigo ASCII de la tecla presionada.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getKey()
{
    return (Uint16)event.key.keysym.sym;
}

//=============================================================================
// METODO    : SDLMod getKeyMode()
// ACCION    : Informa el estado de las teclas especiales (CAPSLOCK, NUMLOCK,
//             CTRL, SHIFT y ALT).
// PARAMETROS: NADA.
// DEVUELVE  : SDLMod -> Estado SDL de la tecla especial.
//-----------------------------------------------------------------------------
SDLMod clsEvent::getKeyMode() {return event.key.keysym.mod;}

//=============================================================================
// METODO    : Uint8 getMouseButtom()
// ACCION    : Informa el boton del mouse presionado.
// PARAMETROS: NADA.
// DEVUELVE  : Uint8 -> boton presionado.
//-----------------------------------------------------------------------------
Uint8 clsEvent::getMouseButton() {return event.button.button;}

//=============================================================================
// METODO    : Uint16 getCursorX()
// ACCION    : Informa la coordenada x del puntero del mouse.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 -> coordenada x.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getCursorX() {return event.button.x;}

//=============================================================================
// METODO    : Uint16 getCursorY()
// ACCION    : Informa la coordenada y del puntero del mouse.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 -> coordenada x.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getCursorY() {return event.button.y;}

//### FIN DE ARCHIVO ##########################################################
