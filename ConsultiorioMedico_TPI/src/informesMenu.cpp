#include <iostream>
#include "informesMenu.h"


using namespace std;

InformesMenu::InformesMenu()
{
    setCantidadOpciones(7);
}

void InformesMenu::mostrarOpciones()
{
    cout << "----- MENU INFORMES-----"<<endl;
    cout << "1- SUELDOS POR MEDICO"<<endl;
    cout << "2- RECAUDACION TOTAL"<<endl;
    cout << "3- RECAUDACION POR OBRA SOCIALES"<<endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void InformesMenu::ejecutarOpcion(int opcion)
{
  switch(opcion)
    {
    case 1:
        sueldosPorMedico();
        break;
    case 2:
        recaudacionTotal();
        break;
    case 3:
        recaudacionPorObraSocial();
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}
