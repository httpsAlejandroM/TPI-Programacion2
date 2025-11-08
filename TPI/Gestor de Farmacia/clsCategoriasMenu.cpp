#include <iostream>
#include "clsCategoriasMenu.h"
#include "rlutil.h"
using namespace std;


CategoriasMenu::CategoriasMenu(){
  _cantidadOpciones = 5;
}

void CategoriasMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void CategoriasMenu::mostrarOpciones(){
  cout << "--- MENU CATEGORIAS ---" << endl;
  cout << "1- AGREGAR CATEGORIA "<<endl;
  cout << "2- BORRAR CATEGORIA "<<endl;
  cout << "3- MODIFICAR CATEGORIA "<<endl;
  cout << "4- VER TODAS LAS CATEGORIAS "<<endl;
  cout << "5- BUSCAR CATEGORIA POR ID"<<endl;
  cout << "0- Atras "<<endl;
}

int CategoriasMenu::seleccionarOpcion(){
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

void CategoriasMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    cout << "AGREGAR CATEGORIA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "BORRAR CATEGORIA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "MODIFICAR CATEGORIA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "VER CATEGORIAS" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR CATEGORIA" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}
