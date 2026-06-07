#pragma once
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
    bool _diasAgenda [5];
    bool _turnos [5];



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
    void setDiasAgenda (const bool* diasAgenda);
    void setTurnosAgenda (const bool* turnosAgenda);


    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEspecialidad();
    const char* getMatricula();
    const char* getTelefono();
    int getIdMedico();
    float getHonorarios();
    bool getEliminado();
    const bool* getDiasAgenda();
    const bool* getTurnosAgenda();


};

