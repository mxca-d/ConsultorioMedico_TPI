#pragma once
#include "fecha.h"

class Paciente{
private:
    char _nombre[30];
    char _apellido[30];
    char _obraSocial[30];
    char _dni [12];
    int _idPaciente;
    int _idObraSocial;
    Fecha _fechaNacimiento;
    bool _eliminado;

public:
    Paciente();
    void setEliminado(bool eliminado);
    void setIdPaciente(int ID);
    void setIdObrasocial(int ID);

    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDni(const char* dni);
    void setObraSocial(const char* obraSocial);
    void setFechaNacimiento(Fecha fecha);


    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getObraSocial();
    int getIdPaciente();
    int getIdObraSocial();
    bool getEliminado();
    Fecha getFechaNacimiento();




};


