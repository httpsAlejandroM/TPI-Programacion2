#pragma once
#include "Fecha.h"

class Cliente {

public:

    Cliente();
    Cliente(int idCliente, const char* nombre, Fecha fechaNacimiento, const char* mail, const char* telefono, int idObraSocial, bool estado);

    void setIdCliente(int idCliente);
    int getIdCliente();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();

    void setMail(const char* mail);
    const char* getMail();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setIdObraSocial(int idObraSocial);
    int getIdObraSocial();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idCliente;
    char _nombre[50];
    Fecha _fechaNacimiento;
    char _mail[50];
    char _telefono[20];
    int _idObraSocial;
    bool _estado;
};
