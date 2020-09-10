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
// ARCHIVO             : clsDot.cpp
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
//              "clsDot".
//
//              "clsDot" consta de dos metodos que permiten administrar pixeles
//              sobre superficies.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsDot.h"

//=============================================================================
// METODO    : void set(int x,int y,rgbColor color,SDL_Surface* sup)
// ACCION    : Dibuja un punto de color en las coordenadas x e y de una
//             superficie dada.
// PARAMETROS: int x            -> coordenada x.
//             int y            -> coordenada y.
//             rgbColor color   -> color del punto.
//             SDL_Surface* sup -> superficie donde se dibujara el punto.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsDot::set(int x, int y, rgbColor color, SDL_Surface* sup)
{
  // Convierte color
  Uint32 col=SDL_MapRGB(sup->format, color.r, color.g, color.b);

  // Determina posición de inicio
  char *buffer=(char*) sup->pixels;

  // Calcula offset para y
  buffer+=sup->pitch*y;

  // Calcula offset para x
  buffer+=sup->format->BytesPerPixel*x;

  // Copia el pixel
  memcpy(buffer, &col, sup->format->BytesPerPixel);
}

//=============================================================================
// METODO    : rgbColor get(int x,int y,SDL_Surface* sup)
// ACCION    : Retorna el color de un pixel que se encuentra en las coordenadas
//             x e y de una superficie dada.
// PARAMETROS: int x            -> coordenada x.
//             int y            -> coordenada y.
//             SDL_Surface* sup -> superficie donde se leera el punto.
// DEVUELVE  : rgbColor -> componentes RGB del pixel.
//----------------------------------------------------------------------
rgbColor clsDot::get(int x, int y,SDL_Surface* sup)
{
  SDL_Color color;
  rgbColor trueColor;
  Uint32 col;

  // Determina posición de inicio
  char *buffer=(char *) sup->pixels;

  // Calcula offset para y
  buffer+=sup->pitch*y;

  // Calcula offset para x
  buffer+=sup->format->BytesPerPixel*x;

  // Obtiene el pixel
  memcpy(&col, buffer, sup->format->BytesPerPixel);

  // Descompone el color
  SDL_GetRGB(col, sup->format, &color.r, &color.g, &color.b);

  // Genera el color RGB
  trueColor.r=color.r;
  trueColor.g=color.g;
  trueColor.b=color.b;

  // Devuelve el color
  return trueColor;
}

//### FIN DE ARCHIVO ##########################################################
