#pragma once
#include "fecha.h"


class Historial
{
    public:
        Historial();
        int getIdHistorial();
        int getIdPaciente();
        int getIdMedico();
        int getIdTurno();
        char* getDiagnostico();
        Fecha getFecha();
        bool getEliminado();


        void setIdHistorial(int id);
        void setIdPaciente(int id);
        void setIdMedico(int id);
        void setIdTurno(int id);
        void setDiagnostico(const char *diagnostico);
        void setFecha(Fecha fecha);
        void setEliminado(bool eliminado);


    private:
        int _idHistorial;
        int _idPaciente;
        int _idMedico;
        int _idTurno;
        char _diagnostico[100];
        Fecha _fecha;
        bool _eliminado;
};


