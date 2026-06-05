#include "medicosManager.h"
#include "medicosArchivo.h"
#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;




void MedicosManager::altaMedico()
{

    char nombre[30],apellido[30],especialidad[30],dni[12],matricula[15],telefono[15];
    bool eliminado,
         valido;

    Carga cargar [] =
    {
        {"Nombre: ", nombre, 30},
        {"Apellido: ", apellido, 30},
        {"DNI: ", dni, 12},
        {"Especialidad: ", especialidad, 30},
        {"Matricula: ", matricula, 15},
        { "telefono: ", especialidad, 15}
    };

    Medicos m;

    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;

    if (std::cin.peek() == '\n')
    {
        std::cin.ignore();
    }

    for (int i=0; i < 6; i++)
    {

        do
        {

            cout << cargar [i].texto;
            cin.getline(cargar[i].pDestino,cargar[i].tamanio);

            if (cancelacionUsuario(cargar[i].pDestino) )
            {
                return;
            }
            todoMayuscula (cargar[i].pDestino);
            valido = validacionCaracteres (cargar[i].pDestino);


        }
        while (!valido);
    }
    /*
        do
        {

            cout << endl;
            cout << "Apellido: ";
            cin.getline (apellido, 30);
            cout << endl;

            if (cancelacionUsuario(apellido) )
            {
                return;
            }
            valido = validacionCaracteres (apellido);


        }
        while (!valido);

        do
        {

            cout << endl;
            cout << "DNI: ";
            cin.getline (dni, 12);
            cout << endl;

            if (cancelacionUsuario(dni) )
            {
                return;
            }
            valido = validacionCaracteres (dni);


        }
        while (!valido);




        cout << endl;
        cout << " Ingrese especialidad: " ;
        cin.getline(especialidad,30);
        cout << endl;
        cout << " Ingrese telefono; " ;
        cin.getline(telefono,15);
        cout << endl;
        cout << " Ingrese matricula; " ;
        cin.getline(matricula,15);
        cout << endl; */

    eliminado = false;
    m.setNombre(nombre);
    m.setApellido(apellido);
    m.setDni(dni);
    m.setEspecialidad(especialidad);
    m.setTelefono(telefono);
    m.setMatricula(matricula);
    m.setIdMedico(generarId());
    m.setEliminado(eliminado);




    if(_repoMedicos.guardar (m))
    {
        cout << "Se guardo el medico exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el medico..." << endl;
    }
}

void MedicosManager::bajaMedico()
{
    Medicos reg;

    int id, pos;

    cout << "Ingrese el ID del medico a dar de baja:";
    cin>>id;
    cout << endl;

    pos=_repoMedicos.buscarPorId(id);

    if(pos==-1)
    {
        cout << "El id ingresado no existe." << endl;
        return;
    }

    reg= _repoMedicos.leer(pos);
    reg.setEliminado(true);

    bool eliminado=_repoMedicos.modificar(reg,pos);

    if(eliminado)
    {
        cout << "El medico se ha dado de baja exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo dar de baja el medico." << endl;
    }




}

void MedicosManager::listarMedico()
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

void MedicosManager::listarMedicoEspecialidad()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();

    bool band = false;
    Medicos m;

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Medicos reg = _repoMedicos.leer(i);
        if (!reg.getEliminado() && !band)
        {
            band = true;
            m = reg;
            cout << reg.getEspecialidad() << endl;

        } else if (!reg.getEliminado() && strcmp (m.getEspecialidad(),reg.getEspecialidad())==0)
        {
            m = reg;
            cout << reg.getEspecialidad() << endl;
        }
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

void MedicosManager::listarMedicoPorApellido()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros];
    Medicos aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoMedicos.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (strcmp (vec[x].getApellido(), vec[x+1].getApellido())> 0 ||
                    (strcmp(vec[x].getApellido(), vec[x+1].getApellido()) == 0
                     && strcmp(vec[x].getNombre(), vec[x+1].getNombre()) > 0))
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Medicos listados por apellido"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        cout << endl;
        cout << "Apellido: " << vec[i].getApellido()<< endl;
        cout << "Nombre: " << vec[i].getNombre()<< endl;
        cout << "ID: " << vec[i].getIdMedico()<< endl;
        cout << "DNI: " << vec[i].getDni()<< endl;
        cout << "Especialidad: " << vec[i].getEspecialidad()<< endl;
        cout << "Telefono; " << vec[i].getTelefono()<< endl;
        cout << "Matricula; " << vec[i].getMatricula()<< endl;

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void MedicosManager::listarMedicoPorEspecialidad()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos reg;
    char especialidad [30];

    cout << "Ingrese especialidad a consultar:  " << endl;
    cin.getline(especialidad,30);



    for (int i = 0; i<cantidadRegistros; i++)
    {
        reg = _repoMedicos.leer(i);
        if (!reg.getEliminado() && strcmp (especialidad, reg.getEspecialidad()) == 0)
        {
            mostrarMedico(reg);
            cout << endl;
        }
    }
}
