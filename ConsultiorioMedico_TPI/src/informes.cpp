#include <iostream>
#include <cstring>
#include "informes.h"
#include "medicosManager.h"
#include "turnoManager.h"
#include "fecha.h"

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

    int cantTurnos= repoTurno.getCantidadRegistros();
    int cantMedicos= repoMedico.getCantidadRegistros();

    for(int i=0;i<cantTurnos;i++){
        turno=repoTurno.leer(i);

        if(strcmp(turno.getEstado(),"ATENDIDO")==0
           && turno.getFechaTurno().getMes()==hoy.getMes()
           && turno.getFechaTurno().getAnio()==hoy.getAnio()){

            medico=repoMedico.leer(repoMedico.buscarPorId(turno.getIdMedico()));
            total+=medico.getHonorarios();
        }


    }

    cout << "El total recaudado durante el mes fue: $" <<total << endl;

}



void recaudacionPorObraSocial(){

    Turno turno;
    TurnoArchivo repoTurno;
    Fecha hoy;
    hoy.setHoy();
    float total=0;

    int cantTurnos= repoTurno.getCantidadRegistros();

    for(int i=0;i<cantTurnos;i++){
        if(strcmp(turno.getEstado(),"ATENDIDO")==0
           && turno.getFechaTurno().getMes()==hoy.getMes()
           && turno.getFechaTurno().getAnio()==hoy.getAnio()){
            total+=turno.getCostoConsulta();
        }

    }




}
