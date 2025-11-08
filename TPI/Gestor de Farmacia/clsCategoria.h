#pragma once

class Categoria {

public:

    Categoria();
    Categoria(int idCategoria, const char* nombre, bool estado);

    void setIdCategoria(int idCategoria);
    int getIdCategoria();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setEstado(bool estado);
    bool getEstado();

private:
    int _idCategoria;
    char _nombre[30];
    bool _estado;
};


