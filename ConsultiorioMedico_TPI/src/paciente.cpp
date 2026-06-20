#include <iostream>
#include <cstring>
#include "paciente.h"

using namespace std;

Paciente::Paciente()
{

    strcpy(_obraSocial, "N/A");
    _idPaciente = -1;


}


void Paciente::setIdPaciente(int id)
{
    _idPaciente=id;


}
void Paciente::setIdObrasocial(int id)
{
    _idObraSocial=id;


}





void Paciente::setObraSocial(const char* obraSocial)
{
    strcpy(_obraSocial,obraSocial);
}


const char* Paciente::getObraSocial()
{
    return _obraSocial;
}

int Paciente::getIdPaciente()
{
    return _idPaciente;
}
int Paciente::getIdObraSocial()
{
    return _idObraSocial;
}

