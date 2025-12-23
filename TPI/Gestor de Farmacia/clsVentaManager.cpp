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

    Venta venta;
    venta.setIdVenta(_ventasRepo.getNuevoID());
    DetalleVenta* detalles = nullptr;
    int cantDetalles = 0;

    Vendedor vendedor;           
    Cliente cliente;
    int opcion;

    do {
        system("cls");

        cout << "----- NUEVA VENTA -----" << endl;
        cout << "1) Seleccionar vendedor -> " << (venta.getIdVendedor() == 0 ? "[SIN CARGAR]" : vendedor.getNombre()) << endl;
        cout << "2) Seleccionar cliente  -> " << (venta.getIdCliente() == 0 ? "[SIN CARGAR]" : to_string(venta.getIdCliente())) << endl;
        cout << "3) Agregar productos    -> (" << cantDetalles << " productos)" << endl;
        cout << "4) Metodo de pago       -> " << (strcmp(venta.getMetodoPago(), "-") == 0 ? "[SIN CARGAR]" : venta.getMetodoPago()) << endl;
        cout << "5) Ver resumen de venta" << endl;
        cout << "6) Confirmar y guardar" << endl;
        cout << "0) Cancelar" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;
        system("cls");

        switch (opcion) {

        case 1:
            venta.setIdVendedor(cargarVendedor(vendedor));
            break;
        case 2:
            venta.setIdCliente(cargarCliente(cliente, venta));   
            break;
        case 3:
            agregarProductos(venta, detalles, cantDetalles);
            break;

        case 4: 
            seleccionarMetodoPago(venta);
            break;

        case 5: {
            float totalNeto = venta.getTotalBruto() * (1 - venta.getDescuento()/100.0f);
            venta.setTotalNeto(totalNeto);

            cout << "------------------ RESUMEN DE LA VENTA ------------------" << endl;
            cout << "Nro comprobante: " << venta.getIdVenta() << endl;
            cout << "Fecha: " << venta.getFecha().toString() << endl;
            cout << "Vendedor ID: " << venta.getIdVendedor() << endl;
            cout << "Cliente ID : " << venta.getIdCliente() << endl;
            cout << "Total bruto: $" << venta.getTotalBruto() << endl;
            cout << "Descuento  : %" << venta.getDescuento() << endl;
            cout << "Total neto : $" << totalNeto << endl;
            cout << "Metodo pago: " << venta.getMetodoPago() << endl;
            cout << "Productos  : " << cantDetalles << endl;

            rlutil::anykey("Presione una tecla para continuar...");
        }
        break;
        case 6: {
            opcion = guardarVenta(venta, detalles, cantDetalles);
        }
        break;
        case 0:
            cout << "Venta cancelada." << endl;
            delete[] detalles;
            return;
        default:
            cout << "Opcion invalida." << endl;
            rlutil::anykey("Presione una tecla...");
            break;
        }

    } while (opcion != 0);
}


int VentaManager::cargarVendedor(Vendedor &vendedor) {
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
    vendedor = vend;
    return dni; 
}

int VentaManager::cargarCliente(Cliente &cliente, Venta &venta) {
    system("cls");
    cout << "--- CARGAR CLIENTE ---" << endl;

    int dni;
    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    int pos = _clientesRepo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "El cliente NO esta registrado en el sistema." << endl;
        bool confirmacion = leerSN("¿Desea continuar igual con este DNI? (S/N): ");

        if (confirmacion) {
            cout << "Continuara la venta sin cliente registrado." << endl;
            rlutil::anykey("Presione una tecla para continuar...");
            venta.setDescuento(0);
            return dni;
        }

        cout << "Cancelando carga de cliente." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return 0;  
    }

    Cliente cli = _clientesRepo.leerRegistro(pos);

    if (!cli.getEstado()) {
        cout << "El cliente esta dado de BAJA y no puede realizar compras." << endl;
        rlutil::anykey("Presione una tecla para continuar...");
        return -1;
    }

    int idObrasocial = cli.getIdObraSocial();    
    int posOS = _obrasSocialesRepo.buscarPorID(idObrasocial);
    ObraSocial os = _obrasSocialesRepo.leerRegistro(posOS);
    venta.setDescuento(os.getPorcentajeDescuento());

    cout << "Cliente encontrado: " << cli.getNombre() << endl;
    cout << "Obra Social: " << os.getNombre() << endl;

    cliente = cli;
    rlutil::anykey("Presione una tecla para continuar...");
    return dni;     
}

void VentaManager::agregarProductos(Venta &venta, DetalleVenta* &detalles, int &cantDetalles) {
    int opcion;

    do {
        system("cls");
        cout << "=== AGREGAR PRODUCTOS A LA VENTA ==="<< endl;
        cout << "1) Buscar producto por nombre"<< endl;
        cout << "2) Listar todos los productos"<< endl;
        cout << "3) Ingresar ID manualmente"<< endl;
        cout << "4) Listar productos del carrito" << endl;
        cout << "0) Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            buscarProductoPorNombre(venta, detalles, cantDetalles);
            break;

        case 2:
            listarProductosDisponibles(venta, detalles, cantDetalles);
            break;

        case 3:
            ingresarProductoPorID(venta, detalles, cantDetalles);
            break;
        case 4:
            listarProductosCarrito(detalles, cantDetalles);
            break;
        case 0:
            return;

        default:
            cout << "Opcion invalida.\n";
            system("pause");
        }

    } while (opcion != 0);
}

void VentaManager::buscarProductoPorNombre(Venta &venta, DetalleVenta* &detalle, int &cantDetalles) {
    char busqueda[50];
    cout << "Ingrese nombre de producto a buscar: ";
    cin.ignore();
    cin.getline(busqueda, 50);

    system("cls");

   cout << "-------------------------------------------- RESULTADOS DE LA BUSQUEDA --------------------------------------------\n";

int cant = _productosRepo.contarRegistros();
bool hayResultados = false;

// Encabezado
cout << left
     << setw(6) << " "
     << setw(6)  << "ID"
     << setw(25) << "NOMBRE"
     << setw(20) << "MARCA"
     << setw(10) << "PRECIO"
     << setw(8)  << "STOCK"
     << setw(15) << "CATEGORIA"
     << setw(10) << "RECETA"
     << "\n";

// Línea separadora
cout << string(95, '-') << endl << endl;

for (int i = 0; i < cant; i++) {
    Producto p = _productosRepo.leerRegistro(i);

    if (!p.getEstado()) continue;

    if (contieneTexto(p.getNombre(), busqueda)) {
        hayResultados = true;
        p.mostrarEnFila();
    }
}
    if (!hayResultados) {
        cout << "No se encontraron coincidencias.\n";
        rlutil::anykey("Presione una tecla para volver al menu anterior...");
        return;
    }

    ingresarProductoPorID(venta, detalle, cantDetalles);
}

void VentaManager::ingresarProductoPorID(Venta &venta, DetalleVenta* &detalles, int &cantDetalles) {
    int idProducto, unidades, resp;
    char confirmacion;
    
    cout << "\n\nIngrese Id del producto: " ;
    cin >> idProducto;
    cout << endl;

    int pos = _productosRepo.buscarPorID(idProducto);

    if(pos < 0 ) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    Producto prod = _productosRepo.leerRegistro(pos);

    if(!prod.getEstado()){
        cout << "El producto esta deshabilitado." << endl;
        return;
    }

    int posCategoria = _categoriaRepo.buscarPorID(prod.getIdCategoria());
    Categoria categoria = _categoriaRepo.leerRegistro(posCategoria);

    cout << "Nombre del producto " << prod.getNombre() << endl;
    cout << "Categoria: " << categoria.getNombre() << endl;
    cout << "Stock disponible: " << prod.getStock() << endl;
    cout << "Precio: " << prod.getPrecio() << endl << endl;


    bool cantValida = false;

    do {
        cout << "Cuantas unidades quiere agregar? (0 para cancelar): ";
        cin >> unidades;

        if(unidades == 0) {
            cout << "Operacion cancelada." << endl;
            return;
        }

        if (unidades < 0 || unidades > prod.getStock()) {
        cout << "Cantidad invalida." << endl;
        } else {
            cantValida = true;
        }

    } while (cantValida == false);
    

    do
    {

        cout << "Esta seguro que desea agregar " << unidades << " " << prod.getNombre() << "? S/N: ";
        cin >> confirmacion;

        resp = charToBoolSN(confirmacion);

        if (resp == -1) {
        cout << "Opcion invalida. Ingrese S o N." << endl;
    }
    } while (resp == -1);
    
      if (resp == 0) {
        cout << "Operacion cancelada." << endl;
        return;
    }

    DetalleVenta nuevoDetalleVenta;
    
    nuevoDetalleVenta.setIdDetalle(_detalleRepo.getNuevoID());
    nuevoDetalleVenta.setIdVenta(venta.getIdVenta());
    nuevoDetalleVenta.setIdProducto(prod.getIdProducto());
    nuevoDetalleVenta.setCantidad(unidades);
    nuevoDetalleVenta.setPrecioUnitario(prod.getPrecio());

   


    DetalleVenta* nuevoArray = new DetalleVenta[cantDetalles + 1];
    float totalBruto = venta.getTotalBruto();
    for (int i = 0; i < cantDetalles; i++){
        nuevoArray[i] = detalles[i];
    }

    nuevoArray[cantDetalles] = nuevoDetalleVenta;

    delete[] detalles;
    detalles = nuevoArray;
    cantDetalles++;

    totalBruto += nuevoDetalleVenta.getSubtotal();
    venta.setTotalBruto(totalBruto);

    cout << "Producto agregado correctamente." << endl;
}

void VentaManager::listarProductosCarrito(DetalleVenta* &detalles, int cantDetalles){
    if (cantDetalles == 0) {
        cout << "No hay productos agregados a la venta." << endl;
        rlutil::anykey("Presione una tecla para volver al menu anterior...");
        return;
    }

    cout << "\n-------------------------------------------- PRODUCTOS EN CARRITO --------------------------------------------\n";

    cout << left
         << setw(6) << " "
         << setw(6)  << "ID"
         << setw(25) << "NOMBRE"
         << setw(20) << "MARCA"
         << setw(10) << "PRECIO"
         << setw(8)  << "UNID"
         << setw(15) << "CATEGORIA"
         << setw(10) << "RECETA"
         << setw(12) << "SUBTOTAL"
         << "\n";

    cout << string(115, '-') << endl;

    for (int i = 0; i < cantDetalles; i++) {

        int idProd = detalles[i].getIdProducto();
        int posProd = _productosRepo.buscarPorID(idProd);

        Producto prod = _productosRepo.leerRegistro(posProd);

        int posCat = _categoriaRepo.buscarPorID(prod.getIdCategoria());
        Categoria cat = _categoriaRepo.leerRegistro(posCat);

        cout << left
             << setw(6) << " "
             << setw(6)  << prod.getIdProducto()
             << setw(25) << prod.getNombre()
             << setw(20) << prod.getMarca()
             << setw(10) << prod.getPrecio()
             << setw(8)  << detalles[i].getCantidad()
             << setw(15) << cat.getNombre()
             << setw(10) << (prod.getReceta() ? "SI" : "NO")
             << setw(12) << detalles[i].getSubtotal()
             << endl;
    }

    cout << string(115, '-') << endl;

    rlutil::anykey("Presione una tecla para volver al menu anterior...");
}

void VentaManager::listarProductosDisponibles(Venta &venta, DetalleVenta* &detalles, int &cantDetalles){
    int cantProd = _productosRepo.contarRegistros();
    system("cls");
    cout << "\n-------------------------------------------- PRODUCTOS DISPONIBLES --------------------------------------------\n";

    cout << left
         << setw(6) << " "
         << setw(6)  << "ID"
         << setw(25) << "NOMBRE"
         << setw(20) << "MARCA"
         << setw(10) << "PRECIO"
         << setw(8)  << "STOCK"
         << setw(15) << "CATEGORIA"
         << setw(10) << "RECETA"
         << "\n";

    cout << string(95, '-') << endl;

    bool hayProductos = false;

    for (int i = 0; i < cantProd; i++) {

        Producto prod = _productosRepo.leerRegistro(i);

        if (!prod.getEstado() || prod.getStock() <= 0) continue;

        int posCat = _categoriaRepo.buscarPorID(prod.getIdCategoria());
        Categoria cat = _categoriaRepo.leerRegistro(posCat);

        cout << left
             << setw(6) << " "
             << setw(6)  << prod.getIdProducto()
             << setw(25) << prod.getNombre()
             << setw(20) << prod.getMarca()
             << setw(10) << prod.getPrecio()
             << setw(8)  << prod.getStock()
             << setw(15) << cat.getNombre()
             << setw(10) << (prod.getReceta() ? "SI" : "NO")
             << endl;

        hayProductos = true;
    }

    if (!hayProductos) {
        cout << "No hay productos disponibles para la venta." << endl;
    }

    cout << string(95, '-') << endl << endl;

    ingresarProductoPorID(venta, detalles, cantDetalles);
    rlutil::anykey("Presione una tecla para continuar...");
}

void VentaManager::seleccionarMetodoPago(Venta &venta) {

    int opcion;

    do {
        system("cls");

        cout << "--- SELECCIONAR METODO DE PAGO ---" << endl << endl;
        cout << "1) Efectivo"<< endl;
        cout << "2) Debito"<< endl;
        cout << "3) Credito"<< endl;
        cout << "4) QR"<< endl;
        cout << "0) Volver"<< endl << endl;

        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1:
            venta.setMetodoPago("Efectivo");
            cout << "Metodo de pago seleccionado: EFECTIVO" << endl;
            rlutil::anykey("Presione una tecla para terminar...");
            break;

        case 2:
            venta.setMetodoPago("Debito");
            cout << "Metodo de pago seleccionado: DEBITO" << endl;
            rlutil::anykey("Presione una tecla para terminar...");
            break;

        case 3:
            venta.setMetodoPago("Credito");
            cout << "Metodo de pago seleccionado: CREDITO" << endl;
            rlutil::anykey("Presione una tecla para terminar...");
            break;

        case 4:
            venta.setMetodoPago("QR");
            cout << "Metodo de pago seleccionado: QR" << endl << endl;
            rlutil::anykey("Presione una tecla para terminar...");
            break;

        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }

    } while (opcion != 0);
}

int VentaManager::guardarVenta(Venta &venta, DetalleVenta* &detalles, int &cantDetalles){

if (venta.getIdVendedor() == 0 || cantDetalles == 0 || strcmp(venta.getMetodoPago(), "-") == 0) {

    cout << "Faltan datos obligatorios para guardar la venta." << endl;
    rlutil::anykey("Presione una tecla...");
    return 0;
}

            float totalNeto = venta.getTotalBruto() * (1 - venta.getDescuento()/100.0f);
            venta.setTotalNeto(totalNeto);

            if (!_ventasRepo.guardar(venta)) {
                cout << "Error al guardar la venta." << endl;
                rlutil::anykey("Presione una tecla...");
            }

            for (int i = 0; i < cantDetalles; i++) {
                _detalleRepo.guardar(detalles[i]);   
            }

            delete[] detalles;

            cout << "Venta guardada correctamente. ID = " << venta.getIdVenta() << endl;
            return 0;
         
}


