#include <iostream>
#include "app.h"

using namespace std;

App::App(){
   setCantidadOpciones(3);
}

void App::setCantidadOpciones(int cant)
{
    _cantidadOpciones = cant;
}

int App:: getCantidadOpciones ()
{
    return _cantidadOpciones;
}

void App::mostrarOpciones(){
   cout << "----- INGRESO USUARIO-----"<<endl;

}

void App::run(){
   Usuarios usuario;


   do{
      system("cls");
      mostrarOpciones();
      usuario = seleccionarOpcion( );
      ejecutarOpcion(usuario);
      system("pause");
   }while(usuario.getNumeroRol() != 0);
}


Usuarios App::seleccionarOpcion(){
   Usuarios usuario;
   int opciones;


   do{
        usuario = _usuario.login();
        opciones= usuario.getNumeroRol();
      if(opciones < 0 || opciones> getCantidadOpciones()){
         cout << " > Opcion no correcta..." << endl;
      }
   } while(opciones < 0 || opciones > getCantidadOpciones());

   return usuario;
}

void App::ejecutarOpcion(Usuarios usuario){
   switch(usuario.getNumeroRol()){
   case 1:
    _menuAdministrador.run();
      break;
   case 2:
    _menuMedico.run();
    break;
   case 3:
    _menuRecepcionista.run();
    break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
