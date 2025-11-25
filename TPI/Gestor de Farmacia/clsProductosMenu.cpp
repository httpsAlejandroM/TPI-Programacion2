#include <iostream>
#include "clsProductosMenu.h"
#include "rlutil.h"
using namespace std;

ProductosMenu::ProductosMenu(){
    _cantidadOpciones = 5;
}

void ProductosMenu::mostrar(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionarOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void ProductosMenu::mostrarOpciones(){
  cout << "--- MENU PRODUCTOS ---" << endl;
  cout << "1- AGREGAR PRODUCTO "<<endl;
  cout << "2- HABILITAR/DESHABILITAR PRODUCTO "<<endl;
  cout << "3- MODIFICAR PRODUCTO "<<endl;
  cout << "4- VER TODOS LOS PRODUCTOS "<<endl;
  //TODO: AGREGAR OPCIONES DESPUES DE LISTAR PRODUCTOS PARA ORDENAR SEGUN: STOCK, PRECIO, CATEGORIA, NOMBRE
  cout << "5- BUSCAR PRODUCTO POR NOMBRE/ID"<<endl;

  cout << "0- Atras "<<endl;
}

int ProductosMenu::seleccionarOpcion(){
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

void ProductosMenu::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    cout << "AGREGAR PRODUCTOS" << endl;
    _productoManager.cargarProducto();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
  break;
  case 2:
    cout << "HABILITAR/DESHABILITAR PRODUCTOS" << endl;
    _productoManager.eliminarProducto();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
  break;
  case 3:
    cout << "MODIFICAR PRODUCTOS" << endl;
    _productoManager.modificarProducto();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
  break;
  case 4:
    cout << "VER PRODUCTOS" << endl;
    _productoManager.listarProductos();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
  break;
  case 5:
    cout << "BUSCAR PRODUCTO" << endl;
    _productoManager.buscarProducto();
    rlutil::anykey("Presione una tecla para volver al menu anterior...");
  break;
  case 0:
   cout << "Volviendo al menu anterior" << endl;
    break;

  }
}
