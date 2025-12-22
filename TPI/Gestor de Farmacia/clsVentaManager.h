#pragma once
#include "clsClientesArchivo.h"
#include "clsObrasSocialesArchivo.h"
#include "clsVentasArchivo.h"
#include "clsDetalleVentaArchivo.h"
#include "clsVenta.h"
#include "clsDetalleVenta.h"
#include "clsProductosArchivo.h"
#include "clsVendedoresArchivo.h"

class VentaManager {

public:
    VentaManager();

    void nuevaVentaMenu();
    // void anularVenta();
    // void listarVentasPorRangoFecha();
    // void buscarVentaPorID();

protected:
    int cargarVendedor();
    int cargarCliente(int &idObraSocial);
    // int cargarMetodoPago();
    void agregarProductos(DetalleVenta* &detalles, int &cantidad, float &totalBruto);

    // void mostrarVenta(Venta venta);
    // void mostrarDetalleVenta(DetalleVenta detalle);

private:
    VentasArchivo _ventasRepo;
    DetalleVentaArchivo _detalleRepo;
    VendedoresArchivo _vendedoresRepo;
    ClientesArchivo _clientesRepo;
    ObrasSocialesArchivo _obrasSocialesRepo;
    ProductosArchivo _productosRepo;
    void buscarProductoPorNombre(DetalleVenta* &detalles, int &cantidad, float &totalBruto);
    // void listarProductosDisponibles();
    // void ingresarProductoPorID(DetalleVenta* &detalles, int &cantidad, float &totalBruto);
};
