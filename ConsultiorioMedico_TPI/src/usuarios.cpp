#include "usuarios.h"
#include <cstring>

Usuarios::Usuarios()
{
    strcpy (_nombreUsuario,"N/A");
    strcpy(_password,"N/A");
    strcpy(_rol,"SIN ROL");
    strcpy(_dni,"N/A");
    _eliminado = false;
}

void Usuarios::setNombreUsuario(const char* usuario)
{
    strcpy(_nombreUsuario, usuario);
}
void Usuarios::setPassword (const char* password)
{
    strcpy(_password,password);
}
void Usuarios::setDni (const char* dni)
{
    strcpy(_dni,dni);
}
void Usuarios::setRol (int rol)
{
    switch(rol)
    {
    case 1:
        strcpy(_rol,"ADMINISTRADOR");
        break;
    case 2:
        strcpy(_rol,"RECEPCIONISTA");
        break;
    case 3:
        strcpy(_rol,"MEDICO");
        break;
    default:
        break;
    }
}

void Usuarios::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

const char* Usuarios::getNombreUsuario()
{
    return _nombreUsuario;
}
const char* Usuarios::getPassword ()
{
    return _password;
}
const char* Usuarios::getDni()
{
    return _dni;
}
const char* Usuarios::getRol()
{
    return _rol;
}

int Usuarios::getNumeroRol ()
{

    if(strcmp(_rol,"ADMINISTRADOR")==0)
    {
        return 1;
    }
    else if(strcmp(_rol,"MEDICO")==0)
    {
        return 2;
    }
    else if (strcmp(_rol,"RECEPCIONISTA")==0)
    {
        return 3;
    }

    return -1;
}


bool Usuarios::getEliminado()
{
    return _eliminado;
}
