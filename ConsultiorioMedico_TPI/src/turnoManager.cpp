#include <iostream>
#include <cstring>
#include "turnoManager.h"
#include "pacienteArchivo.h"
#include "utils.h"

using namespace std;




void TurnoManager::altaTurno()
{

    char hora[6],dniPaciente[8],estado[15];
    int  idTurno, idMedico;
    float costoConsulta;
    Fecha f;
    bool valido;


    Turno turno;

    cout << "-------------------Turno-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;

    controlBufferEnter ();

    do
    {

        cout << "DNI paciente:  ";
        controlBufferEnter();
        cin.getline(dniPaciente,8);


        if (cancelacionUsuario(dniPaciente) && validacionCaracteres (dniPaciente,8))
        {
            return;
        }


        if (_repoPaciente.buscarPorDni(dniPaciente) && validacionCaracteres (dniPaciente))
        {
            valido = true;
        }
        else
        {
            valido = false;
        }

    }
    while (!valido);

    do
    {

        cout << "ID Medico:  ";
        cin >> idMedico;

        if (cancelacionUsuario(idMedico) )
        {
            return;
        }

        if (_repoMedico.buscarCoincidenciaId(idMedico) && validacionCaracteres (idMedico))
        {
            valido = true;
        }
        else
        {
            valido = false;
        }

    }
    while (!valido);
}
/*
   fecha, craar al medico dias que atienden con un vector de turnos disponibles para asignar turno desde
   una lista que se muestre

   lo mismo para la hora
    */





/*

    if(_repoMedicos.guardar (m))
    {
        cout << "Se guardo el medico exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el medico..." << endl;
    }
}*/

void TurnoManager::cancelarTurno()
{
    Turno turno;
    bool guardar = false,
         bandDNI = false;
    char dni[8];
    int  pos, opcion;

    do
    {

        cout << " INGRESE 0 (CERO) PARA CANCELAR..." << endl;
        cout << "INGRESE DNI DEL PACIENTE: ";
        controlBufferEnter();
        cin.getline(dni,8);


        if (cancelacionUsuario(dni) && validacionCaracteres (dni,8))
        {
            return;
        }



        pos = _repoTurno.buscarPorDni (dni);
        if(pos==-1)
        {
            cout << "El DNI no posee turnos pendientes. " << endl;

        }
        else
        {
            bandDNI = true;
            turno = _repoTurno.leer(pos);

            mostrarTurno (turno);

            do
            {

                cout << "DESEA ELIMINAR EL TURNO? 1.SI/2.NO " << endl;
                cin >> opcion;


                if (opcion == 1)
                {
                    turno.setEliminado(true);
                    turno.setEstado ("CANCELADO");
                    bool eliminado= _repoTurno.modificar(turno,pos);

                    if(eliminado)
                    {
                        cout << "El turno se ha cancelado exitosamente." << endl;
                    }
                    else
                    {
                        cout << "No se pudo cancelar el turno." << endl;
                    }
                    guardar = true;

                }
                else if (opcion == 2)
                {
                    cout << "OPERACION ABORTADA..." << endl;
                    guardar = true;
                }
                else
                {
                    cout << "OPCION INCORRECTA..." << endl;
                }
            }
            while (!guardar);
        }
    }
    while (!bandDNI);
}

void TurnoManager::mostrarTurno(Turno turno)
{
    Paciente paciente;
    Medicos medico;

    int posPac, posMedico;

    posPac = _repoPaciente.buscarPorDni(turno.getDniPaciente());
    paciente = _repoPaciente.leer(posPac);

    posMedico = _repoMedico.buscarPorId(turno.getIdMedico());
    medico = _repoMedico.leer(posMedico);

    cout << "+-----------------------------------------------------+" << endl;
    cout << "PACIENTE: " << paciente.getApellido() << ", "<< paciente.getNombre() << endl;
    cout << "DNI: " << turno.getDniPaciente() << endl;
    cout << "MEDICO: " << medico.getApellido() << ", " << medico.getNombre() << endl;
    cout << "FECHA: " << endl; // completar
    cout << "ESTADO: "<< turno.getEstado() << endl;
    cout << "COSTO: " << endl; // completar
    cout << "+-----------------------------------------------------+" << endl;

}

void TurnoManager::listarTurnos()
{
    int cantidad= _repoTurno.getCantidadRegistros();
    Turno reg;
    for(int i=0; i<cantidad; i++)
    {
        reg= _repoTurno.leer(i);

        if(reg.getEliminado()==false)
        {

            mostrarTurno(reg);
            cout << endl;
        }

    }

}

/*
void TurnoManager::listarPorPaciente()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Medicos[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



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

    cout <<               "Turno listados por apellido"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
*/

void TurnoManager::listarPorPaciente()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (strcmp (vec[x].getDniPaciente(), vec[x+1].getDniPaciente())> 0 )
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por paciente"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void TurnoManager::listarPorMedico()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (vec[x].getIdMedico() > vec[x+1].getIdMedico())
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por Medico"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void TurnoManager::listarPorEstado()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (strcmp (vec[x].getEstado(), vec[x+1].getEstado())> 0 )
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por estado"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void TurnoManager::listarPorFecha()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (vec[x].getFechaint() > vec[x+1].getFechaint())
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por Fecha"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}
/*
void TurnoManager::atenderTurno()
{
    Turno turno;
    bool guardar = false,
         bandDNI = false;
    int dni,id, pos, opcion, cantRegistros;

    do
    {
        cout << " INGRESE 0 (CERO) PARA CANCELAR..." << endl;
        cout << "INGRESE DNI DEL PACIENTE: ";
        cin>>dni;
        cout << endl;

        if (dni ==0)
        {
            return;
        }


        pos = _repoTurno.buscarPorDni (dni);
        if(pos==-1)
        {
            cout << "El DNI no posee turnos pendientes. " << endl;

        }
        else
        {
            bandDNI = true;
            turno= _repoTurno.leer(pos);
            turno.getEstado ("EN CURSO");
            mostrarTurno (reg);
            cantRegistros = _repoHistorial.getCantidadRegistros();
            for (int i=0; i<cantRegistros; i++)
            {
                Historial historial;
                historial = _repoHistorial.leer(i);
                if(turno.getIdPaciente() == historial.getIdPaciente() )

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

        */
