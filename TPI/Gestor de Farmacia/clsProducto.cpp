#include <cstring>
#include "clsProducto.h"

Producto::Producto() {
    _idProducto = 0;
    _nombre[0] = '\0';
    _marca[0] = '\0';
    _stock = 0;
    _precio = 0.0f;
    _estado = false;
    _idCategoria = 0;
    _recetaObligatoria = false;
}

Producto::Producto(int idProducto, const char* nombre, const char* marca,
                   int stock, float precio, bool estado,
                   int idCategoria, bool recetaObligatoria) 
{
    _idProducto = idProducto;
    strcpy(_nombre, nombre);
    strcpy(_marca, marca);
    _stock = stock;
    _precio = precio;
    _estado = estado;
    _idCategoria = idCategoria;
    _recetaObligatoria = recetaObligatoria;
}

void Producto::setIdProducto(int idProducto) {
    _idProducto = idProducto;
}

int Producto::getIdProducto() {
    return _idProducto;
}

void Producto::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

const char* Producto::getNombre() {
    return _nombre;
}

void Producto::setMarca(const char* marca) {
    strcpy(_marca, marca);
}

const char* Producto::getMarca() {
    return _marca;
}

void Producto::setStock(int stock) {
    _stock = stock;
}

int Producto::getStock() {
    return _stock;
}

void Producto::setPrecio(float precio) {
    _precio = precio;
}

float Producto::getPrecio() {
    return _precio;
}

void Producto::setEstado(bool estado) {
    _estado = estado;
}

bool Producto::getEstado() {
    return _estado;
}

void Producto::setIDCategoria(int categoria) {
    _idCategoria = categoria;
}

int Producto::getIDCategoria() {
    return _idCategoria;
}

void Producto::setReceta(bool receta) {
    _recetaObligatoria = receta;
}

bool Producto::getReceta() {
    return _recetaObligatoria;
}
