#include <iostream>
#include <cstring>
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
/*
void App::run(const char* dni){
 int opcion

   do{
      system("cls");
      mostrarOpciones();
      opcion = seleccionarOpcion( );
      ejecutarOpcion(opcion, dni);
      system("pause");
   }while(usu.getNumeroRol() != 0);
}
*/

int App::seleccionarOpcion(){
   Usuarios usuario;
   int opciones;


   do{
        usuario = _usuario.login();
        opciones= usuario.getNumeroRol();
        cout << usuario.getDni()<< endl;
        system("pause");
        strcpy(_dniUsuario,usuario.getDni());
      if(opciones < 0 || opciones> getCantidadOpciones()){
         cout << " > Opcion no correcta..." << endl;
      }
   } while(opciones < 0 || opciones > getCantidadOpciones());


   return opciones;
}

void App::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
       cout << "menu medico " << _dniUsuario << endl;
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
