#include <iostream>
#include "clsApp.h"
using namespace std;
#include "rlutil.h"

App::App(){
    _cantidadOpciones = 8;
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
  cout << "--- MENU PRINCIPAL ---" <<endl<<endl;
  cout << "  1- PRODUCTOS "<<endl;
  cout << "  2- VENTAS "<<endl<<endl;
  cout << "  3- CLIENTES "<<endl;
  cout << "  4- OBRAS SOCIALES "<<endl<<endl;
  cout << "  5- CATEGORIAS "<<endl;
  cout << "  6- VENDEDORES "<<endl<<endl;
  cout << "  7- REPORTES "<<endl;
  cout << "  8- Acerca de"<<endl;
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
    _ventaMenu.mostrar();
    break;
  case 3:
    _clienteMenu.mostrar();
  break;
  case 4:
   _obraSocialMenu.mostrar();
    break;
  case 5:
    _categoriaMenu.mostrar();
    break;
  case 6:
    _vendedorMenu.mostrar();
    break;
  case 7:
    _reportesMenu.mostrar();
    break;
  case 8:
   cout << "  Acerca de" << endl;
   acercaDe();
    break;

  case 0:
    cout << "  Cerrando aplicacion... \n\n\n";
    break;
  }
}
