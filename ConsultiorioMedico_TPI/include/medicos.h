#pragma once
#include "medicos.h"
#include <string>

class Medicos
{
private:
    char _nombre[30];
    char _apellido[30];
    char _especialidad[30];
    char _dni[12];
    char  _matricula[15];
    char _telefono[15];
    int _idMedico;
    bool _eliminado;
    float _honorarios;

public:
    Medicos();

    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setEspecialidad(const char* especialidad);
    void setDni(const char* dni);
    void setMatricula(const char* matricula);
    void setTelefono(const char* telefono);
    void setEliminado(bool eliminado);
    void setIdMedico(int id);
    void setHonorarios(float honorarios);

    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEspecialidad();
    const char* getMatricula();
    const char* getTelefono();
    int getIdMedico();
    float getHonorarios();
    bool getEliminado();


};

