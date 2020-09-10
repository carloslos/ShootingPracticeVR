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
// ARCHIVO             : clsSprite.cpp
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
//              "clsSprite".
//
//              "clsSprite" consta de los metodos necesarios para administrar
//              sprites.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsSprite.h"

//=============================================================================
// METODO    : clsSprite()
// ACCION    : Constructor por defecto.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsSprite::clsSprite()
{
  items=1;               // Cantidad de imagenes que componen el sprite.
  i=0;                   // Primer elemento del vector de imagenes del sprite.
  x=0;                   // Coordenada x del sprite.
  y=0;                   // Coordenada y del sprite.
  transparent=BLACK;     // Color considerado transparente  en el sprite.
  opacity=255;           // Nivel de opacidad (0 = transparente / 255 = opaco).


                     // DATOS PARA DETECTAR CONTACTO CON OTRO SPRITE
  coord.x1=0;        // Coordenado x inicial del sprite local.
  coord.y1=0;        // Coordenada y inicial del sprite local.
  coord.x2=0;        // Coordenada x final del sprite local.
  coord.y2=0;        // Coordenada y final del sprite local.
  coord.x3=0;        // Coordenada x inicial del sprite externo.
  coord.y3=0;        // Coordenada y inicial del sprite externo.
  coord.x4=0;        // Coordenada x final del sprite externo.
  coord.y4=0;        // Coordenada y final del sprite externo.
  coord.w1=0;        // Ancho del sprite local.
  coord.w2=0;        // Ancho del sprite externo.
  coord.h1=0;        // Alto del sprite local.
  coord.h2=0;        // Alto del sprite externo.
  coord.xi1=0;       // Coordenada x inicial del area de contacto.
  coord.yi1=0;       // Coordenada y inicial del area de contacto.
  coord.xi2=0;       // Coordenada x final del area de contacto.
  coord.yi2=0;       // Coordenada y final del area de contacto.
  coord.aw=0;        // Ancho del area de contacto.
  coord.ah=0;        // Alto del area de contacto.
  coord.ovl=0;       // Caso de superposicion
                     // (Existen 15 casos, de 0 a 14. El caso 0 significa
                     //  que no hay contacto).

  setName("sin Nombre"); // Da nombre al sprite.
}

//=============================================================================
// METODO    : ~clsSprite()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsSprite::~clsSprite()
{
  for(int p=0; p<getItems();p++)
  {
      if(&spritePointer[p] != NULL)
      {
          delete spritePointer[p].getPtr();
          cout << "Se destruyo la imagen"
               << p
               << " del sprite "
               << getName()
               <<  endl;
      }
  }

  cout << "Se destruyeron la imagenes del sprite " << getName() <<  endl;
}

//=============================================================================
// METODO    : void setItems(int cant)
// ACCION    : Genera un vector de imagenes en memoria dinamica con la
//             cantidad de elementos pasada como parametro.
// PARAMETROS: int c -> cantidad de elementos asignados.
// DEVUELVE  : NADA.
//.............................................................................
// NOTA: Este metodo se utiliza para asignar el vector despues que se
//       construyo un objeto por defecto.
//-----------------------------------------------------------------------------
void clsSprite::setItems(int c)
{
  spritePointer = new clsImage[c];
  items=c;
}
//=============================================================================
// METODO    : void setName(const char* n)
// ACCION    : Asigna un nuevo Nombre al sprite.
// PARAMETROS: char* n -> nuevo nombre.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::setName(const char* n){strcpy(name,n);}

//=============================================================================
// METODO    : int load(const char* file)
// ACCION    : Carga un archivo de imagen en el elemento actual del
//             vector de imagenes..
// PARAMETROS: char* archivo -> cadena con el path y nombre de archivo.
// DEVUELVE  : int --> codigo de error (0 = todo bien)
//-----------------------------------------------------------------------------
int clsSprite::load(const char* file)
{
  if(spritePointer[i].load(file))
  {
      error.set(700);
      return error.get();
  }

  SDL_SetColorKey(spritePointer[i].getPtr(),
                  SDL_SRCCOLORKEY|SDL_RLEACCEL,
                  SDL_MapRGB(spritePointer[i].getPtr()->format,
                             transparent.r,
                             transparent.g,
                             transparent.b
                            )
                 );
  SDL_SetAlpha(spritePointer[i].getPtr(),SDL_SRCALPHA|SDL_RLEACCEL,255);

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : int setI(int item)
// ACCION    : Cambia el indice del vector de elementos:
// PARAMETROS: int item -> nuevo indice.
// DEVUELVE  : int -> el codigo de error relacionado con los
//             mensajes de error declarados en ClsDirectMediaError.h.
//-----------------------------------------------------------------------------
int clsSprite::setI(int item)
{

  if(item < 0 || item >= items)
  {
     error.set(701);
     return error.get();
  }

  i = item;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void paste(SDL_Surface* sup)
// ACCION    : Copia al sprite en sus propias coordenadas dentro de la
//             superficie designada en el parametro sup.
// PARAMETROS: SDL_Surface* sup  -> puntero a la superficie destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::paste(SDL_Surface* sup)
{
  rgbColor cDot;
  int W=spritePointer[i].getPtr()->w;
  int H=spritePointer[i].getPtr()->h;
  SDL_Rect area = {getX(),getY(),W,H};
  SDL_BlitSurface(spritePointer[i].getPtr(), NULL, sup,&area);
}


//=============================================================================
// METODO    : void paste(unsigned int X,unsigned int Y,SDL_Surface* sup)
// ACCION    : Copia al sprite en las coordenadas (X,Y) de la superficie
//             designada en el parametro sup.
//
// PARAMETROS: unsigned int X    -> coordenada Y de la pantalla.
//             unsigned int Y    -> coordenada X de la pantalla.
//             SDL_Surface* sup  -> puntero a la superficie destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::paste(int X,int Y,SDL_Surface* sup)
{
  rgbColor cDot;
  int W=spritePointer[i].getPtr()->w;
  int H=spritePointer[i].getPtr()->h;

  SDL_Rect area = {X,Y,W,H};
  SDL_BlitSurface(spritePointer[i].getPtr(), NULL, sup,&area);

  setX(X);
  setY(Y);
}

//=============================================================================
// METODO    : void setX(int X)
// ACCION    : Cambia la coordenada x del sprite.
// PARAMETROS: int X -> nueva coordenada x del sprite.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::setX(int X){x=X;}


//=============================================================================
// METODO    : void setY(int Y)
// ACCION    : Cambia la coordenada y del sprite.
// PARAMETROS: int Y -> nueva coordenada y del sprite.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::setY(int Y){y=Y;}

//=============================================================================
// METODO    : void setOpacity(int level)
// ACCION    : Cambia el nivel de opacidad del sprite.
// PARAMETROS: int level -> nuevo nivel de opacidad.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::setOpacity(int level)
{
  SDL_SetAlpha(spritePointer[i].getPtr(),
               SDL_SRCALPHA|SDL_RLEACCEL,level);

  opacity=level;
}

//=============================================================================
// METODO    : int getX()
// ACCION    : Devuelve la coordenada x del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de x.
//-----------------------------------------------------------------------------
int clsSprite::getX() {return x;}

//=============================================================================
// METODO    : int getY()
// ACCION    : Devuelve la coordenada y del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de y.
//-----------------------------------------------------------------------------
int clsSprite::getY() {return y;}

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho en pixeles de la imagen actual del
//             sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  cantidad de pixeles.
//-----------------------------------------------------------------------------
int clsSprite::getWidth()
{
  return spritePointer[i].getPtr()->w;
}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto en pixeles de la imagen actual del
//             sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  cantidad de pixeles.
//-----------------------------------------------------------------------------
int clsSprite::getHeight()
{
  return spritePointer[i].getPtr()->h;
}

//=============================================================================
// METODO    : int getOpacity()
// ACCION    : Devuelve el nivel de opacidad del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  Nivel de opacidad.
//-----------------------------------------------------------------------------
int clsSprite::getOpacity(){ return opacity;}

//=============================================================================
// METODO    : int getI()
// ACCION    : Devuelve el indice actual del vector de imagenes.
// PARAMETROS: NADA
// DEVUELVE  : int ->  indice actual.
//-----------------------------------------------------------------------------
int clsSprite::getI(){ return i;}


//=============================================================================
// METODO    : char* getName()
// ACCION    : Devuelve el nombre del sprite.
// PARAMETROS: NADA
// DEVUELVE  : char* ->  puntero a la cadena del nombre.
//-----------------------------------------------------------------------------
char* clsSprite::getName(){return name;};

//=============================================================================
// METODO    : clsImage* getPtr()
// ACCION    : Devuelve un puntero a la primera imagen del vector de imagenes.
// PARAMETROS: NADA
// DEVUELVE  : clsImage* ->  puntero al vector de imagenes.
//-----------------------------------------------------------------------------
clsImage* clsSprite::getPtr(){return spritePointer;}


//=============================================================================
// METODO    : clsImage* getPtr(int i)
// ACCION    : Devuelve un puntero a la imagen i del vector de imagenes.
// PARAMETROS: int i --> posicion de la imagen dentro del vector.
// DEVUELVE  : clsImage* ->  puntero a la imagen de la posicion i.
//-----------------------------------------------------------------------------
clsImage* clsSprite::getPtr(int i)
{
    if(i >= 0 && i < items) return spritePointer+i;
    return NULL;
}


//=============================================================================
// METODO    : int getItems()
// ACCION    : Devuelve la cantidad de imagenes del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int --> cantidad de imagenes
//-----------------------------------------------------------------------------
int clsSprite::getItems() {return items;}


//=============================================================================
// METODO    : void setState(tSpriteState st)
// ACCION    : Establece el estado del sprite.
// PARAMETROS: tSpriteState st -> Nuevo estado.
//                                Valores posibles: INACTIVE / ACTIVE.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::setState(tSpriteState st)
{
   state=st;
}

//=============================================================================
// METODO    : tSpriteState getState()
// ACCION    : Devuelve el estado del sprite.
// PARAMETROS:
// DEVUELVE  : tSpriteState -> estado del sprite.
//                             Valores posibles: INACTIVE / ACTIVE.
//-----------------------------------------------------------------------------
tSpriteState clsSprite::getState()
{
   return state;
}

//=============================================================================
// METODO    : bool getContact(clsSprite* spr)
// ACCION    : Desata una serie de procedimientos con el fin de detectar un
//             contacto entre el sprite local con un sprite externo.
// PARAMETROS: clsSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool ->  "true" si hay contacto y "false" si no lo hay.
//-----------------------------------------------------------------------------
bool clsSprite::getContact(clsSprite* spr)
{
  coord.ovl=0;

  findLocalValues(); // Establecer los valores del sprite local.

  findExternValues(spr);// Establecer los valores del sprite externo.

  if(getSuperposition(spr)) // Verificar superposicion de areas.
  {
    findContactValues(spr); // Encontrar puntos opacos de contacto.

    if(getMatch(spr)) // // Verificar si existe coincidencia.
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

//=============================================================================
// METODO    : void findLocalValues()
// ACCION    : Busca coordenadas iniciales, ancho y alto  del sprite local.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::findLocalValues()
{
  coord.x1=this->getX();
  coord.y1=this->getY();
  coord.w1=this->getWidth();
  coord.h1=this->getHeight();
  coord.x2=coord.x1+coord.w1;
  coord.y2=coord.y1+coord.h1;
}

//=============================================================================
// METODO    : void findExternValues(clsSprite* spr)
// ACCION    : Busca coordenadas iniciales, ancho y alto del sprite externo.
// PARAMETROS: clsSprite* spr -| puntero al sprite externo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsSprite::findExternValues(clsSprite* spr)
{
  coord.x3=spr->getX();
  coord.y3=spr->getY();
  coord.w2=spr->getWidth();
  coord.h2=spr->getHeight();
  coord.x4=coord.x3+coord.w2;
  coord.y4=coord.y3+coord.h2;
}

//=============================================================================
// METODO    : bool getSuperposition(clsSprite* spr)
// ACCION    : Determina si existe superposicion entre las areas del
//             sprite local y el sprite externo.
// PARAMETROS: clsSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool -> "true" si hay superposicion de areas y "false" si
//                     no la hay.
//-----------------------------------------------------------------------------
bool clsSprite::getSuperposition(clsSprite* spr)
{
  if( coord.x2 > coord.x3 && coord.y2 > coord.y3 &&
      coord.x4 > coord.x1 && coord.y4 > coord.y1
    )
  {
    return true;
  }
  return false;
}

//=============================================================================
// METODO    : int findContactValues(clsSprite* spr)
// ACCION    : Busca los valores del area de contacto.
// PARAMETROS: clsSprite* spr -> puntero al sprite externo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
int clsSprite::findContactValues(clsSprite* spr)
{

  coord.ovl=0;

  //---------------------------------------------------------------------------
  // CASO 01
  //---------------------------------------------------------------------------
  if(coord.x1<=coord.x3 && coord.x1<coord.x4 && coord.x2>=coord.x3 &&
     coord.x2<coord.x4 && coord.y1>=coord.y3 && coord.y1<coord.y4 &&
     coord.y2>=coord.y3 && coord.y2<coord.y4)
  {

    coord.aw=coord.x2-coord.x3; coord.ah=coord.y2-coord.y1; coord.ovl=1;

    coord.xi1=coord.w1-coord.aw; coord.yi1=0;
    coord.xi2=0                ; coord.yi2=coord.y1-coord.y3;

    coord.ovl=1;
  }

  //---------------------------------------------------------------------------
  // CASO 02
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x1 ; coord.ah=coord.y2-coord.y1; coord.ovl=2;
    coord.xi1=0;               ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3; coord.yi2=coord.y1-coord.y3;

    coord.ovl=2;
  }

  //---------------------------------------------------------------------------
  // CASO 03
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x2-coord.x1 ; coord.ah=coord.y2-coord.y3; coord.ovl=3;
    coord.xi1=0                ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=coord.x1-coord.x3; coord.yi2=0;
    coord.ovl=3;
  }

  //---------------------------------------------------------------------------
  // CASO 04
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x1  ; coord.ah=coord.y4-coord.y1; coord.ovl=4;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=4;
  }

  //---------------------------------------------------------------------------
  // CASO 05
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x3  ; coord.ah=coord.y4-coord.y3; coord.ovl=5;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=5;
  }

  //---------------------------------------------------------------------------
  // CASO 06
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y4-coord.y3; coord.ovl=6;
    coord.xi1=0                 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=coord.w2-coord.aw; coord.yi2=0;
    coord.ovl=6;
  }

  //---------------------------------------------------------------------------
  // CASO 07
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y2-coord.y3; coord.ovl=7;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=7;
  }

  //---------------------------------------------------------------------------
  // CASO 08
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y4-coord.y1; coord.ovl=8;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=0;
    coord.xi2=0                 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=8;
  }

  //---------------------------------------------------------------------------
  // CASO 09 (muy raro)
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.y2-coord.y1  ; coord.ah=coord.y2-coord.y1; coord.ovl=9;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=9;
  }

  //---------------------------------------------------------------------------
  // CASO 10 (muy raro)
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y4-coord.y3; coord.ovl=10;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=10;
  }

  //---------------------------------------------------------------------------
  // CASO 11
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x2-coord.x3   ; coord.ah=coord.y2-coord.y3; coord.ovl=11;
    coord.xi1=coord.w1-coord.aw ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=0                  ; coord.yi2=0;
    coord.ovl=11;
  }

  //---------------------------------------------------------------------------
  // CASO 12
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y2-coord.y3; coord.ovl=12;
    coord.xi1=0                 ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=coord.w2-coord.aw; coord.yi2=0;
    coord.ovl=12;
  }

  //---------------------------------------------------------------------------
  // CASO 13
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x3; coord.ah=coord.y4-coord.y1; coord.ovl=13;
    coord.xi1=coord.w1-coord.aw  ; coord.yi1=0;
    coord.xi2=0                   ; coord.yi2=coord.h2-coord.ah;
    coord.ovl=13;
  }

  //---------------------------------------------------------------------------
  // CASO 14
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y4-coord.y1; coord.ovl=14;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.w2-coord.aw; coord.yi2=coord.h2-coord.ah;
    coord.ovl=14;
  }
  return coord.ovl;
}

//=============================================================================
// METODO    : bool getMatch(clsSprite* spr)
// ACCION    : Determina si existe coincidencia de puntos opacos entre las dos
//             areas de superposicion.
// PARAMETROS: clsSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool -> "true" si hay coincidencia y "false" si no la hay
//-----------------------------------------------------------------------------
bool clsSprite::getMatch(clsSprite* spr)
{
  int xl,yl,xe,ye,xaa,yaa;
  rgbColor color;
  clsDot pixel;

   // Buscar punto opaco dentro del area de coincidencia del sprite local.
  for(yl = coord.yi1; yl < coord.yi1 + coord.ah; yl++)
  {

    for (xl = coord.xi1; xl < coord.xi1 + coord.aw ; xl++)
    {
      color=pixel.get(xl,yl,this->spritePointer[this->getI()].getPtr());

      if( color.r!=BLACK.r || color.g!=BLACK.g || color.b!=BLACK.b)
      {
        // Se encontro un punto opaco dentro del area de contacto del sprite
        // local.
        xaa=xl-coord.xi1;
        yaa=yl-coord.yi1;
        xe=coord.xi2+xaa;
        ye=coord.yi2+yaa;

        // Verificar opacidad el punto coincidente del sprite externo
        color=pixel.get(xe,ye,spr->getPtr()->getPtr());
        if(color.r!=BLACK.r || color.g!=BLACK.g || color.b!=BLACK.b)
        {
          // Hay coincidencia de puntos opacos entre las dos areas.
          return true;
        }
      }
    }
  }
  return false;
}

//### FIN DE ARCHIVO ##########################################################
