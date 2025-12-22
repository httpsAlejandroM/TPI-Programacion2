#include "clsVendedoresArchivo.h"
#include <cstring>
#include <iostream>

VendedoresArchivo::VendedoresArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool VendedoresArchivo::guardar(Vendedor registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo, "ab");

    if (pFile == nullptr) return false;

    result = fwrite(&registro, sizeof(Vendedor), 1, pFile);

    fclose(pFile);
    return result;
}

Vendedor VendedoresArchivo::leerRegistro(int pos) {
    FILE *pFile;
    Vendedor registro;
    int cantidadRegistros = contarRegistros();

    if (pos < 0 || pos >= cantidadRegistros) { 
        registro.setIdPersona(0);
        registro.setNombre("-");
        registro.setFechaNacimiento( Fecha(1,1,1900) );
        registro.setMail("-");
        registro.setTelefono("-");
        registro.setDireccion("-");
        registro.setEstado(false);

        return registro;
    }

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return registro;

    fseek(pFile, pos * sizeof(Vendedor), SEEK_SET);
    fread(&registro, sizeof(Vendedor), 1, pFile);

    fclose(pFile);
    return registro;
}

bool VendedoresArchivo::leerTodos(Vendedor registros[], int cantidad) {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return false;

    fread(registros, sizeof(Vendedor), cantidad, pFile);

    fclose(pFile);
    return true;
}

int VendedoresArchivo::contarRegistros() {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");
    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes / sizeof(Vendedor);
}

int VendedoresArchivo::buscarPorDNI(int dni) {
    int cantRegistros = contarRegistros();
    Vendedor ven;

    for (int i = 0; i < cantRegistros; i++) {
        ven = leerRegistro(i);
        if (ven.getIdPersona() == dni) {
            return i;
        }
    }

    return -1;
}

bool VendedoresArchivo::modificarRegistro(int pos, Vendedor registro) {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");
    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Vendedor), SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(Vendedor), 1, pFile);

    fclose(pFile);
    return escribio;
}

bool VendedoresArchivo::cambiarEstado(int dni) {
    int pos = buscarPorDNI(dni);
    if (pos < 0) return false;

    Vendedor ven = leerRegistro(pos);
    ven.setEstado(!ven.getEstado());

    return modificarRegistro(pos, ven);
}
