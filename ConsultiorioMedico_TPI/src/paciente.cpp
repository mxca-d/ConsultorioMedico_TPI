#include <iostream>
#include <cstring>
#include "paciente.h"

using namespace std;

Paciente::Paciente(){
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_dni, "N/A");
    strcpy(_obraSocial, "N/A");
    _idPaciente = 0;
    _eliminado = false;

}


void Paciente::setEliminado(bool eliminado){
    _eliminado = eliminado;
}

void Paciente::setIdPaciente(int id){
    if(id>0){
    _idPaciente=id;
    }

}
void Paciente::setNombre(const char* nombre){
    strcpy(_nombre,nombre);

}
//hola

void Paciente::setApellido(const char* apellido){
    strcpy(_apellido,apellido);
}


void Paciente::setDni(const char* dni){
    strcpy(_dni,dni);
}


void Paciente::setObraSocial(const char* obraSocial){
    strcpy(_obraSocial,obraSocial);
}
void Paciente::setFechaNacimiento(Fecha fecha){
    _fechaNacimiento=fecha;

}
const char* Paciente::getNombre(){return _nombre;}
const char* Paciente::getApellido(){return _apellido;}
const char* Paciente::getDni(){return _dni;}
const char* Paciente::getObraSocial(){return _obraSocial;}
int Paciente::getIdPaciente(){return _idPaciente;}
bool Paciente::getEliminado(){return _eliminado;}

Fecha Paciente::getFechaNacimiento(){
//return _fechaNacimiento.();
}
