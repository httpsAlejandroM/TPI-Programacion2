#include "clsProducto.h"
using namespace std;
#include <cstring>

Producto::Producto()
: _stock(0), _estado(false), _recetaObligatoria(false) {
//TODO: HACER EL QUE ID SE INICIALICE AUTOMATICAMENTE CON LA CANTIDAD DE REGISTROS + 1
}

Producto::Producto(int idProducto, const char* nombre, const char* marca, int stock, float precio, bool estado, int idCategoria, bool recetaObligatoria){
setIdProducto(idProducto);
setNombre(nombre);
setMarca(marca);
setStock(stock);
setPrecio(precio);
setEstado(estado);
setIDCategoria(idCategoria);
setReceta(recetaObligatoria);
}

void Producto::setIdProducto(int id) {
    _idProducto = id;
}

int Producto::getIdProducto(){
    return _idProducto;
}

void Producto::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

const char *Producto::getNombre(){
    return _nombre;
}

void Producto::setMarca(const char* marca){
    strcpy(_marca, marca);
}

const char *Producto::getMarca(){
    return _marca;
}

void Producto::setStock(int stock){
    stock = stock < 0 ? 0 : stock;
    _stock = stock;
}

int Producto::getStock(){
    return _stock;
}

void Producto::setPrecio(float precio){
    precio = precio <= 0 ? 1 : precio;
    _precio = precio;
}

float Producto::getPrecio(){
    return _precio;
}

void Producto::setEstado(bool estado){
    _estado = estado;
}

bool Producto::getEstado(){
    return _estado;
}

void Producto::setIDCategoria(int idCategoria){
    _idCategoria = idCategoria;
}

int Producto::getIDCategoria(){
    return _idCategoria;
}

void Producto::setReceta(bool receta){
    _recetaObligatoria = receta;
}

bool Producto::getReceta(){
    return _recetaObligatoria;
}

