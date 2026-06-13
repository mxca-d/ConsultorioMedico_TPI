#include <iostream>
#include "app.h"

using namespace std;

App::App(){
   setCantidadOpciones(3);
}

void App::mostrarOpciones(){


}

int App::seleccionarOpcion(){
    int opcion;

    //_usuarioManager.crearAdminSiNoExiste();

   do{
        _usuario= _usuarioManager.login();
        opcion = _usuarioManager.numeroRol(_usuario.getRol());

      if(opcion < 0 || opcion > getCantidadOpciones()){
         cout << " > Opcion no correcta..." << endl;
      }
   } while(opcion < 0 || opcion > getCantidadOpciones());

   return opcion;
}

void App::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
    _menuAdministrador.run();
      break;
   case 2:
    _menuMedico.leerMedico(_usuario.getDni());
    _menuMedico.run();
    break;
   case 3:
    _menuRecepcionista.run();
    break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
