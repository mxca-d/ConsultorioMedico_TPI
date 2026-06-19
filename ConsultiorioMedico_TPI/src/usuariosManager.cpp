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
    char nombreUsuario[20],pass1[15],pass2[15], dni[9], nombre[30], apellido[30],
         domicilio[30],email[30],telefono[15];
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
        cin.getline(nombreUsuario,20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            valido = false;
            ingreso = false;
        }

        if (cancelacionUsuario(nombreUsuario))
        {
            return;
        }

        if( ingreso && validacionCaracteres(nombreUsuario) && !_repoUsuarios.buscarCoincidenciaNombreUsuario(nombreUsuario))
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

    do
        {
        ingreso = true;
        valido = true;

        cout << "INGRESE SU NOMBRE: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(nombre,30);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
            valido = false;
        }
        if(ingreso && validacionCaracteres(nombre)&& soloLetras(nombre,30))
        {
            valido=true;
        }
        else
        {
            cout << "INGRESO INVALIDO, RECUERDE QUE SOLO SE PERMITEN  LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {
        ingreso = true;
        valido = true;

        cout << "INGRESE SU APELLIDO: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(apellido,30);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
            valido = false;
        }
        if(ingreso && validacionCaracteres(apellido)&& soloLetras(apellido,30))
        {
            valido=true;
        }
        else
        {
            cout << "INGRESO INVALIDO, RECUERDE QUE SOLO SE PERMITEN LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {
        ingreso = true;
        valido = true;

        cout << "INGRESE UN DOMICILIO: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(domicilio,30);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
            valido = false;
        }
        if(ingreso && validacionCaracteres(domicilio)&& letrasYNumeros(domicilio,30))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO, RECUERDE QUE SOLO SE PERMITEN NUMEROS Y LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);

    do
    {
        ingreso = true;
        valido = true;

        cout << "INGRESE TELEFONO DE CONTACTO: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(telefono,15);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
            valido = false;
        }
        if(ingreso && validacionCaracteres(telefono)&& validacionSoloNumeros(telefono))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO, RECUERDE QUE SOLO SE PERMITEN NUMEROS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {
        ingreso = true;
        valido = true;

        cout << "INGRESE UN EMAIL: " ;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(email,30);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            ingreso = false;
            valido = false;
        }
        if(ingreso && validacionCaracteres(email))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO, RECUERDE QUE SOLO SE PERMITEN HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);

    usuario.setNombre(nombre);
    usuario.setApellido(apellido);
    usuario.setDomicilio(domicilio);
    usuario.setTelefono(telefono);
    usuario.setEmail(email);
    usuario.setNombreUsuario(nombreUsuario);
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
            cout << " USUARIO: "<< u.getNombreUsuario()<< endl;
            cout << " ROL: " << u.getRol() << endl;
            if (u.getEliminado())
            {
                cout << "ESTADO: ELIMINADO " << endl;

            }
            else
            {
                cout << "ESTADO: ACTIVO " << endl;
            }
            cout << "NOMBRE: " << u.getNombre() << endl;
            cout << "APELLIDO: " << u.getApellido() << endl;
            cout << "DOMICILIO: "<< u.getDomicilio() << endl;
            cout << "TELEFONO: " << u.getTelefono() << endl;
            cout << "Email: " << u.getEmail() <<endl;
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

void UsuariosManager::modificarUsuario(const char* dni)
{
    Usuarios u;
    int posUsuario, opcion;
    char nombreUsuario [20], pass1 [15], pass2 [15];
    bool valido,ingreso,comprobacion;

    posUsuario = _repoUsuarios.buscarPorDni(dni);
    if (posUsuario == -1)
    {
        cout << "ERROR EN DNI USUARIO.." << endl;
        system ("pause");
        return;
    }
    u = _repoUsuarios.leer(posUsuario);

    do
    {
        valido = true;
        ingreso= true;
        cout << "DNI USUARIO:  " << u.getDni() << endl;
        cout << endl;
        cout << "ELIJA UNA OPCION A MODIFICAR:" << endl;
        cout << "                   1. USUARIO " << endl;
        cout << "                   2. CONTRASEÑA " << endl;
        cout << "                   3. NOMBRE "  << endl;
        cout << "                   4. APELLIDO " << endl;
        cout << "                   5. DOMICILIO "<< endl;
        cout << "                   6. TELEFONO " << endl;
        cout << "                   7. Email " << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 2:
            do
            {
                comprobacion = false;
                cout << "CONTRASEÑA ACTUAL: " << u.getPassword() << endl;
                cout << "CONTRASEÑA NUEVA: ";

                cin.getline(pass1,15);
                cout << endl;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    valido = false;
                    ingreso = false;
                }
                if (cancelacionUsuario(pass1))
                {
                    cout << "CANCELACION POR EL USUARIO..." << endl;
                    system("pause");
                    return;
                }
                if (ingreso && validacionCaracteres(pass1))
                {
                    if (comprobacion == false)
                    {
                        cout << "REPITA LA CONTRASEÑA: " ;
                        cin.getline(pass2,15);
                        cout << endl;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            valido = false;
                            ingreso = false;
                        }
                        if (ingreso && strcmp(pass1,pass2)==0)
                        {
                            comprobacion = true;
                        }

                    }
                    if (comprobacion && ingreso)
                    {

                        u.setPassword(pass1);
                        if (_repoUsuarios.modificar(u,posUsuario))
                        {
                            cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;

                        }
                        else
                        {
                            cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                            comprobacion = false;
                        }
                    }
                }
                else
                {
                    cout << "INGRESO INVALIDO..." << endl;
                    cout << "recuerde que la contraseña debe tener maximo 15 caracteres y minimo 3..." << endl;
                    comprobacion= true;
                }

            }
            while (!comprobacion);
            break;
        case 3:
           /* cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 4:
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 5:
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 6:
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 7:
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            cin.getline(nombreUsuario,20);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                valido = false;
                ingreso = false;
            }

            if (ingreso && validacionCaracteres(nombreUsuario))
            {
                u.setNombreUsuario(nombreUsuario);
                if (_repoUsuarios.modificar(u,posUsuario))
                {
                    cout << "SE HAN GUARDADO LOS CAMBIOS CORRECTAMENTE..." << endl;
                    valido = true;
                }
                else
                {
                    cout << "ERROR AL GUARDAR LOS CAMBIOS, PORFAVOR REINTENTE..." << endl;
                    valido = false;
                }
            }
            else
            {
                cout << "INGRESO INVALIDO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;*/
        case 0:
            return;
        default:
            cout << "OPCION INCORRECTA... " << endl;
            valido = false;
            break;
        }

    }
    while(!valido);
}


