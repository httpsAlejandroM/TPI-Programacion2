#include "clsObraSocialManager.h"
#include <iostream>
#include <cstring>
using namespace std;

ObraSocialManager::ObraSocialManager() {}

void ObraSocialManager::cargarObraSocial() {
    int id;
    char nombre[50];
    float descuento;

    id = _repo.getNuevoID();
    cout << "Obra Social #" << id << endl;

    cout << "Ingrese el nombre de la obra social: ";
    cin.ignore(); // limpia buffer antes de getline
    cin.getline(nombre, 50);

    cout << "Ingrese el porcentaje de descuento (0-100): ";
    cin >> descuento;

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

    for(int i=0; i < cantidad; i++){
        ObraSocial obraSocial = _repo.leerRegistro(i);

        if(obraSocial.getEstado()){
            mostrarObraSocial(obraSocial);
            cout << "----------------------------" << endl;
        }
    }
}


