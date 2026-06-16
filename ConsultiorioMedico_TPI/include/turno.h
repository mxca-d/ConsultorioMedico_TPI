#pragma once
#include "fecha.h"


class Turno
{
private:
    int _idTurno;
    int _idPaciente;
    char _dniPaciente [8];
    int _idMedico;
    Fecha _fechaTurno;
    char _hora[6];
    char _diaTurno [8];
    char _estado[15];
    bool _eliminado;
    float _costoConsulta;



public:
    Turno();
    Turno (int idMedico, int dni, int turno,int idTurno,int idPaciente);
    void setIdTurno(int id);
    void setIdPaciente(int id);
    void setDniPaciente(const char* dni);
    void setIdMedico(int id);
    void setFechaTurno(Fecha fecha);
    void setHora(const char* hora);
    void setDiaTurno (int dia);
    void setEstado(const char* estado);
    void setEliminado(bool eliminado);
    void setCostoConsulta(float costo);

    const char* getHora();
    const char* getEstado();
    int getIdTurno();
    int getIdPaciente();
    const char* getDniPaciente();
    int getIdMedico();
    bool getEliminado();
    Fecha getFechaTurno();
    int getFechaint();
    float getCostoConsulta();
    const char* getDiaTurno();




};


