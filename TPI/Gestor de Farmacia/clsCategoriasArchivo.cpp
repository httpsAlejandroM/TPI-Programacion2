#include "clsCategoriasArchivo.h"
#include <cstring>
#include <iostream>

CategoriasArchivo::CategoriasArchivo(const char* nombreArchivo){
strcpy(_nombreArchivo, nombreArchivo);
}

bool CategoriasArchivo::guardar(Categoria registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo, "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Categoria), 1, pFile);

    fclose(pFile);

    return result;
}

Categoria CategoriasArchivo::leerRegistro(int pos){
    FILE *pFile;
    Categoria registro;

    pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr){
        registro.setIdCategoria(0);
        registro.setEstado(true);
        return registro;
    }

    fseek(pFile, pos * sizeof(Categoria), SEEK_SET);

    if(!fread(&registro, sizeof(Categoria), 1, pFile)){
        registro.setIdCategoria(0);
        registro.setEstado(true);
    }

    fclose(pFile);

    return registro;
}

int CategoriasArchivo::buscarPorID(int id){ //Devuelve la posicion del registro
    int cantRegistros = contarRegistros();

    Categoria categoria;

    for(int i = 0; i < cantRegistros; i++){
        categoria = leerRegistro(i);
        if(categoria.getIdCategoria() == id){
            return i;
        }
    }
    
}

int CategoriasArchivo::contarRegistros(){
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if(pFile == nullptr){
        return -1;
    }

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes/sizeof(Categoria);
}

bool CategoriasArchivo::modificarRegistro(int pos, Categoria categoria){
    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(Categoria), SEEK_SET);
    bool escribio = fwrite(&categoria, sizeof(Categoria), 1, pFile);
    fclose(pFile);
    return escribio;
}

int CategoriasArchivo::getNuevoID(){
    if(contarRegistros() == 0){
        return 1;
    }

    return leerRegistro(contarRegistros() - 1).getIdCategoria() + 1 ;
}

bool CategoriasArchivo::cambiarEstado(int id){
    int pos = buscarPorID(id);
    if(pos < 0) return false;

    Categoria categoria = leerRegistro(pos);

    categoria.setEstado(!categoria.getEstado());

    return modificarRegistro(pos, categoria);
}