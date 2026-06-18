#include <iostream>
#include "historialMenu.h"

using namespace std;

HistorialMenu::HistorialMenu()
{
    setCantidadOpciones(7);
}

void HistorialMenu::mostrarOpciones()
{
    cout << "----- MENU HISTORIAL-----"<<endl;
    cout << "1- LISTAR TODOS"<<endl;
    cout << "2- LISTAR HISTORIALES POR PACIENTES"<<endl;
    cout << "3- LISTAR HISTORIALES POR MEDICO"<<endl;
    cout << "4- CONSULTAR HISTORIALES POR DNI"<<endl;
    cout << "5- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "6- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void HistorialMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerHistorial.listarHistoriales();
        break;
    case 2:
        _managerHistorial.listarPorPaciente();
        break;
    case 3:
        _managerHistorial.listarPorMedico();
        break;
    case 4:
        _managerHistorial.listarPacienteHistorial();
        break;
    case 5:
        _managerHistorial.hacerCopiaDeSeguridad();
        break;
    case 6:
        _managerHistorial.restaurarCopiaDeSeguridad();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
