#include <iostream>
#include "menuRecepcionista.h"

using namespace std;

MenuRecepcionista::MenuRecepcionista(){
   setCantidadOpciones(6);
}

void MenuRecepcionista::mostrarOpciones(){
   cout << "----- MENU RECEPCIONISTA-----"<<endl;
   cout <<" TURNOS:                      " << endl;
   cout << "1- CREAR TURNO"<<endl;
   cout << "2- CANCELAR TURNO"<<endl;
   cout << "3- CONSULTAR TURNO PENDIENTE"<<endl;
   cout << "PACIENTES:                   "<< endl;
   cout << "4- DAR DE ALTA"<<endl;
   cout << "5- DAR DE BAJA"<<endl;
   cout << "6- MODIFICAR"<<endl;
   cout << endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}

void MenuRecepcionista::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
       _managerTurno.altaTurno();
      break;
   case 2:
       _managerTurno.cancelarTurno();
       break;
   case 3:
    _managerTurno.listarTurnoPendientePorPaciente();
    break;
   case 4:
    _pacienteManager.altaPaciente();
    break;
   case 5:
    _pacienteManager.bajaPaciente();
    break;
    case 6:
    _pacienteManager.modificarPaciente();
    break;
   case 0:
      cout << "Saliendo.." << endl;
      break;
   default:
    cout << "OPCION INCORRECTA...";
   }
}
