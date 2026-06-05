#pragma once
#include "fecha.h"
//#include "turnosArchivo.h"

class Turno
{
private:
    int _idTurno;
    int _idPaciente;
    int _dniPaciente;
    int _idMedico;
    Fecha _fechaTurno;
    char _hora[6]; //agregue un espacio mas por los :
    char _estado[15];
    bool _eliminado;
    float _costoConsulta;

    //TurnoArchivo _repoTurno;

public:
    Turno();
    Turno (int idMedico, int dni, int turno,int idTurno,int idPaciente);
    void setIdTurno(int id);
    void setIdPaciente(int id);
    void setDniPaciente(int dni);
    void setIdMedico(int id);
    void setFechaTurno(Fecha fecha);
    void setHora(const char* hora);
    void setEstado(const char* estado);
    void setEliminado(bool eliminado);
    void setCostoConsulta(float costo);

    const char* getHora();
    const char* getEstado();
    int getIdTurno();
    int getIdPaciente();
    int getDniPaciente();
    int getIdMedico();
    bool getEliminado();
    Fecha getFechaTurno();
    float getCostoConsulta();




};


