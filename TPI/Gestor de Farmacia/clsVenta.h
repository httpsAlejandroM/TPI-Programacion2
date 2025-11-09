#pragma once
#include "Fecha.h"

class Ventas {

public:

    Ventas();
    Ventas(int idVenta, Fecha fecha, int idCliente, int idVendedor, float totalBruto, float descuento, float totalNeto, const char* metodoPago, bool estado);

    void setIdVenta(int idVenta);
    int getIdVenta();

    void setFecha(Fecha fecha);
    Fecha getFecha();

    void setIdCliente(int idCliente);
    int getIdCliente();

    void setIdVendedor(int idVendedor);
    int getIdVendedor();

    void setTotalBruto(float totalBruto);
    float getTotalBruto();

    void setDescuento(float descuento);
    float getDescuento();

    void setTotalNeto(float totalNeto);
    float getTotalNeto();

    void setMetodoPago(const char* metodoPago);
    const char* getMetodoPago();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idVenta;
    Fecha _fecha;
    int _idCliente;
    int _idVendedor;
    float _totalBruto;
    float _descuento;
    float _totalNeto;
    char _metodoPago[20];
    bool _estado;
};


