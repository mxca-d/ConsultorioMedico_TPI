#pragma once
#include "pacienteManager.h"
#include "menu.h"

class PacienteMenu: public Menu {
public:
   PacienteMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   PacienteManager _managerPaciente;
};
