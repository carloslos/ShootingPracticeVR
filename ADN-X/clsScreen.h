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
// ARCHIVO             : clsScreen.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsScreen".
//
//              "clsScreen" consta de los metodos necesarios para administrar
//              el monitor de video.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSSCREEN_H
#define CLSSCREEN_H

#include <iostream>    // Contiene la definicion de "cout".
#include "adnConsts.h" // Tipos de datos del sistema adn-X.
#include "clsError.h"  // Administrador de errores.

using namespace std;

class clsScreen
{
  // ATRIBUTOS

  protected:
    clsError error;             // Administrador de errores.
    SDL_Surface* screenPointer; // Puntero a la imagen asignada.
    int width;                  // Ancho de la pantalla en pixeles.
    int height;                 // Alto de la pantalla en pixeles.
    rgbColor color;             // Color de fondo.
    titlebar title;      // Habilitacion de la barra de titulo.


  // METODOS
  public:
    void clean(rgbColor);          // Borra la pantalla con color por parametro
    void setColor(rgbColor);       // Establece el color de la pantalla.
    SDL_Surface* getPtr();         // Devuelve el puntero a la imagen.
    int getWidth();                // Devuelve el ancho de la pantalla.
    int getHeight();               // Devuelve el ancho de la pantalla.
    rgbColor getColor();           // Devuelve el color de la pantalla.
    int init( int,                 // Inicializa la pantalla.
              int,
              int,
              titlebar,
              uint32_t flags);

    void setTitle(const char*); // Pone titulo a la ventana.

    void refresh();       // Refresca la pantalla del monitor para que se
                          // vean los cambios.
    ~clsScreen();         // Destructor.
    titlebar getTitle();  // Informa si la barra de titulo esta habilitada.
};

#endif // CLSSCREEN_H

//### FIN DE ARCHIVO ##########################################################

