#include <iostream>
#include "Medicos.h"
#include <cstring>

using namespace std;

Medicos::Medicos()
{
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_dni, "N/A");
    strcpy(_especialidad, "N/A");
    strcpy (_matricula, "N/A");
    strcpy (_telefono, "N/A");
    _idMedico = 0;
    _eliminado = false;
    for (int i=0; i<5; i++)
    {

        _diasAgenda [i] =false;
        _turnos[i] = false;
    }


}



void Medicos::setNombre(const char* nombre)
{
    strcpy(_nombre,nombre);
}


void Medicos::setApellido(const char* apellido)
{
    strcpy(_apellido,apellido);

}


void Medicos::setEspecialidad(const char* especialidad)
{
    strcpy(_especialidad,especialidad);

}


void Medicos::setDni(const char* dni)
{
    strcpy(_dni,dni);

}


void Medicos::setMatricula(const char* matricula)
{
    strcpy(_matricula,matricula);

}


void Medicos::setTelefono(const char* telefono)
{
    strcpy(_telefono,telefono);

}


void Medicos::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}


void Medicos::setIdMedico(int id)
{
    _idMedico = id;
}

void Medicos::setHonorarios(float honorarios)
{
    _honorarios=honorarios;
}

void Medicos::setDiasAgenda (const bool* diasAgenda )
{
    for (int i=0; i<5; i++)
    {
        _diasAgenda[i] = diasAgenda[i];
    }
}
void Medicos::setTurnosAgenda (const bool* turnosAgenda)
{
    for (int i=0; i<5; i++)
    {
        _turnos[i] = turnosAgenda[i];
    }
}

const char* Medicos::getNombre()
{
    return _nombre;
}
const char* Medicos::getApellido()
{
    return _apellido;
}
const char* Medicos::getDni()
{
    return _dni;
}
const char* Medicos::getEspecialidad()
{
    return _especialidad;
}
const char* Medicos::getMatricula()
{
    return _matricula;
}
const char* Medicos::getTelefono()
{
    return _telefono;
}
int Medicos::getIdMedico()
{
    return _idMedico;
}
bool Medicos::getEliminado()
{
    return _eliminado;
}
float Medicos::getHonorarios()
{
    return _honorarios;
}

const bool* Medicos::getDiasAgenda()
{
    return _diasAgenda;
}
const bool* Medicos::getTurnosAgenda()
{
    return _turnos;
}
