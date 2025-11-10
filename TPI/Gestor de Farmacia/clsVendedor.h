#pragma once
#include "clsFecha.h"
#include "clsPersona.h"

class Vendedor: public  Persona {

public:

    Vendedor();
    Vendedor(int dni, const char* nombre, Fecha fechaNacimiento,const char* mail, const char* telefono, const char* direccion, bool estado);

    void setMail(const char* mail);
    const char* getMail();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setDireccion(const char* direccion);
    const char* getDireccion();

    void setEstado(bool estado);
    bool getEstado();

private:
    char _mail[40];
    char _telefono[20];
    char _direccion[50];
    bool _estado;
};
