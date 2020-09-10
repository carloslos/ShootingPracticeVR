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
// ARCHIVO             : adnConst.h
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
// DESCRIPCION: Este archivo contiene la declaracion de los tipos de datos
//              necesarios para el sistema.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef ADNCONSTS_H
#define ADNCONSTS_H

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// (00) INDICE DE CATEGORIAS
//==============================================================================
// Para un acceso rapido a la declaracion de los tipos de datos de una categoria
// determinada, presione <CTRL> + <F>, e ingrese el numero de categoria (para
// regresar a este indice presione <CTRLF> + <F>, e ingrese "(00)".
//------------------------------------------------------------------------------
// CATEGORIA        NUMERO    DESCRIPCION
//---------------- +--------+---------------------------------------------------
// SISTEMA         |  (01)  | Definicion del Sistema operativo a utilizarse
// OPERATIVO       |        | (Linux o Windows).
//-----------------+--------+---------------------------------------------------
// SDL             |  (02)  | Librerias SDL fundamentales para las ADN-X.
//-----------------+--------+---------------------------------------------------
// VERSION ADN-X   |  (03)  | Constante que identifica la version de ADN-X en el
//                 |        | archivo "stdout.txt" (logfile).
//-----------------+--------+---------------------------------------------------
// MODO VIDEO      |  (04)  | Tipos necesarios para la inicializacion del modo
//                 |        | grafico.
//-----------------+--------+---------------------------------------------------
// PANTALLA        |  (05)  | tipos para la inicializacion del monitor.
//                 |        |
//-----------------+--------+---------------------------------------------------
// COLORES         |  (06)  | Estructura para la composicion de colores RGB.
//-----------------+--------+---------------------------------------------------
// TECLADO         |  (07)  | Constantes con codigos de teclado.
//-----------------+--------+---------------------------------------------------
// MOUSE           |  (08)  | Constantes con codigos de mouse.
//-----------------+--------+---------------------------------------------------
// SPRITES         |  (09)  | Tipos para la administracion de sprites.
//-----------------+--------+---------------------------------------------------
// TEXTOS          |  (10)  | Enumeraciones para la administracion de textos
//-----------------+--------+---------------------------------------------------

//##############################################################################
// (01) - SISTEMA OPERATIVO
//------------------------------------------------------------------------------
// Para compilar en Windows, descomente estas tres lineas.
#ifndef _WIN32
  #define _WIN32
#endif

// Para compilar en Linux, descomente estas tres lineas.
//#ifndef _LINUX
//  #define _LINUX
//#endif
//------------------------------------------------------------------------------


//##############################################################################
// (02) - SDL
//------------------------------------------------------------------------------
#ifdef _WIN32                  // Inclusiones para Windows.
    #include <SDL/SDL.h>
    #include <SDL/SDL_video.h>
    #include <SDL/SDL_image.h>
    #include <SDL/SDL_ttf.h>
    #include <SDL/SDL_mixer.h>
#endif


#ifdef _LINUX                 // Inclusiones para Linux.
  #include <SDL.h>
  #include <SDL_video.h>
  #include "SDL_image.h"
  #include "SDL_ttf.h"
  #include "SDL_mixer.h"
#endif // _LINUX
//------------------------------------------------------------------------------


//#############################################################################
// (03) - VERSION ADN-X
//-----------------------------------------------------------------------------
const char ADNPP_VERSION[]="Sistema ADN-X (v. 14.11 estable)";

//------------------------------------------------------------------------------



//#############################################################################
// (04) - MODO VIDEO
//        Enumeracion se utiliza como parametros para la inicializacion del
//        modo grafico.
//-----------------------------------------------------------------------------
enum graphicVideoMode{
                       DEFAULT,     // Resolucion de video de 800x600x16.
                       AUTODETECT   // Autodeteccion de la resolucion de video.
                     };

//------------------------------------------------------------------------------



//#############################################################################
// (05) - PANTALLA
//        Enumeracion de tipos de entornos posibles.
//-----------------------------------------------------------------------------
enum environment {
                   NOTHING      = 0,             // Sin tipo.
                   HARDWARE     = SDL_HWSURFACE, // Pantalla fisica.
                   ASINCRONIC   = SDL_ASYNCBLIT, // Asincronico
                   EMULATED     = SDL_ANYFORMAT, // Emulado.
                   DOUBLEBUFFER = SDL_DOUBLEBUF,
                   FULLSCREEN   = SDL_FULLSCREEN,// Pantalla completa.
                   RESIZABLE    = SDL_RESIZABLE, // Pantalla redimensionable.
                   NOTITLE      = SDL_NOFRAME,   // Sin titulo.
                  };

//------------------------------------------------------------------------------
// BARRAS DE TITULO.
//                  Esta enumeracion contiene los tipos de estados posibles para
//                  la barra de titulo de la ventana en el monitor.
//-----------------------------------------------------------------------------
enum titlebar{
               DISABLED = false, // Deshabilitada.
               ENABLED = true    // Habilitada.
             };

//-----------------------------------------------------------------------------



//#############################################################################
// (06) - COLORES
//-----------------------------------------------------------------------------
struct rgbColor
{
  Uint8 r;     // componente rojo.
  Uint8 g;     // componente verde,
  Uint8 b;     // componente azul.
};

//-----------------------------------------------------------------------------
// COLORES DEFINIDOS
//-----------------------------------------------------------------------------
// Aqui se pueden agregar colores personalizados de la siguiente forma:
//
//  const rgbColor NOMBRE_COLOR = {valor_rojo,valor_verde,valor_azul};
//
const rgbColor BLACK    = {0,0,0};       // Negro.
const rgbColor BLUE     = {0,0,255};     // Azul puro.
const rgbColor BROWN    = {128,96,32};   // Marron.
const rgbColor CYAN     = {138,217,247};   // Cian
const rgbColor GRAY     = {128,128,128}; // Gris.
const rgbColor GREEN    = {0,255,0};     // Verde puro.
const rgbColor LIGHTBLUE= {128,180,255}; // Celeste.
const rgbColor MAGENTA  = {230,0,230};   // Magenta.
const rgbColor ORANGE   = {255,128,0};   // Anaranjado.
const rgbColor PINK     = {255,0,255};   // Rosado puro.
const rgbColor RED      = {255,0,0};     // Rojo puro.
const rgbColor VIOLET   = {128,0,255};   // Violeta.
const rgbColor WHITE    = {255,255,255}; // Blanco.
const rgbColor YELLOW   = {255,255,0};   // Amarillo puro.

//-----------------------------------------------------------------------------



//#############################################################################
// (07) - TECLADO
//-----------------------------------------------------------------------------
  //...........................................................................
  // ESTADOS DE TECLA
  //...........................................................................
  const Uint8  KEY_FREE    = SDL_KEYUP;   // Tecla liberada
  const Uint8  KEY_PRESSED = SDL_KEYDOWN; // Tecla presionada.

  //...........................................................................
  // DIGITOS
  //...........................................................................
  const Uint16 KEY_0                    = 48;
  const Uint16 KEY_1                    = 49;
  const Uint16 KEY_2                    = 50;
  const Uint16 KEY_3                    = 51;
  const Uint16 KEY_4                    = 52;
  const Uint16 KEY_5                    = 53;
  const Uint16 KEY_6                    = 54;
  const Uint16 KEY_7                    = 55;
  const Uint16 KEY_8                    = 56;
  const Uint16 KEY_9                    = 57;

  //...........................................................................
  // SIGNOS
  //...........................................................................
  const Uint16 KEY_RIGHT_SLASH       = 47;
  const Uint16 KEY_LEFT_SLASH        = 92;
  const Uint16 KEY_EXCLAMATION_MARK  = 33;
  const Uint16 KEY_QUESTION_MARK     = 63;
  const Uint16 KEY_QUOTE             = 39;
  const Uint16 KEY_DOUBLE_QUOTE      = 34;
  const Uint16 KEY_COLON             = 58;
  const Uint16 KEY_PERIOD            = 46;
  const Uint16 KEY_COMMA             = 44;
  const Uint16 KEY_SEMICOLON         = 59;
  const Uint16 KEY_LEFT_PARENTHESES  = 40;
  const Uint16 KEY_RIGHT_PARENTHESES = 41;
  const Uint16 KEY_LEFT_BRACKET      = 91;
  const Uint16 KEY_RIGHT_BRACKET     = 93;
  const Uint16 KEY_LESS              = 60;
  const Uint16 KEY_GREATER           = 62;
  const Uint16 KEY_EQUALS            = 61;
  const Uint16 KEY_ASTERISK          = 42;
  const Uint16 KEY_PLUS              = 43;
  const Uint16 KEY_MINUS             = 45;
  const Uint16 KEY_UNDERSCORE        = 95;
  const Uint16 KEY_AT                = 64;
  const Uint16 KEY_SHARP             = 35;
  const Uint16 KEY_DOLLAR            = 36;
  const Uint16 KEY_AMPERSAND         = 38;
  const Uint16 KEY_BACKQUOTE         = 96;
  const Uint16 KEY_SPACE             = 32;

  //...........................................................................
  // MAYUSCULAS
  //...........................................................................
  const Uint16 KEY_A                    = 65;
  const Uint16 KEY_B                    = 66;
  const Uint16 KEY_C                    = 67;
  const Uint16 KEY_D                    = 68;
  const Uint16 KEY_E                    = 69;
  const Uint16 KEY_F                    = 70;
  const Uint16 KEY_G                    = 71;
  const Uint16 KEY_H                    = 72;
  const Uint16 KEY_I                    = 73;
  const Uint16 KEY_J                    = 74;
  const Uint16 KEY_K                    = 75;
  const Uint16 KEY_L                    = 76;
  const Uint16 KEY_M                    = 77;
  const Uint16 KEY_N                    = 78;
  const Uint16 KEY_O                    = 79;
  const Uint16 KEY_P                    = 80;
  const Uint16 KEY_Q                    = 81;
  const Uint16 KEY_R                    = 82;
  const Uint16 KEY_S                    = 83;
  const Uint16 KEY_T                    = 84;
  const Uint16 KEY_U                    = 85;
  const Uint16 KEY_V                    = 86;
  const Uint16 KEY_W                    = 87;
  const Uint16 KEY_X                    = 88;
  const Uint16 KEY_Y                    = 89;
  const Uint16 KEY_Z                    = 90;

  //...........................................................................
  // MINUSCULAS
  //...........................................................................
  const Uint16 KEY_a                    = 97;
  const Uint16 KEY_b                    = 98;
  const Uint16 KEY_c                    = 99;
  const Uint16 KEY_d                    = 100;
  const Uint16 KEY_e                    = 101;
  const Uint16 KEY_f                    = 102;
  const Uint16 KEY_g                    = 103;
  const Uint16 KEY_h                    = 104;
  const Uint16 KEY_i                    = 105;
  const Uint16 KEY_j                    = 106;
  const Uint16 KEY_k                    = 107;
  const Uint16 KEY_l                    = 108;
  const Uint16 KEY_m                    = 109;
  const Uint16 KEY_n                    = 110;
  const Uint16 KEY_o                    = 111;
  const Uint16 KEY_p                    = 112;
  const Uint16 KEY_q                    = 113;
  const Uint16 KEY_r                    = 114;
  const Uint16 KEY_s                    = 115;
  const Uint16 KEY_t                    = 116;
  const Uint16 KEY_u                    = 117;
  const Uint16 KEY_v                    = 118;
  const Uint16 KEY_w                    = 119;
  const Uint16 KEY_x                    = 120;
  const Uint16 KEY_y                    = 121;
  const Uint16 KEY_z                    = 122;

  //...........................................................................
  // CONTROLES
  //...........................................................................
  const Uint16 KEY_ENTER                = 13;
  const Uint16 KEY_ESCAPE               = 27;
  const Uint16 KEY_TAB                  = 9;
  const Uint16 KEY_BACKSPACE            = 8;
  const Uint16 KEY_DELETE               = 127;
  const Uint16 KEY_INSERT               = 277;
  const Uint16 KEY_PAUSE                = 19;
  const Uint16 KEY_NUMLOCK              = 300;
  const Uint16 KEY_CAPSLOCK             = 301;
  const Uint16 KEY_PRINT                = 316;
  const Uint16 KEY_RIGHT_SHIFT          = 303;
  const Uint16 KEY_LEFT_SHIFT           = 304;
  const Uint16 KEY_RIGHT_CTRL           = 305;
  const Uint16 KEY_LEFT_CTRL            = 306;
  const Uint16 KEY_RIGHT_ALT            = 307;
  const Uint16 KEY_LEFT_ALT             = 308;

  //...........................................................................
  // MOVIMIENTO DEL CURSOR
  //...........................................................................
  const Uint16 KEY_DOWN                 = 274;
  const Uint16 KEY_UP                   = 273;
  const Uint16 KEY_RIGHT                = 275;
  const Uint16 KEY_LEFT                 = 276;
  const Uint16 KEY_PAGEDOWN             = 281;
  const Uint16 KEY_PAGEUP               = 280;
  const Uint16 KEY_HOME                 = 278;
  const Uint16 KEY_END                  = 279;

  //...........................................................................
  // TECLAS FUNCION
  //...........................................................................
  const Uint16 KEY_F1                   = 282;
  const Uint16 KEY_F2                   = 283;
  const Uint16 KEY_F3                   = 284;
  const Uint16 KEY_F4                   = 285;
  const Uint16 KEY_F5                   = 286;
  const Uint16 KEY_F6                   = 287;
  const Uint16 KEY_F7                   = 288;
  const Uint16 KEY_F8                   = 289;
  const Uint16 KEY_F9                   = 290;
  const Uint16 KEY_F10                  = 291;
  const Uint16 KEY_F11                  = 292;
  const Uint16 KEY_F12                  = 293;

  //...........................................................................
  // NUMPAD
  //...........................................................................
  const Uint16 KEY_NUMPAD_0             = 256;
  const Uint16 KEY_NUMPAD_1             = 257;
  const Uint16 KEY_NUMPAD_2             = 258;
  const Uint16 KEY_NUMPAD_3             = 259;
  const Uint16 KEY_NUMPAD_4             = 260;
  const Uint16 KEY_NUMPAD_5             = 261;
  const Uint16 KEY_NUMPAD_6             = 262;
  const Uint16 KEY_NUMPAD_7             = 263;
  const Uint16 KEY_NUMPAD_8             = 264;
  const Uint16 KEY_NUMPAD_9             = 265;
  const Uint16 KEY_NUMPAD_EQUALS        = 272;
  const Uint16 KEY_NUMPAD_ENTER         = 271;
  const Uint16 KEY_NUMPAD_PLUS          = 270;
  const Uint16 KEY_NUMPAD_MINUS         = 269;
  const Uint16 KEY_NUMPAD_MULTIPLY      = 268;
  const Uint16 KEY_NUMPAD_DIVIDE        = 267;
  const Uint16 KEY_NUMPAD_PERIOD        = 266;


/*
  ------------- RESERVADA ----------------------------------------------------
  const Uint16 KEY_F13                  = 294;
  const Uint16 KEY_F14                  = 295;
  const Uint16 KEY_F15                  = 296;
  const Uint16 KEY_SCROLLOCK            = 302;

    SDLK_HELP		= 315,
	SDLK_RMETA		= 309,
	SDLK_LMETA		= 310,
	SDLK_LSUPER		= 311,		 Left Windows key
	SDLK_RSUPER		= 312,		 Right Windows key
	SDLK_MODE		= 313,		 Alt Gr key
	SDLK_COMPOSE	= 314,		 Multi-key compose key
	SDLK_SYSREQ		= 317,
	SDLK_BREAK		= 318,
	SDLK_MENU		= 319,
	SDLK_POWER		= 320,		Power Macintosh power key
	SDLK_EURO		= 321,		Some european keyboards
	SDLK_UNDO		= 322,		Atari keyboard has Undo

  -----------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------
// TECLAS ESPECIALES
//                  Estados especiales (CTRL, ALT, SHIFT, NUMLOCK, CAPSLOCK).
//-----------------------------------------------------------------------------
  const SDLMod KEY_MDF_NONE        = KMOD_NONE;  // Ninguna.
  const SDLMod KEY_MDF_NUMLOCK     = KMOD_NUM;   // Numlock.
  const SDLMod KEY_MDF_CAPSLOCK    = KMOD_CAPS;  // Capslock.
  const SDLMod KEY_MDF_LEFT_CTRL   = KMOD_LCTRL; // Control izquierdo.
  const SDLMod KEY_MDF_RIGHT_CTRL  = KMOD_RCTRL; // Control derecho.
  const SDLMod KEY_MDF_RIGHT_SHIFT = KMOD_RSHIFT;// Shift derecho.
  const SDLMod KEY_MDF_LEFT_SHIFT  = KMOD_LSHIFT;// Shift izquierdo.
  const SDLMod KEY_MDF_RIGHT_ALT   = KMOD_RALT;  // Alt derecho.
  const SDLMod KEY_MDF_LEFT_ALT    = KMOD_LALT;  // Alt iquierdo.

//-----------------------------------------------------------------------------



//#############################################################################
// (08) - MOUSE
//-----------------------------------------------------------------------------
  const Uint8  MOUSE_MOTION = SDL_MOUSEMOTION;      // Mouse mivido.
  const Uint8  MOUSE_DOWN   = SDL_MOUSEBUTTONDOWN;  // Boton presionado.
  const Uint8  MOUSE_UP     = SDL_MOUSEBUTTONUP;    // Boton liberado.

  const Uint8  MOUSE_LEFT_BUTTON     = SDL_BUTTON_LEFT;   // Boton izquierdo.
  const Uint8  MOUSE_RIGHT_BUTTON    = SDL_BUTTON_RIGHT;  // Boton derecho.
  const Uint8  MOUSE_MIDDLE_BUTTON   = SDL_BUTTON_MIDDLE; // Boton medio.

//-----------------------------------------------------------------------------



//#############################################################################
// (09) SPRITES
//-----------------------------------------------------------------------------
// ESTADOS
//-----------------------------------------------------------------------------
enum tSpriteState {INACTIVE,ACTIVE};

//-----------------------------------------------------------------------------
// ESTRUCTURA PARA DETECTAR CONTACTOS
//-----------------------------------------------------------------------------
struct tCoord
{
      int x1,  // coord x inicial del sprite local.
          y1,  // coord y inicial del sprite local.
          x2,  // coord x final del sprite local.
          y2,  // coord y final del sprite local.
          x3,  // coord x inicial del sprite externo.
          y3,  // coord y inicial del sprite externo.
          x4,  // coord x final del sprite externo.
          y4,  // coord y final del sprite externo.
          w1,  // ancho del sprite local.
          w2,  // ancho del sprite externo.
          h1,  // alto del sprite local.
          h2,  // alto del sprite externo.
          xi1, // coord x inicial del area superpuesta en el sprite local.
          yi1, // coord y inicial del area superpuesta en el sprite local.
          xi2, // coord x inicial del area superpuesta en el sprite externo.
          yi2, // coord y inicial del area superpuesta en el sprite externo.
          aw,  // ancho del area superpuesta.
          ah,  // alto  del area superpuesta.
          ovl; // caso de superposicion (overlap).
};

//-----------------------------------------------------------------------------


//#############################################################################
// (10)ENUMERACIONES DEFINIDAS PARA TEXTOS.
//-----------------------------------------------------------------------------
// TEXTURAS
//         Tipos de textura posibles.
//-----------------------------------------------------------------------------
enum tFontTexture{SOLID,SHADED};

//-----------------------------------------------------------------------------
// ESTILOS
//        Tipos de de fuentes posibles.
//-----------------------------------------------------------------------------
enum tFontStyle{NORMAL,BOLD,ITALIC};

//-----------------------------------------------------------------------------


#endif // ADNCONSTS_H

//### FIN DE ARCHIVO ##########################################################

