#include <iostream>
#include <cstdio>
#include "PacienteManager.h"

using namespace std;



void PacienteManager::altaPaciente(){
    char nombre[30], apellido[30], obraSocial[30],dni [12];
    Fecha fechaNacimiento;
    bool fechaValida;

    Paciente p;



    cout << "-------------------PACIENTES-------------------" << endl;
    cout << "Nombre: ";
    cin.getline(nombre,30);
    cout << "Apellido: ";
    cin.getline (apellido, 30);
    do{

    cout << "Fecha de nacimiento: " <<endl;
    fechaValida=fechaNacimiento.cargar();
    if(!fechaValida){
        cout << "Fecha invalida. Ingrese los datos nuevamente...";
        system("pause");
        system("cls");
    }
    }while(!fechaValida);
    cout << "DNI: ";
    cin.ignore();
    cin.getline (dni, 12);
    cout << "Obra Social: ";
    cin.getline (obraSocial, 30);


    p.setNombre(nombre);
    p.setApellido(apellido);
    p.setFechaNacimiento(fechaNacimiento);
//    p.setDni(dni);
    p.setObraSocial(obraSocial);
    p.setIdPaciente(repoPaciente.getCantidadRegistros()+1);
    p.setEliminado(false);

    if(repoPaciente.guardar(p)){
        cout << "Se guardo el paciente exitosamente!" << endl;
    }else{
        cout << "No se pudo guardar el paciente..." << endl;
    }





}


void PacienteManager::bajaPaciente(){
    Paciente reg;

    int id, pos;

    cout << "Ingrese el ID del paciente a dar de baja:";
    cin>>id;
    cout << endl;

    pos=repoPaciente.buscarPorId(id);

    if(pos==-1){
        cout << "El id ingresado no existe." << endl;
        return;
    }

    reg= repoPaciente.leer(pos);
    reg.setEliminado(true);

    bool eliminado=repoPaciente.modificar(reg,pos);

    if(eliminado){
        cout << "El paciente se ha dado de baja exitosamente." << endl;
    }else{
        cout << "No se pudo dar de baja el paciente." << endl;
    }



}


void PacienteManager::modificarPaciente(){
    char nombre[30], apellido[30], obraSocial[30];
    int dni;
    Fecha fechaNacimiento;
    bool fechaValida;
    int id, pos;

    Paciente p;
    PacienteArchivo repoPaciente;

    cout << "Ingrese el ID del paciente a modificar:";
    cin>>id;
    cout << endl;

    pos=repoPaciente.buscarPorId(id);

    if(pos==-1){
        cout << "El id ingresado no existe." << endl;
        return;
    }

    p= repoPaciente.leer(pos);


    int opcion;
    do{
        system("cls");

        cout << "-----------------------------" << endl;
        cout << "Seleccionar que campo desea cambiar:" << endl;
        cout << "1-Nombre" << endl;
        cout << "2-Apellido" << endl;
        cout << "3-Fecha nacimiento" << endl;
        cout << "4-DNI" << endl;
        cout << "5-Obra social" << endl;
        cout << "0-Guardar y salir" << endl;
        cout << "-----------------------------" << endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case 1:
                cout << "Nombre: ";
                cin.getline(nombre,30);
                p.setNombre(nombre);

                break;
            case 2:
                cout << "Apellido: ";
                cin.getline (apellido, 30);
                p.setApellido(apellido);
                break;
        case 3:
            do{

                cout << "Fecha de nacimiento: " <<endl;
                fechaValida=fechaNacimiento.cargar();
                if(!fechaValida){
                    cout << "Fecha invalida. Ingrese los datos nuevamente...";
                    system("pause");
                    system("cls");
                }
            }
            while(!fechaValida);
            p.setFechaNacimiento(fechaNacimiento);

            break;
            case 4:
                cout << "DNI: ";
                cin >> dni;
                p.setDni(dni);
                break;
            case 5:
                cout << "Obra Social: ";
                cin.getline (obraSocial, 30);
                p.setObraSocial(obraSocial);
                break;
            case 0:

                break;
            default:
                cout << "Opcion invalida... intente nuevamente" << endl;
                system("pause");
                break;




        }


    }while(opcion!=0);

    bool modificado=repoPaciente.modificar(p,pos);

    if(modificado){
        cout << "Los datos del paciente han sido modificados exitosamente" << endl;
    }else{
        cout << "No se ha podido modificar los datos del paciente." << endl;
    }

}


void PacienteManager::listarPacientes(){
    int cantidad= repoPaciente.getCantidadRegistros();
    Paciente reg;
    for(int i=0;i<cantidad; i++){
        reg=repoPaciente.leer(i);

        if(reg.getEliminado()!=true){

            mostrarPaciente(reg);
            cout << endl;
        }

    }


}
void PacienteManager::listarXId()//
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = repoPaciente.buscarPorId(id);
    if (posicion >= 0)
    {
        Paciente reg = repoPaciente.leer(posicion);
        mostrarPaciente(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}


void PacienteManager::mostrarPaciente(Paciente reg){

    cout << "ID: " << reg.getIdPaciente() <<endl;
    cout << "Nombre: " <<reg.getNombre()<< endl;
    cout << "Apellido: " <<reg.getApellido()<< endl;
    cout << "Fecha de nacimiento: "<< reg.getFechaNacimiento().getDia()
    << "/" << reg.getFechaNacimiento().getMes()
    << "/" << reg.getFechaNacimiento().getAnio() <<endl;
    cout << "DNI: " <<reg.getDni()<< endl;
    cout << "Obra social: " << reg.getObraSocial()<< endl;
    cout << "Estado: ";
    if(reg.getEliminado()){
        cout << "Inactivo" << endl;
    }else{
        cout << "Activo" << endl;
    }
}

void PacienteManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = repoPaciente.getCantidadRegistros();
    Paciente *vec = new Paciente[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    repoPaciente.leer(vec, cantidadRegistros);
    _archivoBkp.vaciar();
    if (_archivoBkp.guardar(vec, cantidadRegistros))
    {
        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete []vec;
}

void PacienteManager::restaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Paciente *vec = new Paciente[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    repoPaciente.vaciar();
    if (_archivoBkp.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}
