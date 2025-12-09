#pragma once
#include "clsCliente.h"

class ClientesArchivo {

public:
    ClientesArchivo(const char* nombreArchivo = "clientes.dat");

    bool guardar(Cliente registro);
    Cliente leerRegistro(int pos);
    bool leerTodos(Cliente registros[], int cantidad);
    int contarRegistros();
    int buscarPorDNI(int dni);     
    bool modificarRegistro(int pos, Cliente registro);
    bool cambiarEstado(int dni);   

private:
    char _nombreArchivo[30];
};
