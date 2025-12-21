#include "clsVendedoresManager.h"
#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

VendedorManager::VendedorManager() {}

void VendedorManager::cargarVendedor() {
    int dni;
    char nombre[50], mail[40], telefono[20], direccion[50];
    Fecha fechaNacimiento;
    bool estado = true;

    cout << "Ingrese DNI del vendedor: ";
    cin >> dni;

    cin.ignore();
    cout << "Ingrese nombre: ";
    cin.getline(nombre, 50);

    cout << "Ingrese fecha de nacimiento: " << endl;
    fechaNacimiento.cargar();

    cin.ignore();
    cout << "Ingrese mail: ";
    cin.getline(mail, 40);

    cout << "Ingrese telefono: ";
    cin.getline(telefono, 20);

    cout << "Ingrese direccion: ";
    cin.getline(direccion, 50);

    Vendedor vendedor(dni, nombre, fechaNacimiento, mail, telefono, direccion, estado);

    if (_repo.guardar(vendedor)) {
        cout << "Vendedor guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar vendedor." << endl;
    }
}

void VendedorManager::mostrarVendedor(Vendedor vendedor) {
    string estado = vendedor.getEstado() ? "Habilitado" : "Deshabilitado";

    cout << "DNI: " << vendedor.getIdPersona() << endl;
    cout << "Nombre: " << vendedor.getNombre() << endl;
    cout << "Fecha nacimiento: " << vendedor.getFechaNacimiento().toString() << endl;
    cout << "Mail: " << vendedor.getMail() << endl;
    cout << "Direccion: " << vendedor.getDireccion() << endl;
    cout << "Telefono: " << vendedor.getTelefono() << endl;
    cout << "Estado: " << estado << endl;
}

void VendedorManager::listarVendedores() {
    int cantidad = _repo.contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Vendedor vend = _repo.leerRegistro(i);

        if (vend.getEstado()) {
            mostrarVendedor(vend);
            cout << "----------------------------" << endl;
        }
    }
}


void VendedorManager::eliminarVendedor() {
    int dni, pos;
    char confirmacion;
    string accion;

    cout << "Ingrese DNI del vendedor a habilitar/deshabilitar: ";
    cin >> dni;

    pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontró un vendedor con el DNI " << dni << endl;
        return;
    }

    Vendedor vendedor = _repo.leerRegistro(pos);
    accion = vendedor.getEstado() ? "deshabilitar" : "habilitar";

    do {
        cout << "Desea " << accion << " al vendedor: " << vendedor.getNombre()
             << "? Ingrese 's'(SI) o 'n'(NO): ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            _repo.cambiarEstado(dni);
            cout << "Estado del vendedor cambiado correctamente." << endl;
        }
        else if (confirmacion == 'n' || confirmacion == 'N') {
            cout << "No se realizaron cambios." << endl;
        }
        else {
            cout << "Seleccione 's' o 'n'." << endl;
            rlutil::anykey("Presione una tecla...");
            rlutil::cls();
        }
    } while (confirmacion != 's' && confirmacion != 'S' &&
             confirmacion != 'n' && confirmacion != 'N');
}


void VendedorManager::buscarVendedor() {
    int dni;
    cout << "Ingrese DNI del vendedor a buscar: ";
    cin >> dni;

    int pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontró un vendedor con ese DNI." << endl;
        return;
    }

    Vendedor vend = _repo.leerRegistro(pos);
    mostrarVendedor(vend);
}

Vendedor VendedorManager::buscarVendedor(int dni) {
    Vendedor vendedor;

    int pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        return vendedor;
    }

    vendedor = _repo.leerRegistro(pos);
    return vendedor;
}

void VendedorManager::modificarVendedor() {
    int dni, pos;

    cout << "Ingrese DNI del vendedor a modificar: ";
    cin >> dni;

    pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontró un vendedor con ese DNI." << endl;
        return;
    }

    Vendedor vendedorOriginal = _repo.leerRegistro(pos);
    Vendedor modificado = vendedorOriginal;

    int opcion;
    bool seguir = true;

    while (seguir) {
        cout << "\n--- Campos modificables ---\n";
        cout << "1. Nombre\n";
        cout << "2. Fecha Nacimiento\n";
        cout << "3. Mail\n";
        cout << "4. Telefono\n";
        cout << "5. Direccion\n";
        cout << "0. Terminar modificacion\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

            case 1: {
                char nombre[50];
                cout << "Nuevo nombre: ";
                cin.getline(nombre, 50);
                modificado.setNombre(nombre);
                break;
            }

            case 2: {
                Fecha f;
                cout << "Nueva fecha de nacimiento:\n";
                f.cargar();
                modificado.setFechaNacimiento(f);
                break;
            }

            case 3: {
                char mail[40];
                cout << "Nuevo mail: ";
                cin.getline(mail, 40);
                modificado.setMail(mail);
                break;
            }

            case 4: {
                char tel[20];
                cout << "Nuevo telefono: ";
                cin.getline(tel, 20);
                modificado.setTelefono(tel);
                break;
            }

            case 5: {
                char direccion[50];
                cout << "Nueva direccion: ";
                cin.getline(direccion, 50);
                modificado.setDireccion(direccion);
                break;
            }

            case 0:
                seguir = false;
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    }

    if (_repo.modificarRegistro(pos, modificado)) {
        cout << "Vendedor modificado correctamente.\n";
    } else {
        cout << "Error al modificar vendedor.\n";
    }
}

