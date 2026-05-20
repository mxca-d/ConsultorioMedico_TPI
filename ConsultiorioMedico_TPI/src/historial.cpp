#include <iostream>
#include <cstring>
#include "Historial.h"


Historial::Historial(){
 _idHistorial=0;
 _idPaciente=0;
 _idMedico=0;
 _idTurno=0;
 strcpy (_diagnostico, "N/A");
 _fecha= Fecha(0,0,0);
 _eliminado=false;



}


void Historial::setIdHistorial(int id){
    if(id>0){
        _idHistorial=id;
    }

}


void Historial::setIdPaciente(int id){
    if(id>0){
        _idPaciente=id;
    }

}


void Historial::setIdMedico(int id){
    if(id>0){
        _idMedico=id;

    }

}


void Historial::setIdTurno(int id){
    if(id>0){
        _idTurno=id;
    }

}


void Historial::setDiagnostico(const char *diagnostico){
    strcpy(_diagnostico,diagnostico);

}


void Historial::setFecha(Fecha fecha){
    _fecha=fecha;

}


void Historial::setEliminado(bool eliminado){
    _eliminado=eliminado;

}


int Historial::getIdHistorial(){

    return _idHistorial;
}


int Historial::getIdPaciente(){
    return _idPaciente;

}


int Historial::getIdMedico(){
    return _idMedico;

}


int Historial::getIdTurno(){
    return _idTurno;

}


char* Historial::getDiagnostico(){
    return _diagnostico;

}


Fecha Historial::getFecha(){
    return _fecha;

}


bool Historial::getEliminado(){
    return _eliminado;

}
