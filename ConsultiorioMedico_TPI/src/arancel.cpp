#include <iostream>
#include <cstring>
#include "arancel.h"
#include "obraSocialArchivo.h"

using namespace std;

Arancel::Arancel(){

    idObraSocial = 0;
    idArancel = 0;
    strcpy(especialidad, "N/A");
    precio = 0;
    eliminado = false;

}

void Arancel::cargar(){

    listarObraSocial();
    cout << "Ingrese obra social: ";
    cin >> idObraSocial;
    cin.ignore();
    cout << "Ingrese especialidad: ";
    cin.getline(especialidad, 30);
    cout << "Ingrese el precio: ";
    cin>> precio;

}

void Arancel::mostrar(){
    cout<< "ID Obra Social: "<< idObraSocial << endl;
    cout<< "Especialidad: " << especialidad << endl;
    cout << "Precio: " << precio << endl;



}

void Arancel::setIdArancel(int ida){
    idArancel = ida;
}

void Arancel::setEliminado(bool e){
    eliminado = e;
}



int Arancel::getIdArancel(){return idArancel;}
    int Arancel::getIdObraSocial(){return idObraSocial;}
    const char* Arancel::getEspecialidad(){return especialidad;}
    float Arancel::getPrecio(){return precio;}
    bool Arancel::getEliminado(){return eliminado;}
