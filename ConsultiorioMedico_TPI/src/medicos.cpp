#include <iostream>
#include "Medicos.h"
#include <cstring>

using namespace std;

Medicos::Medicos(){
    strcpy(nombre, "N/A");
    strcpy(apellido, "N/A");
    strcpy(dni, "N/A");
    strcpy(especialidad, "N/A");
    strcpy (matricula, "N/A");
    strcpy (telefono, "N/A");
    idMedico = 0;
    eliminado = false;


}

void Medicos::cargar(){
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
}

void Medicos::setEliminado(bool e){
    eliminado = e;
}
void Medicos::setIdMedico(int idm){
    idMedico = idm;
}


const char* Medicos::getNombre(){return nombre;}
const char* Medicos::getApellido(){return apellido;}
const char* Medicos::getDni(){return dni;}
const char* Medicos::getEspecialidad(){return especialidad;}
const char* Medicos::getMatricula(){return matricula;}
const char* Medicos::getTelefono(){return telefono;}
int Medicos::getIdMedico(){return idMedico;}
bool Medicos::getEliminado(){return eliminado;}
