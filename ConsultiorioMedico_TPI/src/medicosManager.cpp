#include "medicosManager.h"
#include "MedicosArchivos.h"
#include <iostream>

using namespace std;




void MedicosManager::Cargar()
{

    int idMedico,
        matricula,
        telefono;
    string apellido,
           nombre,
           especialidad;
    bool eliminado;

    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << " Ingrese apellido: " ;
    cin >> apellido;
    cout << endl;
    cout << " Ingrese nombre: " ;
    cin >> nombre;
    cout << endl;
    cout << " Ingrese especialidad: " ;
    cin >> especialidad;
    cout << endl;
    cout << " Ingrese telefono; " ;
    cin >> telefono;
    cout << endl;
    cout << " Ingrese matricula; " ;
    cin >> matricula;
    cout << endl;

    idMedico = GenerarId ();


                eliminado = 0;

    Medicos medicos( idMedico,  matricula,  telefono, apellido, nombre,
                     especialidad, eliminado);
    _archivo.guardar (medicos);
}

void MedicosManager::ListarTodos()
{
    int cantidadRegistros = _archivo.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Medicos reg = _archivo.leer(i);
        if (!reg.getEliminado())
        {
            Listar(reg);
            cout << endl;
        }
    }
}

void MedicosManager::ListarXId()
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = _archivo.buscar(id);
    if (posicion >= 0)
    {
        Medicos reg = _archivo.leer(posicion);
        Listar(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void MedicosManager::Listar(Medicos medicos)
{
    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << " Ingrese apellido: " << medicos.getApellidos()<< endl;
    cout << " Ingrese nombre: " << medicos.getNombres()<< endl;
    cout << " Ingrese especialidad: " << medicos.getEspecialidad()<< endl;
    cout << " Ingrese telefono; " << medicos.getTelefono()<< endl;
    cout << " Ingrese matricula; " << medicos.getMatricula()<< endl;

}

bool MedicosManager::ExisteId(int id)
{
    return _archivo.buscar(id) >= 0;
}

int MedicosManager::GenerarId()
{
    return _archivo.getCantidadRegistros() + 1;
}

void MedicosManager::HacerCopiaDeSeguridad()
{
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _archivo.leer(vec, cantidadRegistros);
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

void MedicosManager::RestaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    _archivo.vaciar();
    if (_archivo.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}
