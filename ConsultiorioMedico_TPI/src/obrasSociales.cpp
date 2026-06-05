#include <iostream>
#include <cstring>
#include "obrasSociales.h"

using namespace std;

ObraSociales::ObraSociales(){

    _idObraSocial = 0;
    strcpy(_nombre, "N/A");
    _eliminado = false;

}



void ObraSociales::setIdObraSocial(int id){
    _idObraSocial = id;

}

void ObraSociales::setEliminado(bool eliminado){
    _eliminado = eliminado;

}

void ObraSociales::setNombre(const char *nombre){

    strcpy(_nombre,nombre);

}


const char* ObraSociales::getNombre(){return _nombre;}
bool ObraSociales::getEliminado(){return _eliminado;}
int ObraSociales::getIdObraSocial(){return _idObraSocial;}



