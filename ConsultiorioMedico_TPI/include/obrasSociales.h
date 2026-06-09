#pragma once

class ObraSociales{

private:
    int _idObraSocial;
    char _nombre[30];
    bool _eliminado;

public:
    ObraSociales();
    void setIdObraSocial(int id);
    void setNombre(const char *nombre);
    void setEliminado(bool eliminado);

    int getIdObraSocial();
    const char* getNombre();
    bool getEliminado();


};
