#include <iostream>
#include "pacienteMenu.h"

using namespace std;

PacienteMenu::PacienteMenu(){
    setCantidadOpciones(8);
}


void PacienteMenu::mostrarOpciones(){

    cout <<"-----------MENU PACIENTES-----------"<<endl;
    cout << "1-LISTAR PACIENTES" << endl;
    cout << "2-BUSCAR PACIENTE POR ID" << endl;
    cout << "3-LISTAR PACIENTES POR APELLIDO" << endl;
    cout << "4-LISTAR PACIENTES POR OBRA SOCIAL" << endl;
    cout << "5-LISTAR PACIENTES POR DNI" << endl;
    cout << "6-HACER COPIA DE SEGURIDAD" << endl;
    cout << "7-RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << "0-SALIR" << endl;
    cout <<"-----------------------------------"<<endl;


}


void PacienteMenu::ejecutarOpcion(int opcion){

    switch(opcion){

    case 1:
        _managerPaciente.listarPacientes();
        break;
    case 2:
        _managerPaciente.BuscarPorId();
        break;
    case 3:
        _managerPaciente.listarPacientesPorApellido();
        break;
    case 4:
        _managerPaciente.listarPacientesPorObraSocial();
        break;
    case 5:
        _managerPaciente.listarPacientesPorDni();
        break;
    case 6:
        _managerPaciente.hacerCopiaDeSeguridad();
        break;
    case 7:
        _managerPaciente.restaurarCopiaDeSeguridad();
        break;
    case 0:

        break;

    }

}
