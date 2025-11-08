#include <iostream>
#include "clsApp.h"
using namespace std;
#include "rlutil.h"

App::App(){
    _cantidadOpciones = 7;
}

void App::run(){
    int opcion;

    do{
        system("cls");
        opcion = seleccionarOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    } while (opcion != 0);
}
//TODO: Agregar cpp y .h de clases ProductosMenu, VentasMenu, ClientesMenu, OSocialesMenus, VendedoresMenu
void App::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" <<endl<<endl;
  cout << "  1- PRODUCTOS "<<endl;
  cout << "  2- VENTAS "<<endl;
  cout << "  3- CLIENTES "<<endl;
  cout << "  4- OBRAS SOCIALES "<<endl;
  cout << "  5- VENDEDORES "<<endl<<endl;
  cout << "  6- REPORTES "<<endl;
  cout << "  7- Acerca de"<<endl;
  cout << "-----------------" << endl;
  cout << "  0- Salir "<<endl;
}

int App::seleccionarOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "-----------------" << endl;
  cout << "  Opcion: ";
  cin >> opcion;

  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..."<<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}

void App::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _productoMenu.mostrar();
  break;
  case 2:
    cout << "  MENU DE VENTAS" << endl;
    rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 3:
    _clienteMenu.mostrar();
  break;
  case 4:
   cout << "  MENU DE OBRAS SOCIALES" << endl;
   rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 5:
    _vendedorMenu.mostrar();
    break;
  case 6:
   cout << "  REPORTES" << endl;
   rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 7:
   cout << "  Acerca de" << endl;
   acercaDe();
    break;

  case 0:
    cout << "  Cerrando aplicacion... \n\n\n";
    break;
  }
}
