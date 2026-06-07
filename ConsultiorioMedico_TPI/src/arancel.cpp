#include <iostream>
#include <cstring>
#include "arancel.h"
#include "obraSocialArchivo.h"

using namespace std;

Arancel::Arancel()
{

    _idObraSocial = 0;
    _idArancel = 0;
    strcpy( _especialidad, "N/A");
    _cobertura = 0;
    _eliminado = false;

}


void Arancel::setIdArancel(int id)
{
    _idArancel = id;
}
void Arancel::setIdObraSocial(int id)
{
    _idObraSocial = id;
}

void Arancel::setEspecialidad(const char* especialidad)
{
    strcpy (_especialidad,especialidad);
}

void Arancel::setCobertura(float cobertura)
{
    _cobertura = cobertura;
}

void Arancel::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}



int Arancel::getIdArancel()
{
    return  _idArancel;
}
int Arancel::getIdObraSocial()
{
    return  _idObraSocial;
}
const char* Arancel::getEspecialidad()
{
    return  _especialidad;
}
float Arancel::getCobertura()
{
    return  _cobertura;
}
bool Arancel::getEliminado()
{
    return  _eliminado;
}
