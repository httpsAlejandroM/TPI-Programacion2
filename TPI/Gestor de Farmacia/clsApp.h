#pragma once

class App
{

    public:
    App();
    void run();

    protected:
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    private:
    int _cantidadOpciones;

};
