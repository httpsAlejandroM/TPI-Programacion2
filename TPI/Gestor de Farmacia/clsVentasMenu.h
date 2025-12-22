#pragma once
#include "clsVentaManager.h"


class VentasMenu
{

public:
    VentasMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    private:
    int _cantidadOpciones;
    VentaManager _ventaManager;
};
