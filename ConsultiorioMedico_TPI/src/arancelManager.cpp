#include <iostream>
#include "arancelManager.h"
#include "obraSocialManager.h"
#include "utils.h"

using namespace std;
/*
void arancelManager::altaArancel()
{

    char especilidad[30];
    int idArancel, idObraSocial, cantRegistrosObraSocial;
    float precio;
    bool eliminado,
         valido= false;

    ObraSocialManager manObraSocial;
    Arancel m;
    ObraSociales obraSocial;


    cout << "-------------------ARANCELES-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;

    controlBufferEnter();

    do
    {
        manObraSocial.mostrarIdObraSocial();
        cout << "Ingrese un id del listado: " ;
        cin >> idObraSocial;

        if(cancelacionUsuario(idObraSocial))
        {
            return;
        }


        cantRegistrosObraSocial = _repoObrasocial.getCantidadRegistros();
        for (int i=0; i<cantRegistrosObraSocial; i++)
        {
            obraSocial = _repoObrasocial.leer(i);
            if(idObraSocial == obraSocial.getIdObraSocial() )
            {
                valido = true;
                break;
            }
        }
        if(!valido)
        {
            cout << "Ingreso invalido o inexistente..." << endl;

        }

    }
    while (!valido);

    controlBufferEnter();
    do
    {
        cout << "Especialidad:  ";
        cin.getline(especilidad,30);

        if (cancelacionUsuario(especilidad) )
        {
            return;
        }
        valido = validacionCaracteres (especilidad); //preguntar si esta bien que imprima un msj y luego vuelva bool

    }
    while (!valido);

    do
    {
        cout << "Precio:  ";
        cin >> precio;
        if (cancelacionUsuario(precio) )
        {
            return;
        }
        valido = validacionImportes (precio);

    }
    while (!valido);


    idArancel = generarId();

    eliminado = false;
    m.setIdArancel(idArancel);
    m.setIdObraSocial(idObraSocial);
    m.setEspecialidad(especilidad);
    m.setPrecio(precio);
    m.setEliminado(eliminado);





    if(_repoArancel.guardar (m))
    {
        cout << "Se guardo el arancel exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el arancel..." << endl;
    }
}
*/
void arancelManager::bajaArancel()
{
    Arancel reg;

    int id, pos;

    cout << "Ingrese el ID del arancel a dar de baja:";
    cin>>id;
    cout << endl;

    pos=_repoArancel.buscarPorId(id);

    if(pos==-1)
    {
        cout << "El id ingresado no existe." << endl;
        return;
    }

    reg= _repoArancel.leer(pos);
    reg.setEliminado(true);

    bool eliminado=_repoArancel.modificar(reg,pos);

    if(eliminado)
    {
        cout << "El arancel se ha dado de baja exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo dar de baja el arancel." << endl;
    }




}

void arancelManager::listarAranceles()
{
    int cantidadRegistros = _repoArancel.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Arancel reg = _repoArancel.leer(i);
        if (!reg.getEliminado())
        {
            mostrarArancel(reg);
            cout << endl;
        }
    }
}

void arancelManager::listarXId()
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = _repoArancel.buscarPorId(id);
    if (posicion >= 0)
    {
        Arancel reg = _repoArancel.leer(posicion);
        mostrarArancel(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void arancelManager::mostrarArancel(Arancel aranceles)
{
    cout << "-------------------ARANCELES-------------------" << endl;
    cout << endl;
    cout << "ID Arancel: " << aranceles.getIdArancel()<< endl;
    cout << "ID Obra Social: " << aranceles.getIdObraSocial() << endl;
    cout << "Especialidad: " << aranceles.getEspecialidad()<< endl;
    cout << "Valor; " << aranceles.getPrecio()<< endl;


}

/*bool arancelManager::existeId(int id)
{
    return _repoArancel.buscarPorId(id) > 0;//mayor a 0 no? o vamos a hacer que 0 sea un nro posible de id?
}
*/
int arancelManager::generarId()
{
    return _repoArancel.getCantidadRegistros() + 1;
}

void arancelManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = _repoArancel.getCantidadRegistros();
    Arancel *vec = new Arancel[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _repoArancel.leer(vec, cantidadRegistros);
    _archivoBkp.vaciar();
    if (_archivoBkp.guardar(vec, cantidadRegistros))
    {
        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete []vec;
}

void arancelManager::restaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Arancel *vec = new Arancel[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    _repoArancel.vaciar();
    if (_repoArancel.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}

