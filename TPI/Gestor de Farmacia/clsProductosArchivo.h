#pragma once
#include "clsProducto.h"

class ProductosArchivo {

public:
    ProductosArchivo(const char* nombreArchivo = "productos.dat");

    bool guardar(Producto registro);
    Producto leerRegistro(int pos);
    bool leerTodos(Producto registros[], int cantidad);
    int contarRegistros();
    int buscarPorID(int id);
    int getNuevoID();
    bool modificarRegistro(int pos, Producto registro);
    bool cambiarEstado(int id);

private:
    char _nombreArchivo[30];
};
