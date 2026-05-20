#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
#include "fecha.h"

class Turno{
private:
    int idTurno, idPaciente, idMedico;
    Fecha fechaTurno;
    char hora[5];
    char estado[15];
    bool eliminado;

public:
    Turno();
    void cargar();
    void mostrar();
    void setEliminado(bool e);
    void setIdTurno(int idt);
    void setEstado(char es[15]);

    const char* getHora();
    const char* getEstado();
    int getIdTurno();
    int getIdPaciente();
    int getIdMedico();
    bool getEliminado();



};

#endif // TURNO_H_INCLUDED

