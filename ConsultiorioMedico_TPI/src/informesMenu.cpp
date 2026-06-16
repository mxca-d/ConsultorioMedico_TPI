#include <iostream>
#include "informesMenu.h"

using namespace std;

InformesMenu::InformesMenu()
{
    setCantidadOpciones(7);
}

void InformesMenu::mostrarOpciones()
{
    cout << "----- MENU INFORMES-----"<<endl;
    cout << "1- SUELDOS POR MEDICO"<<endl;
    cout << "2- RECAUDACION TOTAL DISCRIMINADA"<<endl;
    cout << "3- RECAUDACION POR OBRA SOCIALES"<<endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void InformesMenu::ejecutarOpcion(int opcion)
{
  /*  switch(opcion)
    {
    case 1:
        _managerUsuario.altaUsuario();
        break;
    case 2:
        _managerUsuario.bajaUsuario();
        break;
    case 3:
        //_managerUsuario.modificarUsuario();
        break;
    case 4:
        _managerUsuario.listarUsuarios();
        break;

    case 5:
  //      _managerUsuario.hacerCopiaDeSeguridad();
        break;
    case 6:
  //      _managerUsuario.restaurarCopiaDeSeguridad();
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }*/
}
