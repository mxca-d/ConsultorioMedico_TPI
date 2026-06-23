#pragma once
#include "menu.h"
#include "usuariosMenu.h"
#include "medicoMenu.h"
#include "pacienteMenu.h"
#include "obraSocialMenu.h"
#include "historialMenu.h"
#include "informesMenu.h"
#include "arancelMenu.h"
#include "turnoMenu.h"

class MenuAdministrador: public Menu {
public:
   MenuAdministrador();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;

private:
    UsuarioMenu _usuarioMenu;
    MedicoMenu _medicoMenu;
    PacienteMenu _pacienteMenu;
    ObraSocialMenu _obraSocialesMenu;
    HistorialMenu _HistorialMenu;
    InformesMenu _informesMenu;
    ArancelMenu _menuArancel;
    TurnoMenu _turnoMenu;

};
