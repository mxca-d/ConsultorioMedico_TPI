#pragma once
#include "usuarios.h"
class Menu
{
public:
    Menu();
    virtual void run();
    virtual void mostrarOpciones() = 0;
    virtual int seleccionarOpcion() ;
    virtual void ejecutarOpcion(int opcion ) =0 ;



protected:
    void setCantidadOpciones(int cantidad);
    int getCantidadOpciones();

    char _dniUsuario[10];

private:
    int _cantidadOpciones;
};
