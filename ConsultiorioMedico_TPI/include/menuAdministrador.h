#pragma once
#include "menu.h"
#include "usuariosManager.h"
#include "medicosManager.h"
#include "obraSocialManager.h"
#include "arancelManager.h"
#include "arancelMenu.h"

class MenuAdministrador: public Menu {
public:
   MenuAdministrador();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;

private:
    UsuariosManager _usuarioManager;
    MedicosManager _medicoManager;
    ObraSocialManager _obraSocialManager;
    arancelManager _arancelManager;
    ArancelMenu _menuArancel;

};
