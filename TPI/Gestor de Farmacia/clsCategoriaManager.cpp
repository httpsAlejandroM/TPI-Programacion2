#include "clsCategoriaManager.h"
#include <iostream>
using namespace std;

CategoriaManager::CategoriaManager() {}

void CategoriaManager::cargarCategoria(){
    int id;
    char nombre[30];

    id = _repo.getNuevoID();
    cout << "Categoria #" << id << endl;

    cout << "Ingrese el nombre de la categoria: ";
    cin >> nombre;

    Categoria categoria(id, nombre, true);

    if(_repo.guardar(categoria)){
        cout << "Categoria guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar categoria." << endl;
    }
}

void CategoriaManager::mostrarCategoria(Categoria categoria){
    cout << "ID:" << categoria.getIdCategoria() << endl;
    cout << "Categoria: " << categoria.getNombre() << endl;
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
//TODO: definir metodo eliminarCategoria y mostrarCategoriaOrdenada