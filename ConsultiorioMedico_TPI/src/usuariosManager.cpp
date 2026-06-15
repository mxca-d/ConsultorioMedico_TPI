#include <iostream>
#include <cstring>
#include <cctype>
#include "usuariosManager.h"
#include "utils.h"

using namespace std;


void UsuariosManager::crearAdminSiNoExiste()
{



    if(_repoUsuarios.getCantidadRegistros()==0)
    {

        Usuarios admin;

        admin.setEliminado(false);
        admin.setDni("0");
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
    char nombre[20],pass1[15],pass2[15], dni[9];
    int rol;
    bool valido = true,
         repetir =false,
         ingreso = true;

    do
    {
        ingreso = true;
        cout << "INGRESE NOMBRE DE USUARIO: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
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
        ingreso = true;
        cout << "INGRESE DNI DEL USUARIO: " ;
        cin.getline(dni,9);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            valido = false;
            ingreso = false;
        }


        if (cancelacionUsuario(dni))
        {
            return;
        }

        if (!validacionSoloNumeros(dni))
        {
            cout << "SOLO SE PERMITEN NUMEROS EN ESTE INGRESO..." << endl;
            ingreso = false;
            valido = false;

        }

        if( ingreso && validacionCaracteres(dni, 9))
        {
            valido = true;

        }
        else if (ingreso)
        {
            cout<< "USUARIO INCORRECTO.... "<< endl;
            valido = false;
        }
    }
    while (!valido);


    do
    {
        cout << "ELIJA UN ROL: " << endl;
        cout << "              1. ADMINISTRADOR." << endl;
        cout << "              2. MEDICO." << endl;
        cout << "              3. RECEPCIONISTA." << endl;
        cin >> rol;

        switch(rol)
        {
        case 1:
            if (_repoUsuarios.buscarCoincidenciaDni(dni))
            {
                int pos;
                Usuarios usu;
                pos=_repoUsuarios.buscarPorDni(dni);
                usu= _repoUsuarios.leer(pos);

                if (usu.getEliminado() == false && strcmp(usu.getRol(),"MEDICO")==0)
                {
                    cout << "YA EXISTE UN USUARIO ACTIVO PARA EL ROL QUE ELIJIO..." << endl;
                    cout << "CARGA CANCELADA...." << endl;
                    return;
                }
            }
            valido = true;
            break;
        case 2:
            if (_repoMedicos.buscarCoincidenciaDni(dni))
            {
                cout << "DNI YA POSEE USUARIO ACTIVO...." << endl;
                valido=false;
                return;
            }
            else
            {

                cout << "DEBE REALIZAR EL ALTA DEL MEDICO PARA GENERAR USUARIO. GRACIAS..." << endl;
                MedicosManager managerMedico;
                managerMedico.altaMedico();
                return;

            }

            valido = true;
            break;
        case 3:
            if (_repoUsuarios.buscarCoincidenciaDni(dni))
            {
                int pos;
                Usuarios usu;
                pos=_repoUsuarios.buscarPorDni(dni);
                usu= _repoUsuarios.leer(pos);

                if (usu.getEliminado() == false && strcmp(usu.getRol(),"RECEPCIONISTA")==0)
                {
                    cout << "YA EXISTE UN USUARIO ACTIVO PARA EL ROL QUE ELIJIO..." << endl;
                    cout << "CARGA CANCELADA...." << endl;
                    return;
                }
            }
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

    if (_repoUsuarios.existenRegistros())
    {


        do
        {

            cout << "INGRESE NOMBRE DE USUARIO: " ;
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
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

            if(_repoUsuarios.buscarCoincidenciaNombreUsuario(nombre) && validacionCaracteres(nombre))
            {
                pos = _repoUsuarios.buscarPorNombreUsuario(nombre);
                usuario = _repoUsuarios.leer(pos);

                cout << "DESEA DAR DE BAJA EL USUARIO? 1.SI/2.NO/ 0.CANCELAR" << endl;
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
    else
    {
        cout << "NO EXISTEN REGISTROS....." << endl;
        return;
    }


}

void UsuariosManager::listarUsuarios()
{
    Usuarios u;
    int cantidadRegistros;

    cantidadRegistros = _repoUsuarios.getCantidadRegistros();
    if (_repoUsuarios.existenRegistros() ==false)
    {
        cout << "NO EXISTE REGISTROS DE USUARIOS....." << endl;
        return;
    }
    else
    {

        cout << "+-----------------USUARIOS-----------------+" << endl;
        for (int i=0; i<cantidadRegistros; i++)
        {
            u = _repoUsuarios.leer(i);
            cout << " ID USUARIO: "<< u.getIdUsuario() << endl;
            cout << " NOMBRE USUARIO: "<< u.getNombreUsuario()<< endl;
            cout << " ROL: " << u.getRol() << endl;
            if (u.getEliminado())
            {
                cout << "ESTADO: ELIMINADO " << endl;

            }
            else
            {
                cout << "ESTADO: ACTIVO " << endl;
            }
            cout << "+-----------------------------------------------------+" << endl;
        }
    }
}

Usuarios UsuariosManager::login()
{
    Usuarios u;
    char username[20], pass [15];
    int pos,
        contPass = 0;
    bool usuarioValido, ingreso, bandPass, intentos;
    do
    {
        contPass = 0;
        do
        {
            system ("cls");
            usuarioValido = true;
            ingreso = true;

            cout <<  "+-----------------LOGIN-----------------+" << endl;
            cout <<  " USUARIO: ";
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
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
                    usuarioValido = true;

                }
                else
                {
                    cout << "USUARIO INVALIDO.." << endl;
                    system("pause");
                    usuarioValido = false;
                }

            }
            else
            {
                cout << "USUARIO INVALIDO.." << endl;
                system("pause");
                usuarioValido = false;
            }
        }
        while (!usuarioValido);

        do
        {

            bandPass = true;
            intentos = true;
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
                bandPass = true;
            }
            else
            {
                contPass ++;
                if (contPass <3)
                {

                    cout << " CONTRASEÑA INCORRECTA, VUELVA A INTENTARLO..." << endl;
                    system("pause");

                    bandPass = false;
                }
                else
                {
                    cout << " DEMASIADOS INTENTOS FALLIDOS..." << endl;
                    system("pause");
                    bandPass=true;
                    intentos = false;

                }
            }
        }
        while (!bandPass);
    }
    while (!intentos);

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


