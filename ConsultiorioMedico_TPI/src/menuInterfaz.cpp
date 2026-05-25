#include <iostream>
#include "menuInterfaz.h"
using namespace std;

MenuInterfaz::MenuInterfaz(){
   setCantidadOpciones(1);
}

void MenuInterfaz::mostrarOpciones(){
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

void MenuInterfaz::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
      break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
