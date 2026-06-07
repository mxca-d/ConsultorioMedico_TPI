#pragma once

class Arancel{
private:
    int _idArancel, _idObraSocial;
    char _especialidad[30];
    float _cobertura;
    bool _eliminado;

public:
    Arancel();

    void setIdArancel(int id);
    void setIdObraSocial(int id);
    void setEspecialidad(const char*especialidad);
    void setCobertura(float cobertura);
    void setEliminado(bool eliminado);

    int getIdArancel();
    int getIdObraSocial();
    const char* getEspecialidad();
    float getCobertura();
    bool getEliminado();



};


