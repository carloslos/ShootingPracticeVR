#include "clsScore.h"

//===========================================================================
// FUNCION   : init
// ACCION    : Inicializa valores para el funcionamiento de la clase
// PARAMETROS: Punteros a clase de pantalla, eventos y fondos de pantalla
// DEVUELVE  : Codigo de error
//---------------------------------------------------------------------------
int clsScore::init(clsScreen *scr, clsEvent *ev, clsBackground *bg)
{
    error.set(0);
    this->screen = scr;
    this->event = ev;
    this->background = bg;

    error.set(text.init());
    if(error.get())return error.get();
    error.set(text.loadFont("FONTS/VT323.ttf",50));
    if(error.get())return error.get();

    scoreInt=scoreCont=l=0;
    readHighscores();

    return error.get();
}

//===========================================================================
// FUNCION   : printScore
// ACCION    : Muestra por pantalla el puntaje actual
// PARAMETROS: Coordenadas X e Y donde imprimir el puntaje
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::printScore(int x, int y)
{
    char scoreString[20];
    text.setFontColor(CYAN);
    strcpy(scoreString, "SCORE: ");
    itoa(scoreInt, scoreItoa, 10);
    strcat(scoreString, scoreItoa);
    text.write(scoreString, x, y, screen->getPtr());
}

//===========================================================================
// FUNCION   : printName
// ACCION    : Muestra por pantalla el nombre a asociar con el puntaje
// PARAMETROS: Coordenadas X e Y donde imprimir el nombre
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::printName(int x, int y)
{
    char c[2];
    c[1]='\0';
    text.write("NAME: ", x, y, screen->getPtr());
    c[0]=name[0];
    if(l==0){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.write(c, x+132, y, screen->getPtr());
    c[0]=name[1];
    if(l==1){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.write(c, x+172, y, screen->getPtr());
    c[0]=name[2];
    if(l==2){text.setFontColor(RED);} else{text.setFontColor(CYAN);}
    text.write(c, x+212, y, screen->getPtr());
    text.setFontColor(CYAN);
}

//===========================================================================
// FUNCION   : scoreIncrease
// ACCION    : Aumenta en 1 el puntaje
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::scoreIncrease()
{
    scoreInt++;
}

//===========================================================================
// FUNCION   : readHigscores
// ACCION    : Lee el archivo highscores.dat y carga los puntajes en un vector
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::readHighscores()
{
    FILE *f=fopen("highscores.dat", "rb");
    scoreCont=0;
    if(f!=NULL)
    {
        while(fread(&highscores[scoreCont], sizeof(struct scoreStruct), 1, f) == 1)
        {
            scoreCont++;
        }
    }
    fclose(f);
}

//===========================================================================
// FUNCION   : getName
// ACCION    : Pide un nombre para asociar con un puntaje
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::getName()
{
    bool exit=false;
    name[0]=65;
    name[1]=65;
    name[2]=65;
    name[3]='\0';
    getNameRefresh();
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
                        if(name[l]>65)
                        {
                            name[l]--;
                        }
                        else
                        {
                            name[l]=90;
                        }
                        getNameRefresh();
                        break;
                    case KEY_S:
                    case KEY_s:
                    case KEY_DOWN:
                        if(name[l]<90)
                        {
                            name[l]++;
                        }
                        else
                        {
                            name[l]=65;
                        }
                        getNameRefresh();
                        break;
                    case KEY_A:
                    case KEY_a:
                    case KEY_LEFT:
                        if(l>0)
                        {
                            l--;

                        }
                        else
                        {
                            l=2;
                        }
                        getNameRefresh();
                        break;
                    case KEY_D:
                    case KEY_d:
                    case KEY_RIGHT:
                        if(l<2)
                        {
                            l++;

                        }
                        else
                        {
                            l=0;
                        }
                        getNameRefresh();
                        break;
                    case KEY_ENTER:
                    case KEY_SPACE:
                    case KEY_ESCAPE:
                        exit=true;
                        break;
                }
            }
        }
    }
}

//===========================================================================
// FUNCION   : printLowScore
// ACCION    : Muestra por pantalla un puntaje que no esta entre los primeros 10
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::printLowScore()
{
    bool exit=false;
    screen->clean(BLACK);
    background->paste(screen->getPtr());
    printScore(332, 196);
    text.centredWrite("MEDIOCRE", 350, screen->getPtr());
    text.centredWrite("PRESS 'SPACE' TO CONTINUE", 480, screen->getPtr());
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
                    case KEY_SPACE:
                    case KEY_ESCAPE:
                        exit=true;
                        break;
                }
            }
        }
    }
}

//===========================================================================
// FUNCION   : saveHighscores
// ACCION    : Guarda, si esta entre los primeros 10, el puntaje en el archivo highscores.dat
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::saveHighscores()
{
    struct scoreStruct ss;
    int m;
    background->setScore();
    ss.points=scoreInt;
    m=sortHighscores(ss);
    if(m>=0)
    {
        getName();
        strcpy(ss.name, name);
        strcpy(highscores[m].name, ss.name);
        writeHighscores();
        printHighscores(m);
    }
    else
    {
        printLowScore();
    }
    scoreInt=0;
}

//===========================================================================
// FUNCION   : writeHighscores
// ACCION    : Guarda el vector de mejores puntajes en el archivo highsores.dat
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::writeHighscores()
{
    FILE *f=fopen("highscores.dat", "wb");
    for(int i=0; i<scoreCont; i++)
    {
        fwrite(&highscores[i], sizeof(struct scoreStruct), 1, f);
    }
    fclose(f);
}

//===========================================================================
// FUNCION   : sortHighscoes
// ACCION    : Guarda o no un puntaje entre los 10 mejores y los ordena
// PARAMETROS: Puntaje a guardar si esta entre los 10 mejores puntajes
// DEVUELVE  : Posicion del vector en que se guardo el puntaje, -1 si no se guardo
//---------------------------------------------------------------------------
int clsScore::sortHighscores(struct scoreStruct ss)
{
    int m=-1;
    readHighscores();
    if(scoreCont==0)
    {
        highscores[0]=ss;
        scoreCont++;
        m=0;
    }
    else
    {
        int i;
        for(i=0; i<scoreCont; i++)
        {
            if(highscores[i].points<=ss.points)
            {
                m=i;
                break;
            }
        }
        if(m==-1 && scoreCont<10)
        {
            highscores[scoreCont]=ss;
            scoreCont++;
            m=scoreCont;
        }
        else
        {
            if(m>-1 || scoreCont<10)
            {
                if(scoreCont<10)
                {
                    scoreCont++;
                }
                for(i=scoreCont-1; i>m; i--)
                {
                    highscores[i]=highscores[i-1];
                }
                highscores[m]=ss;
            }
        }
    }
    return m;
}

//===========================================================================
// FUNCION   : getNameRefresh
// ACCION    : Muestra el menu para guardar el nombre asociado al puntaje
// PARAMETROS: Ninguno
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::getNameRefresh ()
{
    screen->clean(BLACK);
    background->paste(screen->getPtr());
    text.centredWrite("NEW HIGHSCORE", 350, screen->getPtr());
    printScore(332, 196);
    printName(304, 386);
    text.centredWrite("PRESS 'SPACE' TO CONTINUE", 480, screen->getPtr());
    screen->refresh();
}

//===========================================================================
// FUNCION   : printHighscores
// ACCION    : Muestra por pantalla los 10 mejores puntajes
// PARAMETROS: Posicion del ultimo puntaje agregado
// DEVUELVE  : Nada
//---------------------------------------------------------------------------
void clsScore::printHighscores(int m)
{
    int i;
    bool exit=false;
    char points[5];
    screen->clean(BLACK);
    background->setHighscores();
    background->paste(screen->getPtr());
    text.setFontColor(CYAN);
    text.centredWrite("HIGHSCORES", 60, screen->getPtr());
    int x=320, y=140;
    for(i=0; i<scoreCont; i++)
    {
        if(m==i)
        {
            text.setFontColor(RED);
        }
        else
        {
            text.setFontColor(CYAN);
        }
        text.write(highscores[i].name, x, y, screen->getPtr());
        x+=160;
        itoa(highscores[i].points, points, 10);
        text.write(points, x, y, screen->getPtr());
        x-=160;
        y+=40;
    }
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
