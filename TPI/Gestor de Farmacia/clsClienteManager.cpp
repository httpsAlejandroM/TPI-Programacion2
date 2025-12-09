#include "clsClienteManager.h"
#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

ClienteManager::ClienteManager() {}

void ClienteManager::cargarCliente() {
    int dni, idObraSocial;
    char nombre[50], mail[50], telefono[20];
    Fecha fechaNacimiento;
    bool estado = true;

    cout << "Ingrese DNI del cliente: ";
    cin >> dni;

    cin.ignore();
    cout << "Ingrese nombre: ";
    cin.getline(nombre, 50);

    cout << "Ingrese fecha de nacimiento: " << endl;
    fechaNacimiento.cargar();   // Asumiendo que tu clsFecha tiene un cargar()

    cin.ignore();
    cout << "Ingrese mail: ";
    cin.getline(mail, 50);

    cout << "Ingrese telefono: ";
    cin.getline(telefono, 20);

    cout << "Ingrese ID de la obra social: ";
    cin >> idObraSocial;

    Cliente cliente(dni, nombre, fechaNacimiento, mail, telefono, idObraSocial, estado);

    if (_repo.guardar(cliente)) {
        cout << "Cliente guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar cliente." << endl;
    }
}

void ClienteManager::mostrarCliente(Cliente cliente) {
    string estado = cliente.getEstado() ? "Habilitado" : "Deshabilitado";

    cout << "DNI: " << cliente.getIdPersona() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Fecha nacimiento: " << cliente.getFechaNacimiento().toString() << endl;
    cout << "Mail: " << cliente.getMail() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "ID Obra Social: " << cliente.getIdObraSocial() << endl;
    cout << "Estado: " << estado << endl;
}

void ClienteManager::listarClientes() {
    int cantidad = _repo.contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente cli = _repo.leerRegistro(i);

        if (cli.getEstado()) {
            mostrarCliente(cli);
            cout << "----------------------------" << endl;
        }
    }
}

void ClienteManager::eliminarCliente() {
    int dni, pos;
    char confirmacion;
    string accion;

    cout << "Ingrese DNI del cliente a habilitar/deshabilitar: ";
    cin >> dni;

    pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontro un cliente con el DNI " << dni << endl;
        return;
    }

    Cliente cliente = _repo.leerRegistro(pos);
    accion = cliente.getEstado() ? "deshabilitar" : "habilitar";

    do {
        cout << "Desea " << accion << " al cliente: " << cliente.getNombre()
             << "? Ingrese 's'(SI) o 'n'(NO): ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            _repo.cambiarEstado(dni);
            cout << "Estado del cliente cambiado correctamente." << endl;
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

void ClienteManager::buscarCliente() {
    int dni;
    cout << "Ingrese DNI del cliente a buscar: ";
    cin >> dni;

    int pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontro un cliente con ese DNI." << endl;
        return;
    }

    Cliente cli = _repo.leerRegistro(pos);
    mostrarCliente(cli);
}

void ClienteManager::modificarCliente() {
    int dni, pos;

    cout << "Ingrese DNI del cliente a modificar: ";
    cin >> dni;

    pos = _repo.buscarPorDNI(dni);

    if (pos < 0) {
        cout << "No se encontro un cliente con ese DNI." << endl;
        return;
    }

    Cliente clienteOriginal = _repo.leerRegistro(pos);
    Cliente modificado = clienteOriginal;

    int opcion;
    bool seguir = true;

    while (seguir) {
        cout << "\n--- Campos modificables ---\n";
        cout << "1. Nombre\n";
        cout << "2. Fecha Nacimiento\n";
        cout << "3. Mail\n";
        cout << "4. Telefono\n";
        cout << "5. ID Obra Social\n";
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
                cout << "Nueva fecha: " << endl;
                f.cargar();
                modificado.setFechaNacimiento(f);
                break;
            }
            case 3: {
                char mail[50];
                cout << "Nuevo mail: ";
                cin.getline(mail, 50);
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
                int idOS;
                cout << "Nuevo ID obra social: ";
                cin >> idOS;
                modificado.setIdObraSocial(idOS);
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
        cout << "Cliente modificado correctamente.\n";
    } else {
        cout << "Error al modificar cliente.\n";
    }
}
