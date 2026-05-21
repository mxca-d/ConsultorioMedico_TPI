#pragma once
#include "medicosArchivo.h"
#include "medicos.h"

class MedicosManager
{
public:

    void altaMedico();
    void bajaMedico();
    void listarTodos();
    void listarXId();
    void mostrarMedico(Medicos medicos);
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


    //QUEDA PENDIENTE EL MODIFICAR-ESTILO PACIENTEMANAGER(CON LAS RESPECTIVAS VALIDACIONES)

private:
    MedicosArchivos _repoMedicos;
    MedicosArchivos _archivoBkp = MedicosArchivos("medicos.bkp");

    bool existeId(int id);
    int generarId();
};


