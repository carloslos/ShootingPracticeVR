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
// ARCHIVO             : clsEvent.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsEvent".
//
//              "clsEvent" consta de los metodos necesarios para administrar
//              los eventos de teclado y mouse.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSEVENT_H
#define CLSEVENT_H

#include "adnConsts.h" // Tipos de datos del sistema adn-X.

class clsEvent
{
  // ATRIBUTOS

  protected:
    SDL_Event event;   // Registro del evento.

  // METODOS

  public:
    bool wasEvent();        // Informa si se produjo o no un evento.
    Uint8 getEventType();   // Devuelve el tipo de evento producido.
    Uint16 getKey();        // Devuelve la tecla presionada.
    SDLMod getKeyMode();    // Devuelve el estado de las teclas especiales
                            // (CAPSLOCK, NUMLOCK, CTRL, SHIFT y ALT).
    Uint8 getMouseButton(); // Devuelve el boton del mouse presionado.
    Uint16 getCursorX();    // Devuelve la coordenada x del puntero del mouse.
    Uint16 getCursorY();    // Devuelve la coordenada y del puntero del mouse.
};

#endif // CLSEVENT_H

//### FIN DE ARCHIVO ##########################################################

