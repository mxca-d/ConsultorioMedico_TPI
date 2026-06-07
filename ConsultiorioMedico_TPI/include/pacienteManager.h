#pragma once
#include "paciente.h"
#include "pacienteArchivo.h"



class PacienteManager
{

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void listarPacientes();
    void mostrarPaciente(Paciente reg);
    void BuscarPorId();
    void listarPacientesPorApellido();
    void listarPacientesPorObraSocial();
    void listarPacientesPorDni();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    PacienteArchivo repoPaciente;
    PacienteArchivo _archivoBkp = PacienteArchivo("pacientes.bkp");

};
