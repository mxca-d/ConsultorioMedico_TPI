#include <iostream>
#include <cstring>
#include "turno.h"
#include "utils.h"

using namespace std;

Turno::Turno(){
    _idTurno = 0;
    _idMedico = 0;
    _idPaciente = 0;
    strcpy (_hora, "N/A");
    strcpy (_estado, "N/A");
    _eliminado = false;

}

/*void Turno::cargar(){//MANAGER
    _fechaTurno.cargar();
    cin.ignore();
    cout<< "Hora: ";
    cin >> hora;
    cout << "ID del paciente: ";
    cin >> idPaciente;
    cout << "ID del medico: ";
    cin>> idMedico;
    strcpy (estado, "Pendiente");

}

void Turno::mostrar(){//MANAGER
    fechaTurno.mostrar();
    cout << "Hora: " << hora << endl;
    cout << "Estado: " << estado << endl;


}*/

void Turno::setIdTurno(int id){
    if(id>0){
        _idTurno=id;
    }

}


void Turno::setIdPaciente(int id){
    _idPaciente=id;

}


void Turno::setIdMedico(int id){
    _idMedico=id;

}


void Turno::setFechaTurno(Fecha fecha){
    if(fecha.fechaValida(_fechaTurno.getDia(),_fechaTurno.getMes(), _fechaTurno.getAnio())){
        _fechaTurno=fecha;
    }

}


void Turno::setHora(const char* hora){
    if(horaValida){
       strcpy(_hora,hora);
    }

}


void Turno::setEstado(const char* estado){


}


void Turno::setEliminado(bool eliminado){


}

const char* Turno::getHora(){return _hora;}
const char* Turno::getEstado(){return _estado;}
int Turno::getIdTurno(){return _idTurno;}
int Turno::getIdPaciente(){return _idPaciente;}
int Turno::getIdMedico(){return _idMedico;}
bool Turno::getEliminado(){return _eliminado;}
