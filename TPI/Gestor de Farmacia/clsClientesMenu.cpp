#include <iostream>
#include "clsClientesMenu.h"
#include "rlutil.h"
using namespace std;


ClientesMenu::ClientesMenu(){
  _cantidadOpciones = 5;
}

void ClientesMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void ClientesMenu::mostrarOpciones(){
  cout << "--- MENU CLIENTES ---" << endl;
  cout << "1- AGREGAR CLIENTE "<<endl;
  cout << "2- BORRAR CLIENTE "<<endl;
  cout << "3- MODIFICAR DATOS CLIENTE "<<endl;
  cout << "4- VER TODOS LOS CLIENTES "<<endl;
  // TODO: Listado de clientes por apellido, obra social y edad
  cout << "5- BUSCAR CLIENTE POR DNI/ID"<<endl; // <-- CAMBIO
  cout << "0- Atras "<<endl;
}

int ClientesMenu::seleccionarOpcion(){
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

void ClientesMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    cout << "AGREGAR CLIENTE" << endl;
    _clienteManager.cargarCliente();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "BORRAR CLIENTE" << endl;
    _clienteManager.eliminarCliente();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "MODIFICAR DATOS CLIENTE" << endl;
    _clienteManager.modificarCliente();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "VER CLIENTES" << endl;
    _clienteManager.listarClientes();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR CLIENTE" << endl;
    _clienteManager.buscarCliente();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}



