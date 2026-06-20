#include "medicosArchivo.h"
#include <cstdio>
#include <cstring>

MedicosArchivos::MedicosArchivos()
{
    strcpy(_nombreArchivo,"medicos.dat");
}

MedicosArchivos:: MedicosArchivos(const char* nombre)
{
    strcpy(_nombreArchivo,nombre);
}

int MedicosArchivos::getCantidadRegistros()//
{
    FILE *p = fopen(_nombreArchivo, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Medicos);
}

int MedicosArchivos::getCantidadActivos(){
    Medicos reg;
    int cantidad= getCantidadRegistros();
    int contadorActivos=0;

    for(int i=0;i<cantidad;i++){
        reg=leer(i);
        if(!reg.getEliminado()){
            contadorActivos++;
        }
    }
    return contadorActivos;
}

bool MedicosArchivos::guardar(Medicos reg)
{
    FILE *p = fopen(_nombreArchivo, "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Medicos), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool MedicosArchivos::modificar(Medicos reg, int posicionAReemplazar)
{
    FILE *p = fopen(_nombreArchivo, "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Medicos), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Medicos), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool MedicosArchivos::guardar(Medicos *vec, int cantidadRegistrosAEscribir)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Medicos), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


Medicos MedicosArchivos::leer(int pos)
{
    Medicos aux;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, pos * sizeof(Medicos), SEEK_SET);
    fread(&aux, sizeof(Medicos), 1, p);
    fclose(p);
    return aux;
}

void MedicosArchivos::leer(Medicos *vec, int cantidadRegistrosALeer)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return ;
    }

    fread(vec, sizeof(Medicos), cantidadRegistrosALeer, p);
    fclose(p);
}

int MedicosArchivos::buscarPorId(int id)
{
    Medicos aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (aux.getIdMedico() == id && aux.getEliminado()==false)
        {
            return i;
        }
    }
    return -1;
}

int MedicosArchivos::buscarPorDni(const char* dni)
{
    Medicos aux;
    int cantidadRegistros = getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++)
    {
        aux = leer(i);
        if (strcmp(aux.getDni(),dni) == 0 && aux.getEliminado()==false)
        {
            return i;
        }
    }
    return -1;
}

bool MedicosArchivos::buscarCoincidenciaId(int id){
    Medicos reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && reg.getIdMedico()==id){
            return true;
        }

    }

    return false;

}

bool MedicosArchivos::buscarCoincidenciaDni(const char* dni){
    Medicos reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getDni(),dni)==0){
            return true;
        }

    }

    return false;

}

bool MedicosArchivos::buscarCoincidenciaEspecialidad(const char* especialidad){
    Medicos reg;

    int cantidad= getCantidadRegistros();

    for(int i=0;i<cantidad;i++){
        reg= leer(i);

        if(reg.getEliminado()==false && strcmp(reg.getEspecialidad(),especialidad)==0){
            return true;
        }

    }

    return false;

}

void MedicosArchivos::vaciar()
{
    FILE *p = fopen(_nombreArchivo, "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);
}
