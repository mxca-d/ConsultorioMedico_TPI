#include <iostream>
#include "pacienteMenu.h"

using namespace std;

PacienteMenu::PacienteMenu()
{
    setCantidadOpciones(10);
}

void PacienteMenu::mostrarOpciones()
{
    cout << "----- MENU PACIENTE-----"<<endl;
    cout << "1- ALTA PACIENTE"<<endl;
    cout << "2- BAJA PACIENTEO"<<endl;
    cout << "3- MODIFICAR EXISTENTE"<<endl;
    cout << "4- LISTAR TODOS"<<endl;
    cout << "5- LISTAR ORDENADOS POR APELLIDO"<<endl;
    cout << "6- LISTAR ORDENADOS POR OBRA SOCIAL"<<endl;
    cout << "7- LISTAR ORDENADOS POR DNI"<<endl;
    cout << "8- CONSULTAR POR ID"<<endl;
    cout << "9- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "10- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void PacienteMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerPaciente.altaPaciente();
        break;
    case 2:
        _managerPaciente.bajaPaciente();
        break;
    case 3:
        _managerPaciente.modificarPaciente();
        break;
    case 4:
        _managerPaciente.listarPacientes();
        break;
    case 5:
        _managerPaciente.listarPacientesPorApellido();
        break;
    case 6:
        _managerPaciente.listarPacientesPorObraSocial();
        break;
    case 7:
        _managerPaciente.listarPacientesPorDni();
        break;
    case 8:
        _managerPaciente.BuscarPorId();
        break;
    case 9:
        _managerPaciente.hacerCopiaDeSeguridad();
        break;
    case 10:
        _managerPaciente.restaurarCopiaDeSeguridad();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
