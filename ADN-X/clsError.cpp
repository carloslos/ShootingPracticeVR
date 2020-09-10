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
// ARCHIVO             : clsError.cpp
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
//              clase "clsError".
//
//              "clsError" consta de los metodos necesarios para administrar
//              los errores.
//
///////////////////////////////////////////////////////////////////////////////
#include <cstring>    // Libreria estandar de cadenas.
#include <iostream>   // Contiene la definicion de "cout"
#include "clsError.h" // Administrador de errores.

using namespace std;

//=============================================================================
// METODO    : clsError()
// ACCION    : Constructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsError::clsError()
{
    set(0);
}

//=============================================================================
// METODO    : void set(int err)
// ACCION    : Establece el codigo de error del sistema.
// PARAMETROS: int err --> codigo de error pasado por el sistema.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsError::set(int err)
{
  errorId=err;
}

//=============================================================================
// METODO    : void show(bool rtn)
// ACCION    : Muestra el mensaje de error asociado al codigo errorId.
// PARAMETROS: bool rtn --> determina si el mensaje termina con un "endl"
//                          false = sin endl / true = con endl.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsError::show(bool rtn=false)
{
    char msg[256];
    switch(errorId)
    {
         //--------------------------------------------------------------------
         // <000> TODO OK
         //--------------------------------------------------------------------
         case   0: strcpy(msg,"NO HUBO ERRORES");
                   break;

         //--------------------------------------------------------------------
         // <001> ERROR GENERAL DE DIRECTMEDIA
         //--------------------------------------------------------------------
         case   1: strcpy(msg,"ERROR AL INICIAR DIRECTMEDIA.");
                   break;

        //---------------------------------------------------------------------
        // <100> ERRORES DEL SUBSISTEMA DE VIDEO
        //---------------------------------------------------------------------
        case 100: strcpy(msg,"ERROR AL INICIAR SUBSISTEMA DE VIDEO.");
                  break;

        //---------------------------------------------------------------------
        // <200> ERRORES DEL SUBSISTEMA DE AUDIO
        //---------------------------------------------------------------------
        case 200: strcpy(msg,"ERROR AL INICIAR SUBSISTEMA DE AUDIO.");
                  break;

        case 201: strcpy(msg,"ERROR AL CARGAR ACHIVO WAV.");
                  break;

        case 202: strcpy(msg,"ERROR AL CARGAR ACHIVO MP3.");
                  break;

        //---------------------------------------------------------------------
        // <300> ERRORES DEL SUBSISTEMA DE TIMERS
        //---------------------------------------------------------------------
        case 300: strcpy(msg,"ERROR AL INICIAR SUBSISTEMA DE TIMER.");
                  break;

        //---------------------------------------------------------------------
        // <400> ERRORES DEL SUBSISTEMA DE CD-ROM
        //---------------------------------------------------------------------
        case 400: strcpy(msg,"ERROR AL INICIAR SUBSISTEMA DE CD-ROM.");
                  break;

        //---------------------------------------------------------------------
        // <500> ERRORES DEL SUBSISTEMA DE JOYSTICK
        //---------------------------------------------------------------------
        case 500: strcpy(msg,"ERROR AL INICIAR SUBSISTEMA DE JOYSTICK.");
                  break;

        //---------------------------------------------------------------------
        // <600> ERRORES DE IMAGENES
        //---------------------------------------------------------------------
        case 600: strcpy(msg,"ERROR AL CARGAR LA IMAGEN EN MEMORIA RAM.");
                  break;

        //---------------------------------------------------------------------
        // <700> ERRORES DE SPRITES
        //---------------------------------------------------------------------
        case 700: strcpy(msg,"ERROR AL CARGAR UNA IMAGEN EN EL SPRITE.");
                  break;

        case 701: strcpy(msg,"ERROR AL CAMBIAR INDICE DEL VECTOR DE IMAGENES.");
                  break;

        //---------------------------------------------------------------------
        // <800> ERRORES DE PANTALLAS
        //---------------------------------------------------------------------
        case 800: strcpy(msg,"ERROR AL INICIAR LA PANTALLA FISICA.");
                  break;

        case 801: strcpy(msg,"ERROR AL CREAR LA PANTALLA VIRTUAL.");
                  break;

        case 802: strcpy(msg,"ERROR AL CARGAR LA IMAGEN EN LA PANTALLA.");
                  break;


        //---------------------------------------------------------------------
        // <900> ERRORES DE TEXTO
        //---------------------------------------------------------------------
        case 900: strcpy(msg,"ERROR AL INICIAR TEXTO.");
                  break;

        case 901: strcpy(msg,"ERROR AL CARGAR ARCHIVO TTF.");
                  break;

        //---------------------------------------------------------------------
        // <1000> ERRORES DE TIMER
        //---------------------------------------------------------------------
        case 1000:strcpy(msg,"ERROR AL CARGAR TIMER.");
                  break;

    };
    cout <<msg;
    if(rtn)cout <<endl;
}

//=============================================================================
// METODO    : int get()
// ACCION    : Devuelve el codigo de error producido por el sistema.
// PARAMETROS: NADA.
// DEVUELVE  : Un entero que representa el codigo de error.
//-----------------------------------------------------------------------------
int clsError::get(){return errorId;}

//### FIN DE ARCHIVO ##########################################################
