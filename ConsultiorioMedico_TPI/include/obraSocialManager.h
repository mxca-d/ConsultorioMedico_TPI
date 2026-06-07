#pragma once
#include "obrasSociales.h"
#include "obraSocialArchivo.h"



class ObraSocialManager
{

public:
    void altaObraSocial();
    void bajaObraSocial();
    void modificarObraSocial();
    void listarObrasSociales();
    void mostrarObraSocial(ObraSociales reg);
    void buscarObraSocialPorId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    ObraSocialArchivo repoObraSocial;
    ObraSocialArchivo _archivoBkp = ObraSocialArchivo("obraSocial.bkp");

};
