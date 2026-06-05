#include <iostream>
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

int contarObraSocial(){
    ObraSociales o;
    int contador = 0;

    FILE* archivo = fopen("ObraSocial.dat", "rb");
    if (archivo == NULL) {
        return 0;
    }
    while (fread(&o, sizeof(o), 1, archivo) == 1){
        contador++;

    }
    fclose(archivo);
    return contador;


}
*/
int ObraSocialArchivo::getCantidadRegistros(){
    int bytes;
    int total;
    FILE *p= fopen(_nombreArchivo,"rb");
    if(p==nullptr){
        return 0;
    }

    fseek(p,0,2);
    bytes=ftell(p);
    fclose(p);

    total=bytes/sizeof(ObraSociales);

    return total;


}
/*
ObraSociales ObraSocialArchivo::leer(int pos)
{

}

*/
