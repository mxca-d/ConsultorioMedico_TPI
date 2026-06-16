#include <iostream>
#include "menuAdministrador.h"
#include "usuariosManager.h"
using namespace std;

MenuAdministrador::MenuAdministrador()
{
    setCantidadOpciones(7);
}

void MenuAdministrador::mostrarOpciones()
{
    cout << "----- MENU COMPLERO-----"<<endl;
    cout << "1- USUARIO"<<endl;
    cout << "2- MEDICOS"<<endl;
    cout << "3- PACIENTES" << endl;
    cout << "4- OBRA SOCIALES"<<endl;
    cout << "5- ARANCELES" << endl;
    cout << "6- HISTORIALES" << endl;
    cout << "7- INFORMES" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void MenuAdministrador::ejecutarOpcion(int opcion)
{


    switch(opcion)
    {
    case 1:
        _usuarioMenu.run();
        break;
    case 2:
        _medicoMenu.run();
        break;
    case 3:
        _pacienteMenu.run();
        break;
    case 4:
        _obraSocialesMenu.run();
        break;
    case 5:
        _menuArancel.run();
        break;
    case 6:
        _HistorialMenu.run();
        break;
    case 7:
        _informesMenu.run();
        break;
    case 0:
        cout << "Gracias por usar mi app :)" << endl;
        break;
    }
}
