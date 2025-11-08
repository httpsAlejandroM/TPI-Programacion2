#pragma once

class Producto {

public:

    Producto();
    Producto(int idProducto, const char* nombre, const char* marca, int stock, float precio, bool estado, int idCategoria, bool recetaObligatoria);

    void setIdProducto(int idProducto);
    int getIdProducto();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setMarca(const char* marca);
    const char* getMarca();

    void setStock(int stock);
    int getStock();

    void setPrecio(float precio);
    float getPrecio();

    void setEstado(bool estado);
    bool getEstado();

    void setIDCategoria(int categoria);
    int getIDCategoria();

    void setReceta(bool receta);
    bool getReceta();

    private:
    int _idProducto;
    char _nombre[50];
    char _marca[50];
    int _stock;
    float _precio;
    bool _estado;
    int _idCategoria;
    bool _recetaObligatoria;
    };
