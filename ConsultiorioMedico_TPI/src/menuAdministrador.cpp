#include <iostream>
#include "menuAdministrador.h"
using namespace std;

MenuAdministrador::MenuAdministrador(){
   setCantidadOpciones(6);
}

void MenuAdministrador::mostrarOpciones(){
   cout << "----- MENU COMPLERO-----"<<endl;
   cout << "1- TURNOS"<<endl;
   cout << "2- MEDICOS"<<endl;
   cout << "3- PACIENTES"<<endl;
   cout << "4- OBRAS SOCIALES"<<endl;
   cout << "5- ARANCELES"<<endl;
   cout << "6- HISTORIAL PACIENTES"<<endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}

void MenuAdministrador::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:

      break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
