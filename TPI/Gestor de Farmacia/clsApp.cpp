#include <iostream>
#include "clsApp.h"
using namespace std;
#include "rlutil.h"

App::App(){
    _cantidadOpciones = 5;
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

void App::mostrarOpciones(){
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1- PRODUCTOS "<<endl;
  cout << "2- VENTAS "<<endl;
  cout << "3- CLIENTES "<<endl;
  cout << "4- OBRAS SOCIALES "<<endl;
  cout << "5- VENDEDORES "<<endl;
  cout << "-----------------" << endl;
  cout << "0- Salir "<<endl;
}

int App::seleccionarOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
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
    cout << "MENU DE PRODUCTOS" << endl;
    rlutil::anykey("Presione una tecla para volver al menu principal...");
  break;
  case 2:
    cout << "MENU DE VENTAS" << endl;
    rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 3:
    cout << "MENU DE CLIENTES" << endl;
    rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 4:
   cout << "MENU DE OBRAS SOCIALES" << endl;
   rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;
  case 5:
   cout << "MENU DE VENDEDORES" << endl;
   rlutil::anykey("Presione una tecla para volver al menu principal...");
    break;

  case 0:
    cout << "Cerrando aplicacion... " << endl;
    break;
  }
}
