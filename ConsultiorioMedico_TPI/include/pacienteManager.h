#pragma once
#include "paciente.h"
#include "pacienteArchivo.h"
#include "obraSocialManager.h"



class PacienteManager
{

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void listarPacientes();
    void mostrarPaciente(Paciente reg);
    void BuscarPorId();
    void BuscarPorDni();
    void listarPacientesPorApellido();
    void listarPacientesPorObraSocial();
    void listarPacientesPorDni();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    PacienteArchivo repoPaciente;
    PacienteArchivo _archivoBkp = PacienteArchivo("pacientes.bkp");
    ObraSocialArchivo repoObraSocial;
    ObraSociales regObraSocial;
    ObraSocialManager managerObraSocial;

};
