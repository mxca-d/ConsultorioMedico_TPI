#pragma once
#include "usuarios.h"


class UsuariosArchivo
{
public:
    UsuariosArchivo();
    UsuariosArchivo(const char* nombre);

    bool guardar(Usuarios reg);
    bool modificar(Usuarios reg, int posicionAReemplazar);
    int getCantidadRegistros();
    Usuarios leer(int pos);
    bool buscarCoincidenciaNombreUsuario(const char* usuario);
    //bool buscarCoincidenciaPassword (const char* passw);
    int buscarPorNombreUsuario(const char* usuario);


    void vaciar();

protected:

private:
    char _nombreArchivo[30];
};

