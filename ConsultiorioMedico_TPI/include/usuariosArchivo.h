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
    int getCantidadActivos();
    bool existenRegistros();
    Usuarios leer(int pos);
    bool buscarCoincidenciaNombreUsuario(const char* usuario);
    bool buscarCoincidenciaDni(const char* dni);
    //bool buscarCoincidenciaPassword (const char* passw);
    int buscarPorNombreUsuario(const char* usuario);
    int buscarPorDni(const char* dni);

    void vaciar();

protected:

private:
    char _nombreArchivo[30];
};

