#include "clsObraSocialManager.h"
#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "utils.h"

using namespace std;

ObraSocialManager::ObraSocialManager() {}

void ObraSocialManager::cargarObraSocial() {
    int id;
    char nombre[50];
    float descuento;

    id = _repo.getNuevoID();
    cout << "Obra Social #" << id << endl;

    cout << "Ingrese el nombre de la obra social: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Ingrese el porcentaje de descuento (0-100): ";
    cin >> descuento;
    while(descuento < 0 || descuento > 100){
        cout << "Descuento invalido. Ingrese entre 0 y 100: ";
        cin >> descuento;
    }

    ObraSocial obraSocial(id, nombre, descuento, true);

    if(_repo.guardar(obraSocial)){
        cout << "Obra Social guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar Obra Social." << endl;
    }
}

void ObraSocialManager::mostrarObraSocial(ObraSocial obraSocial) {
    cout << "ID: " << obraSocial.getIdOS() << endl;
    cout << "Nombre: " << obraSocial.getNombre() << endl;
    cout << "Descuento: " << obraSocial.getPorcentajeDescuento() << "%" << endl;
}

void ObraSocialManager::listarObrasSociales() {
    int cantidad = _repo.contarRegistros();
    bool hayRegistros = false;

    for(int i=0; i < cantidad; i++){
        ObraSocial obraSocial = _repo.leerRegistro(i);

        if(obraSocial.getEstado()){
            mostrarObraSocial(obraSocial);
            cout << "----------------------------" << endl;
            hayRegistros = true;
        }
    }
    if(!hayRegistros){
        cout << "No hay obras sociales activas para mostrar." << endl;
    }
}

void ObraSocialManager::eliminarObraSocial() {
    int id, pos;
    cout << "ELIMINAR OBRA SOCIAL" << endl;
    cout << "Ingrese ID de la obra social: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos == -1) {
        cout << "La obra social no se encuentra en el archivo." << endl;
        return;
    }

    ObraSocial obj = _repo.leerRegistro(pos);
    if(!obj.getEstado()){
        cout << "La obra social ya se encuentra eliminada." << endl;
        return;
    }

    cout << "Informacion de la obra social:" << endl;
    mostrarObraSocial(obj);

    if (leerSN("\n¨Esta seguro que desea eliminarla? (S/N): ")) {
        if (_repo.cambiarEstado(id)) {
            cout << "La obra social fue eliminada correctamente." << endl;
        } else {
            cout << "Ocurrio un error en la eliminacion." << endl;
        }
    }
}

void ObraSocialManager::modificarObraSocial() {
    int id, pos;
    char nombre[50];
    float descuento;

    cout << "MODIFICAR OBRA SOCIAL" << endl;
    cout << "Ingrese ID de la obra social: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos == -1) {
        cout << "La obra social no se encuentra en el archivo." << endl;
        return;
    }

    ObraSocial obj = _repo.leerRegistro(pos);
    if(!obj.getEstado()){
         cout << "No se puede modificar una obra social eliminada." << endl;
         return;
    }

    cout << "--- DATOS ACTUALES ---" << endl;
    mostrarObraSocial(obj);
    cout << "----------------------" << endl;

    cout << "Ingrese nuevo nombre (Actual: " << obj.getNombre() << "): ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "Ingrese nuevo descuento (Actual: " << obj.getPorcentajeDescuento() << "): ";
    cin >> descuento;

    obj.setNombre(nombre);
    obj.setPorcentajeDescuento(descuento);

    if (_repo.modificarRegistro(pos, obj)) {
        cout << "La obra social fue actualizada correctamente." << endl;
    } else {
        cout << "Ocurrio un error en la actualizacion." << endl;
    }
}

void ObraSocialManager::buscarObraSocial() {
    int id, pos;
    cout << "BUSCAR OBRA SOCIAL" << endl;
    cout << "Ingrese el ID a buscar: ";
    cin >> id;

    pos = _repo.buscarPorID(id);

    if (pos == -1) {
        cout << "No se encontro ninguna obra social con el ID " << id << "." << endl;
    } else {
        ObraSocial obj = _repo.leerRegistro(pos);
        if(obj.getEstado()){
             cout << endl << "--- REGISTRO ENCONTRADO ---" << endl;
             mostrarObraSocial(obj);
             cout << "---------------------------" << endl;
        } else {
             cout << "La obra social existe pero esta dada de baja." << endl;
        }
    }
}

