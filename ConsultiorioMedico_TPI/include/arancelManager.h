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
    void listarAranceles();///CAMBIO MODIFICAR ARANCELES-PLURAL
    void mostrarArancel(Arancel reg);
    void listarPorId();///CAMBIO X = POR
    void hacerCopiaDeSeguridad();
    void restaurarCopiaDeSeguridad();

    int generarId();///AGREGAMOS UN METODO

private:

    ArancelArchivo _repoArancel;
    ArancelArchivo _archivoBkp = ArancelArchivo("aranceles.bkp");


};


