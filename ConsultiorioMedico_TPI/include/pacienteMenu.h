#pragma once
#include "pacienteManager.h"
#include "menu.h"

class PacienteMenu: public Menu {
public:
   PacienteMenu();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion)override;

private:
   PacienteManager _managerPaciente;
};
