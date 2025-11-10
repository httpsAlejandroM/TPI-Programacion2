#include <iostream>
#include "clsVentasMenu.h"
#include "rlutil.h"
using namespace std;


VentasMenu::VentasMenu(){
  _cantidadOpciones = 5;
}

void VentasMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void VentasMenu::mostrarOpciones(){
  cout << "--- MENU VENTAS ---" << endl;
  cout << "1- GESTIONAR NUEVA VENTA "<<endl;
  cout << "2- ANULAR VENTA "<<endl;
  cout << "3- LISTAR VENTAS POR RANGO DE FECHA "<<endl;
  cout << "4- LISTAR VENTAS POR CLIENTE "<<endl;
  cout << "5- BUSCAR VENTA POR ID"<<endl;
  cout << "0- Atras "<<endl;
}

int VentasMenu::seleccionarOpcion(){
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

void VentasMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    cout << "REGISTRAR NUEVA VENTA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "ANULAR VENTA" << endl;
    // llama a cambioEstado de una Venta y devolver¡a el stock
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "LISTAR VENTAS POR RANGO DE FECHA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "LISTAR VENTAS POR CLIENTE" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR VENTA POR ID" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}


