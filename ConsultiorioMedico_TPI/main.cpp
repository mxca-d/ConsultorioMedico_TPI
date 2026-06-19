#include <iostream>
#include "app.h"
#include "usuariosManager.h"
#include "pacienteManager.h"

using namespace std;

int main()
{
    //App app;
    //app.run();

    PacienteManager managerPaciente;

    managerPaciente.altaPaciente();

    return 0;
}
