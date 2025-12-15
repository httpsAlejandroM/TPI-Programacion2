#pragma once
#include "clsVentasArchivo.h"
//#include "clsDetalleVentaArchivo.h"
#include "clsVenta.h"
#include "clsDetalleVenta.h"
//TODO: hacer ventaManager.cpp

class VentaManager {

public:
    VentaManager();

    void nuevaVenta();
    void listarVentas();
    void buscarVenta();

protected:
    void mostrarVenta(Venta venta);
    void mostrarDetalleVenta(DetalleVenta detalle);

private:
    VentasArchivo _ventasRepo;
   // DetalleVentaArchivo _detalleRepo;
};
