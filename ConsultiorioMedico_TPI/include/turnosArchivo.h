#pragma once
#include "turno.h"

class TurnoArchivo
{


public:
    TurnoArchivo();
    TurnoArchivo(const char* nombre);

    bool guardar(Turno reg);
    int getCantidadRegistros();
    Turno leer(int pos);
    bool modificar(Turno reg, int pos);
    int buscarPorId(int id);

    bool guardar(Turno*vec, int cantidadRegistrosAEscribir);
    void leer(Turno *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];

};


