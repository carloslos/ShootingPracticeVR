#include "clsGame.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicializa valores para el funcionamiento de la clase
// PARAMETROS: Punteros a la pantalla, eventos y fondos de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsGame::init(clsScreen *scr, clsEvent *ev, clsBackground *bg)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    this->background = bg;

    error.set(target.init(screen));
    if(error.get())return error.get();

    error.set(score.init(screen, event, background));
    if(error.get())return error.get();

    error.set(hit.init(screen));
    if(error.get())return error.get();

    error.set(time.init(screen, 30)); // TIEMPO DE PARTIDA
    if(error.get())return error.get();

    error.set(text.init());
    if(error.get())return error.get();
    error.set(text.loadFont("FONTS/VT323.ttf",50));
    if(error.get())return error.get();

    error.set(audio.init());
    if(error.get())return error.get();
    error.set(shoot.loadEffect("./ASSETS/Sounds/SMG.wav"));
    if(error.get())return error.get();
    error.set(point.loadEffect("./ASSETS/Sounds/Point.wav"));
    if(error.get())return error.get();

    return error.get();
}

//===========================================================================
// FUNCION   : run
// ACCION    : Ejecuta las acciones principales de la clase
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsGame::run()
{
    error.set(0);
    background->setGame();
    bool exit=false, forced=false;

    error.set(time.readyTimer());
    if(error.get())return error.get();
    error.set(time.run());
    if(error.get())return error.get();

    int timeLeft=time.getTime();
    this->refresh();
    while(!exit)
    {
        if(time.getTime()<1)
        {
            exit=true;
        }
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                keyCommand(&exit, &forced, event->getKey());
                this->refresh();
            }
            if(event->getEventType() == MOUSE_DOWN)
            {
                if(event->getCursorX()<target.getX()+60 && event->getCursorX()>target.getX() && event->getCursorY()<target.getY()+60 && event->getCursorY()>target.getY())
                {
                    shoot.playEffect(1, 0);
                    point.playEffect(2, 0);
                    target.destroy();
                    score.scoreIncrease();
                    this->refresh();
                    hit.hit(event->getCursorX(), event->getCursorY());
                }
                else
                {
                    shoot.playEffect(1, 0);
                }
            }
        }
        if(timeLeft!=time.getTime())
        {
            this->refresh();
            timeLeft=time.getTime();
        }
    }
    if(forced==false)
    {
        score.saveHighscores();
    }
    return error.get();
}

//===========================================================================
// FUNCION   : closeAudio
// ACCION    : Cierra el canal de audio
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsGame::closeAudio()
{
    audio.closeAudio();
}

//===========================================================================
// FUNCION   : refresh
// ACCION    : Refresca la imagen en la pantalla
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsGame::refresh()
{
    screen->clean(BLACK);
    background->paste(screen->getPtr());
    time.printTime();
    score.printScore(550, 528);
    target.create();
    screen->refresh();
}

//===========================================================================
// FUNCION   : keyCommand
// ACCION    : Indica que accion realizar dependiendo de la tecla recibida
// PARAMETROS: Un booleano para saber si se sale del juego, otro para ver si se fuerza la salida y la tecla apretada
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsGame::keyCommand(bool *exit, bool *forced, Uint16 key)
{
    error.set(0);
    switch(key)
    {
        case KEY_ESCAPE:
            if(confirmExit())
            {
                *exit=true;
                *forced=true;
                break;
            }
    }
    return error.get();
}

//===========================================================================
// FUNCION   : confirmExit
// ACCION    : Da a elejir con un cartel si se quiere salir del juego o no
// PARAMETROS: Ninguno
// DEVUELVE  : Un bool que sera true si se quiere salir del juego, false en caso contrario
//---------------------------------------------------------------------------
bool clsGame::confirmExit()
{
    bool ce=false, exit=false, button=false;
    background->setExit();
    int x=screen->getWidth()/2-175, y=180;
    background->setX(x);
    background->setY(y);
    background->paste(screen->getPtr());
    text.setFontColor(CYAN);
    text.centredWrite("EXIT?", y+20, screen->getPtr());
    while(!exit)
    {
        if(button){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
        text.write("YES", x+220, y+75, screen->getPtr());
        if(!button){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
        text.write("NO", x+80, y+75, screen->getPtr());
        screen->refresh();
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                switch(event->getKey())
                {
                    case KEY_ESCAPE:
                        exit=true;
                        break;
                    case KEY_ENTER:
                    case KEY_SPACE:
                        exit=true;
                        if(button)
                        {
                            ce=true;
                        }
                        break;
                    case KEY_a:
                    case KEY_A:
                    case KEY_LEFT:
                        if(button)
                        {
                            button=false;
                        }
                        break;
                    case KEY_d:
                    case KEY_D:
                    case KEY_RIGHT:
                        if(!button)
                        {
                            button=true;
                        }
                        break;
                }
            }
        }
    }
    background->setX(0);
    background->setY(0);
    background->setGame();
    time.pause();
    return ce;
}
