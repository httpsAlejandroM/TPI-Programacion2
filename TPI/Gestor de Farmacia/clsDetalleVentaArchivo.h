#pragma once
#include "clsDetalleVenta.h"

class DetalleVentaArchivo {

public:
    DetalleVentaArchivo(const char* nombreArchivo = "detalleVentas.dat");

    bool guardar(DetalleVenta registro);
    DetalleVenta leerRegistro(int pos);
    bool leerTodos(DetalleVenta registros[], int cantidad);
    int contarRegistros();
    int buscarPorID(int idDetalle);
    int getNuevoID();
    bool modificarRegistro(int pos, DetalleVenta registro);

private:
    char _nombreArchivo[30];
};
