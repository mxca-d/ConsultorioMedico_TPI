#include <iostream>
#include "Medicos.h"
#include <cstring>

using namespace std;

Medicos::Medicos(){
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy(_dni, "N/A");
    strcpy(_especialidad, "N/A");
    strcpy (_matricula, "N/A");
    strcpy (_telefono, "N/A");
    _idMedico = 0;
    _eliminado = false;


}

/*void Medicos::cargar(){
    cout << "Nombre: ";
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline (apellido, 30);
    cout << "DNI: ";
    cin.getline (dni, 12);
    cout << "Especialidad: ";
    cin.getline (especialidad, 30);
    cout << "Matricula: ";
    cin.getline(matricula, 15);
    cout << "Telefono: ";
    cin.getline(telefono, 15);
}

void Medicos::mostrar(){
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "DNI: " << dni << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Telefono: " << telefono << endl;
}*/ //MANAGER


void Medicos::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}


void Medicos::setApellido(const char* apellido){
    strcpy(_apellido,apellido);

}


void Medicos::setEspecialidad(const char* especialidad){
    strcpy(_especialidad,especialidad);

}


void Medicos::setDni(const char* dni){
    strcpy(_dni,dni);

}


void Medicos::setMatricula(const char* matricula){
    strcpy(_matricula,matricula);

}


void Medicos::setTelefono(const char* telefono){
    strcpy(_telefono,telefono);

}


void Medicos::setEliminado(bool eliminado){
    _eliminado = eliminado;
}


void Medicos::setIdMedico(int id){
    _idMedico = id;
}


const char* Medicos::getNombre(){return _nombre;}
const char* Medicos::getApellido(){return _apellido;}
const char* Medicos::getDni(){return _dni;}
const char* Medicos::getEspecialidad(){return _especialidad;}
const char* Medicos::getMatricula(){return _matricula;}
const char* Medicos::getTelefono(){return _telefono;}
int Medicos::getIdMedico(){return _idMedico;}
bool Medicos::getEliminado(){return _eliminado;}
