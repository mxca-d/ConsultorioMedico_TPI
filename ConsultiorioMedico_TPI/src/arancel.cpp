#include <iostream>
#include <cstring>
#include "arancel.h"
#include "obraSocialArchivo.h"

using namespace std;

Arancel::Arancel(){

    _idObraSocial = 0;
     _idArancel = 0;
    strcpy( _especialidad, "N/A");
     _precio = 0;
     _eliminado = false;

}

/*void Arancel::cargar(){

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



}*/

void Arancel::setIdArancel(int id){
     _idArancel = id;
}

void Arancel::setEliminado(bool eliminado){
     _eliminado = eliminado;
}



int Arancel::getIdArancel(){return  _idArancel;}
    int Arancel::getIdObraSocial(){return  _idObraSocial;}
    const char* Arancel::getEspecialidad(){return  _especialidad;}
    float Arancel::getPrecio(){return  _precio;}
    bool Arancel::getEliminado(){return  _eliminado;}
