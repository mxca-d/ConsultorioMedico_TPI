#include <iostream>
#include <cstring>
#include "informes.h"
#include "medicosManager.h"
#include "turnoManager.h"
#include "fecha.h"
#include "pacienteManager.h"

using namespace std;


void sueldosPorMedico(){

    MedicosArchivos repoMedico;
    TurnoArchivo repoTurno;
    Turno turno;
    Medicos medico;
    Fecha hoy;
    hoy.setHoy();

    int cantMedicos=repoMedico.getCantidadRegistros();
    int cantTurnos=repoTurno.getCantidadRegistros();

    for(int i=0;i<cantMedicos;i++){
        medico= repoMedico.leer(i);
        if(!medico.getEliminado()){

        float sueldo=0;

        for(int j=0;j<cantTurnos;j++){
            turno=repoTurno.leer(j);
            if(turno.getIdMedico()==medico.getIdMedico()
               && strcmp(turno.getEstado(),"ATENDIDO")==0
               && turno.getFechaTurno().getMes()==hoy.getMes()
               && turno.getFechaTurno().getAnio()==hoy.getAnio()){
                    sueldo+=medico.getHonorarios();

            }

        }

        cout << "-Medico: " << medico.getNombre() << " " << medico.getApellido() << " $" << sueldo << endl;
        }

    }




}



void recaudacionTotal(){

    Turno turno;
    TurnoArchivo repoTurno;
    Medicos medico;
    MedicosArchivos repoMedico;
    Fecha hoy;
    hoy.setHoy();
    float total=0;
    float abonadoPaciente=0;
    float cubiertoObraSocial=0;

    int cantTurnos= repoTurno.getCantidadRegistros();

    for(int i=0;i<cantTurnos;i++){
        turno=repoTurno.leer(i);

        if(strcmp(turno.getEstado(),"ATENDIDO")==0
           && turno.getFechaTurno().getMes()==hoy.getMes()
           && turno.getFechaTurno().getAnio()==hoy.getAnio()){

            medico=repoMedico.leer(repoMedico.buscarPorId(turno.getIdMedico()));
            total+=medico.getHonorarios();
            abonadoPaciente+=turno.getCostoConsulta();
            cubiertoObraSocial+=(medico.getHonorarios()-turno.getCostoConsulta());
        }


    }

    cout << "-------------RECAUDACION TOTAL DEL MES-------------" << endl;
    cout << "Total recaudado: $" <<total << endl;
    cout << "Cubierto por obras sociales: $" << cubiertoObraSocial << endl;
    cout << "Abonado por pacientes: $" << abonadoPaciente << endl;

}



void recaudacionPorObraSocial(){

    Turno turno;
    TurnoArchivo repoTurno;
    ObraSociales os;
    ObraSocialArchivo repoObraSocial;
    Paciente paciente;
    PacienteArchivo repoPaciente;
    Fecha hoy;
    hoy.setHoy();

    int cantTurnos= repoTurno.getCantidadRegistros();
    int cantOS= repoObraSocial.getCantidadRegistros();

    for(int i=0;i<cantOS;i++){
        os=repoObraSocial.leer(i);
        float total=0;
        if(!os.getEliminado()){

        for(int j=0;j<cantTurnos;j++){
            turno=repoTurno.leer(j);
            paciente=repoPaciente.leer(repoPaciente.buscarPorId(turno.getIdPaciente()));

            if(strcmp(turno.getEstado(),"ATENDIDO")==0
                && paciente.getIdObraSocial()== os.getIdObraSocial()
                && turno.getFechaTurno().getMes()==hoy.getMes()
                && turno.getFechaTurno().getAnio()==hoy.getAnio()){
                total+=turno.getCostoConsulta();
            }

        }
        cout << os.getNombre() << ": $" << total << endl;
        }
    }






}
