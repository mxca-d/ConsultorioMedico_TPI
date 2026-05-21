#pragma once
#include "Medicos.h"
#include <string>

class MedicosArchivos
{
public:

    MedicosArchivos();
    MedicosArchivos(std::string ruta);



    bool guardar(Medicos reg);
    int getCantidadRegistros();
    Medicos leer(int pos);
    bool modificar(Medicos reg, int pos);
    int buscarPorId(int id);



    bool guardar(Medicos *vec, int cantidadRegistrosAEscribir);
    void leer(Medicos *vec, int cantidadRegistrosALeer);
    void vaciar();

private:
    std::string _ruta;
};


