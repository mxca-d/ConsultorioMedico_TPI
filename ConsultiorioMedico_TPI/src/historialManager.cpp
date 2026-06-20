#include <iostream>
#include "historialManager.h"
#include "utils.h"
using namespace std;


bool HistorialManager::cargarHistorial(Turno turno)
{

    char diagnostico[100];
    Historial historial;

    PacienteArchivo repoPaciente;
    MedicosArchivos repoMedico;
    Paciente paciente;
    Medicos medico;

    int idMedico= turno.getIdMedico();
    int idPaciente= turno.getIdPaciente();

    paciente= repoPaciente.leer(repoPaciente.buscarPorId(idPaciente));
    medico= repoMedico.leer(repoMedico.buscarPorId(idMedico));


    cout << "Paciente : " << paciente.getNombre()<< " " << paciente.getApellido() << endl;
    cout << "Medico :" << medico.getNombre()<< " " << medico.getApellido() << endl;
    cout << "Fecha :";
        turno.getFechaTurno().mostrar();
    cout <<endl;
    cout << "---------------------------------------------------------------" << endl;

    do
    {
        system("cls");
        cout << "Ingresar diagnostico:" << endl << endl;
        cargarCadena(diagnostico,100);
        if(!letrasYNumeros(diagnostico,100)){
            cout << "Diagnostico invalido. Intente nuevamente..." << endl;
            system("pause");
        }


    }
    while(!letrasYNumeros(diagnostico,100));

    todoMayuscula(diagnostico);

    historial.setDiagnostico(diagnostico);
    historial.setEliminado(false);
    historial.setFecha(turno.getFechaTurno());
    historial.setIdHistorial(repoHistorial.getCantidadRegistros()+1);
    historial.setIdMedico(idMedico);
    historial.setIdPaciente(idPaciente);
    historial.setIdTurno(turno.getIdTurno());

    if(repoHistorial.guardar(historial))
    {
        cout << "El historial se ha guardado exitosamente." << endl;
        return true;
    }
    else
    {
        cout << "No se ha podido guardar el historial." << endl;
        return false;
    }




}


void HistorialManager::modificarHistorial()
{
    char diagnostico[100];
    Historial historial;
    int idHistorial;
    Paciente paciente;
    PacienteArchivo repoPaciente;
    Medicos medico;
    MedicosArchivos repoMedico;


    cout << "Ingresar el ID del historial que desea modificar:" << endl;
    cin>> idHistorial;

    int posHistorial=repoHistorial.buscarPorId(idHistorial);

    if(posHistorial==-1)
    {
        cout << "No existe el ID de historial ingresado..." << endl;
        return;
    }


    historial= repoHistorial.leer(posHistorial);

    int posPaciente= repoPaciente.buscarPorId(historial.getIdPaciente());
    int posMedico= repoMedico.buscarPorId(historial.getIdMedico());

    paciente= repoPaciente.leer(posPaciente);
    medico= repoMedico.leer(posMedico);

    cout << "Paciente : " << paciente.getNombre()<< " " << paciente.getApellido() << endl;
    cout << "Medico :" << medico.getNombre()<< " " << medico.getApellido() << endl;
    cout << "Fecha :" <<historial.getFecha().toString() << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Ingresar la modificacion del diagnostico:" << endl << endl;
    do{
        system("cls");
        cargarCadena(diagnostico,100);
        if(!letrasYNumeros(diagnostico,100)){
            cout << "Diagnostico invalido. Intente nuevamente..."<< endl;
            system("pause");
        }


    }while(!letrasYNumeros(diagnostico,100));

    todoMayuscula(diagnostico);

    historial.setDiagnostico(diagnostico);

    if(repoHistorial.modificar(historial,posHistorial))
    {
        cout << "El historial se ha modificado exitosamente." << endl;
    }
    else
    {
        cout << "No se ha podido modificar el historial." << endl;
    }

}



void HistorialManager::listarHistoriales()
{
    Historial historial;
    Paciente paciente;
    PacienteArchivo repoPaciente;

    int cantidad = repoHistorial.getCantidadRegistros();


    for(int i=0; i<cantidad; i++)
    {

        historial=repoHistorial.leer(i);
        paciente=repoPaciente.leer(repoPaciente.buscarPorId(historial.getIdPaciente()));

        if(paciente.getEliminado()==false)
        {

            mostrarHistorial(historial);
            cout << "---------------------------------" << endl;
        }


    }


}



void HistorialManager::mostrarHistorial(Historial reg)
{

    Paciente paciente;
    PacienteArchivo repoPaciente;
    Medicos medico;
    MedicosArchivos repoMedico;



    int posMedico= repoMedico.buscarPorId(reg.getIdMedico());
    int posPaciente=repoPaciente.buscarPorId(reg.getIdPaciente());
    paciente=repoPaciente.leer(posPaciente);
    medico=repoMedico.leer(posMedico);


    cout << "ID historial : " << reg.getIdHistorial() << endl;
    cout << "Paciente : " << paciente.getNombre() << " " << paciente.getApellido() << endl;
    cout << "Medico : " << medico.getNombre() << " " << medico.getApellido() << endl;
    cout << "Fecha : " << reg.getFecha().toString() << endl;
    cout << "Diagnostico : " << reg.getDiagnostico() << endl;



}



void HistorialManager::listarPorPaciente()
{

    Paciente paciente;
    PacienteArchivo repoPaciente;
    Historial historial;
    Medicos medico;
    MedicosArchivos repoMedico;

    int cantidadPacientes = repoPaciente.getCantidadRegistros();
    int cantidadHistoriales = repoHistorial.getCantidadRegistros();

    for(int i=0; i<cantidadPacientes; i++)
    {

        paciente=repoPaciente.leer(i);
        bool tieneHistorial=false;

        if(paciente.getEliminado()==false)
        {

            for(int j=0; j<cantidadHistoriales; j++)
            {



                historial=repoHistorial.leer(j);



                if(historial.getIdPaciente()==paciente.getIdPaciente())
                {
                    if(tieneHistorial==false)
                    {
                        cout << "Paciente: " << paciente.getNombre() << " " << paciente.getApellido() << endl;
                        cout << "-------------------------------------" << endl;
                        tieneHistorial=true;

                    }

                    medico= repoMedico.leer(repoMedico.buscarPorId(historial.getIdMedico()));

                    cout << "Medico: " << medico.getNombre() << " " << medico.getApellido() << endl;
                    cout << "Especialidad: " << medico.getEspecialidad() << endl;
                    cout << "Fecha: " << historial.getFecha().toString() << endl;
                    cout << "--------------------------" << endl;
                    cout << historial.getDiagnostico() << endl;
                    cout << endl << endl;
                }



            }

            if(tieneHistorial==true)
            {
                cout << "--------------------------------------------------------------" << endl;
            }
        }



    }




}

void HistorialManager::listarPacienteHistorial()
{
    int posPacientes,cantHistorial;
    char dni[9];
    Paciente paciente;
    PacienteArchivo repoPaciente;
    Historial historial;
    Medicos medico;
    MedicosArchivos repoMedico;
    bool ingresar = true;


    do{
        system("cls");
        cout << "INGRESAR DNI PACIENTE A CONSULTAR: ";
        cargarCadena(dni,9);
        if(!dniValido(dni)){
            cout << "Dni invalido. Intente nuevamente..." << endl;
            system("pause");
        }

    }while(!dniValido(dni));


        posPacientes = repoPaciente.buscarPorDni(dni);

        if(posPacientes == -1)
        {
            cout << "DNI NO ENCONTRADO..." << endl;
            return;
        }
        else
        {

            paciente = repoPaciente.leer(posPacientes);

            cantHistorial = repoHistorial.getCantidadRegistros();

            for(int i=0; i<cantHistorial; i++)
            {

                if(paciente.getEliminado()==false)
                {
                    historial = repoHistorial.leer(i);
                    if(historial.getIdPaciente()==paciente.getIdPaciente())
                    {

                        cout << "Paciente: " << paciente.getNombre() << " " << paciente.getApellido() << endl;

                        medico= repoMedico.leer(repoMedico.buscarPorId(historial.getIdMedico()));

                        cout << "Medico: " << medico.getNombre() << " " << medico.getApellido() << endl;
                        cout << "Especialidad: " << medico.getEspecialidad() << endl;
                        cout << "Fecha: " << historial.getFecha().toString() << endl;
                        cout << "--------------------------" << endl;
                        cout << historial.getDiagnostico() << endl;
                        cout << endl << endl;
                        cout << "--------------------------------------------------------------" << endl;

                    }

                }

            }
        }



}




void HistorialManager::listarPorMedico()
{

    Historial historial;
    Paciente paciente;
    PacienteArchivo repoPaciente;
    Medicos medico;
    MedicosArchivos repoMedico;


    int cantidadMedicos= repoMedico.getCantidadRegistros();
    int cantidadHistoriales= repoHistorial.getCantidadRegistros();


    for(int i=0; i<cantidadMedicos; i++)
    {

        bool tieneHistorial=false;
        medico= repoMedico.leer(i);

        if(medico.getEliminado()==false)
        {

            for(int j=0; j<cantidadHistoriales; j++)
            {

                historial= repoHistorial.leer(j);

                if(medico.getIdMedico()==historial.getIdMedico())
                {

                    if(tieneHistorial==false)
                    {

                        cout << "Medico: " << medico.getNombre() << " " << medico.getApellido() << endl;
                        cout << "-------------------------------------" << endl;
                        tieneHistorial=true;

                    }

                    paciente= repoPaciente.leer(repoPaciente.buscarPorId(historial.getIdPaciente()));


                    cout << "Paciente: " << paciente.getNombre() << " " << paciente.getApellido() << endl;
                    cout << "Fecha: " << historial.getFecha().toString() << endl;
                    cout << "Diagnostico: " << historial.getDiagnostico() << endl;
                    cout << endl << endl;

                }


            }




        }
        if(tieneHistorial)
        {
            cout << "------------------------------------------------------------------" << endl;
        }



    }



}



void HistorialManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = repoHistorial.getCantidadRegistros();
    Historial *vec = new Historial[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al realizar backup" << endl;
        return;
    }

    repoHistorial.leer(vec, cantidadRegistros);
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



void HistorialManager::restaurarCopiaDeSeguridad()
{
    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Historial *vec = new Historial[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Error al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    repoHistorial.vaciar();
    if (repoHistorial.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Error al restaurar backup" << endl;
    }

    delete []vec;

}
