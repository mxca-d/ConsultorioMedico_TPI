#pragma once
#include "Medicos.h"

class MedicosArchivos
{
public:

    MedicosArchivos();
    MedicosArchivos(const char* nombre);

    bool guardar(Medicos reg);
    int getCantidadRegistros();
    Medicos leer(int pos);
    bool modificar(Medicos reg, int pos);
    int buscarPorId(int id);
    bool buscarCoincidenciaId(int id);

    bool guardar(Medicos *vec, int cantidadRegistrosAEscribir);
    void leer(Medicos *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];
};


