#include "clsDetalleVentaArchivo.h"
#include <cstring>
#include <iostream>

DetalleVentaArchivo::DetalleVentaArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool DetalleVentaArchivo::guardar(DetalleVenta registro) {
    FILE* pFile;
    bool result;

    pFile = fopen(_nombreArchivo, "ab");
    if (pFile == nullptr) return false;

    result = fwrite(&registro, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);
    return result;
}

DetalleVenta DetalleVentaArchivo::leerRegistro(int pos) {
    DetalleVenta registro;
    FILE* pFile;
    int cantidad = contarRegistros();

    if (pos < 0 || pos >= cantidad) {
        registro.setIdDetalle(0);
        registro.setIdVenta(0);
        registro.setIdProducto(0);
        registro.setCantidad(0);
        registro.setPrecioUnitario(0.0f);
        registro.setEstado(false);
        return registro;
    }

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return registro;

    fseek(pFile, pos * sizeof(DetalleVenta), SEEK_SET);
    fread(&registro, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);
    return registro;
}

bool DetalleVentaArchivo::leerTodos(DetalleVenta registros[], int cantidad) {
    FILE* pFile;

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return false;

    fread(registros, sizeof(DetalleVenta), cantidad, pFile);

    fclose(pFile);
    return true;
}

int DetalleVentaArchivo::contarRegistros() {
    FILE* pFile;

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);

    fclose(pFile);
    return bytes / sizeof(DetalleVenta);
}

int DetalleVentaArchivo::buscarPorID(int idDetalle) {
    int cantRegistros = contarRegistros();
    DetalleVenta det;

    for (int i = 0; i < cantRegistros; i++) {
        det = leerRegistro(i);
        if (det.getIdDetalle() == idDetalle) {
            return i;
        }
    }

    return -1;
}

int DetalleVentaArchivo::getNuevoID() {
    int cantidad = contarRegistros();
    if (cantidad == 0) return 1;

    DetalleVenta ultimo = leerRegistro(cantidad - 1);
    return ultimo.getIdDetalle() + 1;
}

bool DetalleVentaArchivo::modificarRegistro(int pos, DetalleVenta registro) {
    FILE* pFile;

    pFile = fopen(_nombreArchivo, "rb+");
    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(DetalleVenta), SEEK_SET);
    bool result = fwrite(&registro, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);
    return result;
}
