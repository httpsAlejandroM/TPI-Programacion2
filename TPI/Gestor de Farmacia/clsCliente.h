#pragma once
#include "clsFecha.h"
#include "clsPersona.h"

class Vendedor : public Persona {

public:
    Vendedor();
    Vendedor(int dni, const char* nombre, Fecha fechaNacimiento, const char* mail, const char* telefono, int idObraSocial, bool estado);

    void setMail(const char* mail);
    const char* getMail();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setIdObraSocial(int idObraSocial);
    int getIdObraSocial();

    void setEstado(bool estado);
    bool getEstado();

private:
    char _mail[50];
    char _telefono[20];
    int _idObraSocial;
    bool _estado;
};
