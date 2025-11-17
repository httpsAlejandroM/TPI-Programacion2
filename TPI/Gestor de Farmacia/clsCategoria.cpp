#include <cstring>   
#include "clsCategoria.h"

Categoria::Categoria() {
    _idCategoria = 0;
    _nombre[0] = '-\0';
    _estado = true;
}

Categoria::Categoria(int idCategoria, const char* nombre, bool estado) {
    _idCategoria = idCategoria;
    strcpy(_nombre, nombre);   
    _estado = estado;
}

void Categoria::setIdCategoria(int idCategoria) {
    _idCategoria = idCategoria;
}

int Categoria::getIdCategoria() {
    return _idCategoria;
}

void Categoria::setNombre(const char* nombre) {
    strcpy(_nombre, nombre);
}

const char* Categoria::getNombre() {
    return _nombre;
}

void Categoria::setEstado(bool estado) {
    _estado = estado;
}

bool Categoria::getEstado() {
    return _estado;
}
