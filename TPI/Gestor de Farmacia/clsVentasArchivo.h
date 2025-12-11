#pragma once
#include "clsVenta.h"

class VentasArchivo {

    public:
    VentasArchivo(const char* nombreARchivo = "ventas.dat");

    bool guardar(Venta registro);
    Venta leerRegistro(int pos);
    bool leerTodos(Venta regitros[], int cantidad);
    int contarRegistros();
    int buscarPorID(int id);
    int getNuevoID();
    bool modificarRegistro(int pos, Venta registro);

    private:
    char _nombreArchivo[30];
};