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
//-----------------------------------------------------------------------------
// ARCHIVOS QUE COMPONEN EL SISTEMA Avis adn-X
//
// El paqueta Avis adn-X se compone de los siguientes archivos.
//
// ==============================================================================
// |                            ARCHIVOS DEL SISTEMA                            |
// |____________________________________________________________________________|
// |         ARCHIVO       |      VERSION     |    FECHA       |   PRINCIPALES  |
// |-----------------------+------------------+----------------|----------------|
// | main.cpp              |  v.14.11 estable |   12/11/2014   | Principal      |
// |.......................|..................|................|................|
// |         ARCHIVO       |     VERSION      |    FECHA       | TIPOS DE DATOS |
// |-----------------------+------------------+----------------|----------------|
// | adnConst.h            |  v.14.11 estable |   12/11/2014   | Constantes y   |
// |                       |                  |   12/11/2014   | tipos          |
// |.......................|..................|................|................|
// | ARCHIVOS .h y .cpp    |     VERSION      |    FECHA       |      CLASES    |
// |-----------------------+------------------+----------------|----------------|
// | clsAudio              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsDot                |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsError              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsEvent              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsImage              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsLog                |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsMode               |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsMusic              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsRandom             |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsScreen             |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsSoundEffect        |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsSprite             |  v.14.11 estable |   12/11/2014   | Abstracta      |
// | clsText               |  v.14.11 estable |   12/11/2014   | Instanciable   |
// | clsTimer              |  v.14.11 estable |   12/11/2014   | Instanciable   |
// |_______________________|__________________|________________|________________|


#include <iostream>         // Contiene "cout".
#include <adnConsts.h>      // Tipos de datos del sistema adn-X.
#include <clsLog.h>         // stdout.txt para Linux.
#include <clsError.h>       // Administrador de errores.
#include <clsSPE.h>         // Motor del programa

using namespace std;        // Espacio de nombres estandar.

//#############################################################################
//                           PROGRAMA PRINCIPAL
//=============================================================================
int main ( int argc, char** argv )
{
    //---------------------------------------------------------------------------
    // Habilitar "stdout.txt" (solo para Linux).
    //---------------------------------------------------------------------------
    #ifdef _LINUX
        clsLog logFile; // Administrador de informes logs para Linux. (recomendado).
        logFile.open(); // Habilita la salida "stdout.txt"
        system("date"); // Muestra la fecha y hora de ejecucion en el logFile.
    #endif

    //---------------------------------------------------------------------------
    // IDENTIFICACION DE LA VERSION adn-X EN EL ARCHIVO "stdout.txt".
    //---------------------------------------------------------------------------
    cout << "##########################################################" << endl;
    cout << "           " << ADNPP_VERSION                               << endl;
    cout << "**********************************************************" << endl;
    cout <<  endl;

    //-------------------------------------
    // OBJETOS NECESARIOS PARA EL PROGRAMA
    clsError error;
    clsSPE spe;

    //--------------------------------
    // CODIGO DEL PROGRAMA PRINCIPAL

    error.set(spe.init());
    if(error.get())return error.get();

    error.set(spe.run());
    if(error.get())return error.get();

    //----------------------------
    // FIN DEL PROGRAMA PRINCIPAL
    cout << endl;
    cout << "**********************************************************" << endl;
    cout << "       El proyecto ADN-X ha finalizado correctamente      " << endl;
    cout << "##########################################################" << endl;
    return error.get(); // Fin normal del programa principal.
}

//### FIN DE ARCHIVO ##########################################################
