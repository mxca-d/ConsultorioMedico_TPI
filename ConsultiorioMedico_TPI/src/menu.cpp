#include <iostream>
#include "menu.h"
#include <cstdio>

using namespace std;

Menu::Menu(){
   setCantidadOpciones(0);
}
void Menu::run(){
   int opcion;
   char prueba [10]={"prueba"};


   do{
      system("cls");
      mostrarOpciones();
      opcion = seleccionarOpcion( );

      cout << prueba << endl;
      system ("pause");
      cout << "run "<< _dniUsuario << endl;
      system ("pause");
      ejecutarOpcion(opcion);
      system("pause");
   }while(opcion != 0);
}


int Menu::seleccionarOpcion(){
   int opcion;

   do{
      cout << " Ingrese opcion: ";
      cin >> opcion;

      if(opcion < 0 || opcion > getCantidadOpciones()){
         cout << " > Opcion no correcta..." << endl;
      }
   } while(opcion < 0 || opcion > getCantidadOpciones());

   return opcion;
}

void Menu::setCantidadOpciones(int cantidad){
   _cantidadOpciones = cantidad;
}
int Menu::getCantidadOpciones(){
   return _cantidadOpciones;
}
