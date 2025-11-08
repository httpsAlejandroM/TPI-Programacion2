#pragma once
#include "clsProductosMenu.h"
#include "clsVendedoresMenu.h"
#include "clsClientesMenu.h"
#include "clsCategoriasMenu.h"


class App
{

    public:
    App();
    void run();
    void acercaDe();

    protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    ProductosMenu _productoMenu;
    VendedoresMenu _vendedorMenu;
    ClientesMenu _clienteMenu;
    CategoriasMenu _categoriaMenu;

    private:
    int _cantidadOpciones;

};
