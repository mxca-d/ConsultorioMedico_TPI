#include "usuariosArchivo.h"
#include <cstdio>
#include <cstring>


UsuariosArchivo::UsuariosArchivo()
{
    strcpy(_nombreArchivo,"usuarios.dat");
}

UsuariosArchivo:: UsuariosArchivo(const char* nombre)
{
    strcpy(_nombreArchivo,nombre);
}

int UsuariosArchivo::getCantidadRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Usuarios);
}

int UsuariosArchivo::getCantidadActivos(){
    Usuarios reg;
    int cantidad= getCantidadRegistros();
    int contadorActivos=0;

    for(int i=0;i<cantidad;i++){
        if(reg.getEliminado()!=true){
            contadorActivos++;
        }

    }
    return contadorActivos;

}

bool UsuariosArchivo::guardar(Usuarios reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Usuarios), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool UsuariosArchivo::modificar(Usuarios reg, int posicionAReemplazar)
{
    FILE *p = fopen(_nombreArchivo, "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Usuarios), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Usuarios), 1, p);
    fclose(p);
    return pudoEscribir;
}




Usuarios UsuariosArchivo::leer(int pos)
{
    Usuarios aux;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, pos * sizeof(Usuarios), SEEK_SET);
    fread(&aux, sizeof(Usuarios), 1, p);
    fclose(p);
    return aux;
}




bool UsuariosArchivo::buscarCoincidenciaNombreUsuario (const char* usuario)
{
    Usuarios reg;

    int cantidad= getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getNombreUsuario(),usuario)==0)
        {
            return true;
        }

    }

    return false;

}

bool UsuariosArchivo::buscarCoincidenciaDni (const char* dni)
{
    Usuarios reg;

    int cantidad= getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getDni(),dni)==0)
        {
            return true;
        }

    }

    return false;

}

int UsuariosArchivo::buscarPorNombreUsuario(const char* usuario)
{
    Usuarios reg;

    int cantidad= getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getNombreUsuario(),usuario)==0)
        {
            return i;
        }

    }

    return -1;

}


int UsuariosArchivo::buscarPorDni(const char* dni)
{
    Usuarios reg;

    int cantidad= getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getDni(),dni)==0)
        {
            return i;
        }

    }

    return -1;

}


/*bool UsuariosArchivo::buscarCoincidenciaPassword (const char* passw){
    Usuarios reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getPassword(),passw)==0){
            return true;
        }

    }

    return false;

}
*/

void UsuariosArchivo::vaciar()
{
    FILE *p = fopen(_nombreArchivo, "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);
}

