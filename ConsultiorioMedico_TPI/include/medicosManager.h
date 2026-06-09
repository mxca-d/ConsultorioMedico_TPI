#pragma once
#include "medicosArchivo.h"
#include "medicos.h"

class MedicosManager
{
public:

    void altaMedico();
    void bajaMedico();
    ///FALTA MODIFICARMEDICO
    void listarTodos();///CAMBIAMOS A LISTAR TODOS
    void mostrarMedico(Medicos medicos);
    void listarPorId();///CAMBIO X = POR
    void listarMedicoPorApellido(); ///SERIA MEDICOS EN PLURAL?
    void listarMedicoEspecialidad(const char* especialidad);///SERIA MEDICOS EN PLURAL?
    void listarMedicoPorEspecialidad();///SERIA MEDICOS EN PLURAL?
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    void mostrarEspecialidades();///VAMOS A USAR EL MOSTRAR ESPECIALIDADES DE UTILS?



private:
    MedicosArchivos _repoMedicos;
    MedicosArchivos _archivoBkp = MedicosArchivos("medicos.bkp");

    bool existeId(int id);///AGREGAMOS ESTE METODO
    int generarId();///AGREGAMOS ESTE METODO

    struct Carga///AGREGAMOS ESTE STRUCT
    {
        const char* texto;
        char* pDestino;
        int tamanio;
    };
};


