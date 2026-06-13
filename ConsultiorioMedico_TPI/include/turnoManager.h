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
    //void bajaTurno();
    void cancelarTurno();
    void atenderTurno(const char* dniUsuario);
    void modificarTurno();
    void listarTurnos();
    void mostrarTurno(Turno reg);
    void listarPorPaciente();
    void listarTurnoPendientePorPaciente();
    void listarPorMedico();
    void listarTurnoPendientePorMedico();
    void listarPorEstado();
    void listarPorFecha();
    void listarPorRangoFechas();
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();
    int generarId();


private:
    TurnoArchivo _repoTurno;
    TurnoArchivo _archivoBkp = TurnoArchivo("Turno.bkp");
    PacienteArchivo _repoPaciente;
    MedicosArchivos _repoMedico;
    historialArchivo _repoHistorial;
    ArancelArchivo _repoArancel;

    MedicosManager _managerMedico;
    HistorialManager _managerHistorial;


};
