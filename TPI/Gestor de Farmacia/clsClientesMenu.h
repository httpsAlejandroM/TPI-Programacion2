#pragma once
#include "clsClienteManager.h"

class ClientesMenu
{

public:
    ClientesMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    ClienteManager _clienteManager;
private:
    int _cantidadOpciones;

};


