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
    strcpy (_dniPaciente, "N/A");
    strcpy (_hora, "N/A");
    strcpy (_estado, "N/A");
    strcpy (_diaTurno, "N/A");


    _eliminado = false;


}

Turno::Turno (int idMedico, int dni, int turno,int idTurno, int idPaciente)
{

    _idTurno = idTurno;
    _idMedico = idMedico;
    _idPaciente = idPaciente;
    strcpy (_dniPaciente, "N/A");
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

void Turno::setDniPaciente(const char* dni)
{
    strcpy(_dniPaciente,dni);

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


void Turno::setHora(int hora)/// 0-1
{
    switch(hora)
    {
    case 0 :
        strcpy(_hora,"08:00" );
        break;

    case 1:
        strcpy(_hora,"09:00" );
        break;

    case 2:
        strcpy(_hora,"10:00" );
        break;
    case 3:
        strcpy(_hora,"11:00" );
        break;
    case 4:
        strcpy(_hora,"12:00" );
        break;
    default:
        strcpy(_hora,"ERROR" );
        break;

    }
}
void Turno::setDiaTurno (int dia)
{
    switch(dia)
    {
    case 0 :
        strcpy(_diaTurno,"LUNES" );
        break;

    case 1:
        strcpy(_diaTurno,"MARTES" );
        break;

    case 2:
        strcpy(_diaTurno,"MIERCOLES" );
        break;
    case 3:
        strcpy(_diaTurno,"JUEVES" );
        break;
    case 4:
        strcpy(_diaTurno,"VIERNES" );
        break;
    default:
        strcpy(_diaTurno,"ERROR" );
        break;

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

const char* Turno::getDniPaciente()
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
Fecha Turno::getFechaTurno()
{
    return _fechaTurno;
}

int Turno::getFechaint()
{
    int fecha = _fechaTurno.getAnio()*10000 + _fechaTurno.getMes() * 100 + _fechaTurno.getDia();
    return fecha;
}

const char* Turno::getDiaTurno()
{
    return _diaTurno;
}
