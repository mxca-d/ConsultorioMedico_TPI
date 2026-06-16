#include <iostream>
#include "arancelMenu.h"

using namespace std;

ArancelMenu::ArancelMenu()
{
    setCantidadOpciones(7);
}

void ArancelMenu::mostrarOpciones()
{
    cout << "----- MENU ARANCELES-----"<<endl;
    cout << "1- ALTA DE ARANCEL"<<endl;
    cout << "2- BAJA DE ARANCEL"<<endl;
    cout << "3- MODIFICAR EXISTENTE"<<endl;
    cout << "4- LISTAR TODOS"<<endl;
    cout << "5- CONSULTAR POR ID"<<endl;
    cout << "6- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "7- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void ArancelMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerArancel.altaArancel();
        break;
    case 2:
        _managerArancel.bajaArancel();
        break;
    case 3:
        _managerArancel.modificarArancel();
        break;
    case 4:
        _managerArancel.listarAranceles();
        break;
    case 5:
        _managerArancel.listarXId();
        break;
    case 6:
        _managerArancel.hacerCopiaDeSeguridad();
        break;
    case 7:
        _managerArancel.restaurarCopiaDeSeguridad();
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
