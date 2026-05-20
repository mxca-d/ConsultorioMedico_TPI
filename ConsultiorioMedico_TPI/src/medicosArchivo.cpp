#include "medicosArchivo.h"
#include <cstdio>

MedicosArchivos::MedicosArchivos()
{
    _ruta = "Medicos.dat";
}

MedicosArchivos::MedicosArchivos(std::string ruta)
{
    _ruta = ruta;
}

int MedicosArchivos::getCantidadRegistros()
{
    FILE *p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Medicos);
}

bool MedicosArchivos::guardar(Medicos reg)
{
    FILE *p = fopen(_ruta.c_str(), "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Medicos), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool MedicosArchivos::guardar(Medicos reg, int posicionAReemplazar)
{
    FILE *p = fopen(_ruta.c_str(), "rb+");

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
    FILE *p = fopen(_ruta.c_str(), "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Medicos), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


Medicos MedicosArchivos::leer(int nroRegistro)
{
    Medicos aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Medicos), SEEK_SET);
    fread(&aux, sizeof(Medicos), 1, p);
    fclose(p);
    return aux;
}

void MedicosArchivos::leer(Medicos *vec, int cantidadRegistrosALeer)
{
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return ;
    }

    fread(vec, sizeof(Medicos), cantidadRegistrosALeer, p);
    fclose(p);
}

int MedicosArchivos::buscar(int ID)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Medicos aux;

    for(i=0; i<cantidadRegistros; i++)
    {
        aux = this->leer(i);
        if (aux.getIdMedico() == ID)
        {
            return i;
        }
    }
    return -1;
}

void MedicosArchivos::vaciar()
{
    FILE *p = fopen(_ruta.c_str(), "wb");
    if (p == NULL)
    {
        return ;
    }
    fclose(p);
}
