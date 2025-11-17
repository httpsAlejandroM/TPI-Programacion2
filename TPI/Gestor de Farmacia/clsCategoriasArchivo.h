#pragma once
#include "clsCategoria.h"

class CategoriasArchivo {

public:
    CategoriasArchivo(const char* nombreArchivo = "categorias.dat");

    bool guardar(Categoria registro);
    int buscarPorID(int id);
    Categoria leerRegistro(int pos);
    bool leerTodos(Categoria categorias[], int cantidad);
    int contarRegistros();
    int getNuevoID();
    bool modificarRegistro(int pos, Categoria registro);
    bool cambiarEstado(int id);

private:
    char _nombreArchivo[30];

};
