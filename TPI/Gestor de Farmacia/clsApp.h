#pragma once
#include "clsProductosMenu.h"
#include "clsVendedoresMenu.h"
#include "clsClientesMenu.h"


class App
{

    public:
    App();
    void run();

    protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    ProductosMenu _productoMenu;
    VendedoresMenu _vendedorMenu;
    ClientesMenu _clienteMenu;
    private:
    int _cantidadOpciones;

};
