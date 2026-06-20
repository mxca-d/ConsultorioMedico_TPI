#pragma once
#include "Medicos.h"

class MedicosArchivos
{
public:

    MedicosArchivos();
    MedicosArchivos(const char* nombre);

    bool guardar(Medicos reg);
    int getCantidadRegistros();
    int getCantidadActivos();
    Medicos leer(int pos);
    bool modificar(Medicos reg, int pos);
    int buscarPorId(int id);
    int buscarPorDni(const char* dni);
    bool buscarCoincidenciaId(int id);
    bool buscarCoincidenciaDni(const char* dni);
    bool buscarCoincidenciaEspecialidad(const char* especialidad);

    bool guardar(Medicos *vec, int cantidadRegistrosAEscribir);
    void leer(Medicos *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];
};


