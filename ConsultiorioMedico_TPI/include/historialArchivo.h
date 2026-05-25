#pragma once
#include "Historial.h"

class historialArchivo
{
   public:

    historialArchivo();
    historialArchivo(const char* nombre);

    bool guardar(Historial reg);
    int getCantidadRegistros();
    Historial leer(int pos);
    bool modificar(Historial reg, int pos);
    int buscarPorId(int id);

    bool guardar(Historial *vec, int cantidadRegistrosAEscribir);
    void leer(Historial *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];
};





