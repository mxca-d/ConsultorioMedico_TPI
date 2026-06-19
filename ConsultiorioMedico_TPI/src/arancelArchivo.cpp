#include <iostream>
#include "arancelArchivo.h"
#include "arancel.h"
#include <cstring>

using namespace std;

ArancelArchivo::ArancelArchivo(){
    strcpy(_nombreArchivo,"arancel.dat");
}


ArancelArchivo::ArancelArchivo( const char* nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}



bool ArancelArchivo::guardar(Arancel *vec, int cantidadRegistrosAEscribir){
    FILE *pFile = fopen(_nombreArchivo, "ab");
    if(pFile==nullptr){
        return false;
    }

    int pudoEscribir= fwrite(vec,sizeof(Arancel),cantidadRegistrosAEscribir,pFile);
    fclose(pFile);

    if(pudoEscribir==cantidadRegistrosAEscribir){
        return true;
    }else{
        return false;
    }



}


Arancel ArancelArchivo::leer(int pos){
    Arancel reg;
    FILE *pFile;

    pFile= fopen(_nombreArchivo,"rb");

    if(pFile==nullptr){
        return reg;
    }
    fseek(pFile,pos*sizeof(Arancel),0);
    fread(&reg,sizeof(Arancel),1,pFile);
    fclose(pFile);
    return reg;



}


int ArancelArchivo::getCantidadRegistros(){
    int bytes;
    int total;
    FILE *pFile= fopen(_nombreArchivo,"rb");
    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile,0,2);
    bytes=ftell(pFile);
    fclose(pFile);

    total=bytes/sizeof(Arancel);

    return total;


}


bool ArancelArchivo::modificar(Arancel reg, int pos){

    FILE *pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr){
    return false;
    }

    fseek(pFile, pos * sizeof(Arancel), 0);
    bool pudoEscribir = fwrite(&reg, sizeof(Arancel), 1, pFile);
    fclose(pFile);
    return pudoEscribir;
}
bool ArancelArchivo::guardar(Arancel reg)
{
    FILE *pFile = fopen(_nombreArchivo, "ab");

    if (pFile == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Arancel), 1, pFile);
    fclose(pFile);
    return pudoEscribir;
}

int ArancelArchivo::buscarPorId(int id)
{
    Arancel aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (aux.getIdArancel() == id && aux.getEliminado()==false)
        {
            return i;
        }
    }
    return -1;
}

int ArancelArchivo::buscarPorIdObraSocialYEspecialidad(int id, const char *especialidad)
{
    Arancel aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (aux.getIdObraSocial() == id
            && aux.getEliminado()==false
            && strcmp(aux.getEspecialidad(),especialidad)==0)
        {
            return i;
        }
    }
    return -1;
}

void ArancelArchivo::leer(Arancel *vec, int cantidadRegistrosALeer)
{
    FILE *pFile = fopen(_nombreArchivo, "rb");
    if (pFile == NULL)
    {
        return ;
    }

    fread(vec, sizeof(Arancel), cantidadRegistrosALeer, pFile);
    fclose(pFile);
}
void ArancelArchivo::vaciar()
{
    FILE *pFile = fopen(_nombreArchivo, "wb");
    if (pFile == NULL)
    {
        return ;
    }
    fclose(pFile);
}


