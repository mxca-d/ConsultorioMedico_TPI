#pragma once
#include "medicosArchivo.h"
#include "medicos.h"
#include "usuariosManager.h"

class MedicosManager
{
public:

    void altaMedico();
    void bajaMedico();
    void modificarMedico();
    void listarMedico(); //listarTodos();
    void listarXId();
    void mostrarMedico(Medicos medicos);
    void listarMedicoPorApellido(); //
    void listarMedicoEspecialidad(const char* especialidad);
    void listarMedicoPorEspecialidad();
    //void buscarMedicoPorId();//
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    void mostrarEspecialidadesExistentes();
    int recuperarIdMedico (const char* dni);


    //QUEDA PENDIENTE EL MODIFICAR-ESTILO PACIENTEMANAGER(CON LAS RESPECTIVAS VALIDACIONES)

private:
    MedicosArchivos _repoMedicos;
    MedicosArchivos _archivoBkp = MedicosArchivos("medicos.bkp");

    bool existeId(int id);
    int generarId();

    struct Carga
    {
        const char* texto;
        char* pDestino;
        int tamanio;
    };
};


