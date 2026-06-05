#pragma once
#include "turnoManager.h"
#include "menu.h"

class TurnoMenu: public Menu {
public:
   TurnoMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   TurnoManager _managerTurno;
};
