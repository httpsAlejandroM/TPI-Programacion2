#pragma once
#include "clsFecha.h"

class Persona {

    protected:
    Persona(int id, const char* nombre, Fecha fechaNacimiento); 

    void setIdPersona(int id);
    int getIdPersona();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();


    private:
    int _idDni;
    char _nombre[50];
    Fecha _fechaNacimiento;
};
