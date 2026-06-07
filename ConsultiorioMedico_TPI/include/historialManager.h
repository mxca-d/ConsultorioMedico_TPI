#pragma once
#include "historial.h"
#include "historialArchivo.h"
#include "turnosArchivo.h"
#include "medicosArchivo.h"
#include "pacienteArchivo.h"





class HistorialManager{

public:
    bool cargarHistorial(Turno turno, Medicos medico, Paciente paciente);
    void bajaHistorial();//se deberia dar de baja un historial?
    void modificarHistorial();
    void listarHistoriales();
    void mostrarHistorial(Historial reg);
    void listarPorPaciente();
    void listarPorMedico();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    historialArchivo repoHistorial;
    historialArchivo _archivoBkp = historialArchivo("historial.bkp");

};
