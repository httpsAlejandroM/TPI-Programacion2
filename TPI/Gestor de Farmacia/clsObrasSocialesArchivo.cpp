#include "clsObrasSocialesArchivo.h"
#include <cstring>
#include <iostream>

ObrasSocialesArchivo::ObrasSocialesArchivo(const char* nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}

bool ObrasSocialesArchivo::guardar(ObraSocial registro) {
    FILE *pFile;
    bool result;
    pFile = fopen(_nombreArchivo, "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(ObraSocial), 1, pFile);

    fclose(pFile);

    return result;
}

ObraSocial ObrasSocialesArchivo::leerRegistro(int pos) {
    FILE *pFile;
    ObraSocial registro;

    pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr){
        registro.setIdOS(0);
        registro.setEstado(false);
        return registro;
    }

    fseek(pFile, pos * sizeof(ObraSocial), SEEK_SET);

    if(!fread(&registro, sizeof(ObraSocial), 1, pFile)){
        registro.setIdOS(0);
        registro.setEstado(false);
    }

    fclose(pFile);

    return registro;
}

int ObrasSocialesArchivo::buscarPorID(int id) { //Devuelve posicion del registro
    int cantRegistros = contarRegistros();

    ObraSocial registro;
    for(int i = 0; i < cantRegistros; i++){
        registro = leerRegistro(i);
        if(registro.getIdOS() == id){
            return i;
        }
    }
    return -1;
}

int ObrasSocialesArchivo::contarRegistros() {
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr){
        return -1; // puede ser 0 por si no existe
    }

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes / sizeof(ObraSocial);
}

bool ObrasSocialesArchivo::modificarRegistro(int pos, ObraSocial registro) {
    FILE *pFile;
    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(ObraSocial), SEEK_SET);
    bool escribio = fwrite(&registro, sizeof(ObraSocial), 1, pFile);
    fclose(pFile);
    return escribio;
}

int ObrasSocialesArchivo::getNuevoID() {
    if(contarRegistros() == 0){
        return 1;
    }
    return leerRegistro(contarRegistros() - 1).getIdOS() + 1;
}

bool ObrasSocialesArchivo::cambiarEstado(int id) {
    int pos = buscarPorID(id);
    if(pos < 0) return false;

    ObraSocial registro = leerRegistro(pos);
    registro.setEstado(!registro.getEstado());

    return modificarRegistro(pos, registro);
}



