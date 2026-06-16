#include <iostream>
#include <cstring>
#include "paciente.h"

using namespace std;

Paciente::Paciente(){
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_dni, "N/A");
    strcpy(_domicilio, "N/A");
    strcpy(_telefono, "N/A");
    strcpy(_email, "N/A");
    strcpy(_obraSocial, "N/A");
    _idObraSocial=0;
    _idPaciente = 0;

    _eliminado = false;

}


void Paciente::setEliminado(bool eliminado){
    _eliminado = eliminado;
}

void Paciente::setIdPaciente(int id){
    _idPaciente=id;


}
void Paciente::setIdObrasocial(int id){
    _idObraSocial=id;


}
void Paciente::setObraSocial(const char* obraSocial){
    strcpy(_obraSocial,obraSocial);
}
void Paciente::setNombre(const char* nombre){
    strcpy(_nombre,nombre);

}

void Paciente::setApellido(const char* apellido){
    strcpy(_apellido,apellido);
}


void Paciente::setDni(const char* dni){
    strcpy(_dni,dni);
}


void Paciente::setFechaNacimiento(Fecha fecha){
    _fechaNacimiento=fecha;

}

void Paciente::setEmail(const char* email){
    strcpy(_email,email);
}
void Paciente::setTelefono(const char* telefono){
    strcpy(_telefono,telefono);
}


void Paciente::setDomicilio(const char* domicilio){
    strcpy(_domicilio,domicilio);
}

const char* Paciente::getEmail(){
    return _email;
}


const char* Paciente::getTelefono(){
    return _telefono;
}


const char* Paciente::getDomicilio(){
    return _domicilio;
}

const char* Paciente::getNombre(){return _nombre;}
const char* Paciente::getApellido(){return _apellido;}
const char* Paciente::getDni(){return _dni;}
const char* Paciente::getObraSocial(){ return _obraSocial;}
int Paciente::getIdPaciente(){return _idPaciente;}
int Paciente::getIdObraSocial(){return _idObraSocial;}
bool Paciente::getEliminado(){return _eliminado;}
Fecha Paciente::getFechaNacimiento(){
    return _fechaNacimiento;
}
