#include <iostream>
#include "paciente.h"
#include "PacienteArchivo.h"
#include <cstring>

using namespace std;

PacienteArchivo::PacienteArchivo(){
strcpy(_nombreArchivo,"pacientes.dat");

}


PacienteArchivo::PacienteArchivo(const char* nombre){

strcpy(_nombreArchivo,nombre);
}



bool PacienteArchivo::modificar(Paciente reg, int pos){
    FILE *p;
    p= fopen(_nombreArchivo,"rb+");

    if (p == NULL){
        return false;
    }

    fseek(p, pos* sizeof(Paciente),0);
    bool escribio = fwrite(&reg,sizeof(Paciente),1,p);
    fclose(p);
    return escribio;
}


int PacienteArchivo::buscarPorDni(const char* dni){
    Paciente reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(strcmp(reg.getDni(),dni)==0){
            return i;
        }

    }

    return -1;

}

bool PacienteArchivo::buscarCoincidenciaId(int id){
    Paciente reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdPaciente()==id){
            return true;
        }

    }

    return false;

}

int PacienteArchivo::buscarPorId(int id){
    Paciente reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdPaciente()==id){
            return i;
        }

    }

    return -1;

}

bool PacienteArchivo::buscarCoincidenciaDni(const char* dni){
    Paciente reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(strcmp(reg.getDni(),dni) ==0){
            return true;
        }

    }

    return false;

}



bool PacienteArchivo::guardar(Paciente p){

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"ab");

    if(pFile==nullptr){
        return false;

    }

    bool pudoEscribir=fwrite(&p,sizeof(Paciente),1,pFile);
    fclose(pFile);

    return pudoEscribir;

}

Paciente PacienteArchivo::leer(int pos){
    Paciente reg;

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){
        return reg;
    }
    fseek(pFile,pos*sizeof(Paciente),0);
    fread(&reg,sizeof(Paciente),1,pFile);
    fclose(pFile);

    return reg;

}

void PacienteArchivo::leer(Paciente *vec, int cantidadRegistrosALeer)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return ;
    }

    fread(vec, sizeof(Paciente), cantidadRegistrosALeer, p);
    fclose(p);
}


bool PacienteArchivo::guardar(Paciente *vec, int cantidadRegistrosAEscribir)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Paciente), cantidadRegistrosAEscribir, p);
    fclose(p);

    if(cantidadRegistrosEscritos == cantidadRegistrosAEscribir){

        return true;
    }else{
        return false;
    }
}

void PacienteArchivo::vaciar()
{
    FILE *p = fopen(_nombreArchivo, "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);
}



int PacienteArchivo::getCantidadRegistros(){
    Paciente p;

    FILE* archivo = fopen(_nombreArchivo, "rb");
    if (archivo == NULL) {
        return 0;
    }
    fseek(archivo,sizeof(Paciente),2);
    int bytes= ftell(archivo);

    fclose(archivo);
    int total= bytes / sizeof(Paciente);

    return total;
}

int PacienteArchivo::getCantidadActivos(){
    Paciente reg;
    int cantidad= getCantidadRegistros();
    int contadorActivos=0;

    for(int i=0;i<cantidad;i++){
        reg=leer(i);
        if(reg.getEliminado()!=true){
            contadorActivos++;
        }

    }
    return contadorActivos;

}
