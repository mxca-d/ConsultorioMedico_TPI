#pragma once
#include "paciente.h"

class PacienteArchivo{


public:
    PacienteArchivo();
    PacienteArchivo(const char* nombre);

    bool guardar(Paciente p);
    int getCantidadRegistros();
    int getCantidadActivos();
    Paciente leer(int pos);
    bool modificar(Paciente reg, int pos);
    int buscarPorDni(const char* dni);
    bool buscarCoincidenciaId(int id);
    bool buscarCoincidenciaDni(const char* dni);

    bool guardar(Paciente*vec, int cantidadRegistrosAEscribir);
    void leer(Paciente *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];

};



