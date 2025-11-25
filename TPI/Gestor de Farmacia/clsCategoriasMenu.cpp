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
  cout << "2- HABILITAR/DESHABILITAR CATEGORIA "<<endl;
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
  //TODO: AGREGAR TODOS LOS METODOS DEL MANAGER
  case 1:
    cout << "AGREGAR CATEGORIA" << endl;
    _categoriaManager.cargarCategoria();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 2:
    cout << "HABILITAR/DESHABILITAR CATEGORIA" << endl;
    _categoriaManager.eliminarCategoria();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 3:
    cout << "MODIFICAR CATEGORIA" << endl;
    _categoriaManager.modificarCategoria();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 4:
    cout << "VER CATEGORIAS" << endl;
    _categoriaManager.listarCategorias();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 5:
    cout << "BUSCAR CATEGORIA" << endl;
    _categoriaManager.buscarCategoria();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
    break;
  case 0:
    cout << "Volviendo al menu anterior" << endl;
    break;
  }
}
