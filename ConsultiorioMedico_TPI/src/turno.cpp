#include <iostream>
#include <cstring>
#include "turno.h"

using namespace std;

Turno::Turno(){
    idTurno = 0;
    idMedico = 0;
    idPaciente = 0;
    strcpy (hora, "N/A");
    strcpy (estado, "N/A");
    eliminado = false;

}

void Turno::cargar(){
    fechaTurno.cargar();
    cin.ignore();
    cout<< "Hora: ";
    cin >> hora;
    cout << "ID del paciente: ";
    cin >> idPaciente;
    cout << "ID del medico: ";
    cin>> idMedico;
    strcpy (estado, "Pendiente");

}

void Turno::mostrar(){
    fechaTurno.mostrar();
    cout << "Hora: " << hora << endl;
    cout << "Estado: " << estado << endl;


}
void Turno::setEliminado(bool e){
    eliminado = e;
}
void Turno::setIdTurno(int idt){
    idTurno = idt;
}

void Turno::setEstado(char es[15]){
    strcpy(estado, es);

}

const char* Turno::getHora(){return hora;}
const char* Turno::getEstado(){return estado;}
int Turno::getIdTurno(){return idTurno;}
int Turno::getIdPaciente(){return idPaciente;}
int Turno::getIdMedico(){return idMedico;}
bool Turno::getEliminado(){return eliminado;}
