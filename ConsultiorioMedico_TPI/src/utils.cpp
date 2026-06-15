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
        return false;
    }
    else if (caracteres < 29 && caracteres > 2)
    {
        return true;
    }
    else
    {
        return false;
    }


}

bool validacionCaracteres (const char* cadena, int tamanio)//REPASAR ESTA FUNCION
{

    int caracteres = strlen (cadena);

    if (caracteres == 0)
    {

        return false;
    }
    else if (caracteres <= tamanio && caracteres > 2)
    {
        return true;
    }
    else
    {

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

        return false;
    }


}

bool validacionCaracteres (float num)
{


 if (num < 10000 && num > 0)
    {
        return true;
    }
    else
    {

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

/*
void controlBufferEnter ()
{
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
}*/

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
        cout << "1.LUNES" << endl;
        break;

    case 1:
        cout << "2.MARTES" << endl;
        break;

    case 2:
        cout << "3.MIERCOLES" << endl;
        break;
    case 3:
        cout << "4.JUEVES" << endl;
        break;
    case 4:
        cout << "5.VIERNES" << endl;
        break;
    default:
        cout << "INCORRECTO"<< endl;
        break;

    }
}



void mostrarHoraTurno (int indice)
{
    switch (indice)
    {
    case 0 :
        cout << "1. << 08:00 Hs" << endl;
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


void mostrarEspecialidades(){
    cout << "1- CLINICA MEDICA" << endl;
    cout << "2- CARDIOLOGIA" << endl;
    cout << "3- PEDIATRIA" << endl;
    cout << "4- TRAUMATOLOGIA" << endl;
    cout << "5- KINESIOLOGIA" << endl;
}

bool cargarEspecialidad(int opcion, char* especialidad){

    switch(opcion){
        case 1:
            strcpy(especialidad, "CLINICA MEDICA");
            return true;
        case 2:
            strcpy(especialidad, "CARDIOLOGIA");
            return true;
        case 3:
            strcpy(especialidad, "PEDIATRIA");
            return true;
        case 4:
            strcpy(especialidad, "DERMATOLOGIA");
            return true;
        case 5:
            strcpy(especialidad, "KINESIOLOGIA");
            return true;
        default:
            return false;

    }

}

bool cargarHoraTurno(int opcion, char* hora){

    switch(opcion){
        case 1:
            strcpy(hora, "08:00");
            return true;
        case 2:
            strcpy(hora, "09:00");
            return true;
        case 3:
            strcpy(hora, "10:00");
            return true;
        case 4:
            strcpy(hora, "11:00");
            return true;
        case 5:
            strcpy(hora, "12:00");
            return true;
        default:
            return false;

    }

}
Fecha obtenerFechaBase(int opcion){



    switch(opcion){

    case 1:
        return Fecha(5,1,2026);
    case 2:
        return Fecha(6,1,2026);
    case 3:
        return Fecha(7,1,2026);
    case 4:
        return Fecha(8,1,2026);
    case 5:
        return Fecha(9,1,2026);

    }

}

void obtenerDias(int opcion, Fecha *dias, Fecha hoy){

    Fecha aux = obtenerFechaBase(opcion);
    hoy.agregarDias(1);

    while(aux.esMenor(hoy)){

       aux.agregarDias(7);

    }

    for(int i=0;i<4;i++){

        dias[i]=aux;
        aux.agregarDias(7);

    }


}

bool validacionSoloNumeros(const char* cadena)
{
    int tamanio = strlen(cadena);
    for (int i=0; i< tamanio;i++ )
    {
        if (!isdigit(cadena [i]))
        {
            return false;
        }
    }

    return true;
}

