#include <cstring>
#include "clsObraSocial.h"

ObraSocial::ObraSocial() {
    _idOS = 0;
    _nombre[0] = '\0';
    _porcentajeDescuento = 0.0f;
    _estado = false;
}

ObraSocial::ObraSocial(int idOS, const char* nombre, float porcentajeDescuento, bool estado) {
    _idOS = idOS;
    strcpy(_nombre, nombre);
    _porcentajeDescuento = porcentajeDescuento;
    _estado = estado;
}

void ObraSocial::setIdOS(int idOS) {
    _idOS = idOS;
}

int ObraSocial::getIdOS() {
    return _idOS;
}

void ObraSocial::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

const char* ObraSocial::getNombre() {
    return _nombre;
}

void ObraSocial::setPorcentajeDescuento(float porcentajeDescuento) {
    _porcentajeDescuento = porcentajeDescuento;
}

float ObraSocial::getPorcentajeDescuento() {
    return _porcentajeDescuento;
}

void ObraSocial::setEstado(bool estado) {
    _estado = estado;
}

bool ObraSocial::getEstado() {
    return _estado;
}
