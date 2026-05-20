#include <iostream>
#include <cstring>
#include "obrasSociales.h"

using namespace std;

ObraSociales::ObraSociales(){

    IdObraSocial = 0;
    strcpy(nombre, "N/A");
    eliminado = false;

}

void ObraSociales::cargar(){

    cout << "Nombre de la obra social: ";
    cin.getline(nombre, 30);


}

void ObraSociales::mostrar(){
    cout<< "Obra social: " << nombre<<endl;

}

void ObraSociales::setIdObraSocial(int idos){
    IdObraSocial = idos;

}

void ObraSociales::setEliminado(bool e){
    eliminado = e;

}
const char* ObraSociales::getNombre(){return nombre;}
bool ObraSociales::getEliminado(){return eliminado;}
int ObraSociales::getIdObraSocial(){return IdObraSocial;}



