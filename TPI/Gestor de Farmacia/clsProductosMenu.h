#pragma once
#include "clsProductoManager.h"

class ProductosMenu
{

public:
    ProductosMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    ProductoManager _productoManager;
private:
    int _cantidadOpciones;

};
