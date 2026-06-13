#pragma once
#include "menu.h"
#include "turnoManager.h"
#include "pacienteManager.h"

class MenuMedico: public Menu {
public:
   MenuMedico();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;
private:
    TurnoManager _managerTurno;
    PacienteManager _pacienteManager;
    HistorialManager _historialManager;
};
