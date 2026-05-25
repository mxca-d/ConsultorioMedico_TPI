#pragma once
#include "fecha.h"

class Turno{
private:
    int _idTurno;
    int _idPaciente;
    int _idMedico;
    Fecha _fechaTurno;
    char _hora[6];//agregue un espacio mas por los :
    char _estado[15];
    bool _eliminado;

public:
    void setIdTurno(int id);
    void setIdPaciente(int id);
    void setIdMedico(int id);
    void setFechaTurno(Fecha fecha);
    void setHora(const char* hora);
    void setEstado(const char* estado);
    void setEliminado(bool eliminado);

    Turno();
    void cargar();
    void mostrar();

    const char* getHora();
    const char* getEstado();
    int getIdTurno();
    int getIdPaciente();
    int getIdMedico();
    bool getEliminado();
    Fecha getFechaTurno();



};


