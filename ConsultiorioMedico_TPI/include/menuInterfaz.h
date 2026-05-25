#pragma once
#include "menu.h"

class MenuInterfaz: public Menu {
public:
   MenuInterfaz();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;

private:

};
