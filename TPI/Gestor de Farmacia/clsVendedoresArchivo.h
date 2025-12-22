#pragma once
#include "clsVendedor.h"

class VendedoresArchivo {

public:
    VendedoresArchivo(const char* nombreArchivo = "vendedores.dat");

    bool guardar(Vendedor registro);
    Vendedor leerRegistro(int pos);
    bool leerTodos(Vendedor registros[], int cantidad);
    int contarRegistros();
    int buscarPorDNI(int dni);
    bool modificarRegistro(int pos, Vendedor registro);
    bool cambiarEstado(int dni);

private:
    char _nombreArchivo[30];
};
