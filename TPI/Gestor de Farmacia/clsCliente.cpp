#include "clsCliente.h"
#include <cstring>  

Vendedor::Vendedor()
: Persona(0, "default", Fecha()),   
  _idObraSocial(0),
  _estado(false)
{
    strcpy(_telefono, "123456789");
    strcpy(_mail, "mail@default.com");
}

Vendedor::Vendedor(int dni, const char* nombre, Fecha fechaNacimiento,
                 const char* mail, const char* telefono,
                 int idObraSocial, bool estado)
: Persona(dni, nombre, fechaNacimiento)
{
    setMail(mail);
    setTelefono(telefono);
    setIdObraSocial(idObraSocial);
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

void Vendedor::setIdObraSocial(int idObraSocial) {
    _idObraSocial = idObraSocial;
}

int Vendedor::getIdObraSocial() {
    return _idObraSocial;
}

void Vendedor::setEstado(bool estado) {
    _estado = estado;
}

bool Vendedor::getEstado() {
    return _estado;
}
