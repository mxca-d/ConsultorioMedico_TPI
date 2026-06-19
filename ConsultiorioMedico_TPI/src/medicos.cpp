#include <iostream>
#include "Medicos.h"
#include <cstring>

using namespace std;

Medicos::Medicos()
{

    strcpy(_especialidad, "N/A");
    strcpy (_matricula, "N/A");

    _idMedico = 0;
    for (int i=0; i<5; i++)
    {
        _diasAgenda [i] =false;

    }


}



void Medicos::setEspecialidad(const char* especialidad)
{
    strcpy(_especialidad,especialidad);

}




void Medicos::setMatricula(const char* matricula)
{
    strcpy(_matricula,matricula);

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

void Medicos::setDiaAgendaEleccion (int seleccion, bool estado )
{

        _diasAgenda[seleccion] = estado;

}



const char* Medicos::getEspecialidad()
{
    return _especialidad;
}
const char* Medicos::getMatricula()
{
    return _matricula;
}

int Medicos::getIdMedico()
{
    return _idMedico;
}


float Medicos::getHonorarios()
{
    return _honorarios;
}

const bool* Medicos::getDiasAgenda()
{
    return _diasAgenda;
}
