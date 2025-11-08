#include <iostream>
#include <string>
#include "clsApp.h"
#include "rlutil.h"

using namespace std;

void App::acercaDe() {
    rlutil::cls();

    int ejeX = 40;
    int ejeY = 5;

    rlutil::locate(ejeX, ejeY);
    cout << "   =====================================" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++; //10
    rlutil::locate(ejeX, ejeY);
    cout << "   |         GESTOR DE FARMACIA        |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |===================================|" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |     Sistema desarrollado por:     |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |            Equipo 10              |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |-Alejandro Medina   - Legajo 33220 |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |-Esteban Reyes      - Legajo 33402 |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   | Version 25.10.0.1                 |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   | UTN FRGP - Programacion II        |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   | Libreria utilizada: RLUTIL        |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   |                                   |" << endl;

    ejeY++;
    rlutil::locate(ejeX, ejeY);
    cout << "   =====================================" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    ejeY+=4;
    rlutil::locate(ejeX, ejeY);
    rlutil::anykey("Presione una tecla para volver al menu principal...");
    rlutil::cls();

}
