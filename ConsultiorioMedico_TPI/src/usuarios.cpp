#include "usuarios.h"
#include <cstring>

Usuarios::Usuarios()
{
    strcpy (_nombreUsuario ,"N/A");
    strcpy(_password,"N/A");
    strcpy(_rol,"SIN ROL");
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
const char* Usuarios::getRol()
{
    return _rol;
}

bool Usuarios::getEliminado()
{
    return _eliminado;
}
