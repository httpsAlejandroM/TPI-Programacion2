#pragma once
#include "clsVendedoresManager.h"

class VendedoresMenu
{

public:
    VendedoresMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);


private:
    int _cantidadOpciones;
    VendedorManager _vendedorManager;
};

