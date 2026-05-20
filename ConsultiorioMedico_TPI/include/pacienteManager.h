#pragma once
#include "paciente.h"
#include "pacienteArchivo.h"



class PacienteManager{

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void listarPacientes();
    void mostrarPaciente(Paciente reg);




private:
    PacienteArchivo repoPaciente;


};
