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
// ARCHIVO             : clsText.cpp
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
//              "clsText".
//
//              "clsText" consta de los metodos necesarios para administrar
//              textos en modo grafico.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsText.h"

//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa el uso de texto en modo grafico.
//             VALORES POR DEFECTO: estilo     -> NORMAL.
//                                  textura    -> SOLID.
//                                  ancho      -> 20.
//                                  alto       -> 20.
//                                  fontColor  -> BLACK.
//                                  backColor  -> GRAY.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error ( 0 = todo bien)
//-----------------------------------------------------------------------------
int clsText::init()
{
  if(TTF_Init() < 0)
  {
    error.set(900);
    return error.get();
  }

  style=NORMAL;
  texture=SOLID;
  Height=20;
  Width=20;
  fontColor=BLACK;
  backColor=GRAY;

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    :  ~clsText()
// ACCION    : Destructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsText::~clsText()
{
  cout << "El texto " << getFontFile() << " se cerro correctamente." << endl;
}

//=============================================================================
// METODO    : int loadFont(char* file, int size)
// ACCION    : Carga un archivo de fuente tipo ttf..
// PARAMETROS: char* file -> Ruta y nombre del archivo ttf.
//             int size   -> Tamanio de la fuente.
// DEVUELVE  : int --> codigo de error ( 0 = todo bien).
//-----------------------------------------------------------------------------
int clsText::loadFont(const char* file, int size)
{
  char aux[256];
  int i,j;

  font=TTF_OpenFont(file,size);
  if(font==NULL)
  {
    error.set(901);
    return error.get();
  }

  i=strlen(file)-1;
  while(file[i]!='/' && file[i]!='\\')
  {
    i--;
  }

  i++;
  j=0;
  while(file[i]!='\0')
  {
    aux[j]=file[i];
    i++;
    j++;
  }
  aux[j-4]='\0';

  strcpy(fontName,aux);
  strcpy(fontFile,file);

  Width=size;
  Height=size;

  error.set(0);
  return error.get();

}

//=============================================================================
// METODO    : void setFontColor(rgbColor color)
// ACCION    : Cambia el color del texto.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setFontColor(rgbColor color)
{
  fontColor=color;
}

//=============================================================================
// METODO    : void setBackColor(rgbColor color)
// ACCION    : Cambia el color del fondo del texto.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setBackColor(rgbColor color)
{
  backColor=color;
}

//=============================================================================
// METODO    : void setStyle(tFontStyle sty)
// ACCION    : Cambia el estilo de la fuente.
// PARAMETROS: tFontStyle sty -> estilos
//                               Estilos posibles: NORMAL,BOLD,ITALIC.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setStyle(tFontStyle sty)
{
  style=sty;
}

//=============================================================================
// METODO    : void setTexture(tFontTexture tex)
// ACCION    : Cambia la textura de la fuente.
// PARAMETROS: tFontTexture tex -> texturas.
//                                 Texturas posibles: SOLID,SHADED.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setTexture(tFontTexture tex)
{
  texture=tex;
}

//=============================================================================
// METODO    : int setFontFile(const char* str)
// ACCION    : Cambia path y nombre de archivo ttf.
// PARAMETROS: const char* str --> path y archivo ttf-
// DEVUELVE  : int --> codigo de error ( 0 = todo bien).
//-----------------------------------------------------------------------------
int clsText::setFontFile(const char* str)
{
  error.set(loadFont(str,Width));
  if(error.get())
  {
    return error.get();
  }

  error.set(0);
  return error.get();
}
//=============================================================================
// METODO    : void centredWrite(char* texto,int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto centrado en las coordenadas Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::centredWrite(const char* text,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  SDL_Color bcolor;

  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  bcolor.r=backColor.r;
  bcolor.g=backColor.g;
  bcolor.b=backColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  switch(texture)
  {
    case SOLID   : frame = TTF_RenderText_Solid(font,text,fcolor);
                   break;
    case SHADED  : frame = TTF_RenderText_Shaded(font,text,fcolor,bcolor);
                   break;
  }

  int x=(scr->w - this->getWidth())/2;

  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;

  SDL_BlitSurface(frame,NULL,scr,&area);
  SDL_FreeSurface(frame);
}

//=============================================================================
// METODO    : void write(char* text, intx, int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto en las coordenadas X e Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int x              -> Coordenada X de la superficie destino
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::write(const char* text,int x,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  SDL_Color bcolor;

  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  bcolor.r=backColor.r;
  bcolor.g=backColor.g;
  bcolor.b=backColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  switch(texture)
  {
    case SOLID     : frame = TTF_RenderText_Solid(font,text,fcolor);
                    break;
    case SHADED:    frame = TTF_RenderText_Shaded(font,text,fcolor,bcolor);
                    break;
  }
  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;
  SDL_BlitSurface(frame,NULL,scr,&area);
  SDL_FreeSurface(frame);
}

//=============================================================================
// METODO    : void writeBlended(char* text, intx, int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto en las coordenadas X e Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int x              -> Coordenada X de la superficie destino
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::writeBlended(const char* text,int x,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  frame = TTF_RenderText_Blended(font,text,fcolor);

  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;
  SDL_BlitSurface(frame,NULL,scr,&area);
  SDL_FreeSurface(frame);
}

//=============================================================================
// METODO    : rgb getFontColor()
// ACCION    : Devuelve el color de la fuente.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Color -> color de fuente.
//-----------------------------------------------------------------------------
rgbColor clsText::getFontColor(){return fontColor;};

//=============================================================================
// METODO    : rgbColor getBackColor()
// ACCION    : Devuelve el color de fondo.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Color -> color de fondo.
//-----------------------------------------------------------------------------
rgbColor clsText::getBackColor(){return backColor;};

//=============================================================================
// METODO    : tFontStyle getStyle()
// ACCION    : Devuelve el estilo de la fuente .
// PARAMETROS: NADA.
// DEVUELVE  : tFontStyle -> Estilo.
//-----------------------------------------------------------------------------
tFontStyle clsText::getStyle(){return style;};

//=============================================================================
// METODO    : tFontTexture getTexture()
// ACCION    : Devuelve la textura de la fuente .
// PARAMETROS: NADA.
// DEVUELVE  : tFontTexture -> Textura.
//-----------------------------------------------------------------------------
tFontTexture clsText::getTexture(){return texture;};

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho total del texto.
// PARAMETROS: NADA.
// DEVUELVE  : int -> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsText::getWidth(){return Width;}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto total del texto.
// PARAMETROS: NADA.
// DEVUELVE  : int -> alto en pixeles.
//-----------------------------------------------------------------------------
int clsText::getHeight(){return Height;}

//=============================================================================
// METODO    : char* getFontName().
// ACCION    : Devuelve el nombre de la fuente.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> nombre de la fuente.
//-----------------------------------------------------------------------------
char* clsText::getFontName(){return fontName;}

//=============================================================================
// METODO    : char* getFontFile().
// ACCION    : Devuelve el nombre del archivo ttf.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> nombre del archivo.
//-----------------------------------------------------------------------------
char* clsText::getFontFile(){return fontFile;}

//### FIN DE ARCHIVO ##########################################################
