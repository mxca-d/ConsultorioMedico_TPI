#include <iostream>
#include "medicoMenu.h"

using namespace std;

MedicoMenu::MedicoMenu()
{
    setCantidadOpciones(10);
}

void MedicoMenu::mostrarOpciones()
{
    cout << "----- MENU MEDICO-----"<<endl;
    cout << "1- ALTA MEDICO"<<endl;
    cout << "2- BAJA MEDICO"<<endl;
    cout << "3- MODIFICAR EXISTENTE"<<endl;
    cout << "4- LISTAR TODOS"<<endl;
    cout << "5- LISTAR ORDENADOS POR APELLIDO"<<endl;
    cout << "6- LISTAR ORDENADOS POR ESPECIALIDAD"<<endl;
    cout << "7- CONSULTAR POR ID"<<endl;
    cout << "8- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "9- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void MedicoMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerMedico.altaMedico();
        break;
    case 2:
        _managerMedico.bajaMedico();
        break;
    case 3:
        _managerMedico.modificarMedico();
        break;
    case 4:
        _managerMedico.listarMedicos();
        break;
    case 5:
        _managerMedico.listarMedicoPorApellido();
        break;
    case 6:
        _managerMedico.listarMedicoPorEspecialidad();
        break;
    case 7:
        _managerMedico.mostrarPorId();
        break;
    case 8:
        _managerMedico.hacerCopiaDeSeguridad();
        break;
    case 9:
        _managerMedico.restaurarCopiaDeSeguridad();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
