#pragma once
#include "fecha.h"
//#include "turnosArchivo.h"

class Turno
{
private:
    int _idTurno;
    int _idPaciente;
    int _idMedico;
    char _dniPaciente [8];///AGREGAMOS ATRIBUTO
    Fecha _fechaTurno;
    char _hora[6];
    char _diaTurno [8];///AGREGAMOS ATRIBUTO
    char _estado[15];
    bool _eliminado;
    float _costoConsulta;



public:
    Turno();
    Turno (int idMedico, int dni, int turno,int idTurno,int idPaciente);///AGREGAMOS CONSTRCUTOR CON PARAMETROS
    void setIdTurno(int id);
    void setIdPaciente(int id);
    void setDniPaciente(const char* dni);///AGREGAMOS METODO
    void setIdMedico(int id);
    void setFechaTurno(Fecha fecha);
    void setHora(int hora);
    void setEstado(const char* estado);
    void setDiaTurno (int dia);///AGREGAMOS METODO
    void setEliminado(bool eliminado);
    void setCostoConsulta(float costo);

    int getIdTurno();
    int getIdPaciente();
    int getIdMedico();
    Fecha getFechaTurno();
    const char* getHora();
    const char* getEstado();
    bool getEliminado();
    float getCostoConsulta();
    const char* getDniPaciente();///AGREGAMOS METODO
    int getFechaint();///CONSULTAR FRAN
    const char* getDiaTurno();///AGREGAMOS METODO




};


