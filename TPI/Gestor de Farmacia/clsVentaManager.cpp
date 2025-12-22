#include "clsVentaManager.h"
#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "utils.h"
#include <iomanip> 

using namespace std;

VentaManager::VentaManager(){

}


void VentaManager::nuevaVentaMenu() {

    int idVendedor = 0;
    int idCliente = 0;
    char metodoPago[20] = " ";
    float totalBruto = 0;
    float descuento = 0;
    int idObraSocial = 0;

    DetalleVenta* detalles = nullptr;
    int cantDetalles = 0;

    int opcion;

    do {
        system("cls");

        cout << "----- NUEVA VENTA -----" << endl;
        cout << "1) Seleccionar vendedor         -> " << (idVendedor == 0 ? "[SIN CARGAR]" : to_string(idVendedor)) << endl;
        cout << "2) Seleccionar cliente          -> " << (idCliente == 0 ? "[SIN CARGAR]" : to_string(idCliente)) << endl;
        cout << "3) Agregar productos       -> (" << cantDetalles << " productos)" << endl;
        cout << "4) Definir metodo de pago  -> " << (metodoPago[0] == ' ' ? "[SIN CARGAR]" : metodoPago) << endl;
        cout << "5) Aplicar descuento       -> $" << descuento << endl;
        cout << "6) Ver resumen de la venta" << endl;
        cout << "7) Confirmar y guardar venta" << endl;
        cout << "0) Cancelar" << endl;

        cout << "-------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion) {

        case 1:
            idVendedor = cargarVendedor();
            break;

        case 2:
            idCliente = cargarCliente(idObraSocial);
            break;

        case 3:
            agregarProductos(detalles, cantDetalles, totalBruto);
            break;

        case 4:
            {
                cout << "Metodo de pago (ej: Efectivo, Debito, Credito, QR): ";
                cin.ignore();
                cin.getline(metodoPago, 20);
            }
            break;

        case 5:
            {
                cout << "Aplicar descuento ($): ";
                cin >> descuento;
                if(descuento < 0) descuento = 0;
                if(descuento > totalBruto) descuento = totalBruto;
            }
            break;

        case 6:
            {
                float totalNeto = totalBruto - descuento;

                cout << "--- RESUMEN DE LA VENTA ---" << endl;
                cout << "Vendedor: " << idVendedor << endl;
                cout << "Cliente : " << idCliente << endl;
                cout << "Metodo de pago: " << metodoPago << endl;
                cout << "Total Bruto: $" << totalBruto << endl;
                cout << "Descuento: $" << descuento << endl;
                cout << "Total Neto: $" << totalNeto << endl;
                cout << "Cantidad de productos: " << cantDetalles << endl;

                rlutil::anykey("Presione una tecla para continuar...");
            }
            break;

        case 7:
            {
                /// Validaciones mínimas
                if (idCliente == 0 || idVendedor == 0 || cantDetalles == 0 || metodoPago[0] == ' ') {
                    cout << "Faltan datos obligatorios para guardar la venta." << endl;
                    rlutil::anykey("Presione una tecla...");
                    break;
                }

                /// Crear la venta
                int idVenta = _ventasRepo.getNuevoID();

                Fecha fechaHoy;

                float totalNeto = totalBruto - descuento;

                Venta v(idVenta, fechaHoy, idCliente, idVendedor,
                        totalBruto, descuento, totalNeto, metodoPago, true);

                /// Guardar venta
                if (!_ventasRepo.guardar(v)) {
                    cout << "Error al guardar la venta." << endl;
                    rlutil::anykey("Presione una tecla...");
                    break;
                }

                /// Guardar todos los detalles
                for (int i = 0; i < cantDetalles; i++) {
                    detalles[i].setIdVenta(idVenta);
                    _detalleRepo.guardar(detalles[i]);
                }

                cout << "Venta guardada correctamente. ID = " << idVenta << endl;

                delete[] detalles;  // liberar memoria
                rlutil::anykey("Presione una tecla...");
                return; /// salir del menu

            }
            break;

        case 0:
            cout << "Venta cancelada." << endl;
            delete[] detalles;  // liberar si corresponde
            rlutil::anykey("Presione una tecla...");
            return;

        default:
            cout << "Opcion invalida." << endl;
            rlutil::anykey("Presione una tecla...");
            break;
        }

    } while(opcion != 0);
}


int VentaManager::cargarVendedor() {
    system("cls");
    cout << "--- CARGAR VENDEDOR ---" << endl;

    int dni;
    cout << "Ingrese DNI del vendedor: ";
    cin >> dni;

    int pos = _vendedoresRepo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "ERROR: El vendedor no esta registrado en el sistema." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return 0;
    }

    Vendedor vend = _vendedoresRepo.leerRegistro(pos);

    if (vend.getEstado() == false) {
        cout << "ERROR: El vendedor existe pero esta DESHABILITADO." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return 0;
    }

    cout << "Vendedor encontrado: " << vend.getNombre() << endl;

    rlutil::anykey("Presione una tecla para continuar...");
    return dni; 
}

int VentaManager::cargarCliente(int &idObrasocial) {
    system("cls");
    cout << "--- CARGAR CLIENTE ---" << endl;

    int dni;
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    int pos = _clientesRepo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "El cliente NO está registrado en el sistema." << endl;
        bool confirmacion = leerSN("¿Desea continuar igual con este DNI? (S/N): ");

        if (confirmacion) {
            cout << "Continuará la venta sin cliente registrado." << endl;
            rlutil::anykey("Presione una tecla para continuar...");
            return dni;
        }

        cout << "Cancelando carga de cliente." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return 0;  
    }

    Cliente cli = _clientesRepo.leerRegistro(pos);

    if (!cli.getEstado()) {
        cout << "ERROR: El cliente está dado de BAJA y no puede realizar compras." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return -1;
    }

    idObrasocial = cli.getIdObraSocial();    
    cout << "Cliente encontrado: " << cli.getNombre() << endl;
    cout << "Obra Social ID: " << cli.getIdObraSocial() << endl;


    rlutil::anykey("Presione una tecla para continuar...");
    return dni;     
}

void VentaManager::agregarProductos(DetalleVenta* &detalles, int &cantidad, float &totalBruto) {
    int opcion;

    do {
        system("cls");
        cout << "=== AGREGAR PRODUCTOS A LA VENTA ===\n";
        cout << "1) Buscar producto por nombre\n";
        cout << "2) Listar productos disponibles\n";
        cout << "3) Ingresar ID manualmente\n";
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            buscarProductoPorNombre(detalles, cantidad, totalBruto);
            break;

        case 2:
            // listarProductosDisponibles();
            // ingresarProductoPorID(detalles, cantidad, totalBruto);
            break;

        case 3:
            // ingresarProductoPorID(detalles, cantidad, totalBruto);
            break;

        case 0:
            return;

        default:
            cout << "Opcion invalida.\n";
            system("pause");
        }

    } while (opcion != 0);
}

void VentaManager::buscarProductoPorNombre(DetalleVenta* &detalles, int &cantidad, float &totalBruto) {
    char busqueda[50];
    cout << "Ingrese nombre de producto a buscar: ";
    cin.ignore();
    cin.getline(busqueda, 50);

    system("cls");

   cout << "--- RESULTADOS DE LA BÚSQUEDA ---\n\n";

int cant = _productosRepo.contarRegistros();
bool hayResultados = false;

// Encabezado
cout << left
     << setw(6)  << "ID"
     << setw(25) << "NOMBRE"
     << setw(20) << "MARCA"
     << setw(10) << "PRECIO"
     << setw(8)  << "STOCK"
     << setw(12) << "CATEGORIA"
     << setw(10) << "RECETA"
     << "\n";

// Línea separadora
cout << string(95, '-') << "\n";

for (int i = 0; i < cant; i++) {
    Producto p = _productosRepo.leerRegistro(i);

    if (!p.getEstado()) continue;

    //contieneTexto(p.getNombre(), busqueda)
    //strstr(p.getNombre(), busqueda) != nullptr
    if (contieneTexto(p.getNombre(), busqueda)) {
        hayResultados = true;
        p.mostrarEnFila();
    }
}
    if (!hayResultados) {
        cout << "\nNo se encontraron coincidencias.\n";
        system("pause");
        return;
    }

    cout << "\nIngrese ID para agregar: ";
    int id;
    cin >> id;

    // ingresarProductoPorID(detalles, cantidad, totalBruto);
}



