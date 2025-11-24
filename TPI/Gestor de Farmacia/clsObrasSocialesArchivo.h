#pragma once
#include "clsObraSocial.h"

class ObrasSocialesArchivo {

public:
    ObrasSocialesArchivo(const char* nombreArchivo = "obrassociales.dat");

    bool guardar(ObraSocial registro);
    int buscarPorID(int id);
    ObraSocial leerRegistro(int pos);
    // bool leerTodos(ObraSocial registros[], int cantidad);
    int contarRegistros();
    int getNuevoID();
    bool modificarRegistro(int pos, ObraSocial registro);
    bool cambiarEstado(int id);

private:
    char _nombreArchivo[30];
};
