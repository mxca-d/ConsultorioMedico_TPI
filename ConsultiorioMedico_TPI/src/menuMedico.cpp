#include <iostream>
#include "MenuMedico.h"

using namespace std;

MenuMedico::MenuMedico()
{
    setCantidadOpciones(5);
}

void MenuMedico::mostrarOpciones()
{
    cout << "BIENVENIDO/A "<< _medico.getNombre() << " " << _medico.getApellido() << "!"<< endl;
    cout <<" TURNOS:                      " << endl;
    cout << "1- ATENDER TURNO"<<endl;
    cout << "2- CANCELAR TURNO"<<endl;
    cout << "3- CONSULTAR TURNO PENDIENTE"<<endl;
    cout << "HISTORIA CLINICA:                   "<< endl;
    cout << "4- CONSULTAR"<<endl;
    cout << "USUARIO:" << endl;
    cout << "5- CAMBIAR NOMBRE/CONTRASEÑA DE USUARIO" << endl;///pendiente modificacion en usuario
    cout << endl;
    cout << "0- SALIR"<<endl;
    cout << "------------------------"<<endl;
}

void MenuMedico::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:

        _managerTurno.atenderTurno();
        break;
    case 2:
        _managerTurno.cancelarTurno();
        break;
    case 3:
        _managerTurno.listarTurnoPendientePorMedico(_medico.getDni());
        break;
    case 4:
        _historialManager.listarPacienteHistorial();
        break;
    case 5:
        //_usuariosManager.modificar()///pendiente
        break;
    case 0:
        cout << "Saliendo.." << endl;
        break;
    default:
        cout << "OPCION INCORRECTA...";
    }
}

void MenuMedico::leerMedico(const char* dni){

    int idMedico= _managerMedico.recuperarIdMedico(dni);
    int pos=_repoMedico.buscarPorId(idMedico);


    if(pos!=-1){
        _medico= _repoMedico.leer(pos);

    }



}


