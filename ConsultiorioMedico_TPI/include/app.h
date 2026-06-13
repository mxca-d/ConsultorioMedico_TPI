#pragma once
#include "usuariosManager.h"
#include "menuAdministrador.h"
#include "menuMedico.h"
#include "menuRecepcionista.h"

class App: public Menu {
public:
   App();
//   void run(Usuarios usu) ;
   void mostrarOpciones() override;
   int seleccionarOpcion() override ;
   void ejecutarOpcion(int opcion)  override ;

   void setCantidadOpciones(int cant);
   int getCantidadOpciones ();

private:
    UsuariosManager _usuario;
    int _cantidadOpciones;

    MenuRecepcionista _menuRecepcionista;
    MenuMedico _menuMedico;
    MenuAdministrador _menuAdministrador;
};
