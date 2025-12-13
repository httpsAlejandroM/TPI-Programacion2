#include "clsVentasArchivo.h"
#include <cstring>
#include <iostream>

VentasArchivo::VentasArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool VentasArchivo::guardar(Venta registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo, "ab");

    if(pFile == nullptr) return false;

    result = fwrite(&registro, sizeof(Venta), 1, pFile);

    fclose(pFile);
    return result;
}

Venta VentasArchivo::leerRegistro(int pos) {
    Venta registro;
    FILE* pFile;
    int cantidad = contarRegistros();

    if (pos < 0 || pos >= cantidad) {
        // registro inválido → devolvemos uno por defecto
        registro.setIdVenta(0);
        registro.setEstado(false);
        registro.setIdCliente(0);
        registro.setIdVendedor(0);
        registro.setFecha(Fecha());
        registro.setTotalBruto(0);
        registro.setDescuento(0);
        registro.setTotalNeto(0);
        registro.setMetodoPago("-");

        return registro;
    }

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return registro;

    fseek(pFile, pos * sizeof(Venta), SEEK_SET);
    fread(&registro, sizeof(Venta), 1, pFile);

    fclose(pFile);
    return registro;
}

bool VentasArchivo::leerTodos(Venta registros[], int cantidad) {
    FILE* pFile;
    
    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return false;

    fread(registros, sizeof(Venta), cantidad, pFile);

    fclose(pFile);
    return true;
}

int VentasArchivo::contarRegistros() {
    FILE* pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes / sizeof(Venta);
}

int VentasArchivo::buscarPorID(int id) {
    int cantidad = contarRegistros();
    Venta ven;

    for (int i = 0; i < cantidad; i++) {
        ven = leerRegistro(i);
        if (ven.getIdVenta() == id) {
            return i;
        }
    }

    return -1;
}

int VentasArchivo::getNuevoID() {
    int cantidad = contarRegistros();
    if (cantidad == 0) return 1;

    Venta ultimo = leerRegistro(cantidad - 1);
    return ultimo.getIdVenta() + 1;
}

bool VentasArchivo::modificarRegistro(int pos, Venta reg) {
    FILE* pFile;
    
    pFile = fopen(_nombreArchivo, "rb+");
    
    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Venta), SEEK_SET);
    bool result = fwrite(&reg, sizeof(Venta), 1, pFile);

    fclose(pFile);
    return result;
}