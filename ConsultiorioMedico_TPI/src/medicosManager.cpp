#include "medicosManager.h"
#include "medicosArchivo.h"
#include <iostream>

using namespace std;




void MedicosManager::altaMedico()
{

    char nombre[30],apellido[30],especialidad[30],dni[12],matricula[15],telefono[15];
    int idMedico;
    bool eliminado;

    Medicos m;

    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << "Nombre: ";
    cin.getline(nombre,30);
     cout << endl;
    cout << "Apellido: ";
    cin.getline (apellido, 30);
    cout << endl;
    cout << "DNI: ";
    cin.getline (dni, 12);
    cout << endl;
    cout << " Ingrese especialidad: " ;
    cin.getline(especialidad,30);
    cout << endl;
    cout << " Ingrese telefono; " ;
    cin.getline(telefono,15);
    cout << endl;
    cout << " Ingrese matricula; " ;
    cin.getline(matricula,15);
    cout << endl;

    m.setNombre(nombre);
    m.setApellido(apellido);
    m.setDni(dni);
    m.setEspecialidad(especialidad);
    m.setTelefono(telefono);
    m.setMatricula(matricula);
    m.setIdMedico(generarId());
    eliminado = false;


    if(_repoMedicos.guardar (m)){
        cout << "Se guardo el medico exitosamente!" << endl;
    }else{
        cout << "No se pudo guardar el medico..." << endl;
    }
}

void MedicosManager::bajaMedico(){
    Medicos reg;

    int id, pos;

    cout << "Ingrese el ID del medico a dar de baja:";
    cin>>id;
    cout << endl;

    pos=_repoMedicos.buscarPorId(id);

    if(pos==-1){
        cout << "El id ingresado no existe." << endl;
        return;
    }

    reg= _repoMedicos.leer(pos);
    reg.setEliminado(true);

    bool eliminado=_repoMedicos.modificar(reg,pos);

    if(eliminado){
        cout << "El medico se ha dado de baja exitosamente." << endl;
    }else{
        cout << "No se pudo dar de baja el medico." << endl;
    }




}

void MedicosManager::listarTodos()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Medicos reg = _repoMedicos.leer(i);
        if (!reg.getEliminado())
        {
            mostrarMedico(reg);
            cout << endl;
        }
    }
}

void MedicosManager::listarXId()
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = _repoMedicos.buscarPorId(id);
    if (posicion >= 0)
    {
        Medicos reg = _repoMedicos.leer(posicion);
        mostrarMedico(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void MedicosManager::mostrarMedico(Medicos medicos)
{
    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << "ID: " << medicos.getIdMedico()<< endl;
    cout << "Nombre: " << medicos.getNombre()<< endl;
    cout << "Apellido: " << medicos.getApellido()<< endl;
    cout << "DNI: " << medicos.getDni()<< endl;
    cout << "Especialidad: " << medicos.getEspecialidad()<< endl;
    cout << "Telefono; " << medicos.getTelefono()<< endl;
    cout << "Matricula; " << medicos.getMatricula()<< endl;

}

bool MedicosManager::existeId(int id)
{
    return _repoMedicos.buscarPorId(id) > 0;//mayor a 0 no? o vamos a hacer que 0 sea un nro posible de id?
}

int MedicosManager::generarId()
{
    return _repoMedicos.getCantidadRegistros() + 1;
}

void MedicosManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _repoMedicos.leer(vec, cantidadRegistros);
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

void MedicosManager::restaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    _repoMedicos.vaciar();
    if (_repoMedicos.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}
