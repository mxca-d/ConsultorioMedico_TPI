#include <iostream>
#include <cstdio>
#include "PacienteManager.h"
#include <cstring>
#include "utils.h"

using namespace std;



void PacienteManager::altaPaciente()
{
    char nombre[30], apellido[30],email[30],domicilio[30],telefono[15], obraSocial[30],dni [9];
    Fecha fechaNacimiento, hoy;
    hoy.setHoy();
    bool fechaValida, valido;
    int opcionObraSocial;

    Paciente p;



    cout << "-------------------PACIENTES-------------------" << endl;
    cout << "INGRESE 0 PARA CANCELAR LA OPERACION..." << endl <<endl;
    do
    {

        valido=true;
        cout << "Nombre: ";
        valido=cargarCadena(nombre,30);
        if(cancelacionUsuario(nombre))
        {
            system("pause");
            return;
        }
        if(!soloLetras(nombre))
        {
            valido=false;

        }
        if(!valido)
        {
            cout << "Nombre invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
        else
        {
            valido=true;
        }
    }
    while(!valido);

    todoMayuscula(nombre);
    p.setNombre(nombre);

    do
    {
        valido=true;
        cout << "Apellido: ";
        valido=cargarCadena(apellido,30);
        if(cancelacionUsuario(apellido))
        {
            system("pause");
            return;
        }

        if(!soloLetras(apellido))
        {
            valido=false;
        }
        if(!valido)
        {
            cout << "Apellido invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
    }
    while(!valido);

    todoMayuscula(apellido);
    p.setApellido(apellido);


    do
    {
        fechaValida=true;
        cout << "Fecha de nacimiento: " <<endl;
        fechaValida=fechaNacimiento.cargar();
        if(!fechaValida)
        {
            cout << "Fecha invalida. Vuelva a intentarlo..."<< endl;
            system("pause");

        }
        else if(!fechaNacimiento.esMenor(hoy))
        {
            cout << "Fecha invalida. Vuelva a intentarlo..."<< endl;
            fechaValida=false;
            system("pause");
        }

    }
    while(!fechaValida);

    p.setFechaNacimiento(fechaNacimiento);

    do
    {
        valido = true;
        cout << "DNI: ";
        valido=cargarCadena(dni,9);
        if(cancelacionUsuario(dni))
        {
            system("pause");
            return;
        }
        if(!dniValido(dni))
        {
            valido=false;
        }
        if(!valido)
        {
            cout << "DNI invalido. Vuelva a intentarlo..."<< endl;
            valido=false;
            system("pause");
        }
        else if(repoPaciente.buscarCoincidenciaDni(dni))
        {
            cout << "Ya existe un paciente con ese DNI..." << endl;
            system("pause");
            valido=false;
        }


    }
    while(!valido);

    p.setDni(dni);

    do
    {
        valido = true;
        cout << "Domicilio: ";
        valido=cargarCadena(domicilio,30);
        if(cancelacionUsuario(domicilio))
        {
            system("pause");
            return;
        }
        if(!letrasYNumeros(domicilio))
        {
            valido=false;
        }
        if(!valido)
        {
            cout << "Domicilio invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
    }
    while(!valido);

    todoMayuscula(domicilio);
    p.setDomicilio(domicilio);

    do
    {
        valido = true;
        cout << "Telefono: ";
        valido=cargarCadena(telefono,15);
        if(cancelacionUsuario(telefono))
        {
            system("pause");
            return;
        }
        if(!soloNumeros(telefono))
        {
            valido=false;
        }

        if(!valido)
        {
            cout << "Telefono invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
    }
    while(!valido);

    p.setTelefono(telefono);

    do
    {
        valido = true;
        cout << "Email: ";
        valido=cargarCadena(email,30);
        if(cancelacionUsuario(email))
        {
            system("pause");
            return;
        }
        cout << endl;
        if(!valido)
        {
            cout << "Email invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
    }
    while(!valido);

    todoMayuscula(email);
    p.setEmail(email);


    do
    {
        valido=true;
        cout << "Obra Social: ";
        managerObraSocial.listarObrasSociales();
        cout << "Ingresar ID de la obra social a la que pertenezca:" << endl;
        cin>> opcionObraSocial;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');

        }
        if(cancelacionUsuario(opcionObraSocial))
        {
            system("pause");
            return;
        }
        if(!repoObraSocial.buscarCoincidenciaId(opcionObraSocial))
        {
            valido=false;
            cout << "ID invalido. Vuelva a intentarlo..."<< endl;
            system("pause");
        }
    }
    while(!valido);

    regObraSocial=repoObraSocial.leer(repoObraSocial.buscarPorId(opcionObraSocial));

    p.setIdObrasocial(opcionObraSocial);
    p.setObraSocial(regObraSocial.getNombre());

    cout << endl <<endl;

    p.setIdPaciente(repoPaciente.getCantidadRegistros()+101);
    p.setEliminado(false);

    if(repoPaciente.guardar(p))
    {
        cout << "Se guardo el paciente exitosamente!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el paciente..." << endl;
    }


}


void PacienteManager::bajaPaciente()
{
    Paciente reg;
    char dni[9];
    bool valido;

    int pos;
    do
    {
        system("cls");
        valido=true;
        cout << "Ingrese el DNI del paciente a dar de baja:";
        valido=cargarCadena(dni,9);
        if(!dniValido(dni))
        {
            valido=false;
        }
        if(!valido)
        {
            cout << "DNI invalido. Vuelva a intentar..." << endl;
            system("pause");
        }

    }
    while(!valido);

    cout << endl;

    pos=repoPaciente.buscarPorDni(dni);

    if(pos==-1)
    {
        cout << "El DNI ingresado no existe." << endl;
        return;
    }

    reg= repoPaciente.leer(pos);
    reg.setEliminado(true);

    bool eliminado=repoPaciente.modificar(reg,pos);

    if(eliminado)
    {
        cout << "El paciente se ha dado de baja exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo dar de baja el paciente." << endl;
    }



}


void PacienteManager::modificarPaciente()
{
    char nombre[30], apellido[30],email[30],domicilio[30],telefono[15], obraSocial[30],dni [9];
    Fecha fechaNacimiento, hoy;
    bool fechaValida;
    int pos, opcionObraSocial;
    char dniBusqueda[9];
    bool valido;
    hoy.setHoy();

    Paciente p;
    PacienteArchivo repoPaciente;

    cout << "Ingrese el DNI del paciente a modificar:";
    cin>>dniBusqueda;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');

    }
    cout << endl;

    pos=repoPaciente.buscarPorDni(dniBusqueda);

    if(pos==-1)
    {
        cout << "El DNI ingresado no existe." << endl;
        return;
    }

    p= repoPaciente.leer(pos);

    mostrarPaciente(p);

    int opcion;
    do
    {

        cout << "-----------------------------" << endl;
        cout << "Seleccionar que campo desea cambiar:" << endl;
        cout << "1-Nombre" << endl;
        cout << "2-Apellido" << endl;
        cout << "3-Fecha nacimiento" << endl;
        cout << "4-DNI" << endl;
        cout << "5-Domicilio" << endl;
        cout << "6-Telefono" << endl;
        cout << "7-Email" << endl;
        cout << "8-Obra social" << endl;
        cout << "9-Estado" << endl;
        cout << "10-Cancelar" << endl;
        cout << "0-Guardar y salir" << endl;
        cout << "-----------------------------" << endl;
        cin>>opcion;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');

        }
        switch(opcion)
        {
        case 1:
            do
            {
                system("cls");
                valido=true;
                cout << "Nombre: ";
                valido=cargarCadena(nombre,30);

                if(!soloLetras(nombre))
                {
                    valido=false;
                }
                if(!valido)
                {
                    cout << "Nombre invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }
            while(!valido);

            todoMayuscula(nombre);
            p.setNombre(nombre);

            break;
        case 2:
            do
            {
                system("cls");
                valido=true;
                cout << "Apellido: ";
                valido=cargarCadena(apellido,30);

                if(!soloLetras(apellido))
                {
                    valido=false;
                }
                if(!valido)
                {
                    cout << "Apellido invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }
            while(!valido);

            todoMayuscula(apellido);
            p.setApellido(apellido);

            break;
        case 3:
            do
            {
                fechaValida=true;
                cout << "Fecha de nacimiento: " <<endl;
                fechaValida=fechaNacimiento.cargar();
                if(!fechaValida || !fechaNacimiento.esMenor(hoy))
                {
                    cout << "Fecha invalida. Ingrese los datos nuevamente...";
                    system("pause");
                    system("cls");
                }
            }
            while(!fechaValida);

            p.setFechaNacimiento(fechaNacimiento);

            break;
        case 4:
            do
            {
                valido = true;

                system("cls");
                cout << "DNI: ";
                valido=cargarCadena(dni,9);

                if(!dniValido(dni))
                {
                    cout << "DNI invalido. Vuelva a intentarlo..." << endl;
                    system("pause");
                    valido = false;
                }
                else if(strcmp(dni, p.getDni()) != 0 &&
                        repoPaciente.buscarCoincidenciaDni(dni))
                {
                    cout << "Ya existe un paciente con este DNI." << endl;
                    system("pause");
                    valido = false;
                }

            }
            while(!valido);

            p.setDni(dni);

            break;
        case 5:
            do
            {
                system("cls");
                valido = true;
                cout << "Domicilio: ";
                valido=cargarCadena(domicilio,30);

                if(!letrasYNumeros(domicilio))
                {
                    valido=false;
                }
                if(!valido)
                {
                    cout << "Domicilio invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }
            while(!valido);

            todoMayuscula(domicilio);
            p.setDomicilio(domicilio);

            break;
        case 6:
            do
            {
                system("cls");
                valido = true;
                cout << "Telefono: ";
                valido=cargarCadena(telefono,15);

                if(!soloNumeros(telefono))
                {
                    valido=false;
                }
                if(!valido)
                {
                    cout << "Telefono invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }
            while(!valido);

            p.setTelefono(telefono);
            break;

        case 7:
            do
            {
                system("cls");
                valido = true;
                cout << "Email: ";
                valido=cargarCadena(email,30);

                if(!valido)
                {
                    cout << "Email invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }
            while(!valido);
            todoMayuscula(email);
            p.setEmail(email);
            break;

        case 8:
            do
            {
                system("cls");
                valido = true;
                cout << "Obra Social: ";
                managerObraSocial.listarObrasSociales();
                cout << "Ingresar ID de la obra social a la que pertenezca:" << endl;
                cin>> opcionObraSocial;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000,'\n');

                }
                if(!repoObraSocial.buscarCoincidenciaId(opcionObraSocial))
                {
                    cout << "ID invalido. Vuelva a intentarlo..."<< endl;
                    valido=false;
                    system("pause");
                }
            }
            while(!valido);

            regObraSocial=repoObraSocial.leer(repoObraSocial.buscarPorId(opcionObraSocial));

            p.setIdObrasocial(opcionObraSocial);
            p.setObraSocial(regObraSocial.getNombre());

            break;

        case 9:
        {
            int seleccion;
            cout << "El estado actual es ";
            if(p.getEliminado())
            {
                cout << "Inactivo." << endl;
                do
                {
                    valido=true;
                    cout <<"Desea activarlo nuevamente? 1.SI/2.NO" << endl;

                    cin>>seleccion;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000,'\n');
                        valido = false;
                    }

                }
                while(seleccion!=1 && seleccion!=2 && !valido);

                if(seleccion==2)
                {
                    cout << "OPERACION CANCELADA..."<< endl;
                    system("pause");
                    return;
                }
                else
                {
                    p.setEliminado(false);
                }

            }
            else
            {
                cout << "Activo. No se aceptan modificaciones." << endl;
            }

            system("pause");

            break;
        }
        case 10:
            cout << "MODIFICACION CANCELADA...." << endl;
            cout << "NO SE GUARDARON CAMBIOS... " << endl;
            return;

        case 0:
            break;

        default:
            cout << "Opcion invalida... intente nuevamente" << endl;
            system("pause");
            break;




        }


    }
    while(opcion!=0);

    bool modificado=repoPaciente.modificar(p,pos);

    if(modificado)
    {
        cout << "Los datos del paciente han sido modificados exitosamente" << endl;
    }
    else
    {
        cout << "No se ha podido modificar los datos del paciente." << endl;
    }

}


void PacienteManager::listarPacientes()
{
    int cantidad= repoPaciente.getCantidadRegistros();
    Paciente reg;
    for(int i=0; i<cantidad; i++)
    {
        reg=repoPaciente.leer(i);

        if(reg.getEliminado()!=true)
        {

            mostrarPaciente(reg);
            cout << endl;
        }

    }


}
void PacienteManager::BuscarPorId()
{
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');

    }
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

void PacienteManager::BuscarPorDni()
{
    char dni[9];
    bool valido;
    do
    {
        valido = true;
        cout << "Ingrese el DNI: ";
        cargarCadena(dni,9);
        if(!dniValido(dni))
        {
            valido=false;
        }
        if(!valido)
        {
            cout << "DNI invalido. Intente nuevamente..." << endl;
        }

    }
    while(!valido);

    int posicion = repoPaciente.buscarPorDni(dni);
    if (posicion >= 0)
    {
        Paciente reg = repoPaciente.leer(posicion);
        mostrarPaciente(reg);
    }
    else
    {
        cout << "No existe el registro con DNI #" << dni << endl;
    }
}


void PacienteManager::listarPacientesPorApellido()
{
    Paciente reg;

    int cantidadActivos= repoPaciente.getCantidadActivos();
    int cantidadTotal= repoPaciente.getCantidadRegistros();

    Paciente *pacientesOrdenados;
    pacientesOrdenados= new Paciente [cantidadActivos];

    int posPacientesOrdenados =0;

    for(int i=0; i<cantidadTotal; i++)
    {

        reg= repoPaciente.leer(i);

        if(reg.getEliminado()==false)
        {

            pacientesOrdenados[posPacientesOrdenados]=reg;
            posPacientesOrdenados++;

        }

    }



    Paciente aux;


    for(int i=0; i <cantidadActivos-1; i++)
    {

        for (int j=i+1; j<cantidadActivos; j++)
        {

            if(strcmp(pacientesOrdenados[i].getApellido(),pacientesOrdenados[j].getApellido())>0) //evalua valor A-Z con ASCII
            {

                aux=pacientesOrdenados[i];
                pacientesOrdenados[i]=pacientesOrdenados[j];
                pacientesOrdenados[j]=aux;

            }

        }

    }

    for(int i=0; i<cantidadActivos; i++)
    {

        mostrarPaciente(pacientesOrdenados[i]);
        cout << endl;

    }

    delete[] pacientesOrdenados;

}


void PacienteManager::listarPacientesPorObraSocial()
{

    Paciente reg;
    int cantidadActivos= repoPaciente.getCantidadActivos();
    int cantidadTotal= repoPaciente.getCantidadRegistros();

    Paciente *pacientesOrdenados;

    pacientesOrdenados= new Paciente [cantidadActivos];

    int posPacientesOrdenados=0;

    for(int i=0; i<cantidadTotal; i++)
    {

        reg=repoPaciente.leer(i);

        if(reg.getEliminado()==false)
        {

            pacientesOrdenados[posPacientesOrdenados]=reg;
            posPacientesOrdenados++;

        }

    }


    Paciente aux;


    for(int i=0; i<cantidadActivos-1; i++)
    {


        for(int j=i+1; j<cantidadActivos; j++)
        {

            if(strcmp(pacientesOrdenados[i].getObraSocial(),pacientesOrdenados[j].getObraSocial())>0)
            {
                aux=pacientesOrdenados[i];
                pacientesOrdenados[i]=pacientesOrdenados[j];
                pacientesOrdenados[j]=aux;

            }

        }


    }

    for(int i=0; i<cantidadActivos; i++)
    {

        mostrarPaciente(pacientesOrdenados[i]);
        cout << endl;
    }


    delete[] pacientesOrdenados;

}


void PacienteManager::listarPacientesPorDni()
{

    Paciente reg;
    int cantidadActivos = repoPaciente.getCantidadActivos();
    int cantidadTotal= repoPaciente.getCantidadRegistros();

    Paciente *pacientesOrdenados;

    pacientesOrdenados= new Paciente [cantidadActivos];

    int posPacientesOrdenados=0;

    for(int i=0; i<cantidadTotal; i++)
    {

        reg=repoPaciente.leer(i);

        if(reg.getEliminado()==false)
        {

            pacientesOrdenados[posPacientesOrdenados]=reg;
            posPacientesOrdenados++;

        }




    }

    Paciente aux;


    for(int i=0; i<cantidadActivos-1; i++)
    {

        for(int j=i+1; j<cantidadActivos; j++)
        {

            if(strcmp(pacientesOrdenados[i].getDni(),pacientesOrdenados[j].getDni())>0)
            {

                aux= pacientesOrdenados[i];
                pacientesOrdenados[i]=pacientesOrdenados[j];
                pacientesOrdenados[j]=aux;

            }

        }
    }



    for(int i=0; i<cantidadActivos; i++)
    {

        mostrarPaciente(pacientesOrdenados[i]);
        cout << endl;


    }

    delete [] pacientesOrdenados;


}






void PacienteManager::mostrarPaciente(Paciente reg)
{
    ObraSocialArchivo repoObraSocial;
    ObraSociales os;
    os=repoObraSocial.leer(repoObraSocial.buscarPorId(reg.getIdObraSocial()));

    cout << "ID: " << reg.getIdPaciente() <<endl;
    cout << "Nombre: " <<reg.getNombre()<< endl;
    cout << "Apellido: " <<reg.getApellido()<< endl;
    cout << "Fecha de nacimiento: ";
    reg.getFechaNacimiento().mostrar();
    cout << endl;
    cout << "DNI: " <<reg.getDni()<< endl;
    cout << "Domicilio: " << reg.getDomicilio() << endl;
    cout << "Telefono: " << reg.getTelefono() << endl;
    cout << "Email: " << reg.getEmail() << endl;
    cout << "Obra social: " << os.getNombre()<< endl;
    cout << "Estado: ";
    if(reg.getEliminado())
    {
        cout << "Inactivo" << endl;
    }
    else
    {
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
    if (repoPaciente.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}

