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
// ARCHIVO             : clsScreen.cpp
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
//              "clsScreen".
//
//              "clsScreen" consta de los metodos necesarios para administrar
//              el monitor de video.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsScreen.h"

//=============================================================================
// METODO    : void clean(rgbColor bc).
// ACCION    : Borra la pantalla con color pasado por parametro.
// PARAMETROS: rgbColor bc -> color para borrar.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::clean(rgbColor bc=BLACK)
{
  uint32_t background = SDL_MapRGB(screenPointer->format,bc.r,bc.g,bc.b);
  SDL_FillRect(screenPointer, NULL, background);
}

//=============================================================================
// METODO    : void setColor(rgbColor bc).
// ACCION    : Cambia el color de la pantalla.
// PARAMETROS: rgbColor bc ->  nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::setColor(rgbColor bc)
{
  SDL_MapRGB(screenPointer->format,bc.r,bc.g,bc.b);
}

//=============================================================================
// METODO    : SDL_Surface* getPtr().
// ACCION    : Devuelve un puntero a la superficie de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Surface* -> puntero a la superficie.
//-----------------------------------------------------------------------------
SDL_Surface* clsScreen::getPtr() { return screenPointer;}

//=============================================================================
// METODO    : int getWidth().
// ACCION    : Devuelve el ancho en pixeles de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : int -> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsScreen::getWidth(){return width;}

//=============================================================================
// METODO    : int getHeight().
// ACCION    : Devuelve el alto en pixeles de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : int -> alto en pixeles.
//-----------------------------------------------------------------------------
int clsScreen::getHeight(){return height;}

//=============================================================================
// METODO    : rgbColor getColor().
// ACCION    : Devuelve el color de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : rgbColor -> color de pantalla.
//-----------------------------------------------------------------------------
rgbColor clsScreen::getColor(){return color;}
//=============================================================================
// METODO    : int init(unsigned int anch,unsigned int alt,
//                      unsigned int bpp,bool barra,Uint32_t flags)
// ACCION    : Inicializa la pantalla fisica (monitor).
// PARAMETROS: unsigned int w -> Ancho de la pantalla en pixeles.
//             unsigned int h -> Alto de la pantalla en pixeles.
//             unsigned int d -> Profundidad de color en bits.
//                               VALORES POSIBLES: 8, 16, 32 y 64.
//             titlebar bar   -> indicador de habilitacion de la barra de
//                               titulo.
//                               VALORES POSIBLES: ENABLED
//                                                 DISABLED
//             Uint32_t flags    -> tipos de entorno para la pantalla.
//             ----------------------------------------------------------------
//             |                VALORES POSIBLES PARA FLAGS
//             |---------------------------------------------------------------
//             | ASINCRONIC     | Habilita  el volcado asincronico  para
//             |                | la pantalla. Esto ralentiza el volcado
//             |                | en  maquinas  con  una  sola  CPU pero
//             |                | aprovecha   las  caracteristicas  del
//             |                | doble corazon.
//             |----------------|----------------------------------------------
//             | EMULATED       | En caso de no poder inicializar el entorno
//             |                | con la profundidad de color estipulada, per-
//             |                | mite hacerlo en algun modo compatible.
//             |----------------|----------------------------------------------
//             | FULLSCREEN     | Hailita la pantalla completa. Esto no
//             |                | siempre es posible.
//             |----------------|----------------------------------------------
//             | RESIZABLE      | Genera un entorno de ventana redimensionable.
//-----------------------------------------------------------------------------
// DEVUELVE: int --> codigo de error (0 = todo bien.).
//-----------------------------------------------------------------------------
int clsScreen::init(int w, int h, int d,
                    titlebar bar, uint32_t flags)
{
  if(flags)
  {
    screenPointer = SDL_SetVideoMode(w,h,d,HARDWARE|DOUBLEBUFFER|flags);
  }
  else
  {
    screenPointer = SDL_SetVideoMode(w,h,d,HARDWARE|DOUBLEBUFFER);
  }
  if (screenPointer==NULL)
  {
    error.set(800);
    return error.get();
  }

  title = bar;
  width  = w;
  height  = h;
  color = BLACK;

  cout << "Monitor de video iniciado correctamente." << endl;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void setTitle(const char* t).
// ACCION    : Si la barra de titutlo esta habilitada, le pone el titulo
//             pasado como parametro.
//             cambios.
// PARAMETROS: const char* t -> titulo nuevo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::setTitle(const char* t)
{
  if(title==ENABLED) SDL_WM_SetCaption(t, NULL);
}

//=============================================================================
// METODO    : void refresh().
// ACCION    : Refresca la pantalla del monitor para que se vean los
//             cambios.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::refresh(){SDL_Flip(screenPointer);}

//=============================================================================
// METODO    : titlebar getTitle().
// ACCION    : Devuelve el estado de la barra de titutlo.
// PARAMETROS: NADA.
// DEVUELVE  : titlebar -> ENABLE = true / DESABLE = false
//-----------------------------------------------------------------------------
titlebar clsScreen::getTitle(){return title;}


//=============================================================================
// METODO    : ~clsScreen()
// ACCION    : Destructor.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsScreen::~clsScreen()
{
  if(screenPointer != NULL) SDL_FreeSurface(screenPointer);
  cout << "Monitor de video cerrado correctamente." << endl;
}

//### FIN DE ARCHIVO ##########################################################
