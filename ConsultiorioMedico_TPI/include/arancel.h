#pragma once

class Arancel{
private:
    int _idArancel, _idObraSocial;
    char _especialidad[30];
    float _precio;
    bool _eliminado;

public:
    Arancel();

    void setIdArancel(int id);
    void setIdObraSocial(int id);
    void setEspecialidad(const char*especialidad);
    void setPrecio(float precio);
    void setEliminado(bool eliminado);

    int getIdArancel();
    int getIdObraSocial();
    const char* getEspecialidad();
    float getPrecio();
    bool getEliminado();



};


