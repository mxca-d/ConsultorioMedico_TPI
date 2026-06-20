#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

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


/*bool validacionCaracteres (float num)
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
*/

void todoMayuscula (char *pCadena)
{
    for (int i = 0; pCadena[i] != '\0'; i++)
    {
        pCadena[i] = toupper(pCadena[i]);
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

bool letrasYNumeros(const char *cadena){

    int largo = strlen(cadena);

    if(largo < 3){
        return false;
    }

    int i = 0;
    while(cadena[i] != '\0')
    {
        if(!((cadena[i] >= 65 && cadena[i] <= 90)///A-Z =65 a 90
            || (cadena[i] >= 97 && cadena[i] <= 122)///a-z =97 a 122
            || cadena[i] == 32 ///32= espacio
            || (cadena[i] >= 48 && cadena[i] <= 57)))///48=0 y 57=9
            {
            return false;
        }


        i++;
    }

    return true;


}



bool soloNumeros(const char *cadena){

    int largo = strlen(cadena);

    if(largo == 0){
        return false;
    }

    int i = 0;
    while(cadena[i] != '\0')
    {
        if(cadena[i] < 48 || cadena[i] > 57)///48=0 y 57=9 - ASCII
        {
            return false;
        }

        i++;
    }

    return true;
}

bool dniValido(const char *dni){

    int largo = strlen(dni);

    if(largo<7 || largo>8){
        return false;
    }

    int i = 0;
    while(dni[i] != '\0')
    {
        if(dni[i] < 48 || dni[i] > 57)///48=0 y 57=9 - ASCII
        {
            return false;
        }

        i++;
    }

    return true;
}

bool soloLetras(const char *cadena){

    int largo = strlen(cadena);

    if(largo < 3){
        return false;
    }

    int i = 0;

    while(cadena[i] != '\0')
    {
        if(!((cadena[i] >= 65 && cadena[i] <= 90)///A-Z =65 a 90
            || (cadena[i] >= 97 && cadena[i] <= 122)///a-z =97 a 122
            || cadena[i] == 32)){///32= espacio
            return false;
        }

        i++;
    }

    return true;
}


bool cargarCadena(char *cadena, int tam){
    if(cin.peek() == '\n'){
        cin.ignore();
    }

    cin.getline(cadena, tam);

    if(cin.fail()){
        cin.clear();
        cin.ignore(10000,'\n');
        return false;
    }

    return true;
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

    for(int i=0;i<2;i++){

        dias[i]=aux;
        aux.agregarDias(7);

    }


}

bool validacionSoloNumeros(const char* cadena)
{
    int tamanio = strlen(cadena);
    for (int i=0; i< tamanio; i++ )
    {
        if (!isdigit(cadena [i]))
        {
            return false;
        }
    }

    return true;
}



