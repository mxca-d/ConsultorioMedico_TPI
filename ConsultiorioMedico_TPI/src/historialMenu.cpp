#include <iostream>
#include "historialMenu.h"

using namespace std;

HistorialMenu::HistorialMenu()
{
    setCantidadOpciones(5);
}

void HistorialMenu::mostrarOpciones()
{
    cout << "----- MENU HISTORIAL-----"<<endl;
    cout << "1- LISTAR TODOS"<<endl;
    cout << "2- LISTAR ORDENADOS POR PACIENTES"<<endl;
    cout << "3- LISTAR ORDENADOS POR MEDICO"<<endl;
    cout << "4- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "5- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
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
        _managerHistorial.hacerCopiaDeSeguridad();
        break;
    case 5:
        _managerHistorial.restaurarCopiaDeSeguridad();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
