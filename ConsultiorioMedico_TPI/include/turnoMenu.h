#pragma once
#include "turnoManager.h"
#include "menu.h"

class TurnoMenu: public Menu {
public:
   TurnoMenu();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion)override;
private:
   TurnoManager _managerTurno;
};
