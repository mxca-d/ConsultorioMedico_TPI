#include <iostream>
#include "paciente.h"
#include "PacienteArchivo.h"

using namespace std;

PacienteArchivo::PacienteArchivo(){
_nombreArchivo="pacientes.dat";

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

bool PacienteArchivo::guardar(Paciente p){

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"ab");

    if(pFile==nullptr){
        return false;

    }

    fwrite(&p,sizeof(Paciente),1,pFile);
    fclose(pFile);

    return true;

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
