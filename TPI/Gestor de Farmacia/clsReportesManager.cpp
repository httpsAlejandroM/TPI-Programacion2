#include "clsReportesManager.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "rlutil.h"

using namespace std;

// 1. REPORTE DE RECAUDACION POR ANIO
void ReportesManager::reporteRecaudacionAnual() {
    int anio;
    system("cls");
    cout << "--- REPORTE: RECAUDACION POR ANIO ---" << endl;
    cout << "Ingrese el anio a consultar: ";
    cin >> anio;

    int cantidad = _ventasRepo.contarRegistros();
    float totalRecaudado = 0;
    int ventasContadas = 0;

    for(int i = 0; i < cantidad; i++) {
        Venta v = _ventasRepo.leerRegistro(i);

        // venta activa y sea del anio elegido
        if(v.getEstado() && v.getFecha().getAnio() == anio) {
            totalRecaudado += v.getTotalNeto();
            ventasContadas++;
        }
    }

    cout << "\n----------------------------------------" << endl;
    cout << " RESULTADOS DEL ANIO " << anio << endl;
    cout << "----------------------------------------" << endl;
    cout << " Cantidad de Ventas: " << ventasContadas << endl;
    cout << " RECAUDACION TOTAL:  $" << fixed << setprecision(2) << totalRecaudado << endl;
    cout << "----------------------------------------" << endl;

    rlutil::anykey("Presione una tecla para volver...");
}

// 2. RANKING DE PRODUCTOS MAS VENDIDOS
void ReportesManager::reporteProductosMasVendidos() {
    system("cls");
    cout << "Generando Ranking de Productos... Por favor aguarde." << endl;

    // carga los productos en memoria dinamica
    int cantProductos = _productosRepo.contarRegistros();
    if(cantProductos == 0) {
        cout << "No hay productos registrados." << endl;
        rlutil::anykey("...");
        return;
    }

    // vector dinamico de productos
    Producto* productos = new Producto[cantProductos];
    // vector de contadores
    int* contadores = new int[cantProductos];

    // lee productos del disco y los contadores a 0
    for(int i=0; i<cantProductos; i++) {
        productos[i] = _productosRepo.leerRegistro(i);
        contadores[i] = 0;
    }

    // recorre los detalles de venta
    int cantDetalles = _detallesRepo.contarRegistros();

    for(int i=0; i < cantDetalles; i++) {
        DetalleVenta dv = _detallesRepo.leerRegistro(i);

        // detalle valido
        if(dv.getEstado()) {
            // busca el indice del vector de productos de este ID
            for(int j=0; j < cantProductos; j++) {
                if(productos[j].getIdProducto() == dv.getIdProducto()) {
                    contadores[j] += dv.getCantidad(); // suma cantidad vendida
                    break;
                }
            }
        }
    }

    // ordena vectores (burbuja) de Mayor a Menor segun cantidad vendida
    for(int i=0; i < cantProductos - 1; i++) {
        for(int j=0; j < cantProductos - i - 1; j++) {
            if(contadores[j] < contadores[j+1]) {
                // Swap contadores
                int auxCount = contadores[j];
                contadores[j] = contadores[j+1];
                contadores[j+1] = auxCount;

                // Swap productos (nombre va con su contador)
                Producto auxProd = productos[j];
                productos[j] = productos[j+1];
                productos[j+1] = auxProd;
            }
        }
    }

    // muestra Ranking
    system("cls");
    cout << "--- RANKING DE PRODUCTOS MAS VENDIDOS (TOP 10) ---" << endl;
    cout << left << setw(5) << "POS" << setw(30) << "PRODUCTO" << setw(15) << "UNIDADES" << endl;
    cout << "--------------------------------------------------" << endl;

    int top = 0;
    for(int i=0; i < cantProductos; i++) {
        // solo muestra si vendio al menos 1 unidad
        if(contadores[i] > 0) {
            top++;
            cout << left << setw(5) << top
                 << setw(30) << productos[i].getNombre()
                 << setw(15) << contadores[i] << endl;

            if(top == 10) break; //corta en top 10
        }
    }

    if(top == 0) cout << "No se registraron ventas aun." << endl;

    delete[] productos;
    delete[] contadores;

    rlutil::anykey("Presione una tecla para volver...");
}

// 3. CANTIDAD DE VENTAS POR VENDEDOR

void ReportesManager::reporteVentasPorVendedor() {
    system("cls");
    cout << "Calculando rendimiento de vendedores..." << endl;

    int cantVendedores = _vendedoresRepo.contarRegistros();
    if(cantVendedores == 0) {
        cout << "No hay vendedores." << endl;
        return;
    }

    Vendedor* vendedores = new Vendedor[cantVendedores];
    int* ventasPorVendedor = new int[cantVendedores];

    for(int i=0; i<cantVendedores; i++) {
        vendedores[i] = _vendedoresRepo.leerRegistro(i);
        ventasPorVendedor[i] = 0;
    }

    //recorre Ventas para contar
    int cantVentas = _ventasRepo.contarRegistros();

    for(int i=0; i < cantVentas; i++) {
        Venta v = _ventasRepo.leerRegistro(i);

        if(v.getEstado()) {
            // buscamos el vendedor que hizo la venta
            for(int j=0; j < cantVendedores; j++) {
                if(vendedores[j].getIdPersona() == v.getIdVendedor()) {
                    ventasPorVendedor[j]++;
                    break;
                }
            }
        }
    }

    system("cls");
    cout << "--- CANTIDAD DE VENTAS POR EMPLEADO ---" << endl;
    cout << left << setw(10) << "ID" << setw(25) << "NOMBRE" << setw(10) << "VENTAS" << endl;
    cout << "-----------------------------------------------" << endl;

    for(int i=0; i < cantVendedores; i++) {
        // muestra solo si el vendedor esta activo y tuvo ventas
        if(vendedores[i].getEstado()) {
            cout << left << setw(10) << vendedores[i].getIdPersona()
                 << setw(25) << vendedores[i].getNombre()
                 << setw(10) << ventasPorVendedor[i] << endl;
        }
    }

    delete[] vendedores;
    delete[] ventasPorVendedor;

    rlutil::anykey("Presione una tecla para volver...");
}


