#include "clsVenta.h"
#include <cstring>   

Venta::Venta() {
    _idVenta = 0;
    _fecha = Fecha();        
    _idCliente = 0;
    _idVendedor = 0;
    _totalBruto = 0.0f;
    _descuento = 0.0f;
    _totalNeto = 0.0f;
    strcpy(_metodoPago, "-"); 
    _estado = true;
}

Venta::Venta(int idVenta, Fecha fecha, int idCliente, int idVendedor,
             float totalBruto, float descuento, float totalNeto,
             const char* metodoPago, bool estado)
{
    setIdVenta(idVenta);
    setFecha(fecha);
    setIdCliente(idCliente);
    setIdVendedor(idVendedor);
    setTotalBruto(totalBruto);
    setDescuento(descuento);
    setTotalNeto(totalNeto);
    setMetodoPago(metodoPago);
    setEstado(estado);
}

void Venta::setIdVenta(int idVenta) { 
    _idVenta = idVenta; 
}

int Venta::getIdVenta() { 
    return _idVenta; 
}

void Venta::setFecha(Fecha fecha) { 
    _fecha = fecha; 
}

Fecha Venta::getFecha() { 
    return _fecha; 
}

void Venta::setIdCliente(int idCliente) { 
    _idCliente = idCliente; 
}

int Venta::getIdCliente() { 
    return _idCliente; 
}

void Venta::setIdVendedor(int idVendedor) { 
    _idVendedor = idVendedor; 
}

int Venta::getIdVendedor() { 
    return _idVendedor; 
}

void Venta::setTotalBruto(float totalBruto) { 
    _totalBruto = totalBruto; 
}

float Venta::getTotalBruto() { 
    return _totalBruto; 
}

void Venta::setDescuento(float descuento) {
    _descuento = descuento; 
}

float Venta::getDescuento() { 
    return _descuento; 
}

void Venta::setTotalNeto(float totalNeto) { 
    _totalNeto = totalNeto; 
}

float Venta::getTotalNeto() { 
    return _totalNeto; 
}

void Venta::setMetodoPago(const char* metodoPago) {
 strncpy(_metodoPago, metodoPago, sizeof(_metodoPago) - 1);
    _metodoPago[sizeof(_metodoPago) - 1] = '\0';
}

const char* Venta::getMetodoPago() {
    return _metodoPago;
}

void Venta::setEstado(bool estado) { 
    _estado = estado; 
}

bool Venta::getEstado() { 
    return _estado; 
}
