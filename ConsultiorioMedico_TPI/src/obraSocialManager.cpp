#include <iostream>
#include "obraSocialManager.h"
#include <cstring>
#include "utils.h"

using namespace std;


void ObraSocialManager::altaObraSocial()
{

    char nombre[30];
    bool valido, ingreso;
    int cantidad;
    ObraSociales reg;
    do
    {
        valido = false;
        ingreso = true;
        cout << "-------------------OBRA SOCIAL-------------------" << endl;
        cout << endl;
        cout << "Ingrese 0 (cero) para cancelar la operacion" << endl;
        cout << "Ingrese el nombre de la obra social:" ;


        valido= cargarCadena(nombre,30);
        todoMayuscula(nombre);
        if(cancelacionUsuario(nombre))
        {
            cout << "OPERACION CANCELADA..." << endl;
            return;
        }
        if (valido && soloLetras(nombre))
        {

            cantidad = repoObraSocial.getCantidadRegistros();


            for( int i=0; i<cantidad; i++)
            {

                reg= repoObraSocial.leer(i);

                if(reg.getEliminado()==false && strcmp(reg.getNombre(),nombre)==0)
                {
                    cout << "La obra social ingresada ya existe..." << endl;
                    valido = false;
                }

            }

        }
        else
        {
            cout <<"INGRESO INVALIDO O NULO..." <<endl;
            valido = false;
        }
    }
    while (!valido);

    reg.setNombre(nombre);
    reg.setEliminado(false);
    reg.setIdObraSocial(cantidad+1);
    bool seGuardo=repoObraSocial.guardar(reg);

    if(seGuardo)
    {
        cout << "La obra social fue registrada con exito." << endl;
    }
    else
    {
        cout << "No se pudo guardar la obra social..." << endl;
    }




}



void ObraSocialManager::bajaObraSocial()
{
    ObraSociales reg;
    bool valido = true;

    int id, pos;

    do
    {

        cout << "Ingrese el ID de la obra social a dar de baja:";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin>>id;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            valido = false;
        }
        cout << endl;
        if (valido)
        {

            pos=repoObraSocial.buscarPorId(id);

            if(pos==-1)
            {
                cout << "El id ingresado no existe." << endl;
                return;
            }

            reg= repoObraSocial.leer(pos);
            reg.setEliminado(true);

            bool eliminado=repoObraSocial.modificar(reg,pos);

            if(eliminado)
            {
                cout << "La obra social se ha dado de baja exitosamente." << endl;
            }
            else
            {
                cout << "No se pudo dar de baja la obra social." << endl;
            }
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO..." << endl;
            valido =false;
        }
    }
    while(!valido);


}



void ObraSocialManager::modificarObraSocial()
{

    char nombre[30];
    bool valido;

    ObraSociales reg;
    ObraSociales aux;
    int id, pos;

    listarObrasSociales();
    do
    {
        valido = true;
        cout << "Ingrese ID de la obra social a modificar:";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin>>id;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            valido = false;
        }
        if (cancelacionUsuario(id))
        {
            cout << "CANCELACION POR EL USUARIO..." << endl;
            return;
        }
        if (valido)
        {

            pos=repoObraSocial.buscarPorId(id);

            if(pos==-1)
            {
                cout << "El id ingresado no existe." << endl;
                valido = false;
            }
        }
    }
    while(!valido);
    do
    {
        valido = true;
        reg= repoObraSocial.leer(pos);

        cout << "Ingresar nuevo nombre:" << endl;
        valido = cargarCadena(nombre,30);
        if (cancelacionUsuario(nombre))
        {
            cout << "CANCELACION POR EL USUARIO..." << endl;
            return;
        }
        todoMayuscula(nombre);
        if (valido && soloLetras(nombre))
        {
            int cantidad=repoObraSocial.getCantidadRegistros();

            for(int i=0; i<cantidad; i++)
            {

                aux=repoObraSocial.leer(i);

                if(strcmp(aux.getNombre(),nombre)==0)
                {
                    if(aux.getEliminado())
                    {
                        cout << "Existe obra social dada de baja con ese nombre. "
                             << "En caso de querer reactivar, realizarlo desde la opcion 'Dar alta obra social'" << endl;
                        return;

                    }
                    else if (aux.getIdObraSocial() != id)
                    {
                        cout << "Ya existe una obra social activa con ese nombre." << endl;
                        return;
                    }

                }

            }
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO..." << endl;
            valido = false;
        }
    }
    while(!valido);


    reg.setNombre(nombre);
    bool modificado=repoObraSocial.modificar(reg,pos);

    if(modificado)
    {
        cout << "El nombre de la obra social ha sido modificado exitosamente" << endl;
    }
    else
    {
        cout << "No se ha podido modificar el nombre de la obra social." << endl;
    }



}



void ObraSocialManager::listarObrasSociales()
{

    ObraSociales reg;

    int cantidad=repoObraSocial.getCantidadRegistros();

    for(int i=0; i<cantidad; i++)
    {

        reg=repoObraSocial.leer(i);

        if(reg.getEliminado()==false)
        {
            mostrarObraSocial(reg);
        }
    }

}



void ObraSocialManager::mostrarObraSocial(ObraSociales reg)
{

    if(reg.getEliminado()==false)
    {
        cout << reg.getIdObraSocial() << " - " << reg.getNombre() << endl;
    }


}



void ObraSocialManager::buscarObraSocialPorId()
{

    ObraSociales reg;
    int id, pos;
    bool valido;

    do
    {
        valido = true;
        cout << "Ingrese ID de la obra social:";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin>>id;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
            valido = false;
        }
        if (cancelacionUsuario(id))
        {
            cout << "CANCELACION POR EL USUARIO..." << endl;
            return;
        }
        if (valido)
        {

            pos=repoObraSocial.buscarPorId(id);

            if(pos==-1)
            {
                cout << "El id ingresado no existe." << endl;
                valido = false;
            }
        }
        else
        {
            cout << "INGRESO INVALIDO O NULO... " << endl;

        }

    }
    while(!valido);

    reg= repoObraSocial.leer(pos);

    mostrarObraSocial(reg);

}



void ObraSocialManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = repoObraSocial.getCantidadRegistros();
    ObraSociales *vec = new ObraSociales[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al realizar backup" << endl;
        return;
    }

    repoObraSocial.leer(vec, cantidadRegistros);
    _archivoBkp.vaciar();
    if (_archivoBkp.guardar(vec, cantidadRegistros))
    {
        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Error al realizar backup" << endl;
    }

    delete []vec;

}



void ObraSocialManager::restaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    ObraSociales *vec = new ObraSociales[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    repoObraSocial.vaciar();
    if (repoObraSocial.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Error al restaurar backup" << endl;
    }

    delete []vec;

}
