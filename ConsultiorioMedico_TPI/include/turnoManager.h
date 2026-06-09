#pragma once
#include "turno.h"
#include "turnosArchivo.h"
#include "pacienteArchivo.h"
#include "medicosArchivo.h"
#include "historialArchivo.h"
#include"arancelArchivo.h"
#include "medicosManager.h"
#include "historialManager.h"

class TurnoManager
{

public:
    void altaTurno();
    void cancelarTurno();
    void atenderTurno();
    void modificarTurno();
    void listarTurnos();
    void mostrarTurno(Turno reg);
    void listarPorPaciente();
    void listarPorMedico();
    void listarPorEstado();
    void listarPorFecha();
    void listarPorRangoFechas();///POSIBLEMENTE LO SAQUEMOS?
    void listarXId();///CAMBIO X = POR-(((EXISTE?)))
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();
    int generarId();///AGREGAMOS METODO


private:
    TurnoArchivo _repoTurno;
    TurnoArchivo _archivoBkp = TurnoArchivo("Turno.bkp");
    PacienteArchivo _repoPaciente;
    MedicosArchivos _repoMedico;
    historialArchivo _repoHistorial; ///AGREGAMOS ATRIBUTO-REPO
    ArancelArchivo _repoArancel;    ///AGREGAMOS ATRIBUTO-REPO

    MedicosManager _managerMedico;  ///AGREGAMOS ATRIBUTO-MANAGER
    HistorialManager _managerHistorial; ///AGREGAMOS ATRIBUTO-MANAGER


};
