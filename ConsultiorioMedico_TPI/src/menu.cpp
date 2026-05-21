#include <iostream>
#include "menu.h"
#include "pacienteArchivo.h"
#include "historialArchivo.h"
#include "medicosArchivo.h"
#include "turnosArchivo.h"
#include "obraSocialArchivo.h"
#include "arancelArchivo.h"

using namespace std;


/*void menuTurnos(){
    int opcion;
do {
    cout<< "--SUBMENU TURNOS-- " <<endl << endl;
    cout << "1. AGENDAR TURNOS " << endl;
    cout << "2. MODIFICAR TURNOS "<< endl;
    cout << "3. CANCELAR TURNO " <<endl;
    cout << "4. VER TURNOS " << endl;
    cout << "5. CAMBIAR ESTADO DEL TURNO "<<endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){
        case 1: altaTurno(); break;
        case 2: modificarTurno(); break;
        case 3: bajaTurno(); break;
        case 4: listarTurnos(); break;
        case 5: cambiarEstadoTurno(); break;
    }
} while(opcion != 0);
}


void menuPacientes(){
    int opcion;
do {
    cout<< "--SUBMENU PACIENTES-- " <<endl << endl;
    cout << "1. ALTA PACIENTE " << endl;
    cout << "2. MODIFICAR PACIENTE "<< endl;
    cout << "3. BAJA PACIENTE " <<endl;
    cout << "4. LISTAR PACIENTES " << endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){
        case 1: altaPaciente(); break;
        case 2: modificarPaciente(); break;
        case 3: bajaPaciente(); break;
        case 4: listarPacientes(); break;
    }
} while(opcion != 0);
}

void menuMedicos(){
    int opcion;
do {
    cout<< "--SUBMENU MEDICOS-- " <<endl << endl;
    cout << "1. ALTA MEDICO " << endl;
    cout << "2. MODIFICAR MEDICO "<< endl;
    cout << "3. BAJA MEDICO " <<endl;
    cout << "4. LISTAR MEDICOS" << endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){

    }
} while(opcion != 0);
}

void menuAdministracion(){
    int opcion;
do {
    cout<< "--SUBMENU ADMINISTRACION-- " <<endl << endl;
    cout << "1. VER HISTORIAL " << endl;
    cout << "2. ALTA HISTORIAL "<< endl;
    cout << "3. BAJA HISTORIAL " <<endl;
    cout << "4. OBRAS SOCIALES " <<endl;
    cout << "5. ARANCELES " <<endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){


    }
} while(opcion != 0);
}

void menuObrasSociales(){
    int opcion;
do {
    cout<< "--SUBMENU OBRAS SOCIALES-- " <<endl << endl;
    cout << "1. ALTA OBRA SOCIAL " << endl;
    cout << "2. MODIFICAR OBRA SOCIAL "<< endl;
    cout << "3. BAJA OBRA SOCIAL " <<endl;
    cout << "4. LISTAR OBRAS SOCIALES " << endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){
        case 1: altaObraSocial(); break;
        case 2: modificarObraSocial(); break;
        case 3: bajaObraSocial(); break;
        case 4: listarObraSocial(); break;
    }
} while(opcion != 0);
}

void menuAranceles(){
    int opcion;
do {
    cout<< "--SUBMENU ARANCELES-- " <<endl << endl;
    cout << "1. ALTA ARANCEL " << endl;
    cout << "2. MODIFICAR ARANCEL "<< endl;
    cout << "3. BAJA ARANCEL " <<endl;
    cout << "4. LISTAR ARANCELES " << endl;
    cout << "0. VOLVER ATRAS " << endl;
    cin >> opcion;
    cin.ignore();

    switch(opcion){
        case 1: altaArancel(); break;
        case 2: modificarArancel(); break;
        case 3: bajaArancel(); break;
        case 4: listarArancel(); break;
    }
} while(opcion != 0);
}

void menuPrincipal(){
    int opcion;

do {
    cout << "1. TURNOS " <<endl;
    cout << "2. PACIENTES "<<endl;
    cout << "3. MEDICOS "<<endl;
    cout << "4. ADMINISTRACION "<<endl;
    cout << "0. SALIR " <<endl;
    cin>> opcion;
    cin.ignore();

    switch(opcion){
    case 1: menuTurnos();break;
    case 2: menuPacientes(); break;
    case 3: menuMedicos(); break;
    case 4: menuAdministracion(); break;
        }
}  while(opcion!=0);
}
*/
