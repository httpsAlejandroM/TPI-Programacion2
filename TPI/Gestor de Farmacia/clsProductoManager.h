#pragma once
#include "clsProductosArchivo.h"   
#include "clsProducto.h"

class ProductoManager {

public:
    ProductoManager();

    void cargarProducto();
    void listarProductos();
    void eliminarProducto();      
    void modificarProducto();
    void buscarProducto();

protected:
    void mostrarProducto(Producto producto);

private:
    ProductosArchivo _repo;      
};
