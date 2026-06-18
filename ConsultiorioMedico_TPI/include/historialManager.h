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
    void listarPacienteHistorial();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    historialArchivo repoHistorial;
    historialArchivo _archivoBkp = historialArchivo("historial.bkp");

};
