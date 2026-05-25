#pragma once
#include "historial.h"
#include "historialArchivo.h"



class HistorialManager{

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void listarPacientes();
    void mostrarPaciente(Historial reg);
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    historialArchivo repoPaciente;
    historialArchivo _archivoBkp = historialArchivo("historial.bkp");

};
