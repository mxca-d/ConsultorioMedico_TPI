#include <iostream>
#include <cstring>
#include "turno.h"
#include "turnosArchivo.h"
#include "paciente.h"
#include "obrasSociales.h"
#include "arancel.h"
#include "medicos.h"

using namespace std;

void altaTurno(){
    Turno t;
    t.cargar();

    Paciente p;
    FILE* archivoPacientes = fopen("Pacientes.dat", "rb");
    while(fread(&p, sizeof(p), 1, archivoPacientes) == 1){
        if(p.getIdPaciente() == t.getIdPaciente()){
            break;
        }
    }
    fclose(archivoPacientes);

    Medicos m;
    FILE* archivoMedicos = fopen("Medicos.dat", "rb");
    while(fread(&m, sizeof(m), 1, archivoMedicos) == 1){
        if(m.getIdMedico() == t.getIdMedico()){
            break;
        }
    }
    fclose(archivoMedicos);

    ObraSociales os;
    FILE* archivoOS = fopen("ObraSocial.dat", "rb");
    while(fread(&os, sizeof(os), 1, archivoOS) == 1){
    if(strcmp(os.getNombre(), p.getObraSocial()) == 0){
        break;
    }
}
    fclose(archivoOS);

     Arancel a;
    FILE* archivoAranceles = fopen("Aranceles.dat", "rb");
    while(fread(&a, sizeof(a), 1, archivoAranceles) == 1){
    if(a.getIdObraSocial() == os.getIdObraSocial() &&
       strcmp(a.getEspecialidad(), m.getEspecialidad()) == 0){
        break;
    }
}
    fclose(archivoAranceles);

    cout << "Precio de la consulta: $" << a.getPrecio() << endl;

    int nuevoId = contarTurnos() + 1;


    FILE* archivo = fopen("Turnos.dat", "ab");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    t.setIdTurno(nuevoId);
    fwrite(&t, sizeof(t), 1, archivo);
    fclose(archivo);

    cout << "Turno guardado con exito. " <<endl;
}

void listarTurnos(){
    Turno t;

    FILE* archivo = fopen("Turnos.dat", "rb");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&t, sizeof(t), 1, archivo)== 1){
    if (!t.getEliminado()) {
    t.mostrar();
    }
    }
    fclose(archivo);

}

void bajaTurno(){
    Turno t;
    int id;
    cout << "Ingrese el id del turno: " << endl;
    cin >> id;

    FILE* archivo = fopen("Turnos.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&t, sizeof(t), 1, archivo)== 1){
        if (t.getIdTurno() == id){
            t.setEliminado(true);
            fseek(archivo, -sizeof(t), SEEK_CUR);
            fwrite(&t, sizeof(t), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}

void modificarTurno(){
    Turno t;
    int id;
    cout << "Ingrese el id del turno: " << endl;
    cin >> id;

    FILE* archivo = fopen("Turnos.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&t, sizeof(t), 1, archivo) == 1){
        if(t.getIdTurno() == id){
            t.cargar();
            fseek(archivo, -sizeof(t), SEEK_CUR);
            fwrite(&t, sizeof(t), 1, archivo);
            break;
        }
    }
    fclose(archivo);


}
int contarTurnos(){
    Turno t;
    int contador = 0;

    FILE* archivo = fopen("Turnos.dat", "rb");
    if (archivo == NULL) {
        return 0;
    }
    while (fread(&t, sizeof(t), 1, archivo) == 1){
        contador++;

    }
    fclose(archivo);
    return contador;
}

void cambiarEstadoTurno(){
     Turno t;
    int id;
    cout << "Ingrese el id del turno: " << endl;
    cin >> id;

    FILE* archivo = fopen("Turnos.dat", "r+b");
    if (archivo == NULL){
        cout << "Error al abrir el archivo. " << endl;
        return;
    }
    while(fread(&t, sizeof(t), 1, archivo) == 1){
        if(t.getIdTurno() == id){
            int opcion;
            cout << "Elija el nuevo estado del turno " <<endl;
            cout << "1. Pendiente" << endl;
            cout << "2. Atendido" << endl;
            cout << "3. Cancelado" << endl;
            cin >> opcion;
            cin.ignore();

            switch(opcion){
            case 1: t.setEstado("Pendiente"); break;
            case 2: t.setEstado("Atendido"); break;
            case 3: t.setEstado("Cancelado"); break;
}
            fseek(archivo, -sizeof(t), SEEK_CUR);
            fwrite(&t, sizeof(t), 1, archivo);
            break;
        }
    }
    fclose(archivo);

}
