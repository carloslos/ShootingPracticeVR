#include "clsMenu.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicializa valores para el funcionamiento de la clase
// PARAMETROS: Punteros a clase de pantalla, eventos y fondos de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsMenu::init(clsScreen *scr, clsEvent *ev, clsBackground *bg)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    this->background = bg;

    error.set(game.init(screen, event, background));
    if(error.get())return error.get();

    error.set(score.init(screen, event, background));
    if(error.get())return error.get();

    error.set(text.init());
    if(error.get())return error.get();
    error.set(text.loadFont("FONTS/VT323.ttf",50));
    if(error.get())return error.get();

    error.set(menu.loadEffect("./ASSETS/Sounds/Menu.wav"));
    if(error.get())return error.get();

    return error.get();
}

//===========================================================================
// FUNCION   : run
// ACCION    : Ejecuta el menu principal
// PARAMETROS: Ninguno
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsMenu::run()
{
    bool exit=false;
    int i=0;
    menuRefresh(0);
    while(!exit)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                switch(event->getKey())
                {
                    case KEY_W:
                    case KEY_w:
                    case KEY_UP:
                        menu.playEffect(1, 0);
                        if(i>0)
                        {
                            i--;
                        }
                        else
                        {
                            i=3;
                        }
                        menuRefresh(i);
                        break;
                    case KEY_S:
                    case KEY_s:
                    case KEY_DOWN:
                        menu.playEffect(1, 0);
                        if(i<3)
                        {
                            i++;
                        }
                        else
                        {
                            i=0;
                        }
                        menuRefresh(i);
                        break;
                    case KEY_ENTER:
                    case KEY_SPACE:
                        switch(i)
                        {
                            case 0:
                                error.set(game.run());
                                if(error.get())return error.get();
                                break;
                            case 1:
                                score.readHighscores();
                                score.printHighscores(-1);
                                break;
                            case 2:
                                displayHelp();
                                break;
                            case 3:
                                exit=true;
                                break;
                        }
                        i=0;
                        menuRefresh(0);
                        break;
                    case KEY_ESCAPE:
                        exit=true;
                        break;
                }
            }
        }
    }
    game.closeAudio();
    return error.get();
}

//===========================================================================
// FUNCION   : menuRefresh
// ACCION    : Muestra por pantalla el menu principal
// PARAMETROS: Un int con la opcion del menu elejida actualmente
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsMenu::menuRefresh(int i)
{
    int y=160;
    screen->clean(BLACK);
    background->setMenu();
    background->paste(screen->getPtr());
    if(i==0){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.centredWrite("PLAY", y, screen->getPtr());
    if(i==1){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.centredWrite("HIGHSCORES", y+100, screen->getPtr());
    if(i==2){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.centredWrite("HELP", y+200, screen->getPtr());
    if(i==3){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.centredWrite("EXIT", y+300, screen->getPtr());
    screen->refresh();
}

//===========================================================================
// FUNCION   : displayHelp
// ACCION    : Muestra por pantalla la ayuda para el juego
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsMenu::displayHelp()
{
    int y=80;
    bool exit=false;
    screen->clean(BLACK);
    background->paste(screen->getPtr());
    text.setFontColor(CYAN);
    text.centredWrite("HELP", y, screen->getPtr());
    text.centredWrite("JUST SHOOT THE TARGETS", y+100, screen->getPtr());
    text.centredWrite("AIM WITH THE MOUSE, SHOOT WITH LEFT CLICK", y+160, screen->getPtr());
    text.centredWrite("PRESS ESCAPE AT ANY MOMENT TO EXIT", y+220, screen->getPtr());
    text.centredWrite("PRESS 'SPACE' TO CONTINUE", y+400, screen->getPtr());
    screen->refresh();
    while(!exit)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                switch(event->getKey())
                {
                    case KEY_ENTER:
                    case KEY_ESCAPE:
                    case KEY_SPACE:
                        exit=true;
                        break;
                }
            }
        }
    }
}
