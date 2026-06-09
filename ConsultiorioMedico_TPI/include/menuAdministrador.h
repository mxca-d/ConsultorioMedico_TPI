#pragma once
#include "menu.h"

class MenuAdministrador: public Menu {
public:
   MenuAdministrador();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;

private:

};
