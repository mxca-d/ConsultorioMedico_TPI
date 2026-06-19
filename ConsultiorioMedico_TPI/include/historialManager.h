#pragma once
#include "historial.h"
#include "historialArchivo.h"
#include "turnosArchivo.h"
#include "medicosArchivo.h"
#include "pacienteArchivo.h"





class HistorialManager{

public:
    bool cargarHistorial(Turno turno);
    void modificarHistorial();
    void listarHistoriales();
    void mostrarHistorial(Historial reg);
    void listarPorPaciente();
    void listarPorMedico();
    void buscarPorDniPaciente();
    void buscarPorDniMedico();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    void listarPacienteHistorial();

private:
    historialArchivo repoHistorial;
    historialArchivo _archivoBkp = historialArchivo("historial.bkp");

};
