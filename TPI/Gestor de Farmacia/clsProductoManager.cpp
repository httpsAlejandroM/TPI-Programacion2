#include "clsProductoManager.h"
#include <iostream>
#include <string>
#include "rlutil.h"
#include "utils.h"
#include <iomanip> 

using namespace std;

ProductoManager::ProductoManager() {}

void ProductoManager::cargarProducto() {
    int id, stock, idCategoria;
    float precio;
    char nombre[50], marca[50];
    char recetaChar;
    bool recetaObligatoria;

    id = _repo.getNuevoID();
    cout << "Producto #" << id << endl;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Ingrese la marca del producto: ";
    cin.getline(marca, 50);

    cout << "Ingrese el stock: ";
    cin >> stock;

    cout << "Ingrese el precio: ";
    cin >> precio;

    cout << "Ingrese la categoria del producto (ID)." << endl;
    cout << "1. Medicamentos." << endl;
    cout << "2. Perfumeria." << endl;
    cout << "3. Insumos." << endl;
    idCategoria = leerRangoInts("Opcion: ", 1, 3);

    bool confirmacion = leerSN("Requiere receta? (s/n)");

    recetaObligatoria = confirmacion;

    Producto producto(id, nombre, marca, stock, precio, true, idCategoria, recetaObligatoria);

    if (_repo.guardar(producto)) {
        cout << "Producto guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el producto." << endl;
    }
}

void ProductoManager::mostrarProducto(Producto prod) {
    string estado = prod.getEstado() ? "Habilitado" : "Deshabilitado";
    string receta = prod.getReceta() ? "Si" : "No";

    cout << "ID: " << prod.getIdProducto() << endl;
    cout << "Nombre: " << prod.getNombre() << endl;
    cout << "Marca: " << prod.getMarca() << endl;
    cout << "Stock: " << prod.getStock() << endl;
    cout << "Precio: $" << prod.getPrecio() << endl;
    cout << "Categoria (ID): " << prod.getIdCategoria() << endl;
    cout << "Requiere receta: " << receta << endl;
    cout << "Estado: " << estado << endl;
}

void ProductoManager::mostrarEnFila(Producto prod){
    string receta = prod.getReceta() ? "Si" : "No";

     cout << left
             << setw(6)  << prod.getIdProducto()
             << setw(25) << prod.getNombre()
             << setw(20) << prod.getMarca()
             << setw(10) << prod.getPrecio()
             << setw(8)  << prod.getStock()
             << setw(12) << prod.getIdCategoria()
             << setw(10) << (prod.getReceta() ? "SI" : "NO")
             << "\n";
}

void ProductoManager::listarProductos() {
    int cantidad = _repo.contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Producto p = _repo.leerRegistro(i);
        if (p.getEstado()) {
            mostrarProducto(p);
            cout << "----------------------------" << endl;
        }
    }
}

void ProductoManager::buscarProducto() {
    int id, pos;

    cout << "Introduzca el ID del producto que desea buscar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos < 0) {
        cout << "No se encontró un producto con ese ID." << endl;
        return;
    }

    Producto producto = _repo.leerRegistro(pos);
    mostrarProducto(producto);
}

void ProductoManager::eliminarProducto() {
    int id, pos;
    char confirmacion;

    cout << "Introduzca el ID del producto que desea habilitar/deshabilitar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos < 0) {
        cout << "No se encontró un producto con ese ID." << endl;
        return;
    }

    Producto prod = _repo.leerRegistro(pos);
    string accion = prod.getEstado() ? "deshabilitar" : "habilitar";

    do {
        cout << "Desea " << accion << " el producto '" << prod.getNombre() << "'? (s/n): ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            _repo.cambiarEstado(id);
            cout << "Estado cambiado con éxito." << endl;
        }
        else if (confirmacion == 'n' || confirmacion == 'N') {
            cout << "No se realizaron cambios." << endl;
        }
        else {
            cout << "Seleccione una opcion valida 's' o 'n'." << endl;
            rlutil::anykey("Presione una tecla para continuar...");
            rlutil::cls();
        }

    } while (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' && confirmacion != 'N');
}

void ProductoManager::modificarProducto() {
    int id, pos;

    cout << "Ingrese el ID del producto a modificar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);
    if (pos < 0) {
        cout << "No se encontró un producto con ese ID." << endl;
        return;
    }

    Producto p = _repo.leerRegistro(pos);

    bool continuar = true;
    int opcion;

    while (continuar) {
        cout << "----------------------------------------\n";
        cout << "PRODUCTO ACTUAL:\n";
        mostrarProducto(p);
        cout << "----------------------------------------\n";

        cout << "¿Qué desea modificar?" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Marca" << endl;
        cout << "3. Stock" << endl;
        cout << "4. Precio" << endl;
        cout << "5. ID Categoría" << endl;
        cout << "6. Receta Obligatoria" << endl;
        cout << "0. Terminar modificación" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            char nombre[50];
            cout << "Nuevo nombre: ";
            cin.getline(nombre, 50);
            p.setNombre(nombre);
            break;
        }
        case 2: {
            char marca[50];
            cout << "Nueva marca: ";
            cin.getline(marca, 50);
            p.setMarca(marca);
            break;
        }
        case 3: {
            int stock;
            cout << "Nuevo stock: ";
            cin >> stock;
            p.setStock(stock);
            break;
        }
        case 4: {
            float precio;
            cout << "Nuevo precio: ";
            cin >> precio;
            p.setPrecio(precio);
            break;
        }
        case 5: {
            int categoria;
            cout << "Nuevo ID de categoría: ";
            cin >> categoria;
            p.setIdCategoria(categoria);
            break;
        }
        case 6: {
            bool confirmacion = leerSN("Requiere receta? (s/n)");
            p.setReceta(confirmacion);
            break;
        }
        case 0:
            continuar = false;
            break;

        default:
            cout << "Opción inválida.\n";
        }

    }

    if (_repo.modificarRegistro(pos, p)) {
        cout << "Producto modificado correctamente.\n";
    } else {
        cout << "Error al modificar el producto.\n";
    }
}
