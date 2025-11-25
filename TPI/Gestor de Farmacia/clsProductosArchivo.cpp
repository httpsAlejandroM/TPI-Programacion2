#include "clsProductosArchivo.h"
#include <cstring>
#include <iostream>

ProductosArchivo::ProductosArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ProductosArchivo::guardar(Producto registro) {
    FILE *pFile;
    bool result;
    
    pFile = fopen(_nombreArchivo, "ab");

    if (pFile == nullptr) return false;

    result = fwrite(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);
    return result;
}

Producto ProductosArchivo::leerRegistro(int pos) {
    Producto registro;
    FILE *pFile;
    int cantidad = contarRegistros();

    if (pos < 0 || pos >= cantidad) { //registro invalido/nulo
        registro.setIdProducto(0);
        registro.setNombre("-");
        registro.setMarca("-");
        registro.setStock(0);
        registro.setPrecio(0);
        registro.setEstado(false);
        registro.setIdCategoria(0);
        registro.setReceta(false);

        return registro;
    }

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return registro;

    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);
    return registro;
}

bool ProductosArchivo::leerTodos(Producto registros[], int cantidad) {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return false;

    fread(registros, sizeof(Producto), cantidad, pFile);

    fclose(pFile);
    return true;
}

int ProductosArchivo::contarRegistros() {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes/sizeof(Producto);
}

int ProductosArchivo::buscarPorID(int id) {
    int cantRegistros = contarRegistros();
    Producto prod;

    for (int i = 0; i < cantRegistros; i++) {
        prod = leerRegistro(i);
        if (prod.getIdProducto() == id) {
            return i;
        }
    }

    return -1;
}

int ProductosArchivo::getNuevoID() {
    int cantidad = contarRegistros();
    if (cantidad == 0) return 1;

    Producto ultimo = leerRegistro(cantidad - 1);
    return ultimo.getIdProducto() + 1;
}

bool ProductosArchivo::modificarRegistro(int pos, Producto prod) {
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    bool result = fwrite(&prod, sizeof(Producto), 1, pFile);
    fclose(pFile);
    return result;
}

bool ProductosArchivo::cambiarEstado(int id) {
    int pos = buscarPorID(id);
    if (pos < 0) return false;

    Producto prod = leerRegistro(pos);
    prod.setEstado(!prod.getEstado());

    return modificarRegistro(pos, prod);
}
