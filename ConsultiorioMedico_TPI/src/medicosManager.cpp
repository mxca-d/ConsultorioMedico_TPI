#include "medicosManager.h"
#include "medicosArchivo.h"
#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;




void MedicosManager::altaMedico()
{
    ///FALTAN UNOS ATRIBUTOS DE CONTACTO
    char nombre[30],apellido[30],especialidad[30],dni[12],matricula[15],telefono[15];
    float honorarios;
    int opcion;
    bool eliminado,
         valido,
         diasAgenda [5] = {false};

    Carga cargar [] =
    {
        {"Nombre: ", nombre, 30},
        {"Apellido: ", apellido, 30},
        {"DNI: ", dni, 12},
        {"Especialidad: ", especialidad, 30},
        {"Matricula: ", matricula, 15},
        { "telefono: ", telefono, 15}
    };

    Medicos m;

    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }

    for (int i=0; i < 6; i++)
    {

        do
        {

            cout << cargar [i].texto;
            cin.getline(cargar[i].pDestino,cargar[i].tamanio);

            if (i == 2)
            {
                if (_repoMedicos.buscarCoincidenciaDni (cargar[i].pDestino))
                {
                    cout << "DNI ya existente" << endl;
                    return;
                }
            }
            if (cancelacionUsuario(cargar[i].pDestino) )
            {
                return;
            }
            todoMayuscula (cargar[i].pDestino);
            valido = validacionCaracteres (cargar[i].pDestino);


        }
        while (!valido);
    }

    do
    {
        cout << "Valor consulta: " ;
        cin >> honorarios;

        if (cancelacionUsuario (honorarios))
        {
            return;
        }

        valido = validacionImportes (honorarios);

    }
    while (!valido);
    system("cls");
    cout << "           DIAS DE ATENCION        " << endl;
    for (int i=0; i<5; i++)
    {
        do
        {

            cout << "Presione 1. para habilitar agenda." << endl;
            cout << "Presione 2. para no agregar dia." << endl;
            cout << "0. para cancelar carga. " << endl;
            mostrarDiaAgenda(i);
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "agregado.." << endl;
                system ("pause");
                diasAgenda [i] = true;
                valido = true;
                break;
            case 2:
                valido = true;
                break;
            case 0:
                return;
            default:
                cout << "OPCION INCORRECTA..." << endl;
                system ("pause");
                valido = false;
                break;
            }
        }
        while (!valido);
        system("cls");
    }


    eliminado = false;
    m.setNombre(nombre);
    m.setApellido(apellido);
    m.setDni(dni);
    m.setEspecialidad(especialidad);
    m.setTelefono(telefono);
    m.setMatricula(matricula);
    m.setHonorarios(honorarios);
    m.setIdMedico(generarId());
    m.setEliminado(eliminado);
    m.setDiasAgenda(diasAgenda);

    mostrarMedico (m);




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

void MedicosManager::listarPorId()///LISTAR O MOSTRAR POR ID?
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

void MedicosManager::listarMedicoEspecialidad(const char* especialidad)///COORDINAR SI VAMOS A USAR UTILS
{
    int coincidencias = 0;
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();

    Medicos m;

    for (int i = 0; i<cantidadRegistros; i++)
    {
        m = _repoMedicos.leer(i);
        if (!m.getEliminado() && strcmp(especialidad, m.getEspecialidad())==0)
        {
            cout << "idMedico: " << m.getIdMedico() << endl;
            cout << "Medico: " << m.getApellido() << ", " << m.getNombre() << endl;
            cout << "-------------------------------------------------------------" << endl;
            coincidencias ++;

        }

    }

    if (coincidencias ==0)
    {
        cout << "NO HAY COINCIDENCIAS PARA LA ESPECIALIDAD EN CONSULTA..." << endl;
    }
}

void MedicosManager::mostrarMedico(Medicos medicos)///AGREGAR LOS ATRIBUTOS DE CONTACTO
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
    cout << "Valor consulta: " << medicos.getHonorarios() << endl;
    cout << "Dias Atencion: " << endl;
    const bool* diasAgenda = medicos.getDiasAgenda();
    for (int i=0; i<5; i++)
    {

        if(diasAgenda [i]== true)
        {
            mostrarDiaAgenda(i);
        }
    }

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
    ///DEBERIAMOS ANTES VER SI ESTAN ACTIVOS? GENERE ALGO PARECIDO EN HISTORIAL



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

void MedicosManager::mostrarEspecialidades()
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos *vec = new Medicos[cantidadRegistros],
    *vecAux = new Medicos[cantidadRegistros];
    int cantidadMostrar = 0;



    if (vec == nullptr || vecAux == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        delete[] vec;
        delete[] vecAux;
        return;
    }

    if (cantidadRegistros ==0)
    {
        cout << "Sin registros" << endl;
        return;
    }
    _repoMedicos.leer(vec, cantidadRegistros);


    for (int i=0; i<cantidadRegistros; i++)
    {

        if (!vec[i].getEliminado()&& cantidadMostrar==0)
        {
            vecAux[cantidadMostrar] = vec[i];
            cantidadMostrar ++;
        }
        else if (!vec[i].getEliminado())
        {
            bool repetido = false;
            for (int x=0; x<cantidadMostrar; x++)
            {
                if (strcmp (vec[i].getEspecialidad(),vecAux[x].getEspecialidad())==0)
                {
                    repetido = true;
                    break;
                }
            }

            if (!repetido)
            {
                vecAux[cantidadMostrar] = vec[i];
                cantidadMostrar ++;
            }
        }
    }

    cout << "--- LISTADO DE ESPECIALIDADES ---" << endl;

    for (int i=0; i<cantidadMostrar; i++)
    {
        cout << vecAux[i].getEspecialidad() << endl;
    }

    delete[] vec;
    delete[] vecAux;
}
