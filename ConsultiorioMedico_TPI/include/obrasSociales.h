#pragma once

class ObraSociales{

private:
    int _idObraSocial;
    char _nombre[30];
    bool _eliminado;

public:
    ObraSociales();
    void setIdObraSocial(int id);
    void setEliminado(bool eliminado);
    void setNombre(const char *nombre);

    const char* getNombre();
    int getIdObraSocial();
    bool getEliminado();


};
