#pragma once
#include "arancelArchivo.h"
#include "arancel.h"
#include "obraSocialArchivo.h"


class arancelManager
{
public:
    void altaArancel();
    void bajaArancel();
    void modificarArancel();
    void listarAranceles();
    void mostrarArancel(Arancel reg);
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    int generarId();

private:

    ArancelArchivo _repoArancel;
    ArancelArchivo _archivoBkp = ArancelArchivo("aranceles.bkp");


};


