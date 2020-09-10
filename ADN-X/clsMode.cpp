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
// ARCHIVO             : clsMode.cpp
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
//              clsMode".
//
//              "clsMode" consta de los metodos necesarios para administrar
//              el modo grafico.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsMode.h"

//=============================================================================
// METODO    : int init(graphicVideoMode gvm)
// ACCION    : Inicializa el subsistema de video en forma automatica.
// PARAMETROS: graphicVideoMode gvm --> resolucion de video.
//             MODOS POSIBLES: DEFAULT (800x600x16).
//                             AUTODETECT  (autodetectado).
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsMode::init(graphicVideoMode gvm=DEFAULT)
{
  const SDL_VideoInfo* videoinfo;

  sdlError=SDL_InitSubSystem(SDL_INIT_VIDEO);
  if(sdlError<0)
  {
    error.set(100); // <100> ERRORES DE SUBSISTEMA DE VIDEO
    return error.get();
  }

  if(gvm==AUTODETECT)
  {
     videoinfo=SDL_GetVideoInfo();
     scrWidth=videoinfo->current_w;
     scrHeight=videoinfo->current_h;
     scrDepth=videoinfo->vfmt->BitsPerPixel;
  }
  else
  {
    scrWidth=800;
    scrHeight=600;
    scrDepth=16;
  }

  cout << "Modo grafico iniciado correctamente." << endl;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : int init(int w, int h, int d)
// ACCION    : Inicializa el subsistema de video en forma manual.
// PARAMETROS: int w --> ancho de pantalla en pixeles.
//             int h --> alto de pantalla en pixeles.
//             int d --> profundidad de colores en bits.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsMode::init(int w, int h, int d)
{
  sdlError=SDL_InitSubSystem(SDL_INIT_VIDEO);
  if(sdlError<0)
  {
    error.set(100); // <100> ERRORES DE SUBSISTEMA DE VIDEO
    return error.get();
  }

  scrWidth=w;
  scrHeight=h;
  scrDepth=d;

  cout << "Modo grafico iniciado correctamente." << endl;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : ~clsMode()
// ACCION    : Destructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsMode::~clsMode()
{
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  cout << "El modo grafico se cerro correctamente." << endl;
}

//=============================================================================
// METODO    : void crashPrevent()
// ACCION    : Cierra todo el sistema si se produce un cuelgue.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMode::crashPrevent()
{
  atexit(SDL_Quit);
}

//=============================================================================
// METODO    : int getScrWidth()
// ACCION    : Devuelve el ancho de pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int --> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsMode::getScrWidth(){return scrWidth;}

//=============================================================================
// METODO    : int getScrHeight()
// ACCION    : Devuelve el alto de pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int --> alto en pixeles.
//-----------------------------------------------------------------------------
int clsMode::getScrHeight(){return scrHeight;}

//=============================================================================
// METODO    : int getScrDepth()
// ACCION    : Devuelve la profundidade de colores en bits
// PARAMETROS: NADA.
// DEVUELVE  : int --> profundidad en bits.
//-----------------------------------------------------------------------------
int clsMode::getScrDepth(){return scrDepth;}

//### FIN DE ARCHIVO ##########################################################

