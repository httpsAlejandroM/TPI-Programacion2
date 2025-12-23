#pragma once
#include "clsProductosMenu.h"
#include "clsVendedoresMenu.h"
#include "clsClientesMenu.h"
#include "clsCategoriasMenu.h"
#include "clsObrasSocialesMenu.h"
#include "clsVentasMenu.h"
#include "clsReportesMenu.h"

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
    ObrasSocialesMenu _obraSocialMenu;
    VentasMenu _ventaMenu;
    ReportesMenu _reportesMenu;

    private:
    int _cantidadOpciones;

};
