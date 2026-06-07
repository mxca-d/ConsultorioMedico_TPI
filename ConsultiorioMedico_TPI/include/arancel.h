#pragma once

class Arancel{
private:
    int _idArancel, _idObraSocial;
    char _especialidad[30];
    int _cobertura;
    bool _eliminado;

public:
    Arancel();

    void setIdArancel(int id);
    void setIdObraSocial(int id);
    void setEspecialidad(const char*especialidad);
    void setCobertura(int cobertura);
    void setEliminado(bool eliminado);

    int getIdArancel();
    int getIdObraSocial();
    const char* getEspecialidad();
    int getCobertura();
    bool getEliminado();



};


