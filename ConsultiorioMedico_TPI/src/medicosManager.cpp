#include "medicosManager.h"
#include "medicosArchivo.h"
#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;




void MedicosManager::altaMedico()///agregue la creacion del usuario
{
    Usuarios usuario;
    UsuariosArchivo repoUsuarios;

    char nombre[30],apellido[30],especialidad[30],dni[12],matricula[15],telefono[15];
    float honorarios;
    int opcion;
    bool eliminado,ingresar,
         valido,
         diasAgenda [5] = {false};

    Carga cargar [5] =
    {
        {"Nombre: ", nombre, 30},
        {"Apellido: ", apellido, 30},
        {"DNI: ", dni, 12},
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

    for (int i=0; i < 5; i++)
    {

        do
        {
            ingresar =true;
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
            if (i==4)
            {
                if(!validacionSoloNumeros(cargar[4].pDestino))
                {
                    cout << "Solo se Permiten Numeros..."<< endl;
                    valido = false;
                    continue;
                }
            }
            if (cancelacionUsuario(cargar[i].pDestino) )
            {
                cout << "Carga cancelada por el usuario..." << endl;
                return;
            }
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingresar = false;
            }
            todoMayuscula (cargar[i].pDestino);
            if (ingresar && validacionCaracteres(cargar[i].pDestino))
            {
                valido = true;
            }



        }
        while (!valido);
    }

    do
    {
        mostrarEspecialidades();
        cout << "Elija una especialidad: " << endl;
        cin >> opcion;
        cin.ignore();
        valido = cargarEspecialidad(opcion,especialidad);
    }
    while(!valido);

    do
    {
        valido = true;
        cout << "Valor consulta: " ;
        cin >> honorarios;
        cin.ignore();

        if (cancelacionUsuario (honorarios))
        {
            cout << "Carga cancelada por el usuario..." << endl;
            return;
        }

        valido = validacionImportes (honorarios);

    }
    while (!valido);
    system("cls");
    cout << "           DIAS DE ATENCION        " << endl;
    for (int i=0; i<5; i++)///revisar for- doble dowhile
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
                cout << "Carga cancelada por el usuario..." << endl;
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

    usuario.setIdUsuario(repoUsuarios.getCantidadRegistros()+1);
    usuario.setDni(m.getDni());
    usuario.setNombreUsuario(m.getDni());
    usuario.setPassword("1234");
    usuario.setRol(2);
    usuario.setEliminado(false);

    mostrarMedico (m);




    if(_repoMedicos.guardar (m))
    {
        cout << "Se guardo el medico exitosamente!" << endl;

        if(repoUsuarios.guardar(usuario))
        {

            cout << "Tambien se genero el usuario." << endl;

        }
        else
        {

            cout << "Pero no se pudo generar el usuario..." << endl;
        }
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

void MedicosManager::listarMedicos()
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

void MedicosManager::mostrarPorId()
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

void MedicosManager::listarMedicoEspecialidad(const char* especialidad)
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

void MedicosManager::listarMedicoPorEspecialidad()///ORDENAR POR ESPECIALIDAD?
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

void MedicosManager::mostrarEspecialidadesExistentes()
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

int MedicosManager::recuperarIdMedico (const char* dni)
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos medico;

    for (int i=0; i<cantidadRegistros; i++)
    {
        medico = _repoMedicos.leer(i);
        if (strcmp(medico.getDni(), dni)==0)
        {
            return medico.getIdMedico();
            break;
        }

    }
    return -1;
}

void MedicosManager::modificarMedico()
{
    char nombre[30], apellido[30], dni [9], especialidad[30], matricula[15],
     telefono[15], honorarios [15];
    Fecha fechaNacimiento;
    bool fechaValida, ingreso, dias[5];
    int  pos, eleccion;

    Medicos m;


    cout << "Ingrese el DNI del medico a modificar:";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }

    cin.getline(dni,9);
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << endl;

    if (cancelacionUsuario(dni))
    {
        cout << "Carga cancelada por el usuario..." << endl;
        return;
    }


    pos=_repoMedicos.buscarPorDni(dni);

    if(pos==-1)
    {
        cout << "El id ingresado no existe." << endl;
        return;
    }

    m= _repoMedicos.leer(pos);


    int opcion;
    do
    {
        system("cls");
        ingreso = true;

        cout << "-----------------------------" << endl;
        cout << "Seleccionar que campo desea cambiar:" << endl;
        cout << "1-Nombre" << endl;
        cout << "2-Apellido" << endl;
        cout << "3-Fecha nacimiento" << endl;
        cout << "4-DNI" << endl;
        cout << "5-Especialidad" << endl;
        cout << "6-Matricula" << endl;
        cout << "7-Telefono" << endl;
        cout << "8-Honorarios" << endl;
        cout << "9-Dias Agenda" << endl;
        cout << "10-Cancelar" << endl;
        cout << "0-Guardar y salir" << endl;
        cout << "-----------------------------" << endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            cout << "Nombre: ";
            cin.getline(nombre,30);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso =false;
            }
            todoMayuscula(nombre);
            if (ingreso && validacionCaracteres(nombre))
            {
                m.setNombre(nombre);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }
            break;
        case 2:
            cout << "Apellido: ";
            cin.getline (apellido, 30);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso=false;
            }
            todoMayuscula(apellido);
            if (ingreso && validacionCaracteres(apellido))
            {
                m.setApellido(apellido);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }

            break;
        case 3:
            /*do
            {

                cout << "Fecha de nacimiento: " <<endl;
                fechaValida=fechaNacimiento.cargar();
                if(!fechaValida)
                {
                    cout << "Fecha invalida. Ingrese los datos nuevamente...";
                    system("pause");
                    system("cls");
                }
            }
            while(!fechaValida);
            p.setFechaNacimiento(fechaNacimiento);
            */
            break;
        case 4:
            cout << "DNI: ";
            cin.getline (dni, 12);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso = false;
            }
            if(!validacionSoloNumeros(dni))
            {
                cout << "INGRESO INVALIDO, SOLO SE PERMITE NUMEROS..." << endl;
                break;
            }
            if (ingreso && validacionCaracteres(dni))
            {
                m.setDni(dni);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }

            break;
        case 5:
            mostrarEspecialidades();
            cout << "Elija una especialidad: " << endl;
            cin >> eleccion;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso=false;
            }
            if(ingreso && cargarEspecialidad(eleccion,especialidad))
            {
                m.setEspecialidad(especialidad);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;
            }
            break;

        case 6:
            cout << "Matricula: " << endl;
            cin.getline(matricula,15);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso=false;
            }
            if (ingreso&&validacionCaracteres(matricula))
            {
                m.setMatricula(matricula);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }
            break;
        case 7:
            cout << "Telefono: " << endl;
            cin.getline(telefono,15);
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso=false;
            }
            if(!validacionSoloNumeros(telefono))
            {
                cout << "INGRESO INVALIDO, SOLO SE PERMITE NUMEROS..." << endl;
                break;
            }
            if (ingreso&&validacionCaracteres(telefono))
            {
                m.setTelefono(telefono);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }

            break;
        case 8:
            cout << "Honorarios: " << endl;
            cin >> honorarios;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                ingreso=false;
            }
            if (ingreso&&validacionCaracteres(honorarios))
            {
                m.setTelefono(telefono);
            }
            else
            {
                cout<< "INGRESO INVALIDO,MODIFICACION NO REALIZADA..." << endl;

            }
            break;

        case 9:
            cout << "           DIAS DE ATENCION        " << endl;
            for (int i=0; i<5; i++)
            {
                do
                {

                    cout << "Presione 1. para habilitar agenda." << endl;
                    cout << "Presione 2. para no agregar dia." << endl;
                    cout << "0. para cancelar carga. " << endl;
                    mostrarDiaAgenda(i);
                    cin >> eleccion;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        ingreso=false;
                    }
                    if (ingreso)
                    {

                        switch (eleccion)
                        {
                        case 1:
                            cout << "agregado.." << endl;
                            system ("pause");
                            dias [i] = true;
                            ingreso =true;
                            break;
                        case 2:
                            ingreso =true;
                            break;
                        case 0:
                            cout << "Carga cancelada por el usuario..." << endl;
                            return;
                        default:
                            cout << "OPCION INCORRECTA..." << endl;
                            system ("pause");
                            ingreso = false;
                            break;
                        }
                    }
                }
                while (!ingreso);
            }
            m.setDiasAgenda(dias);
            break;

        case 10:
            cout << "MODIFICACION CANCELADA...." << endl;
            cout << "NO SE GUARDARON CAMBIOS... " << endl;
            return;

        case 0:

            break;
        default:
            cout << "Opcion invalida... intente nuevamente" << endl;
            system("pause");
            break;

        }


    }
    while(opcion!=0);


    bool modificado=_repoMedicos.modificar(m,pos);

    if(modificado)
    {
        cout << "Los datos del paciente han sido modificados exitosamente" << endl;
    }
    else
    {
        cout << "No se ha podido modificar los datos del paciente." << endl;
    }

}

