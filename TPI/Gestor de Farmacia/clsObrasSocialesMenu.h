#pragma once

class ObrasSocialesMenu
{

public:
    ObrasSocialesMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);


private:
    int _cantidadOpciones;

};
