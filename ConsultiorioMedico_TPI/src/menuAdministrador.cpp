#include <iostream>
#include "menuAdministrador.h"
#include "usuariosManager.h"
using namespace std;

MenuAdministrador::MenuAdministrador()
{
    setCantidadOpciones(6);
}

void MenuAdministrador::mostrarOpciones()
{
    cout << "----- MENU COMPLERO-----"<<endl;
    cout << "1- DAR ALTA USUARIO"<<endl;
    cout << "2- DAR ALTA MEDICO"<<endl;
    cout << "3- DAR DE ALTA OBRA SOCIAL" << endl;
    cout << "4- MENU ARANCEL"<<endl;
    cout << "5- LISTAR USUARIOS" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void MenuAdministrador::ejecutarOpcion(int opcion)
{


    switch(opcion)
    {
    case 1:
        _usuarioManager.altaUsuario();
        break;
    case 2:
        _medicoManager.altaMedico();
        break;
    case 3:
        _obraSocialManager.altaObraSocial();
        break;
    case 4:
        _menuArancel.run();
        break;
    case 5:
        _usuarioManager.listarUsuarios();
        break;
    case 0:
        cout << "Gracias por usar mi app :)" << endl;
        break;
    }
}
