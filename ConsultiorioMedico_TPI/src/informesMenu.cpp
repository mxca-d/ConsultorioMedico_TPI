#include <iostream>
#include "informesMenu.h"

using namespace std;

InformesMenu::InformesMenu()
{
    setCantidadOpciones(4);
}

void InformesMenu::mostrarOpciones()
{
    cout << "----- MENU INFORMES-----"<<endl;
    cout << "1- SUELDOS POR MEDICO"<<endl;
    cout << "2- RECAUDACION TOTAL"<<endl;
    cout << "3- RECAUDACION TOTAL DESCONTANDO OBRA SOCIALES"<<endl;
    cout << "4- RECAUDACION POR OBRA SOCIALES"<<endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void InformesMenu::ejecutarOpcion(int opcion)
{
 /*   switch(opcion)
    {
    case 1:
        _managerObraSocial.altaObraSocial();
        break;
    case 2:
        _managerObraSocial.bajaObraSocial();
        break;
    case 3:
        _managerObraSocial.modificarObraSocial();
        break;
    case 4:
        _managerObraSocial.listarObrasSociales();
        break;
    case 5:
        _managerObraSocial.buscarObraSocialPorId();
        break;
    case 6:
        _managerObraSocial.hacerCopiaDeSeguridad();
        break;
    case 7:
        _managerObraSocial.restaurarCopiaDeSeguridad();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    } */
}
