#include "clsVendedor.h"
#include <cstring> 

Vendedor::Vendedor()
: Persona(0, "default", Fecha()), _estado(false){
    strcpy(_mail, "default@mail.com");
    strcpy(_telefono, "000000000");
    strcpy(_direccion, "Sin direccion");
}

Vendedor::Vendedor(int dni, const char* nombre, Fecha fechaNacimiento,
                   const char* mail, const char* telefono,
                   const char* direccion, bool estado)
: Persona(dni, nombre, fechaNacimiento){
    setMail(mail);
    setTelefono(telefono);
    setDireccion(direccion);
    setEstado(estado);
}

void Vendedor::setMail(const char* mail) {
    if(mail != nullptr){
        strcpy(_mail, mail);
    }
}

const char* Vendedor::getMail() {
    return _mail;
}

void Vendedor::setTelefono(const char* telefono) {
    if(telefono != nullptr){
        strcpy(_telefono, telefono);
    }
}

const char* Vendedor::getTelefono() {
    return _telefono;
}

void Vendedor::setDireccion(const char* direccion) {
    if(direccion != nullptr){
        strcpy(_direccion, direccion);
    }
}

const char* Vendedor::getDireccion() {
    return _direccion;
}

void Vendedor::setEstado(bool estado) {
    _estado = estado;
}

bool Vendedor::getEstado() {
    return _estado;
}
