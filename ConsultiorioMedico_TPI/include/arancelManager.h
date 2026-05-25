#pragma once
#include "arancelArchivo.h"
#include "arancel.h"


class arancelManager
{
    public:
    void altaPaciente();
    void bajaPaciente();
    void modificarArancel();
    void listarAranceles();
    void mostrarArancel(Arancel reg);
    void listarXId();
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();


private:
    ArancelArchivo repoArancel;
    ArancelArchivo _archivoBkp = ArancelArchivo("aranceles.bkp");
};


