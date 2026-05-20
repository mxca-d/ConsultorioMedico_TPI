#include <iostream>
#include <cstring>
#include "historialArchivo.h"


historialArchivo::historialArchivo(){
    _nombreArchivo: "historial.dat";
}


historialArchivo::historialArchivo( const char* nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}



bool historialArchivo::guardar(Historial reg){
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p==nullptr){
        return false;
    }

    bool pudoEscribir= fwrite(&reg,sizeof(Historial),1,p);
    fclose(p);

    return pudoEscribir;




}


Historial historialArchivo::leer(int pos){
    Historial reg;
    FILE *p;

    p= fopen(_nombreArchivo,"rb");

    if(p==nullptr){
        return reg;
    }
    fseek(p,pos*sizeof(Historial),0);
    fread(&reg,sizeof(Historial),1,p);
    fclose(p);
    return reg;



}


int historialArchivo::getCantidadRegistros(){
    int bytes;
    int total;
    FILE *p= fopen(_nombreArchivo,"rb");
    if(p==nullptr){
        return 0;
    }

    fseek(p,0,2);
    bytes=ftell(p);
    fclose(p);

    total=bytes/sizeof(Historial);

    return total;


}


bool historialArchivo::modificar(Historial reg, int pos){

    FILE *p = fopen(_nombreArchivo, "rb+");

    if (p == nullptr){
    return false;
    }

    fseek(p, pos * sizeof(Historial), 0);
    bool pudoEscribir = fwrite(&reg, sizeof(Historial), 1, p);
    fclose(p);
    return pudoEscribir;
}


