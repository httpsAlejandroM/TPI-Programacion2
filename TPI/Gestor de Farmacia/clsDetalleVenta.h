#pragma once

class DetalleVenta {

public:
    DetalleVenta();
    DetalleVenta(int idDetalle, int idVenta, int idProducto,
                 int cantidad, float precioUnitario, bool estado);

    void setIdDetalle(int idDetalle);
    int getIdDetalle();

    void setIdVenta(int idVenta);
    int getIdVenta();

    void setIdProducto(int idProducto);
    int getIdProducto();

    void setCantidad(int cantidad);
    int getCantidad();

    void setPrecioUnitario(float precioUnitario);
    float getPrecioUnitario();

    float getSubtotal();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idDetalle;
    int _idVenta;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _estado;
};
