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



/*bool ArancelArchivo::guardar(Historial reg){
    FILE *p = fopen(_nombreArchivo, "ab");
    if(p==nullptr){
        return false;
    }

    bool pudoEscribir= fwrite(&reg,sizeof(Arancel),1,p);
    fclose(p);

    return pudoEscribir;




}


Arancel ArancelArchivo::leer(int pos){
    Arancel reg;
    FILE *p;

    p= fopen(_nombreArchivo,"rb");

    if(p==nullptr){
        return reg;
    }
    fseek(p,pos*sizeof(Arancel),0);
    fread(&reg,sizeof(Arancel),1,p);
    fclose(p);
    return reg;



}

*/
int ArancelArchivo::getCantidadRegistros(){
    int bytes;
    int total;
    FILE *p= fopen(_nombreArchivo,"rb");
    if(p==nullptr){
        return 0;
    }

    fseek(p,0,2);
    bytes=ftell(p);
    fclose(p);

    total=bytes/sizeof(Arancel);

    return total;


}


/*bool ArancelArchivo::modificar(Arancel reg, int pos){

    FILE *p = fopen(_nombreArchivo, "rb+");

    if (p == nullptr){
    return false;
    }

    fseek(p, pos * sizeof(Arancel), 0);
    bool pudoEscribir = fwrite(&reg, sizeof(Arancel), 1, p);
    fclose(p);
    return pudoEscribir;
}

*/


/*void altaArancel(){
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
*/
