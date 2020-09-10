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
// ARCHIVO             : clsAudio.cpp
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
//              "clsAudio".
//
//              "clsAudio" consta de los metodos necesarios para administrar
//              el dispsitivo de audio.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsAudio.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa el subsistema de audio.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsAudio::init()
{
  sdlError=SDL_InitSubSystem(SDL_INIT_AUDIO);
  if(sdlError<0)
  {
    error.set(200); // <200> ERRORES DE SUBSISTEMA DE AUDIO
    return error.get();
  }

  frecuence = 22050; // Maximo que percibe el oido humano.
  channels  = 2;     // Estereo
  buffer    = 4096;
  format    = AUDIO_S16;

  channel=0;


  error.set(Mix_OpenAudio(frecuence, format, channels, buffer));
  if(error.get()) return error.get();

  cout << "Sistema de audio iniciado correctamente." << endl;
  return error.get();
}

//=============================================================================
// METODO    : void closeAudio()
// ACCION    : Cierra el dispositivo de audio.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsAudio::closeAudio()
{
    Mix_CloseAudio();
    cout << "Sistema de audio finalizado correctamente." << endl;
}

//### FIN DE ARCHIVO ##########################################################
