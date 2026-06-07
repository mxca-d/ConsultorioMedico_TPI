#include <iostream>
#include <cstring>
#include "historialArchivo.h"


historialArchivo::historialArchivo(){
    strcpy(_nombreArchivo,"historial.dat");
}


historialArchivo::historialArchivo( const char* nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}



bool historialArchivo::guardar(Historial reg){

    FILE *pFile = fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){
        return false;
    }

    bool pudoEscribir= fwrite(&reg,sizeof(Historial),1,pFile);
    fclose(pFile);

    return pudoEscribir;




}


Historial historialArchivo::leer(int pos){
    Historial reg;
    FILE *pFile;

    pFile= fopen(_nombreArchivo,"rb");

    if(pFile==nullptr){
        return reg;
    }
    fseek(pFile,pos*sizeof(Historial),0);
    fread(&reg,sizeof(Historial),1,pFile);
    fclose(pFile);
    return reg;



}


int historialArchivo::getCantidadRegistros(){
    int bytes;
    int total;
    FILE *pFile= fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile,0,2);
    bytes=ftell(pFile);
    fclose(pFile);

    total=bytes/sizeof(Historial);

    return total;


}


bool historialArchivo::modificar(Historial reg, int pos){

    FILE *pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr){
    return false;
    }

    fseek(pFile, pos * sizeof(Historial), 0);
    bool pudoEscribir = fwrite(&reg, sizeof(Historial), 1, pFile);
    fclose(pFile);
    return pudoEscribir;
}


int historialArchivo::buscarPorId(int id){

    Historial reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){

        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdHistorial()==id){
            return i;
        }

    }

    return -1;


}



bool historialArchivo::guardar(Historial *vec, int cantidadRegistrosAEscribir){


    FILE *pFile;

    pFile=fopen(_nombreArchivo,"ab");

    if(pFile==nullptr){
        return false;
    }

    int cantidadEscrita= fwrite(vec,sizeof(Historial),cantidadRegistrosAEscribir,pFile);
    fclose(pFile);

    if(cantidadEscrita==cantidadRegistrosAEscribir){
        return true;
    }else{
        return false;
    }


}



void historialArchivo::leer(Historial *vec, int cantidadRegistrosALeer){

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){
        return;
    }

    fread(vec,sizeof(Historial),cantidadRegistrosALeer,pFile);
    fclose(pFile);



}



void historialArchivo::vaciar(){

    FILE *pFile;
    pFile= fopen(_nombreArchivo, "wb");
    if(pFile==nullptr){
        return;
    }
    fclose(pFile);

}


