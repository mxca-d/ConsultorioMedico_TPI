#pragma once
#include "obrasSociales.h"
#include "obraSocialArchivo.h"



class ObraSocialManager{

public:
    void altaPaciente();
    void bajaPaciente();
    void modificarPaciente();
    void listarPacientes();
    void mostrarPaciente(ObraSociales reg);
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    ObraSocialArchivo repoPaciente;
    ObraSocialArchivo _archivoBkp = ObraSocialArchivo("obraSocial.bkp");

};
