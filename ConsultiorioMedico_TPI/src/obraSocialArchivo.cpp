#include <iostream>
#include <cstring>
#include "obraSocialArchivo.h"
#include "obrasSociales.h"
using namespace std;


ObraSocialArchivo::ObraSocialArchivo()
{
    strcpy(_nombreArchivo,"obrasocial.dat");

}



ObraSocialArchivo::ObraSocialArchivo(const char* nombre)
{
    strcpy(_nombreArchivo,nombre);

}



bool ObraSocialArchivo::guardar(ObraSociales p)
{

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"ab");

    if(pFile==nullptr)
    {
        return false;

    }

    bool pudoEscribir=fwrite(&p,sizeof(ObraSociales),1,pFile);
    fclose(pFile);

    return pudoEscribir;

}



int ObraSocialArchivo::getCantidadRegistros()
{

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");

    if(pFile==nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);

    int bytes= ftell(pFile);
    int total= bytes / sizeof(ObraSociales);
    fclose(pFile);
    return total;


}



ObraSociales ObraSocialArchivo::leer(int pos)
{

    FILE *pFile;
    ObraSociales reg;

    pFile= fopen(_nombreArchivo,"rb");

    if(pFile==nullptr)
    {
        return reg;
    }

    fseek(pFile,pos*sizeof(ObraSociales),0);
    fread(&reg,sizeof(ObraSociales),1,pFile);


    fclose(pFile);

    return reg;




}



bool ObraSocialArchivo::modificar(ObraSociales reg, int pos)
{

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

    fseek(pFile, pos* sizeof(ObraSociales),0);
    bool escribio = fwrite(&reg,sizeof(ObraSociales),1,pFile);
    fclose(pFile);

    return escribio;

}



int ObraSocialArchivo::buscarPorId(int id)
{
    ObraSociales reg;

    int cantidad= getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdObraSocial()==id)
        {
            return i;
        }

    }

    return -1;

}



bool ObraSocialArchivo::guardar(ObraSociales*vec, int cantidadRegistrosAEscribir)
{

    FILE *pfile;

    pfile= fopen(_nombreArchivo,"ab");

    if(pfile==nullptr)
    {
        return false;
    }

    bool escribio= fwrite(vec,sizeof(ObraSociales),cantidadRegistrosAEscribir,pfile);
    fclose(pfile);
    return escribio;

}



void ObraSocialArchivo::leer(ObraSociales *vec, int cantidadRegistrosALeer)
{

    FILE *pFile;

    pFile= fopen(_nombreArchivo,"rb");

    if(pFile==nullptr)
    {
        return;
    }

    fread(vec,sizeof(ObraSociales),cantidadRegistrosALeer,pFile);

    fclose(pFile);
    return;


}



void ObraSocialArchivo::vaciar()
{
    FILE *pFile;

    pFile= fopen(_nombreArchivo, "wb");
    if(pFile==nullptr)
    {
        return;
    }
    fclose(pFile);



}

bool ObraSocialArchivo::buscarCoincidenciaId(int id){
    ObraSociales reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdObraSocial()==id){
            return true;
        }

    }

    return false;

}

