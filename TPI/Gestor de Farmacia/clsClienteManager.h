#pragma once
#include "clsClientesArchivo.h"

class ClienteManager {

public:
    ClienteManager();
    void cargarCliente();
    void listarClientes();
    void eliminarCliente();
    void modificarCliente();
    void buscarCliente();

protected:
    void mostrarCliente(Cliente cliente);

private:
    ClientesArchivo _repo;
};
