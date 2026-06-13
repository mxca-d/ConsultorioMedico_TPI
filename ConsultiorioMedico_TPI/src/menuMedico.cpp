#include <iostream>
#include "MenuMedico.h"

using namespace std;

MenuMedico::MenuMedico()
{
    setCantidadOpciones(4);
}

void MenuMedico::mostrarOpciones()
{
    cout << "-------- MENU MEDICO --------"<<endl;
    cout <<" TURNOS:                      " << endl;
    cout << "1- ATENDER TURNO"<<endl;
    cout << "2- CANCELAR TURNO"<<endl;
    cout << "3- CONSULTAR TURNO PENDIENTE"<<endl;
    cout << "HISTORIA CLINICA:                   "<< endl;
    cout << "4- CONSULTAR"<<endl;
    cout << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
    cout << "ant"<< _dniUsuario << "des"<<endl;

}

void MenuMedico::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
cout << "menu medico " << _dniUsuario << endl;
        _managerTurno.atenderTurno(_dniUsuario);
        break;
    case 2:
        _managerTurno.cancelarTurno();
        break;
    case 3:
        _managerTurno.listarTurnoPendientePorMedico();
        break;
    case 4:
        //_historialManager.listarPorPaciente();// no funca..
        break;
    case 5:
        _pacienteManager.bajaPaciente();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
