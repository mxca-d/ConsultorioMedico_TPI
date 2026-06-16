#include <iostream>
#include "obraSocialMenu.h"

using namespace std;

ObraSocialMenu::ObraSocialMenu()
{
    setCantidadOpciones(7);
}

void ObraSocialMenu::mostrarOpciones()
{
    cout << "----- MENU OBRA SOCIAL-----"<<endl;
    cout << "1- ALTA OBRA SOCIAL"<<endl;
    cout << "2- BAJA OBRA SOCIAL"<<endl;
    cout << "3- MODIFICAR EXISTENTE"<<endl;
    cout << "4- LISTAR TODAS"<<endl;
    cout << "5- CONSULTAR POR ID"<<endl;
    cout << "6- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "7- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void ObraSocialMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
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
    }
}
