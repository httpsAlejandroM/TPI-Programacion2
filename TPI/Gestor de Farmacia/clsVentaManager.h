#pragma once
#include "clsClientesArchivo.h"
#include "clsObrasSocialesArchivo.h"
#include "clsVentasArchivo.h"
#include "clsDetalleVentaArchivo.h"
#include "clsVenta.h"
#include "clsDetalleVenta.h"
#include "clsProductosArchivo.h"
#include "clsVendedoresArchivo.h"
#include "clsCategoriasArchivo.h"

class VentaManager {

public:
    VentaManager();

    void nuevaVentaMenu();
    void listarVentas();
    void buscarVentaPorID();

protected:
    int cargarVendedor(Vendedor &vendedor);
    int cargarCliente(Cliente &cliente, Venta &venta);
    void agregarProductos(Venta &venta, DetalleVenta* &detalle, int &cantDetalles);
    void seleccionarMetodoPago(Venta &venta);
    int guardarVenta(Venta &venta, DetalleVenta* &detalles, int &cantDetalles);

    // void mostrarVenta(Venta venta);
    // void mostrarDetalleVenta(DetalleVenta detalle);

private:
    VentasArchivo _ventasRepo;
    DetalleVentaArchivo _detalleRepo;
    VendedoresArchivo _vendedoresRepo;
    ClientesArchivo _clientesRepo;
    ObrasSocialesArchivo _obrasSocialesRepo;
    ProductosArchivo _productosRepo;
    CategoriasArchivo _categoriaRepo;

    void buscarProductoPorNombre(Venta &venta, DetalleVenta* &detalle, int &cantDetalles);
    void listarProductosDisponibles(Venta &venta, DetalleVenta* &detalle, int &cantDetalles);
    void ingresarProductoPorID(Venta &venta, DetalleVenta* &detalles, int &cantidad);
    void listarProductosCarrito(DetalleVenta* &detalles, int cantDetalles);
};
