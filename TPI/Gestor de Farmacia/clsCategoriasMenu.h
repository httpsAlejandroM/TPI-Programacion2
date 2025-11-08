#pragma once

class CategoriasMenu
{

public:
    CategoriasMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);


private:
    int _cantidadOpciones;

};
