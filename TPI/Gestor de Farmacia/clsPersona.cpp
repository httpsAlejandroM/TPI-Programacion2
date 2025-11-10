#include "clsPersona.h"
#include <cstring>

Persona::Persona(int id, const char* nombre, Fecha fechaNacimiento){
    setIdPersona(id);
    setNombre(nombre);
    setFechaNacimiento(fechaNacimiento);
}

void Persona::setIdPersona(int id){
    _idDni = id;
}

int Persona::getIdPersona(){
    return _idDni;
}

void Persona::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

const char* Persona::getNombre(){
    return _nombre;
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento(){
    return _fechaNacimiento;
}