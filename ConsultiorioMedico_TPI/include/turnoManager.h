#pragma once
#include "turno.h"
#include "turnosArchivo.h"
#include "pacienteArchivo.h"
#include "medicosArchivo.h"
#include "historialArchivo.h"
#include "medicosManager.h"

class TurnoManager
{

public:
    void altaTurno();
    //void bajaTurno();
    void cancelarTurno();
    void atenderTurno();
    void modificarTurno();
    void listarTurnos();
    void mostrarTurno(Turno reg);
    void listarPorPaciente();
    void listarPorMedico();
    void listarPorEstado();
    void listarPorFecha();
    void listarPorRangoFechas();
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    TurnoArchivo _repoTurno;
    TurnoArchivo _archivoBkp = TurnoArchivo("Turno.bkp");
    PacienteArchivo _repoPaciente;
    MedicosArchivos _repoMedico;
    historialArchivo _repoHistorial;

    MedicosManager _managerMedico;


};
