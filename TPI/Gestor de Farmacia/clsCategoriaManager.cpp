#include "clsCategoriaManager.h"
#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

CategoriaManager::CategoriaManager() {}

void CategoriaManager::cargarCategoria(){
    int id;
    char nombre[30];

    id = _repo.getNuevoID();
    cout << "Categoria #" << id << endl;

    cout << "Ingrese el nombre de la categoria: ";
    cin.ignore();
    cin.getline(nombre, 30);

    Categoria categoria(id, nombre, true);

    if(_repo.guardar(categoria)){
        cout << "Categoria guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar categoria." << endl;
    }
}

void CategoriaManager::mostrarCategoria(Categoria categoria){
    string estado = categoria.getEstado() ? "Habilitado" : "Deshabilitado";
    cout << "ID:" << categoria.getIdCategoria() << endl;
    cout << "Categoria: " << categoria.getNombre() << endl;
    cout << "Estado: " << estado << endl;
}

void CategoriaManager::listarCategorias(){
    int cantidad = _repo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        Categoria categoria = _repo.leerRegistro(i);
        //-------------id -------------categoria
        if(categoria.getEstado()){
            mostrarCategoria(categoria);
            cout << "----------------------------" << endl;
        }
    }
}

void CategoriaManager::eliminarCategoria(){
    int id, pos;
    Categoria categoria;
    char confirmacion;
    string accion; 

    cout << "Introduzca el ID de la categoria que quiere habilitar/deshabilitar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos < 0) {
        cout << "No se encontro un registro con el id " << id << endl;
        return;
    }

    categoria = _repo.leerRegistro(pos);

    accion = categoria.getEstado() ? "deshabilitar" : "habilitar";

    do {
        cout << "Desea " << accion << " la categoria: " << categoria.getNombre() << "?  Ingrese 's'(SI) o 'n'(NO): ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            _repo.cambiarEstado(id);
            cout << "Se cambio el estado de la categoria " << categoria.getNombre() << " con exito." << endl;
        }
        else if (confirmacion == 'n' || confirmacion == 'N') {
            cout << "No se realizaron cambios en la categoria." << endl;
        } else {
            cout << "Seleccione una opcion valida 's' o 'n'." << endl;
            rlutil::anykey("Presione una tecla para volver al menu anterior...");
            rlutil::cls();
        }
    } while (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' && confirmacion != 'N');
}


void CategoriaManager::buscarCategoria(){
    int id, pos;
    Categoria categoria;

    cout << "Introduzca el ID de la categoria que desea buscar: ";
    cin >> id;
    pos = _repo.buscarPorID(id);

    if (pos < 0) {
        cout << "No se encontro un registro con el id " << id << endl;
        return;
    }

    categoria = _repo.leerRegistro(pos);

    mostrarCategoria(categoria);
}

void CategoriaManager::modificarCategoria(){
    int id, pos;
    bool estado;
    char nombre[30];

    cout << "Introduzca el Id de la categoria que desea modificar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos < 0) {
        cout << "No se encontro un registro con el id " << id << endl;
        return;
    }

    cout << "Categoria #" << id << endl;

    cout << "Ingrese el nuevo nombre de la categoria: ";
    cin.ignore();
    cin.getline(nombre, 30);

    estado = _repo.leerRegistro(pos).getEstado();

    Categoria categoria(id, nombre, estado);

    if(_repo.modificarRegistro(pos, categoria)){
        cout << "Categoria modificada correctamente." << endl;
    } else {
        cout << "Error al modificar la categoria." << endl;
    }
    
}