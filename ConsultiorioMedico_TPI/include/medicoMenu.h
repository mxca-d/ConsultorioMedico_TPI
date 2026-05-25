#pragma once
#include "medicosManager.h"
#include "menu.h"

class MedicoMenu: public Menu {
public:
   MedicoMenu();
   void mostrarOpciones();
   void ejecutarOpcion(int opcion);

private:
   MedicosManager _managerMedico;
};
