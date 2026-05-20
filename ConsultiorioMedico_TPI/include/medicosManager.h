#ifndef MANAGGERMEDICOS_H
#define MANAGGERMEDICOS_H
#include "MedicosArchivos.h"

class ManaggerMedicos
{
public:
    void Cargar();
    void ListarTodos();
    void ListarXId();
    void Listar(Medicos medicos);
    void HacerCopiaDeSeguridad();
    void RestaurarCopiaDeSeguridad();

private:
    MedicosArchivos _archivo;
    MedicosArchivos _archivoBkp = MedicosArchivos("Medicos.bkp");

    bool ExisteId(int id);
    int GenerarId();
};

#endif // MANAGGERMEDICOS_H
