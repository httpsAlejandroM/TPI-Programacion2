#pragma once
#include "clsCategoriaManager.h"

class CategoriasMenu
{

public:
    CategoriasMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    CategoriaManager _categoriaManager;
private:
    int _cantidadOpciones;

};
