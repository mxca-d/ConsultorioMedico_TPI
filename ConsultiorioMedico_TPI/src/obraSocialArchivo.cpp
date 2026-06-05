#include <iostream>
#include <cstring>
#include "obraSocialArchivo.h"
#include "obrasSociales.h"
using namespace std;

/*void altaObraSocial(){
  ObraSociales o;
    o.cargar();
    int nuevoId = contarObraSocial() + 1;


    FILE* archivo = fopen("ObraSocial.dat", "ab");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    o.setIdObraSocial(nuevoId);
    fwrite(&o, sizeof(o), 1, archivo);
    fclose(archivo);

    cout << "Obra social guardada con exito. " <<endl;
}


void bajaObraSocial(){
   ObraSociales o;
    int id;
    cout << "Ingrese el id de la obra social: " << endl;
    cin >> id;

    FILE* archivo = fopen("ObraSocial.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&o, sizeof(o), 1, archivo)== 1){
        if (o.getIdObraSocial() == id){
            o.setEliminado(true);
            fseek(archivo, -sizeof(o), SEEK_CUR);
            fwrite(&o, sizeof(o), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}

void listarObraSocial(){
    ObraSociales o;

    FILE* archivo = fopen("ObraSocial.dat", "rb");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&o, sizeof(o), 1, archivo)== 1){
    if (!o.getEliminado()) {
    o.mostrar();
    }
    }
    fclose(archivo);


}

void modificarObraSocial(){
    ObraSociales o;
    int id;
    cout << "Ingrese el id de la obra social: " << endl;
    cin >> id;

    FILE* archivo = fopen("ObraSocial.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&o, sizeof(o), 1, archivo) == 1){
        if(o.getIdObraSocial() == id){
            o.cargar();
            fseek(archivo, -sizeof(o), SEEK_CUR);
            fwrite(&o, sizeof(o), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}
*/

ObraSocialArchivo::ObraSocialArchivo(){
    strcpy(_nombreArchivo,"obrasocial.dat");

}



ObraSocialArchivo::ObraSocialArchivo(const char* nombre){
    strcpy(_nombreArchivo,nombre);

}



bool ObraSocialArchivo::guardar(ObraSociales p){

FILE *pFile;

    pFile=fopen(_nombreArchivo,"ab");

    if(pFile==nullptr){
        return false;

    }

    bool pudoEscribir=fwrite(&p,sizeof(ObraSociales),1,pFile);
    fclose(pFile);

    return pudoEscribir;

}



int ObraSocialArchivo::getCantidadRegistros(){

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb");

    if(pFile=nullptr){
        return 0;
    }

    fseek(pFile,sizeof(ObraSociales),2);

    int bytes= ftell(pFile);
    int total= bytes / sizeof(ObraSociales);

    return total;


}



ObraSociales ObraSocialArchivo::leer(int pos){

    FILE *pFile;
    ObraSociales reg;

    pFile= fopen(_nombreArchivo,"rb");

    if(pFile=nullptr){
        return reg;
    }

    fseek(pFile,pos*sizeof(ObraSociales),0);
    fread(&reg,sizeof(ObraSociales),1,pFile);


    fclose(pFile);

    return reg;




}



bool ObraSocialArchivo::modificar(ObraSociales reg, int pos){

    FILE *pFile;

    pFile=fopen(_nombreArchivo,"rb+");
    if(pFile==nullptr){
        return false;
    }

    fseek(pFile, pos* sizeof(ObraSociales),0);
    bool escribio = fwrite(&reg,sizeof(ObraSociales),1,pFile);
    fclose(pFile);

    return escribio;

}



int ObraSocialArchivo::buscarPorId(int id){
    ObraSociales reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdObraSocial()==id){
            return i;
        }

    }

    return -1;

}



bool ObraSocialArchivo::guardar(ObraSociales*vec, int cantidadRegistrosAEscribir){


}



void ObraSocialArchivo::leer(ObraSociales *vec, int cantidadRegistrosALeer){


}



void ObraSocialArchivo::vaciar(){


}
