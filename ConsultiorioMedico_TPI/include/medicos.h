#pragma once
#include <string>
#include "usuarios.h"

class Medicos: public Usuarios
{
private:

    char _especialidad[30];
    char  _matricula[15];
    int _idMedico;
    float _honorarios;
    bool _diasAgenda [5];
    bool _turnos [5];



public:
    Medicos();


    void setEspecialidad(const char* especialidad);

    void setMatricula(const char* matricula);

    void setIdMedico(int id);
    void setHonorarios(float honorarios);
    void setDiasAgenda (const bool* diasAgenda);
    void setDiaAgendaEleccion (int seleccion, bool estado );
    void setTurnosAgenda (const bool* turnosAgenda);
    void setTurnoEleccion (int seleccion, bool estado );



    const char* getEspecialidad();
    const char* getMatricula();

    int getIdMedico();
    float getHonorarios();

    const bool* getDiasAgenda();
    const bool* getTurnosAgenda();


};

