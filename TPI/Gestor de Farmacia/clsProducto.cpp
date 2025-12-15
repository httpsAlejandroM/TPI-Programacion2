#include <cstring>
#include "clsProducto.h"
#include <iostream>
using namespace std;


Producto::Producto()
: _idProducto(0),
  _stock(0),
  _precio(0.0f),
  _estado(false),
  _idCategoria(0),
  _recetaObligatoria(false)
{
    _nombre[0] = '\0';
    _marca[0] = '\0';
}

Producto::Producto(int idProducto, const char* nombre, const char* marca,
                   int stock, float precio, bool estado,
                   int idCategoria, bool recetaObligatoria) 
{
    _idProducto = idProducto;
    strncpy(_nombre, nombre, 49);
    _nombre[49] = '\0';
    strncpy(_marca, marca, 49);
    _marca[49] = '\0';
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
    strncpy(_nombre, nombre, 49);
    _nombre[49] = '\0';
}

const char* Producto::getNombre() {
    return _nombre;
}

void Producto::setMarca(const char* marca) {
    strncpy(_marca, marca, 49);
    _marca[49] = '\0';
}

const char* Producto::getMarca() {
    return _marca;
}

void Producto::setStock(int stock) {
   if(stock < 0){
    _stock = 0;
     return;
   } 
    _stock = stock;
}

int Producto::getStock() {
    return _stock;
}

void Producto::setPrecio(float precio) {
   if(precio <= 0) {
    _precio = 0;
   }

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

void Producto::setIdCategoria(int categoria) {
    _idCategoria = categoria;
}

int Producto::getIdCategoria() {
    return _idCategoria;
}

void Producto::setReceta(bool receta) {
    _recetaObligatoria = receta;
}

bool Producto::getReceta() {
    return _recetaObligatoria;
}

void Producto::mostrar(){
    cout << "ID: " << _idProducto << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Stock: " << _stock << endl;
    cout << "Precio: " << _precio << endl;
    cout << "Estado: " << (_estado ? "Habilitado" : "Deshabilitado") << endl;
    cout << "ID Categoria: " << _idCategoria << endl;
    cout << "Receta Obligatoria: " << (_recetaObligatoria ? "Si" : "No") << endl;
}