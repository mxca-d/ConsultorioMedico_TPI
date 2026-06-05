#pragma once
#include "paciente.h"

class PacienteArchivo{


public:
    PacienteArchivo();
    PacienteArchivo(const char* nombre);

    bool guardar(Paciente p);
    int getCantidadRegistros();
    Paciente leer(int pos);
    bool modificar(Paciente reg, int pos);
    int buscarPorId(int id);
    bool buscarCoincidenciaId(int id);
    bool buscarPorDni(int dni);

    bool guardar(Paciente*vec, int cantidadRegistrosAEscribir);
    void leer(Paciente *vec, int cantidadRegistrosALeer);
     void vaciar();

private:
    char _nombreArchivo[30];

};



