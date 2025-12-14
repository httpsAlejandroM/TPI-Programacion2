#include <iostream>
#include "clsObrasSocialesMenu.h"
#include "rlutil.h"
using namespace std;


ObrasSocialesMenu::ObrasSocialesMenu(){
  _cantidadOpciones = 5;
}

void ObrasSocialesMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void ObrasSocialesMenu::mostrarOpciones(){
  cout << "--- MENU OBRAS SOCIALES ---" << endl;
  cout << "1- AGREGAR OBRA SOCIAL "<<endl;
  cout << "2- BORRAR OBRA SOCIAL "<<endl;
  cout << "3- MODIFICAR OBRA SOCIAL "<<endl;
  cout << "4- VER TODAS LAS OBRAS SOCIALES "<<endl;
  cout << "5- BUSCAR OBRA SOCIAL POR ID"<<endl;
  cout << "0- Atras "<<endl;
}

int ObrasSocialesMenu::seleccionarOpcion(){
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

void ObrasSocialesMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    _obraSocialManager.cargarObraSocial();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    _obraSocialManager.eliminarObraSocial();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    _obraSocialManager.modificarObraSocial();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "VER OBRAS SOCIALES" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR OBRA SOCIAL" << endl;
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}
