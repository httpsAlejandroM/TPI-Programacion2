#include "clsClientesArchivo.h"
#include <cstring>
#include <iostream>

ClientesArchivo::ClientesArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ClientesArchivo::guardar(Cliente registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo, "ab");

    if (pFile == nullptr) return false;

    result = fwrite(&registro, sizeof(Cliente), 1, pFile);

    fclose(pFile);
    return result;
}

Cliente ClientesArchivo::leerRegistro(int pos) {
    FILE *pFile;
    Cliente registro;
    int cantidadRegistros = contarRegistros();

    if (pos < 0 || pos >= cantidadRegistros) { 
        // Valores por defecto si la posición es inválida
        registro.setIdPersona(0);
        registro.setNombre("-");
        registro.setFechaNacimiento( Fecha(1,1,1900) );
        registro.setMail("-");
        registro.setTelefono("-");
        registro.setIdObraSocial(0);
        registro.setEstado(false);

        return registro;
    }

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return registro;

    fseek(pFile, pos * sizeof(Cliente), SEEK_SET);
    fread(&registro, sizeof(Cliente), 1, pFile);

    fclose(pFile);
    return registro;
}

bool ClientesArchivo::leerTodos(Cliente registros[], int cantidad) {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return false;

    fread(registros, sizeof(Cliente), cantidad, pFile);

    fclose(pFile);
    return true;
}

int ClientesArchivo::contarRegistros() {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes / sizeof(Cliente);
}

int ClientesArchivo::buscarPorDNI(int dni) {
    int cantRegistros = contarRegistros();
    Cliente cli;

    for (int i = 0; i < cantRegistros; i++) {
        cli = leerRegistro(i);
        if (cli.getIdPersona() == dni) {
            return i;
        }
    }

    return -1;  
}

bool ClientesArchivo::modificarRegistro(int pos, Cliente registro) {
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr) return false;

    fseek(pFile, pos * sizeof(Cliente), SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(Cliente), 1, pFile);

    fclose(pFile);
    return escribio;
}

bool ClientesArchivo::cambiarEstado(int dni) {
    int pos = buscarPorDNI(dni);
    if (pos < 0) return false;

    Cliente cli = leerRegistro(pos);
    cli.setEstado(!cli.getEstado());

    return modificarRegistro(pos, cli);
}
