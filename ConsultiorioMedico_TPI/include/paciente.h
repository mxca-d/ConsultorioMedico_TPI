#pragma once
#include "fecha.h"
#include "usuarios.h"

class Paciente: public Usuarios
{
private:
    char _obraSocial[30];
    int _idPaciente;
    int _idObraSocial;
    Fecha _fechaNacimiento;


public:
    Paciente();

    void setIdPaciente(int ID);
    void setIdObrasocial(int ID);
    void setObraSocial(const char* obraSocial);
    const char* getObraSocial();
    int getIdPaciente();
    int getIdObraSocial();





};


