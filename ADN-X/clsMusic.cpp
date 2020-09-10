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
// ARCHIVO             : clsMusic.cpp
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
//              musica.
//
//              Nota: Los archivos deben ser de tipo mp3.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsMusic.h"

//=============================================================================
// METODO    : void setName(const char* n)
// ACCION    : Asigna un nuevo Nombre al objeto.
// PARAMETROS: char* n -> nuevo nombre.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMusic::setName(const char* n)
{
    strcpy(name,n);
}

//=============================================================================
// METODO    : char* getName()
// ACCION    : Devuelve el nombre del objeto.
// PARAMETROS: NADA
// DEVUELVE  : char* ->  puntero a la cadena del nombre.
//-----------------------------------------------------------------------------
char* clsMusic::getName()
{
    return name;
}

//=============================================================================
// METODO    : int loadMusic(const char* path)
// ACCION    : Lee un archivo mp3 y se lo asigna al puntero music.
// PARAMETROS: const char* path --> ruta y nombre del archivo mp3.
// DEVUELVE  : int --> codigo de error. (NULL = error).
//-----------------------------------------------------------------------------
int clsMusic::loadMusic(const char* path)
{
    error.set(0);
    music = Mix_LoadMUS(path);
    if(music==NULL) error.set(202);
    return error.get();
}

//=============================================================================
// METODO    : void playMusic(int t)
// ACCION    : Ejecuta un efecto de sonido.
// PARAMETROS: int t  --> cantidad de repeticiones:
//                            0 = normal
//                            -1 = indefinidamente.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMusic::playMusic(int t)
{
    Mix_PlayMusic(music,t);
}

//=============================================================================
// METODO    : void stopMusic()
// ACCION    : Detiene un archivo de musica.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMusic::stopMusic()
{
    Mix_HaltMusic();
}

//=============================================================================
// METODO    : void closeMusic()
// ACCION    : Libera la memoria tomada para el archivo de musica.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMusic::closeMusic()
{
    Mix_FreeMusic(music);

}

//### FIN DE ARCHIVO ##########################################################
