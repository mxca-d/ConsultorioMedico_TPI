#pragma once
#include "Historial.h"

class historialArchivo
{
    public:
        historialArchivo();
        historialArchivo( const char* nombreArchivo);

        bool guardar(Historial reg);
        Historial leer(int pos);
        int getCantidadRegistros();
        bool modificar(Historial reg, int pos);

    private:
        char _nombreArchivo[40];
};





