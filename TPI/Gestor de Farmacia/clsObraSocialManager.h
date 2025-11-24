#pragma once
#include "clsObrasSocialesArchivo.h"

class ObraSocialManager {

public:
    ObraSocialManager();
    void cargarObraSocial();
    void listarObrasSociales();
    // void eliminarObraSocial();
    // void mostrarObraSocialOrdenada();

protected:
    void mostrarObraSocial(ObraSocial obraSocial);

private:
    ObrasSocialesArchivo _repo;
};
