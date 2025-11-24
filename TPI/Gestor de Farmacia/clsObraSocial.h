#pragma once

class ObraSocial {

public:
    ObraSocial();
    ObraSocial(int idOS, const char* nombre, float porcentajeDescuento, bool estado);

    void setIdOS(int idOS);
    int getIdOS();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setPorcentajeDescuento(float porcentajeDescuento);
    float getPorcentajeDescuento();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idOS;
    char _nombre[50];
    float _porcentajeDescuento;
    bool _estado;
};

