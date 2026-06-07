#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

bool horaValida(const char* hora)
{

    if(strlen(hora) != 5) //verifica cant char
    {
        return false;
    }

    if(hora[2] != ':') // verifica que esten los :
    {
        return false;
    }

    if(hora[0] < '0' || hora[0] > '9') // verifica rango
    {
        return false;
    }

    if(hora[1] < '0' || hora[1] > '9')
    {
        return false;
    }

    if(hora[3] < '0' || hora[3] > '9')
    {
        return false;
    }

    if(hora[4] < '0' || hora[4] > '9')
    {
        return false;
    }

    int horas = (hora[0] - '0') * 10 + (hora[1] - '0');//resto 48= '0' y lo convierto en decena para sumar

    int minutos = (hora[3] - '0') * 10 + (hora[4] - '0');

    if(horas < 0 || horas > 23) //verifico que no supere las hs
    {
        return false;
    }

    if(minutos < 0 || minutos > 59) //verifico q no supere los minutos
    {
        return false;
    }

    return true;
}

bool cancelacionUsuario (const char* cadena)
{
    if (strcmp (cadena, "0") == 0)
    {
        cout << "Carga cancelada por el usuario..." << endl;
        return true;
    }

    return false;
}

bool cancelacionUsuario (int num)
{
    if (num == 0)
    {
        cout << "Carga cancelada por el usuario..." << endl;
        return true;
    }

    return false;
}


bool cancelacionUsuario (float num)
{
    if (num == 0)
    {
        cout << "Carga cancelada por el usuario..." << endl;
        return true;
    }

    return false;
}

bool validacionCaracteres (const char* cadena)
{
    int caracteres = strlen (cadena);

    if (caracteres == 0)
    {
        cout << ">> Error: no puede quedar vacio.\n" << endl;
        return false;
    }
    else if (caracteres < 29 && caracteres > 2)
    {
        return true;
    }
    else
    {
        cout << "Fuera de rango, recuerde ingresar hasta 30 caracteres..." << endl;
        cin.clear();
        cin.ignore(30, '\n');
        return false;
    }


}

bool validacionCaracteres (const char* cadena, int tamanio)
{

    int caracteres = strlen (cadena);

    if (caracteres == 0)
    {
        cout << ">> Error: no puede quedar vacio.\n" << endl;
        return false;
    }
    else if (caracteres <= tamanio && caracteres > 2)
    {
        return true;
    }
    else
    {
        cout << "Fuera de rango, recuerde ingresar hasta " << tamanio<< "caracteres..." << endl;
        cin.clear();
        cin.ignore(30, '\n');
        return false;
    }


}
bool validacionCaracteres (int num)
{


    if (num < 10000 && num > 0)
    {
        return true;
    }
    else
    {
        cout << "Fuera de rango" << endl;
        return false;
    }


}


void todoMayuscula (char *pCadena)
{
    for (int i = 0; pCadena[i] != '\0'; i++)
    {
        pCadena[i] = toupper(pCadena[i]);
    }
}

void controlBufferEnter ()
{
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
}

bool validacionImportes (float precio)
{
    if (precio > 0 && precio < 5000000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void mostrarDiaAgenda (int indice)
{
    switch (indice)
    {
    case 0 :
        cout << "LUNES" << endl;
        break;

    case 1:
        cout << "MARTES" << endl;
        break;

    case 2:
        cout << "MIERCOLES" << endl;
        break;
    case 3:
        cout << "JUEVES" << endl;
        break;
    case 4:
        cout << "VIERNES" << endl;
        break;
    default:
        cout << "INCORRECTO"<< endl;
        break;

    }
}
void mostrarTrunoAgenda (int indice)
{
    switch (indice)
    {
    case 0 :
        cout << "1. 08:00 Hs" << endl;
        break;

    case 1:
        cout << "2. 09:00 Hs" << endl;
        break;

    case 2:
        cout << "3. 10:00 Hs" << endl;
        break;
    case 3:
        cout << "4. 11:00 Hs" << endl;
        break;
    case 4:
        cout << "5. 12:00 Hs" << endl;
        break;
    default:
        cout << "INCORRECTO"<< endl;
        break;

    }
}

