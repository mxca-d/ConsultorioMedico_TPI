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
        valido = false;
        cout << "INGRESE NOMBRE DE USUARIO: " ;
        valido = cargarCadena(nombreUsuario,20);

            if (cancelacionUsuario(nombreUsuario))
        {
            cout << "CANCELADO..."<< endl;
            return;
        }

        if(valido  && !_repoUsuarios.buscarCoincidenciaNombreUsuario(nombreUsuario))
        {
            valido = true;
        }
        else
        {
            cout<< "USUARIO INCORRECTO O EXISTENTE" << endl;
            valido=false;
        }
    }
    while (!valido);

    do
    {
        valido = false;
        repetir= false;
        cout << "INGRESE CONTRASEÑA: ";
        repetir = cargarCadena(pass1,15);

        if(cancelacionUsuario(pass1))
        {
            cout << "CANCELADO..."<< endl;
            return;
        }

        if (repetir)
        {
            cout << "REPITA LA CONTRASEÑA: ";
            valido = cargarCadena(pass2,15);

            if(cancelacionUsuario(pass2))
            {
                cout << "CANCELADO..."<< endl;
                return;
            }
            if (valido && strcmp (pass1,pass2)==0)
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
        valido = false;
        cout << "INGRESE DNI DEL USUARIO: " ;
        valido = cargarCadena(dni,9);

        if (cancelacionUsuario(dni))
        {
            cout << "CANCELADO..."<< endl;
            return;
        }

        if (valido &&!dniValido(dni))
        {
            cout << "SOLO SE PERMITEN NUMEROS EN ESTE INGRESO..." << endl;

            valido = false;

        }
        else
        {
            valido = true;
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
        valido = true;

        cout << "INGRESE SU NOMBRE: " ;
        valido = cargarCadena(nombre,30);
        if(valido && soloLetras(nombre))
        {
            valido=true;
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO, RECUERDE QUE SOLO SE PERMITEN  LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {
        valido = false;

        cout << "INGRESE SU APELLIDO: " ;
        valido = cargarCadena(apellido,30);
        if(ingreso && soloLetras(apellido))
        {
            valido=true;
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO, RECUERDE QUE SOLO SE PERMITEN LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {

        valido = false;

        cout << "INGRESE UN DOMICILIO: " ;
        valido = cargarCadena(domicilio,30);
        if(ingreso && letrasYNumeros(domicilio))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO, RECUERDE QUE SOLO SE PERMITEN NUMEROS Y LETRAS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);

    do
    {
        valido = false;

        cout << "INGRESE TELEFONO DE CONTACTO: " ;
        valido = cargarCadena(telefono,15);
        if(ingreso && validacionSoloNumeros(telefono))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO, RECUERDE QUE SOLO SE PERMITEN NUMEROS HASTA 30 CARACTERES..." << endl;
            valido = false;
        }
    }
    while(!valido);
    do
    {

        valido = false;

        cout << "INGRESE UN EMAIL: " ;
        if(cargarCadena(email,30))
        {
            valido = true;
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO, RECUERDE QUE SOLO SE PERMITEN HASTA 30 CARACTERES..." << endl;
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
    usuario.setDni(dni);



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

    bool valido = false;


        do
        {

            cout << "INGRESE NOMBRE DE USUARIO: " ;
            valido = cargarCadena(nombre,20);

            if (cancelacionUsuario(nombre))
            {
                cout << "CANCELADO..."<< endl;
                return;
            }

            if(valido && _repoUsuarios.buscarCoincidenciaNombreUsuario(nombre))
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

void UsuariosManager::listarUsuarios()
{
    Usuarios u;
    int cantidadRegistros;

    cantidadRegistros = _repoUsuarios.getCantidadRegistros();
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
            cout << "DNI: " << u.getDni() <<endl;
            cout << "TELEFONO: " << u.getTelefono() << endl;
            cout << "EMAIL: " << u.getEmail() <<endl;
            cout << "+-----------------------------------------------------+" << endl;
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
            usuarioValido = false;

            cout <<  "+-----------------LOGIN-----------------+" << endl;
            cout <<  " USUARIO: ";
            usuarioValido = cargarCadena (username,20);
            if ( usuarioValido &&_repoUsuarios.buscarCoincidenciaNombreUsuario(username))
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
            ingreso = false;
            cout << " CONTRASEÑA: ";
            ingreso = cargarCadena(pass,15);

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
    char nombreUsuario [20], pass1 [15], pass2 [15],telefono[15],
         email[30],domicilio[30];
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
        cout << "                   3. DOMICILIO "<< endl;
        cout << "                   4. TELEFONO " << endl;
        cout << "                   5. EMAIL " << endl;
        cout << "                   6. ESTADO " << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            valido = false;
            cout << "NOMBRE DE USUARIO ACTUAL: " << u.getNombreUsuario()<< endl;
            cout << "USUARIO NUEVO: ";

            valido = cargarCadena(nombreUsuario,20);
            if (cancelacionUsuario(nombreUsuario))
            {
                cout << "CANCELADO..."<< endl;
                return;
            }

            if (valido)
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
                cout << "recuerde que nombre de usuario debe tener maximo 20 ..." << endl;
                valido= false;
            }
            break;
        case 2:
            do
            {
                valido = false;
                comprobacion = false;
                cout << "CONTRASEÑA ACTUAL: " << u.getPassword() << endl;
                cout << "CONTRASEÑA NUEVA: ";

                valido = cargarCadena(pass1,15);
                cout << endl;

                if (cancelacionUsuario(pass1))
                {
                    cout << "CANCELACION POR EL USUARIO..." << endl;
                    system("pause");
                    return;
                }
                if (valido )
                {
                    if (comprobacion == false)
                    {
                        cout << "REPITA LA CONTRASEÑA: " ;
                        valido = cargarCadena(pass2,15);
                        cout << endl;
                        if (valido && strcmp(pass1,pass2)==0)
                        {
                            comprobacion = true;
                        }
                        else
                        {
                            cout << "CONTRASEÑA NO COINCIDEN..." << endl;
                            comprobacion = false;
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
                    cout << "recuerde que la contraseña debe tener maximo 15 caracteres ..." << endl;
                    comprobacion= true;
                }

            }
            while (!comprobacion);
            break;
        case 3:

            valido = false;
            cout << "DOMICILIO ACTUAL: " << u.getDomicilio()<< endl;
            cout << "DOMICILIO NUEVO: ";

            valido = cargarCadena(domicilio,30);

            if (valido && soloLetras(domicilio))
            {
                u.setDomicilio(domicilio);
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
                cout << "INGRESO INVALIDO O NULO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 4:
            cout << "TELEFONO: " << u.getTelefono()<< endl;
            cout << "TELEFONO NUEVO: ";

            valido=cargarCadena(telefono,15);

            if (valido && soloNumeros(telefono))
            {
                u.setTelefono(telefono);
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
                cout << "INGRESO INVALIDO O NULO..." << endl;
                cout << "recuerde que nombre de usuario debe tener maximo 20 caracteres y minimo 3..." << endl;
                valido= false;
            }
            break;
        case 5:
            cout << "EMAIL ACTUAL: " << u.getEmail()<< endl;
            cout << "EMAIL NUEVO: ";

            valido= cargarCadena(email,30);

            if (valido )
            {
                u.setEmail(email);
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
            {
            int seleccion;
            cout << "El estado actual es ";
            if(u.getEliminado()){
                cout << "Inactivo." << endl;
                do
                {
                    valido=true;
                    cout <<"Desea activarlo nuevamente? 1.SI/2.NO" << endl;
                    if (cin.peek() == '\n')
                    {
                        cin.ignore();
                    }
                    cin>>seleccion;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000,'\n');
                        valido = false;
                    }

                }
                while(seleccion!=1 && seleccion!=2 && !valido);

                if(seleccion==2)
                {
                    cout << "OPERACION CANCELADA..."<< endl;
                    system("pause");
                    return;
                }else{
                    u.setEliminado(false);
                }

            }else{
                cout << "Activo. No se aceptan modificaciones." << endl;
            }

            system("pause");

            break;
            }

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


