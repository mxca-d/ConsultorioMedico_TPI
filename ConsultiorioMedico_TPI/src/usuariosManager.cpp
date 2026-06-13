#include <iostream>
#include <cstring>
#include "usuariosManager.h"
#include "utils.h"

using namespace std;


void UsuariosManager::crearAdminSiNoExiste(){



    if(_repoUsuarios.getCantidadRegistros()==0){

        Usuarios admin;

        admin.setEliminado(false);
        admin.setIdMedico(0);
        admin.setIdUsuario(_repoUsuarios.getCantidadRegistros()+1);
        admin.setNombreUsuario("admin");
        admin.setPassword("1234");
        admin.setRol(1);

        _repoUsuarios.guardar(admin);

    }


}


void UsuariosManager::altaUsuario()
{
    Usuarios usuario;
    char nombre[20],pass1[15],pass2[15];
    int rol;
    bool valido = true,
         repetir =false,
         ingreso = true;

    do
    {
        ingreso = true;
        cout << "INGRESE NOMBRE DE USUARIO: " ;
        cin.getline(nombre,20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            valido = false;
            ingreso = false;
        }




        if (cancelacionUsuario(nombre))
        {
            return;
        }

        if( ingreso && validacionCaracteres(nombre,20) && !_repoUsuarios.buscarCoincidenciaNombreUsuario(nombre))
        {
            valido = true;

        }
        else
        {
            cout<< "USUARIO INCORRECTO O EXISTENTE" << endl;
            valido = false;
        }
    }
    while (!valido);

    do
    {
        cout << "INGRESE CONTRASEÑA: ";
        cin.getline(pass1,15);

        if(cancelacionUsuario(pass1))
        {
            return;
        }
        repetir = validacionCaracteres(pass1,15);


        if (repetir)
        {
            cout << "REPITA LA CONTRASEÑA: ";
            cin.getline(pass2,15);

            if(cancelacionUsuario(pass2))
            {
                return;
            }
            if (validacionCaracteres(pass2,15)&& strcmp (pass1,pass2)==0)
            {
                valido = true;
            }
            else
            {
                valido = false;
                cout << "LAS CONTRASEÑAS NO COINCIDEN..." << endl;
            }
        }
    }
    while (!valido);

    do
    {
        cout << "ELIJA UN ROL: " << endl;
        cout << "              1. ADMINISTRADOR." << endl;
        cout << "              2. RECEPCIONISTA." << endl;
        cout << "              3. MEDICO." << endl;
        cin >> rol;

        switch(rol)
        {
        case 1:
            valido = true;
            break;
        case 2:
            valido = true;
            break;
        case 3:
            valido = true;
            break;
        default:
            cout << "OPCION INCORRECTA.." << endl;
            valido = false;
            break;
        }
    }
    while (!valido);

    usuario.setNombreUsuario(nombre);
    usuario.setPassword(pass1);
    usuario.setRol(rol);
    usuario.setEliminado(false);
    usuario.setIdUsuario(_repoUsuarios.getCantidadRegistros()+1);


    if(_repoUsuarios.guardar(usuario))
    {
        cout << "USUARIO CREADO CORRECTAMENTE..." << endl;
    }
    else
    {
        cout << "ERROR EN LA CREACION DEL USUARIO..." << endl;
    }
}

void UsuariosManager::bajaUsuario()
{
    Usuarios usuario;
    char nombre[20];
    int pos, opcion;

    bool valido = true;

    do
    {

        cout << "INGRESE NOMBRE DE USUARIO: " ;
        cin.getline(nombre,20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            valido = false;
        }

        if (cancelacionUsuario(nombre))
        {
            return;
        }

        if(_repoUsuarios.buscarCoincidenciaNombreUsuario(nombre))
        {
            pos = _repoUsuarios.buscarPorNombreUsuario(nombre);
            usuario = _repoUsuarios.leer(pos);

            cout << "DESEA DAR DE BAJA EL USUAIO? 1.SI/2.NO/ 0.CANCELAR" << endl;
            cin >> opcion;

            switch(opcion)
            {
            case 1:
                usuario.setEliminado(true);
                if (_repoUsuarios.modificar(usuario,pos))
                {
                    cout << "USUARIO ELIMINADO.." << endl;
                    valido = true;

                }
                else
                {
                    cout << "ERROR, ELIMINACION NO COMPLETADA... " << endl;
                    valido = true;
                }

                break;
            case 2:
                valido =false;
                break;
            case 0:
                return;
            default:
                cout << "OPCION INCORRECTA..." << endl;
                break;

            }


        }
        else
        {
            cout<< "USUARIO INCORRECTO O EXISTENTE" << endl;
            valido = false;
        }
    }
    while (!valido);


}

void UsuariosManager::listarUsuarios()
{
    Usuarios u;
    int cantidadRegistros;

    cantidadRegistros = _repoUsuarios.getCantidadRegistros();
    cout << "+-----------------USUARIOS-----------------+" << endl;
    for (int i=0; i<cantidadRegistros; i++)
    {
        u = _repoUsuarios.leer(i);
        cout << " NOMBRE USUARIO: "<< u.getNombreUsuario()<< endl;
        cout << " ROL: " << u.getRol() << endl;

    }
}

Usuarios UsuariosManager::login()
{
    Usuarios u;
    char username[20], pass [15];
    int pos,
        contPass = 0;
    bool valido, ingreso;
    do
    {
        system ("cls");
        valido = true;
        ingreso = true;
        cout <<  "+-----------------LOGIN-----------------+" << endl;
        cout <<  " USUARIO: ";
        cin.getline(username,20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
        }
        if ( ingreso &&_repoUsuarios.buscarCoincidenciaNombreUsuario(username))
        {
            pos = _repoUsuarios.buscarPorNombreUsuario(username);
            u =_repoUsuarios.leer(pos);
            if (!u.getEliminado())
            {
                valido = true;

            }
            else
            {
                cout << "USUARIO INVALIDO.." << endl;
                system("pause");
                valido = false;
            }

        }
        else
        {
            cout << "USUARIO INVALIDO.." << endl;
            system("pause");
            valido = false;
        }
    }
    while (!valido);

    do
    {

        valido = true;
        ingreso = true;
        cout << " CONTRASEÑA: ";
        cin.getline(pass,15);
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
        }

        if (ingreso && strcmp(pass,u.getPassword())==0)
        {
            cout << "Bienvenido " << u.getRol() << endl;
            system("pause");
            valido= true;
        }
        else
        {
            contPass ++;
            if (contPass <3)
            {

                cout << " CONTRASEÑA INCORRECTA, VUELVA A INTENTARLO..." << endl;
                system("pause");

                valido = false;
            }
            else
            {
                cout << " DEMASIADOS INTENTOS FALLIDOS..." << endl;
                system("pause");
                return u;
            }
        }
    }
    while (!valido);

    return u;
}

int UsuariosManager::numeroRol (const char* rol)
{

    if(strcmp(rol,"ADMINISTRADOR")==0)
    {
        return 1;
    }
    else if(strcmp(rol,"MEDICO")==0)
    {
        return 2;
    }
    else if (strcmp(rol,"RECEPCIONISTA")==0)
    {
        return 3;
    }

    return -1;
}


