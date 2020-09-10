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
// ARCHIVO             : clsSprite.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsSprite".
//
//              "clsSprite" consta de los metodos necesarios para administrar
//              sprites.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSSPRITE_H
#define CLSSPRITE_H

#include <iostream>    // Contiene la definicion de "cout".
#include <cstring>     // Administracion de cadenas de caracteres.
#include "adnConsts.h" // Tipos de datos del sistema adn-X.
#include "clsError.h"  // Administrador de errores.
#include "clsDot.h"    // Administrador de pixeles.
#include "clsImage.h"  // Administrador de imagenes.
#include "clsDot.h"    // Administrador de pixeles.
#include "clsScreen.h" // Administrador de pantalla.

using namespace std;

class clsSprite
{
   protected:
    clsError error;           // Administrador de errores.
    clsImage* spritePointer;  // Puntero al vector de imagenes.
    int items;                // Cantidad total de items del vector de imagenes.
    char name[30];            // Nombre del sprite.
    int i;                    // Elemento actual dentro del vector de imagenes.
    int x;                    // coordenada x del sprite.
    int y;                    // coordenada y del sprite.
    int opacity;              // Grado de opacidad de las imagenes.
    rgbColor transparent ;    // Color asignado como transparente.
    tSpriteState state;       // Estado del sprite.
    clsDot dot;               // Administrador de pixeles.

    tCoord coord;             // Estructura con datos de contacto.

  protected:
    virtual void inherit()=0;     // Convierte a la clase en abstracta.
    void findLocalValues();       // Busca coordenadas iniciales,
                                  // ancho y alto del sprite local.

    void findExternValues(clsSprite*); // Busca coordenadas iniciales,
                                       // ancho y alto del sprite externo.

    int findContactValues(clsSprite*);// Busca valores del area de
                                      // contacto.

    bool getSuperposition(clsSprite*);// Detecta si hay superposicion de
                                      // areas entre el sprite local y
                                      // un sprite externo.

    bool getMatch(clsSprite*);        // Detecta puntos de coincidencia
                                      // dentro del area de contacto.

  public:
    clsSprite();                   // Constructor por defecto.
    virtual ~clsSprite();          // Destructor implicito.
    int load(const char*);         // Carga una imagen en el elemento actual
                                   // del sprite
    void paste(SDL_Surface*);      // Copia el sprite en sus propias coordenadas
                                   // sobre la superficie destino.


    void paste(int,                // Copia el sprite en las coordenadas x, y de
               int,                // la superficie destino.
               SDL_Surface*);

    void setName(const char*);     // Pone un nuevo nombre al sprite.
    void setItems(int);            // Asigna un vector de imagenes a un objeto
                                   // que aun no lo tiene.
    int setI(int);                 // Cambia el indice del vector de imagenes.
    void setX(int);                // Cambia la coordenada x del sprite.
    void setY(int);                // Cambia la coordenada y del sprite.
    void setOpacity(int);          // Cambia el nivel de opacidad del sprite.
    void setState(tSpriteState);   // Establece el estado del sprite.

    char* getName();               // Devuelve el nombre del sprite.
    int getX();                    // Devuelve la coordenada x del sprite.
    int getY();                    // Devuelve la coordenada y del sprite.
    int getWidth();                // Devuelve el ancho de la imagen actual.
    int getHeight();               // Devuelve el ancho de la imagen actual.
    int getOpacity();              // Devuelve el nivel de opacidad del sprite.
    int getI();                    // Devuelve el indice actual del vector de
                                   // imagenes.
    clsImage* getPtr();            // Devuelve un puntero al vector de imagenes.
    clsImage* getPtr(int);         // Devuelve un puntero a la imagen i del vector.
    int getItems();                // Devuelve el total de imagenes.
    tSpriteState getState();       // Devuelve el estado del sprite.

    bool getContact(clsSprite*);   // Detecta contacto del sprite LOCAL con otro
                                   // sprite externo.
};

#endif // CLSSPRITE_H

//### FIN DE ARCHIVO ##########################################################

