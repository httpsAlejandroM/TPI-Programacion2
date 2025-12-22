#pragma once
#include "clsVendedoresArchivo.h"
 
class VendedorManager {

public:
    VendedorManager();
    void cargarVendedor();
    void listarVendedores();
    void eliminarVendedor();
    void modificarVendedor();
    void buscarVendedor();
    Vendedor buscarVendedor(int dni);

protected:
    void mostrarVendedor(Vendedor vendedor);

private:
    VendedoresArchivo _repo;
};
