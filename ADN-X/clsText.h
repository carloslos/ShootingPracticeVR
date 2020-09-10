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
// ARCHIVO             : clsText.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsText".
//
//              "clsText" consta de los metodos necesarios para administrar
//              textos en modo grafico.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSTEXT_H
#define CLSTEXT_H

#include <iostream>    // Contiene la definicion de "cout".
#include "adnConsts.h" // Tipos de datos del sistema adn-X.
#include "clsError.h"  // Administrador de errores.

using namespace std;

class clsText
{
  // ATRIBUTOS

  protected:
    clsError error;              // Administrador de errores
    char fontName[256];          // Nombre de la fuente atual.
    char fontFile[256];          // Nombre del archivo actual.
    SDL_Surface* frame;          // Marco del texto;
    TTF_Font* font;              // Puntero al archivo de fuente.
    rgbColor fontColor;          // Color de la fuente
    rgbColor backColor;          // Color fondo. Por defecto PINK.
    tFontStyle style;            // Estilo de la fuente.
    tFontTexture texture;        // Textura de la fuente.
    int Height;                  // Altura total del texto;
    int Width;                   // Ancho total del texto;

  // METODOS

  public:
    int init();                          // Inicializa el modo texto para el
                                         // modo grafico.
    ~clsText();                          // Destructor.
    int  loadFont(const char*, int);     // Carga un archivo fuente tipo ttf.
    void setFontColor(rgbColor);         // Cambia el color de la fuente.
    void setBackColor(rgbColor);         // Cambia el color del fondo.
    void setStyle(tFontStyle);           // Cambia el estilo de la fuente.
    void setTexture(tFontTexture);       // Cambia la textura de la fuente.
    int setFontFile(const char*);        // Cambia path y nombre de archivo ttf.
    void write(const char*,int,          // Escribe un texto en una pantalla.
               int,SDL_Surface*);
    void writeBlended(const char*, int,  // Escribe el texto blendeado en una
                      int, SDL_Surface*);// pantalla.
    void centredWrite(const char*,int,   // Escribe un texto centrado en una
                      SDL_Surface*);     // pantalla.
    rgbColor getFontColor();             // Devuelve el color de la fuente.
    rgbColor getBackColor();             // Devuelve el color del fondo.
    tFontStyle getStyle();               // Devuelve el estilo.
    tFontTexture getTexture();           // Devuelve la textura.
    int getHeight();                     // Devuelve la altura.
    int getWidth();                      // Devuelve el ancho.
    char* getFontName();                 // Devuelve el nombre de la fuente.
    char* getFontFile();                 // Devuelve el nombre del archivo.

};

#endif // CLSTEXT_H

//### FIN DE ARCHIVO ##########################################################

