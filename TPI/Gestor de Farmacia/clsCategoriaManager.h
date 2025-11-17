#pragma once
#include "clsCategoriasArchivo.h"

class CategoriaManager {

    public:
    CategoriaManager();
    void cargarCategoria();
    void listarCategorias();
    void eliminarCategoria();
    void mostrarCategoriaOrdenada();

    protected:
    void mostrarCategoria(Categoria categoria);

    private:
    CategoriasArchivo _repo;
};