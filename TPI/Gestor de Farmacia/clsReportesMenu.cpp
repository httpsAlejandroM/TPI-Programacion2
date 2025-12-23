#include "clsReportesMenu.h"
#include <iostream>
#include "rlutil.h"
using namespace std;

void ReportesMenu::mostrar() {
    int opcion;
    do {
        system("cls");
        mostrarOpciones();
        cin >> opcion;
        ejecutarOpcion(opcion);
    } while(opcion != 0);
}

void ReportesMenu::mostrarOpciones() {
    cout << "--- INFORMES---" << endl;
    cout << "1. Recaudacion Anual" << endl;
    cout << "2. Ranking Productos Mas Vendidos" << endl;
    cout << "3. Cantidad Ventas por Vendedor" << endl;
    cout << "-------------------------------" << endl;
    cout << "0. Volver al Menu Principal" << endl;
    cout << "Opcion: ";
}

void ReportesMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
        case 1: _manager.reporteRecaudacionAnual(); break;
        case 2: _manager.reporteProductosMasVendidos(); break;
        case 3: _manager.reporteVentasPorVendedor(); break;
        case 0: break;
        default:
            cout << "Opcion incorrecta" << endl;
            rlutil::anykey("...");
            break;
    }
}
