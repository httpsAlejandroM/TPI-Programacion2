#include "clsCliente.h"
#include <cstring>  

Cliente::Cliente()
: Persona(0, "default", Fecha()),   
  _idObraSocial(0),
  _estado(false)
{
    strcpy(_telefono, "123456789");
    strcpy(_mail, "mail@default.com");
}

Cliente::Cliente(int dni, const char* nombre, Fecha fechaNacimiento,
                 const char* mail, const char* telefono,
                 int idObraSocial, bool estado)
: Persona(dni, nombre, fechaNacimiento)
{
    setMail(mail);
    setTelefono(telefono);
    setIdObraSocial(idObraSocial);
    setEstado(estado);
}

void Cliente::setMail(const char* mail) {
        if(mail != nullptr){
        strcpy(_mail, mail);
    }
}

const char* Cliente::getMail() {
    return _mail;
}

void Cliente::setTelefono(const char* telefono) {
    if(telefono != nullptr){
        strcpy(_telefono, telefono);
    }
}

const char* Cliente::getTelefono() {
    return _telefono;
}

void Cliente::setIdObraSocial(int idObraSocial) {
    _idObraSocial = idObraSocial;
}

int Cliente::getIdObraSocial() {
    return _idObraSocial;
}

void Cliente::setEstado(bool estado) {
    _estado = estado;
}

bool Cliente::getEstado() {
    return _estado;
}
