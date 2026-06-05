#include <iostream>
#include <cstring>
#include "turno.h"
#include "turnosArchivo.h"
#include "paciente.h"
#include "obrasSociales.h"
#include "arancel.h"
#include "medicos.h"

using namespace std;

/*void altaTurno(){
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

} */


TurnoArchivo::TurnoArchivo()
{
    strcpy(_nombreArchivo,"turnos.dat");
}

TurnoArchivo:: TurnoArchivo(const char* nombre)
{
    strcpy(_nombreArchivo,nombre);
}

int TurnoArchivo::getCantidadRegistros()//
{
    FILE *p = fopen(_nombreArchivo, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Turno);
}

bool TurnoArchivo::guardar(Turno reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool TurnoArchivo::modificar(Turno reg, int posicionAReemplazar)
{
    FILE *p = fopen(_nombreArchivo, "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Turno), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Turno), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool TurnoArchivo::guardar(Turno *vec, int cantidadRegistrosAEscribir)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Turno), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


Turno TurnoArchivo::leer(int pos)
{
    Turno aux;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, pos * sizeof(Turno), SEEK_SET);
    fread(&aux, sizeof(Turno), 1, p);
    fclose(p);
    return aux;
}

void TurnoArchivo::leer(Turno *vec, int cantidadRegistrosALeer)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return ;
    }

    fread(vec, sizeof(Turno), cantidadRegistrosALeer, p);
    fclose(p);
}

int TurnoArchivo::buscarPorId(int id)
{
    Turno aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (aux.getIdTurno() == id && aux.getEliminado()==false)
        {
            return i;
        }
    }
    return -1;
}

int TurnoArchivo::buscarPorDni(int dni)
{
    Turno aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (aux.getDniPaciente() == dni && aux.getEliminado()==false && aux.getEstado() == "PENDIENTE")
        {
            return i;
        }
    }
    return -1;
}

void TurnoArchivo::vaciar()
{
    FILE *p = fopen(_nombreArchivo, "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);
}

