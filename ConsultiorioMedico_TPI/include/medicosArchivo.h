#ifndef MEDICOSARCHIVOS_H
#define MEDICOSARCHIVOS_H

#include "Medicos.h"
#include <string>

class MedicosArchivos
{
public:
    int getCantidadRegistros();
    bool guardar(Medicos reg);
    bool guardar(Medicos reg, int posicionAReemplazar);
    bool guardar(Medicos *vec, int cantidadRegistrosAEscribir);

    Medicos leer(int nroRegistro);
    void leer(Medicos *vec, int cantidadRegistrosALeer);
    int buscar(int ID);
    void vaciar();

    MedicosArchivos();
    MedicosArchivos(std::string ruta);
private:
    std::string _ruta;
};

#endif // MEDICOSARCHIVOS_H
