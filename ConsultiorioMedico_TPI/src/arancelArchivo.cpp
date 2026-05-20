#include <iostream>
#include "gestorArancel.h"
#include "arancel.h"

using namespace std;



void altaArancel(){
  Arancel a;
    a.cargar();
    int nuevoId = contarArancel() + 1;


    FILE* archivo = fopen("Aranceles.dat", "ab");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    a.setIdArancel(nuevoId);
    fwrite(&a, sizeof(a), 1, archivo);
    fclose(archivo);

    cout << "Arancel guardado con exito. " <<endl;
}


void bajaArancel(){
   Arancel a;
    int id;
    cout << "Ingrese el id del arancel: " << endl;
    cin >> id;

    FILE* archivo = fopen("Aranceles.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&a, sizeof(a), 1, archivo)== 1){
        if (a.getIdArancel() == id){
            a.setEliminado(true);
            fseek(archivo, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}

void listarArancel(){
    Arancel a;

    FILE* archivo = fopen("Aranceles.dat", "rb");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&a, sizeof(a), 1, archivo)== 1){
    if (!a.getEliminado()) {
    a.mostrar();
    }
    }
    fclose(archivo);


}

void modificarArancel(){
    Arancel a;
    int id;
    cout << "Ingrese el id del arancel: " << endl;
    cin >> id;

    FILE* archivo = fopen("Aranceles.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&a, sizeof(a), 1, archivo) == 1){
        if(a.getIdArancel() == id){
            a.cargar();
            fseek(archivo, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}

int contarArancel(){
    Arancel a;
    int contador = 0;

    FILE* archivo = fopen("Aranceles.dat", "rb");
    if (archivo == NULL) {
        return 0;
    }
    while (fread(&a, sizeof(a), 1, archivo) == 1){
        contador++;

    }
    fclose(archivo);
    return contador;


}
