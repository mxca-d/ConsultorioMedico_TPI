#include <iostream>
#include "turnoMenu.h"
#include "utils.h"

using namespace std;

TurnoMenu::TurnoMenu()
{

    setCantidadOpciones(10);
}

void TurnoMenu::mostrarOpciones()
{

    cout <<"-----------MENU TURNOS-----------"<<endl;
    cout << "1-LISTAR TURNOS" << endl;
    cout << "2-BUSCAR TURNOS POR DNI DEL PACIENTE" << endl;
    cout << "3-BUSCAR TURNOS POR DNI DEL MEDICO" << endl;
    cout << "4-LISTAR TURNOS POR PACIENTE" << endl;
    cout << "5-LISTAR TURNOS POR MEDICOS" << endl;
    cout << "6-LISTAR TURNOS POR ESTADO" << endl;
    cout << "7-LISTAR TURNOS POR FECHA" << endl;
    cout << "8-HACER COPIA DE SEGURIDAD" << endl;
    cout << "9-RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << "0-SALIR" << endl;
    cout <<"-----------------------------------"<<endl;

}


void TurnoMenu::ejecutarOpcion(int opcion)
{

    switch(opcion)
    {

    case 1:
        _managerTurno.listarTurnos();
        break;
    case 2:
        _managerTurno.listarTurnoPendientePorPaciente();
        break;
    case 3:
        char dni[9];
        bool valido;
        cout << "DNI MEDICO: ";
        valido = cargarCadena(dni,9);
        if (valido && dniValido(dni))
        {
            _managerTurno.listarTurnoPendientePorMedico(dni);
        }
        else
        {
            cout << "Ingreso invalido.." << endl;
        }
        break;
    case 4:
        _managerTurno.listarPorPaciente();
        break;
    case 5:
        _managerTurno.listarPorMedico();
        break;
    case 6:
        _managerTurno.listarPorEstado();
        break;
    case 7:
        _managerTurno.listarPorFecha();
        break;
    case 8:
        _managerTurno.hacerCopiaDeSeguridad();
        break;
    case 9:
        _managerTurno.restaurarCopiaDeSeguridad();
        break;
    case 0:

        break;

    }


}
