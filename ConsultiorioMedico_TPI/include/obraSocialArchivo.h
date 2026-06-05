#pragma once
#include "obrasSociales.h"

class ObraSocialArchivo
{


public:
    ObraSocialArchivo();
    ObraSocialArchivo(const char* nombre);

    bool guardar(ObraSociales p);
    int getCantidadRegistros();
    ObraSociales leer(int pos);
    bool modificar(ObraSociales reg, int pos);
    int buscarPorId(int id);


    bool guardar(ObraSociales*vec, int cantidadRegistrosAEscribir);
    void leer(ObraSociales *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];

};

