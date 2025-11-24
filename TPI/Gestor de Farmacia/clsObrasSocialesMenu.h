#pragma once
#include "clsObraSocialManager.h"

class ObrasSocialesMenu
{

public:
    ObrasSocialesMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    ObraSocialManager _obraSocialManager;

private:
    int _cantidadOpciones;

};
