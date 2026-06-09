#pragma once
#include <string>

class Medicos
{
private:
    int _idMedico;
    char _nombre[30];
    char _apellido[30];
    char _dni[12];
    //email
    //domicilio
    char _especialidad[30];
    char  _matricula[15];
    char _telefono[15];
    bool _eliminado;
    float _honorarios;
    bool _diasAgenda [5];///AGREGAMOS ESTE ATRIBUTO
    bool _turnos [5];///AGREGAMOS ESTE ATRIBUTO

    ///FALTA EMAIL Y DIRECCION, PERO LO AGREGO AL CREAR LA CLASE PERSONA QUE VA A HEREDAR ESOS DATOS


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
    void setDiasAgenda (const bool* diasAgenda);///AGREGAMOS ESTE METODO
    void setDiaAgendaEleccion (int seleccion, bool estado );///AGREGAMOS ESTE METODO
    void setTurnosAgenda (const bool* turnosAgenda);///AGREGAMOS ESTE METODO
    void setTurnoEleccion (int seleccion, bool estado );///AGREGAMOS ESTE METODO


    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEspecialidad();
    const char* getMatricula();
    const char* getTelefono();
    int getIdMedico();
    float getHonorarios();
    bool getEliminado();
    const bool* getDiasAgenda();///AGREGAMOS ESTE METODO
    const bool* getTurnosAgenda();///AGREGAMOS ESTE METODO


};

