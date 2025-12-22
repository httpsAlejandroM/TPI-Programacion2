#include <iostream>
#include "clsVendedoresMenu.h"
#include "rlutil.h"
using namespace std;

VendedoresMenu::VendedoresMenu(){
  _cantidadOpciones = 5;
}

void VendedoresMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void VendedoresMenu::mostrarOpciones(){
  cout << "--- MENU VENDEDORES ---" << endl;
  cout << "1- AGREGAR VENDEDOR "<<endl;
  cout << "2- BORRAR VENDEDOR "<<endl;
  cout << "3- MODIFICAR DATOS VENDEDOR "<<endl;
  cout << "4- VER TODOS LOS VENDEDORES "<<endl;
  cout << "5- BUSCAR VENDEDOR POR DNI/ID"<<endl;
  cout << "0- Atras "<<endl;
}

int VendedoresMenu::seleccionarOpcion(){
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

void VendedoresMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    cout << "AGREGAR VENDEDOR" << endl;
    _vendedorManager.cargarVendedor();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "BORRAR VENDEDOR" << endl;
    _vendedorManager.eliminarVendedor();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "MODIFICAR DATOS VENDEDOR" << endl;
    _vendedorManager.modificarVendedor();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "VER VENDEDORES" << endl;
    _vendedorManager.listarVendedores();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR VENDEDOR" << endl;
    _vendedorManager.buscarVendedor();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}

