#pragma once

class Vendedor {

public:

    Vendedor();
    Vendedor(int idVendedor, const char* nombre, int dni, const char* mail, const char* telefono, const char* direccion, bool estado);

    void setIdVendedor(int idVendedor);
    int getIdVendedor();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setDNI(int dni);
    int getDNI();

    void setMail(const char* mail);
    const char* getMail();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setDireccion(const char* direccion);
    const char* getDireccion();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idVendedor;
    char _nombre[50];
    int _dni;
    char _mail[40];
    char _telefono[20];
    char _direccion[50];
    bool _estado;
};
