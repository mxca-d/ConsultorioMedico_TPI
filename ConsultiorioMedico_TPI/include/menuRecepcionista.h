#pragma once
#include "menu.h"
#include "turnoManager.h"
#include "pacienteManager.h"

class MenuRecepcionista: public Menu {
public:
   MenuRecepcionista();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;

private:
    TurnoManager _managerTurno;
    PacienteManager _pacienteManager;
};
