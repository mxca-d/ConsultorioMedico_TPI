#pragma once

class ObraSociales{

private:
    int IdObraSocial;
    char nombre[30];
    bool eliminado;

public:
    ObraSociales();
    void setIdObraSocial(int idos);
    void setEliminado(bool e);
    void cargar();
    void mostrar();

    const char* getNombre();
    int getIdObraSocial();
    bool getEliminado();
    //hola


};
