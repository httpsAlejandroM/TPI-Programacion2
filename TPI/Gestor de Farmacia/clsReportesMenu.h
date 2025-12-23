#pragma once
#include "clsReportesManager.h"

class ReportesMenu {
public:
    void mostrar();
private:
    void mostrarOpciones();
    void ejecutarOpcion(int opcion);
    ReportesManager _manager;
};
