#include "clsDetalleVenta.h"

DetalleVenta::DetalleVenta()
: _idDetalle(0),
  _idVenta(0),
  _idProducto(0),
  _cantidad(0),
  _precioUnitario(0.0f),
  _estado(true)
{
}

DetalleVenta::DetalleVenta(int idDetalle, int idVenta, int idProducto,
                           int cantidad, float precioUnitario, bool estado)
{
    setIdDetalle(idDetalle);
    setIdVenta(idVenta);
    setIdProducto(idProducto);
    setCantidad(cantidad);
    setPrecioUnitario(precioUnitario);
    setEstado(estado);
}

void DetalleVenta::setIdDetalle(int idDetalle) {
    _idDetalle = idDetalle;
}

void DetalleVenta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}

void DetalleVenta::setIdProducto(int idProducto) {
    _idProducto = idProducto;
}

void DetalleVenta::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleVenta::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}

void DetalleVenta::setEstado(bool estado) {
    _estado = estado;
}

int DetalleVenta::getIdDetalle() {
    return _idDetalle;
}

int DetalleVenta::getIdVenta() {
    return _idVenta;
}

int DetalleVenta::getIdProducto() {
    return _idProducto;
}

int DetalleVenta::getCantidad() {
    return _cantidad;
}

float DetalleVenta::getPrecioUnitario() {
    return _precioUnitario;
}

float DetalleVenta::getSubtotal() {
    return _cantidad * _precioUnitario;
}

bool DetalleVenta::getEstado() {
    return _estado;
}