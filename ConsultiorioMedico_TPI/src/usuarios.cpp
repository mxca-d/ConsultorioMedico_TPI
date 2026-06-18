#include "usuarios.h"
#include <cstring>

Usuarios::Usuarios()
{
    strcpy (_nombreUsuario,"N/A");
    strcpy(_password,"N/A");
    strcpy(_rol,"SIN ROL");
    strcpy(_nombre, "N/A");
    strcpy(_apellido, "N/A");
    strcpy (_domicilio, "N/A");
    strcpy (_email, "N/A");
    strcpy (_telefono, "N/A");
    _eliminado = false;
    _idUsuario=0;
    strcpy(_dni,"N/A");
}

void Usuarios::setNombreUsuario(const char* usuario)
{
    strcpy(_nombreUsuario, usuario);
}
void Usuarios::setPassword (const char* password)
{
    strcpy(_password,password);
}


void Usuarios::setNombre(const char* nombre)
{
    strcpy(_nombre,nombre);

}

void Usuarios::setApellido(const char* apellido)
{
    strcpy(_apellido,apellido);
}

void Usuarios::setEmail(const char* email)
{
    strcpy(_email,email);

}

void Usuarios::setDomicilio(const char* domicilio)
{
    strcpy(_domicilio,domicilio);

}

void Usuarios::setTelefono(const char* telefono)
{
    strcpy(_telefono,telefono);

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
        strcpy(_rol,"MEDICO");
        break;
    case 3:
        strcpy(_rol,"RECEPCIONISTA");
        break;
    default:
        break;
    }
}

void Usuarios::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}




void Usuarios::setIdUsuario(int id)
{

    _idUsuario=id;
}





int Usuarios::getIdUsuario()
{
    return _idUsuario;

}


const char* Usuarios::getNombreUsuario()
{
    return _nombreUsuario;
}
const char* Usuarios::getPassword ()
{
    return _password;
}

const char* Usuarios::getNombre()
{
    return _nombre;
}
const char* Usuarios::getApellido()
{
    return _apellido;
}
const char* Usuarios::getDomicilio()
{
    return _domicilio;
}

const char* Usuarios::getTelefono()
{
    return _telefono;
}
const char* Usuarios::getEmail()
{
    return _email;
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
