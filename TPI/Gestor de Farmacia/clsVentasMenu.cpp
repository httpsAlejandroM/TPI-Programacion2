#include <iostream>
#include "clsVentasMenu.h"
#include "rlutil.h"
using namespace std;


VentasMenu::VentasMenu(){
  _cantidadOpciones = 4;
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
  cout << "1- GESTIONAR NUEVA VENTA"<<endl;
  cout << "2- LISTAR VENTAS POR RANGO DE FECHA "<<endl;
  cout << "3- BUSCAR VENTA POR ID"<<endl;
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
    _ventaManager.nuevaVentaMenu();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "LISTAR VENTAS POR RANGO DE FECHA" << endl;
    _ventaManager.listarVentas();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "BUSCAR VENTA POR ID" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}


