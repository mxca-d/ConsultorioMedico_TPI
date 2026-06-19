#pragma once
#include "arancelArchivo.h"
#include "arancel.h"
#include "obraSocialManager.h"


class arancelManager
{
public:
    void altaArancel();
    void bajaArancel();
    void modificarArancel();
    void listarAranceles();
    void mostrarArancel(Arancel reg);
    void listarPorId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    int generarId();

private:

    ArancelArchivo _repoArancel;
    ArancelArchivo _archivoBkp = ArancelArchivo("aranceles.bkp");
    ObraSocialManager managerObraSocial;
    ObraSocialArchivo repoObraSocial;


};


