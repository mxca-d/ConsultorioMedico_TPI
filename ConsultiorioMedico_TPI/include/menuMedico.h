#pragma once
#include "menu.h"
#include "turnoManager.h"
#include "pacienteManager.h"
#include "usuariosManager.h"
#include "medicosArchivo.h"
#include "medicosManager.h"

class MenuMedico: public Menu {
public:
   MenuMedico();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;
   void leerMedico(const char* dni);

private:
    int _idMedico;
    Medicos _medico;
    MedicosArchivos _repoMedico;
    TurnoManager _managerTurno;
    PacienteManager _pacienteManager;
    HistorialManager _historialManager;
    UsuariosManager _usuariosManager;
    MedicosManager _managerMedico;
};
