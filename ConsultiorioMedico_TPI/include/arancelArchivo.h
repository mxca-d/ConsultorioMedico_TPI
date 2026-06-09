#pragma once
#include "arancel.h"


class ArancelArchivo{

public:

    ArancelArchivo();
    ArancelArchivo(const char* nombre);

    bool guardar(Arancel p);
    int getCantidadRegistros();
    Arancel leer(int pos);
    bool modificar(Arancel reg, int pos);
    int buscarPorId(int id);
    int buscarPorIdObraSocial(int id);///AGREGAMOS METODO

    bool guardar(Arancel*vec, int cantidadRegistrosAEscribir);
    void leer(Arancel *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    char _nombreArchivo[30];

};


