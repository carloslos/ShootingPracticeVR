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
// ARCHIVO             : clsImage.cpp
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
//              "clsImage".
//
//              "clsImage" consta de los metodos necesarios para administrar
//              las imagenes.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsImage.h"

//=============================================================================
// METODO    : SDL_Surface getPtr()
// ACCION    : Devuelve un puntero a la imagen.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Surface* -> puntero a la imagen.
//-----------------------------------------------------------------------------
SDL_Surface* clsImage::getPtr(){return imagePointer;};

//=============================================================================
// METODO    : int load(const char* archivo)
// ACCION    : Carga un archivio de imagen en memoria RAM.
// PARAMETROS: char* archivo -> cadena con el path y nombre de archivo.
// DEVUELVE  : int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsImage::load(const char* archivo)
{
  imagePointer = IMG_Load(archivo);
  if(imagePointer == NULL)
  {
    error.set(600);
    return error.get();
  }

  SDL_SetColorKey(imagePointer,
                  SDL_SRCCOLORKEY|SDL_RLEACCEL,
                  SDL_MapRGB(imagePointer->format,PINK.r,PINK.g,PINK.b));

  SDL_SetAlpha(imagePointer,SDL_SRCALPHA|SDL_RLEACCEL,255);

  error.set(0);
  return error.get();
};

//=============================================================================
// METODO    : void unload()
// ACCION    : Destructor explicito.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsImage::unload()
{
  if(imagePointer) SDL_FreeSurface(imagePointer);
};

//=============================================================================
// METODO    : ~clsImage()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsImage::~clsImage()
{
  if(imagePointer) delete imagePointer;
  if(imagePointer != NULL) SDL_FreeSurface(imagePointer);
};

//### FIN DE ARCHIVO ##########################################################
