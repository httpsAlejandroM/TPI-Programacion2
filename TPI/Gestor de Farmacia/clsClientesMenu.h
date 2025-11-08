#pragma once

class ClientesMenu
{

public:
    ClientesMenu();
    void mostrar();

protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);


private:
    int _cantidadOpciones;

};


