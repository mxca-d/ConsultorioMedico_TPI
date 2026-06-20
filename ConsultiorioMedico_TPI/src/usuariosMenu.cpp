#include <iostream>
#include "usuariosMenu.h"
#include "utils.h"

using namespace std;

UsuarioMenu::UsuarioMenu()
{
    setCantidadOpciones(7);
}

void UsuarioMenu::mostrarOpciones()
{
    cout << "----- MENU USUARIO-----"<<endl;
    cout << "1- ALTA DE USUARIO"<<endl;
    cout << "2- BAJA DE USUARIO"<<endl;
    cout << "3- MODIFICAR EXISTENTE"<<endl;
    cout << "4- LISTAR TODOS"<<endl;
    cout << "5- CREAR COPIA DE SEGURIDAD"<<endl;
    cout << "6- REESTABLECER DESDE COPIA DE SEGURIDAD" << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void UsuarioMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _managerUsuario.altaUsuario();
        break;
    case 2:
        _managerUsuario.bajaUsuario();
        break;
    case 3:
        {
        bool valido = false;
        char dni[9];
        if (_repoUsuarios.getCantidadActivos()>1)
        {
            cout << "INGRESE DNI USUARIO A MODIFICAR: ";
            valido = cargarCadena(dni,9);
            if (valido && soloNumeros(dni))
            {
                _managerUsuario.modificarUsuario(dni);
            }
            else
            {
                cout << "DNI INVALIDO O NULO..." << endl;
            }
        } else
        {
            cout << "NO EXISTEN REGISTROS A MODIFICAR..." << endl;
        }
        break;
        }
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
    }
}
