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
// ARCHIVO             : clsMusic.h
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
// DESCRIPCION: Este archivo contiene los encabezados de la clase "clsMixer".
//
//              "clsMusic" consta de los metodos necesarios para administrar
//              efectos de sonido y musica.
//
//              Los archivos de deben ser de tipo .mp3.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSMUSIC_H
#define CLSMUSIC_H

#include <iostream>    // Contiene la definicion de "cout".
#include "adnConsts.h" // Tipos de datos del sistema adn-X.
#include "clsError.h"  // Administrador de errores.

using namespace std;

class clsMusic
{
    // ATRIBUTOS

    protected:
      clsError error;     // Administrador de errores.
      char name[80];      // Nombre del objeto.
      Mix_Music *music;   // Puntero al archivo de musica.

    // METODOS

    public:
      int loadMusic(const char*); // Carga un archivo de musica (tipo mp3).
      void playMusic(int);        // Ejecuta un archivo de musica.
      void stopMusic();           // Detiene la musica.
      void closeMusic();          // Libera la memoria tomada para la musica.
      void setName(const char*);  // Establece el nombre del objeto.
      char* getName();            // Devuelve el nombre del objeto.
};

#endif // CLSMUSIC_H

//### FIN DE ARCHIVO ##########################################################


