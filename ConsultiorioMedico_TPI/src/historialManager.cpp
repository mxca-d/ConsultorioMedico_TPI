#include <iostream>
#include "historialManager.h"
using namespace std;

/*void HistorialManager::cargarHistorial(){

    int idPaciente,idMedico,idTurno, posTurno;
    char diagnostico[100];

    Fecha fecha;
    TurnoManager managerTurno;
    Turno turno;
    TurnoArchivo repoTurno;
    Historial historial;
    PacienteArchivo repoPaciente;
    Paciente paciente;
    Medicos medico;
    MedicosArchivos repoMedico;

    fecha.setHoy();

    cout << "------------HISTORIAL------------" << endl;
    cout << "Ingrese ID del turno:" <<endl;// O BUSCAR POR DNI
    cin>>idTurno;
    cout << "Ingrese ID del medico:" <<endl;// O BUSCAR POR DNI
    cin>>idMedico;

    posTurno=repoTurno.buscarPorId(idTurno);
    if(posTurno==-1){
        cout << "El turno ingresado no existe" << endl;
        return;
    }

    turno=repoTurno.leer(posTurno);
    idPaciente=turno.getIdPaciente();
    if(turno.getIdMedico()!=idMedico){
        cout << "El turno ingresado no corresponde al medico" << endl;
        return;
    }

    if(turno.getEstado()== "CANCELADO"){
        cout << "Este turno fue cancelado" << endl;
        return;
    }else if(turno.getEstado()=="ATENDIDO"){
        cout << "Este turno ya fue atendido" << endl;
        return;
    }

    int posPaciente= repoPaciente.buscarPorId(idPaciente);
    int posMedico= repoMedico.buscarPorId(idMedico);

    if(posPaciente == -1){
        cout << "El paciente asociado al turno no existe." << endl;
        return;
    }

    if(posMedico == -1){
        cout << "El medico asociado al turno no existe." << endl;
        return;
    }

    paciente=repoPaciente.leer(posPaciente);
    medico=repoMedico.leer(posMedico);

    cout << "Paciente : " << paciente.getNombre()<< " " << paciente.getApellido() << endl;
    cout << "Medico :" << medico.getNombre()<< " " << medico.getApellido() << endl;
    cout << "Fecha :" <<turno.getFechaTurno().toString() <<endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Ingresar diagnostico:" << endl << endl;
    cin.ignore();
    bool diagnosticoValido;
    do{

        cin.getline(diagnostico,100);
        diagnosticoValido=validacionCaracteres(diagnostico,100);
    }while(!diagnosticoValido);

    todoMayuscula(diagnostico);

    historial.setDiagnostico(diagnostico);
    historial.setEliminado(false);
    historial.setFecha(turno.getFechaTurno());
    historial.setIdHistorial(repoHistorial.getCantidadRegistros()+1);
    historial.setIdMedico(idMedico);
    historial.setIdPaciente(idPaciente);
    historial.setIdTurno(idTurno);

    if(repoHistorial.guardar(historial)){

    turno.setEstado("ATENDIDO");

    if(repoTurno.modificar(turno,posTurno)){
        cout << "El historial se ha guardado exitosamente." << endl;
    }else{
        cout << "El historial se guardo existosamente pero no se pudo modificar el turno" << endl;
    }
    }else{
        cout << "No se ha podido guardar el historial." << endl;
    }




}*/



// SI TURNO VALIDA TODO, EL ALTA DEBERIA DEVOLVER BOOL Y RECIBIR POR PARAMETRO LOS DATOS DE TURNO, MEDICO Y PACIENTE
bool HistorialManager::cargarHistorial(Turno turno, Medicos medico, Paciente paciente){

    char diagnostico[100];
    Historial historial;

    int idPaciente = turno.getIdPaciente();
    int idMedico = turno.getIdMedico();
    int idTurno = turno.getIdTurno();


    cout << "Paciente : " << paciente.getNombre()<< " " << paciente.getApellido() << endl;
    cout << "Medico :" << medico.getNombre()<< " " << medico.getApellido() << endl;
    cout << "Fecha :" <<turno.getFechaTurno().toString() <<endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Ingresar diagnostico:" << endl << endl;
    cin.ignore();
    bool diagnosticoValido;
    do{

        cin.getline(diagnostico,100);
        diagnosticoValido=validacionCaracteres(diagnostico,100);
    }while(!diagnosticoValido);

    todoMayuscula(diagnostico);

    historial.setDiagnostico(diagnostico);
    historial.setEliminado(false);
    historial.setFecha(turno.getFechaTurno());
    historial.setIdHistorial(repoHistorial.getCantidadRegistros()+1);
    historial.setIdMedico(idMedico);
    historial.setIdPaciente(idPaciente);
    historial.setIdTurno(idTurno);

    if(repoHistorial.guardar(historial)){
        cout << "El historial se ha guardado exitosamente." << endl;
    }else{
        cout << "No se ha podido guardar el historial." << endl;
    }




}



void HistorialManager::bajaHistorial();//se deberia dar de baja un historial{






void HistorialManager::modificarHistorial(){

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

    if(posHistorial==-1){
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
    cin.ignore();
    bool diagnosticoValido;
    do{

        cin.getline(diagnostico,100);
        diagnosticoValido=validacionCaracteres(diagnostico,100);
    }while(!diagnosticoValido);

    todoMayuscula(diagnostico);

    historial.setDiagnostico(diagnostico);

    if(repoHistorial.modificar(historial,posHistorial)){
        cout << "El historial se ha modificado exitosamente." << endl;
    }else{
        cout << "No se ha podido modificar el historial." << endl;
    }

}



void HistorialManager::listarHistoriales(){
    Historial historial;

    int cantidad = repoHistorial.getCantidadRegistros();


    for(int i=0;i<cantidad;i++){

        historial=repoHistorial.leer(i);
        mostrarHistorial(historial);
        cout << "---------------------------------" << endl;



    }


}



void HistorialManager::mostrarHistorial(Historial reg){

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



void HistorialManager::listarPorPaciente(){

    Paciente paciente;
    PacienteArchivo repoPaciente;

    int cantidad = repoPaciente.getCantidadRegistros();




}


void HistorialManager::listarPorMedico(){


}



void HistorialManager::hacerCopiaDeSeguridad(){


}



void HistorialManager::restaurarCopiaDeSeguridad(){


}
