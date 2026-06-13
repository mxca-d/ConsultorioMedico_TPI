#pragma once
#include "usuariosManager.h"
#include "menuAdministrador.h"
#include "menuMedico.h"
#include "menuRecepcionista.h"

class App {
public:
   App();
   void run();
   void mostrarOpciones() ;
   Usuarios seleccionarOpcion() ;
   void ejecutarOpcion(Usuarios usuario) ;

   void setCantidadOpciones(int cant);
   int getCantidadOpciones ();

private:
    UsuariosManager _usuario;
    int _cantidadOpciones;

    MenuRecepcionista _menuRecepcionista;
    MenuMedico _menuMedico;
    MenuAdministrador _menuAdministrador;
};
