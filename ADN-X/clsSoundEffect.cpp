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
// ARCHIVO             : clsSoundEffect.cpp
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
// DESCRIPCION: Este archivo contiene la definicionde los metodos de la clase
//              "clsSoundEffect".
//
//              "clsSoundEffect" consta de los metodos necesarios para
//              administrar efectos de sonido.
//
//              Los archivos de efectos deben ser de tipo .wav.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsSoundEffect.h"

//=============================================================================
// METODO    : void setName(const char* n)
// ACCION    : Asigna un nuevo Nombre al objeto.
// PARAMETROS: char* n -> nuevo nombre.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSoundEffect::setName(const char* n)
{
    strcpy(name,n);
}

//=============================================================================
// METODO    : char* getName()
// ACCION    : Devuelve el nombre del objeto.
// PARAMETROS: NADA
// DEVUELVE  : char* ->  puntero a la cadena del nombre.
//-----------------------------------------------------------------------------
char* clsSoundEffect::getName()
{
    return name;
}

//=============================================================================
// METODO    : int loadEffect(const char* path)
// ACCION    : Lee un archivo wav y se lo asigna al puntero effect.
// PARAMETROS: const char* path --> ruta y nombre del archivo wav.
// DEVUELVE  : int --> codigo de error. (NULL = error).
//-----------------------------------------------------------------------------
int clsSoundEffect::loadEffect(const char* path)
{
    error.set(0);
    effect = Mix_LoadWAV(path);
    if(effect==NULL) error.set(201);
    return error.get();
}

//=============================================================================
// METODO    : void playEffect(int ch, int t)
// ACCION    : Ejecuta un efecto de sonido.
// PARAMETROS: int ch --> canal;
//             int t  --> cantidad de repeticiones:
//                            0 = normal
//                            -1 = indefinidamente.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSoundEffect::playEffect(int ch,int t)
{
    channel=ch;
    Mix_PlayChannel(ch,effect,t);
}

//=============================================================================
// METODO    : void stopEffect()
// ACCION    : Detiene un efecto de sonido.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSoundEffect::stopEffect()
{
    Mix_HaltChannel(channel);
}

//=============================================================================
// METODO    : void closeEffect()
// ACCION    : Libera la memoria tomada para el efecto.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSoundEffect::closeEffect()
{
    Mix_FreeChunk(effect);
}

