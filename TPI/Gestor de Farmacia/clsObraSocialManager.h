#pragma once
#include "clsObrasSocialesArchivo.h"

class ObraSocialManager {

public:
    ObraSocialManager();
    void cargarObraSocial();
    void listarObrasSociales();
    void modificarObraSocial();
    void eliminarObraSocial();
    void buscarObraSocial();

protected:
    void mostrarObraSocial(ObraSocial obraSocial);

private:
    ObrasSocialesArchivo _repo;
};
