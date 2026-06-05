#include <iostream>
#include <cstring>
#include "turno.h"
#include "utils.h"

using namespace std;

Turno::Turno()
{
    _idTurno = 0;
    _idMedico = 0;
    _idPaciente = 0;
    _dniPaciente = 0;
    strcpy (_hora, "N/A");
    strcpy (_estado, "N/A");
    _eliminado = false;

}

Turno::Turno (int idMedico, int dni, int turno,int idTurno, int idPaciente)
{

    _idTurno = idTurno;
    _idMedico = idMedico;
    _idPaciente = idPaciente;
    _dniPaciente = dni;
    strcpy (_estado, "PENDIENTE");
    _eliminado = false;
}



void Turno::setIdTurno(int id)
{
    if(id>0)
    {
        _idTurno=id;
    }

}


void Turno::setIdPaciente(int id)
{
    _idPaciente=id;

}

void Turno::setDniPaciente(int dni)
{
    _dniPaciente=dni;

}


void Turno::setIdMedico(int id)
{
    _idMedico=id;

}


void Turno::setFechaTurno(Fecha fecha)
{
    if(fecha.fechaValida(_fechaTurno.getDia(),_fechaTurno.getMes(), _fechaTurno.getAnio()))
    {
        _fechaTurno=fecha;
    }

}


void Turno::setHora(const char* hora)
{
    if(horaValida(hora))
    {
        strcpy(_hora,hora);
    }

}


void Turno::setEstado(const char* estado)
{
    strcpy(_estado,estado);

}


void Turno::setEliminado(bool eliminado)
{
    _eliminado = eliminado;

}


void Turno::setCostoConsulta(float costo)
{
    _costoConsulta=costo;

}
const char* Turno::getHora()
{
    return _hora;
}
const char* Turno::getEstado()
{
    return _estado;
}
int Turno::getIdTurno()
{
    return _idTurno;
}
int Turno::getIdPaciente()
{
    return _idPaciente;
}

int Turno::getDniPaciente()
{
    return _dniPaciente;
}
int Turno::getIdMedico()
{
    return _idMedico;
}
bool Turno::getEliminado()
{
    return _eliminado;
}
float Turno::getCostoConsulta()
{
    return _costoConsulta;
}
