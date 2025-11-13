#pragma once
#include "clsCategoria.h"

class CategoriasArchivo {

public:
    CategoriasArchivo(const char* nombreArchivo = "categorias.dat");

    bool guardar(Categoria registro);
    bool guardar(int pos, Categoria categoria);
    int buscarPorID(int id);
    bool eliminar(int pos);
    Categoria leer(int pos);
    int leerTodos(Categoria categorias[], int cantidad);
    int cantidadRegistros();
    int getNuevoID();
    bool modificar(int pos, Categoria registro);


private:
    char _nombreArchivo[30];

};
