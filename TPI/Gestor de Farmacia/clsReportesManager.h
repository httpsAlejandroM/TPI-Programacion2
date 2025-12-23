#pragma once
#include "clsVentasArchivo.h"
#include "clsDetalleVentaArchivo.h"
#include "clsProductosArchivo.h"
#include "clsVendedoresArchivo.h"
#include "clsVenta.h"
#include "clsDetalleVenta.h"
#include "clsProducto.h"
#include "clsVendedor.h"

class ReportesManager {

public:
    void reporteRecaudacionAnual();
    void reporteProductosMasVendidos();
    void reporteVentasPorVendedor();

private:
    VentasArchivo _ventasRepo;
    DetalleVentaArchivo _detallesRepo;
    ProductosArchivo _productosRepo;
    VendedoresArchivo _vendedoresRepo;
};
