#include <iostream>
#include <cstring>
#include "turnoManager.h"
#include "pacienteArchivo.h"
#include "medicosManager.h"
#include "utils.h"

using namespace std;



void TurnoManager::altaTurno() ///ALTA TURNO NUEVO- A CHEQUEAR
{

    char dniPaciente[9], especialidad[30];
    int  idMedico, posMed,seleccion, posArancel, posPas,opcionEspecialidad, opcionTurno, cantidadOpciones;
    float costoConsulta;
    Medicos medico;
    Paciente paciente;
    Arancel arancel;
    Turno turno;
    Turno opciones[50];
    bool valido;



    cout << "-------------------Turno-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;


    do{
        valido=true;
        cout << "DNI paciente:  ";

        cargarCadena(dniPaciente,9);
        if (cancelacionUsuario(dniPaciente)){
            system("pause");
            return;
        }

        if(!dniValido(dniPaciente)){
            cout << "DNI invalido. Intente nuevamente..." << endl;
            valido=false;
        }else{
            posPas= _repoPaciente.buscarPorDni(dniPaciente);
            if (posPas==-1){
            cout << "DNI NO ENCONTRADO..." << endl;
            valido = false;

            }
        }

    }while(!valido);


    paciente = _repoPaciente.leer(posPas);

    do
    {
        valido = true;
        mostrarEspecialidades();
        cout << "Ingrese especilidad que desea: " ;
        cin>>opcionEspecialidad;
        if (cancelacionUsuario(opcionEspecialidad)){
            system("pause");
            return;
        }

        if (opcionEspecialidad>0 &&opcionEspecialidad<6)
        {
            valido=true;
        }
        else
        {
            cout << "Opcion incorrecta. Intente nuevamente..." ;
            valido=false;
            system("pause");
        }


    }
    while(!valido);


    cargarEspecialidad(opcionEspecialidad,especialidad);


    do
    {
        system("cls");
        _managerMedico.listarMedicoEspecialidad(especialidad);
        system("pause");
        cout << "Seleccionar ID medico:  ";
        cin >> idMedico;

        if (cancelacionUsuario(idMedico)){
            system("pause");
            return;
        }

        if (_repoMedico.buscarCoincidenciaId(idMedico)){
            posMed=_repoMedico.buscarPorId(idMedico);
            medico = _repoMedico.leer(posMed);

            cantidadOpciones = turnosDisponiblesPorMedico(medico,opciones);


            if(cantidadOpciones==0)
            {
                cout << "NO HAY TURNOS DISPONIBLES CON EL MEDICO " << medico.getNombre() << " " << medico.getApellido() << endl;
                valido=false;
            }
            else
            {
                valido=true;
            }
        }else{
            cout << "INGRESO INVALIDO...."<< endl;
            valido = false;
        }

    }
    while (!valido);

    do
    {
        cout << "Seleccione el turno que desea dar de alta:";
        cin>>opcionTurno;

        if (cancelacionUsuario(opcionTurno)){
            system("pause");
            return;
        }

        if(opcionTurno < 1 || opcionTurno > cantidadOpciones)
        {
            cout << "OPCION INVALIDA. INTENTE NUEVAMENTE..." << endl;
            system("pause");
        }

    }
    while(opcionTurno < 1 || opcionTurno > cantidadOpciones);



    posArancel = _repoArancel.buscarPorIdObraSocial(paciente.getIdObraSocial()); ///REVISAR ARANCEL
    if (posArancel >= 0)
    {
        arancel = _repoArancel.leer(posArancel);

    }
    float descArancel = medico.getHonorarios() *arancel.getCobertura() /100;
    costoConsulta = medico.getHonorarios() - descArancel;

    turno = opciones[opcionTurno-1];
    turno.setIdPaciente(paciente.getIdPaciente());
    turno.setDniPaciente(dniPaciente);
    turno.setCostoConsulta(costoConsulta);
    turno.setEliminado(false);
    turno.setEstado("PENDIENTE");
    turno.setIdTurno(generarId());


    do
    {
        system("cls");
        mostrarTurno(turno);
        cout <<"CONFIRMAR TURNO? 1.SI/2.NO" << endl;
        cin >>seleccion;
        if (cancelacionUsuario(seleccion)){
            system("pause");
            return;
        }

    }
    while(seleccion!=1 && seleccion!=2);

    if(seleccion==2)
    {
        cout << "OPERACION CANCELADA..."<< endl;
        system("pause");
        return;
    }
    else
    {

        if(_repoTurno.guardar(turno))
        {
            cout << "TURNO REGISTRADO CORRECTAMENTE." << endl;
        }
        else
        {
            cout << "ERROR AL GUARDAR EL TURNO." << endl;
        }

    }


}



void TurnoManager::cancelarTurno()
{
    Turno turno;
    bool valido;
    char dni[9];
    int  pos, opcion;


    cout << " INGRESE 0 (CERO) PARA CANCELAR LA OPERACION..." << endl << endl;

    do
    {
        system("cls");
        valido=true;
        cout << "DNI paciente:  ";

        cargarCadena(dni,9);
        if (cancelacionUsuario(dni))
        {
            system("pause");
            return;
        }

        if(!dniValido(dni))
        {
            cout << "DNI invalido. Intente nuevamente..." << endl;
            system("pause");
            valido=false;
        }
        else
        {
            pos= _repoTurno.buscarPorDni(dni);
            if (pos==-1)
            {
                cout << "El DNI ingresado no posee turnos pendientes..." << endl;
                system("pause");
                return;

            }
        }

    }while(!valido);

    turno = _repoTurno.leer(pos);


    do
    {
        valido=true;
        system("cls");
        mostrarTurno (turno);
        cout << "DESEA ELIMINAR EL TURNO? 1.SI/2.NO " << endl;
        cin >> opcion;
        if (cancelacionUsuario(opcion))
        {
            system("pause");
            return;
        }

        if (opcion == 1)
        {

            turno.setEliminado(true);
            turno.setEstado ("CANCELADO");
            bool eliminado= _repoTurno.modificar(turno,pos);

            if(eliminado)
            {
                cout << "El turno se ha cancelado exitosamente." << endl;
                system("cls");
            }
            else
            {
                cout << "No se pudo cancelar el turno." << endl;
            }
            valido = true;

        }
        else if (opcion == 2)
        {
            cout << "OPERACION ABORTADA..." << endl;
            valido = true;
        }
        else
        {
            cout << "OPCION INCORRECTA..." << endl;
            system("cls");
            valido=false;
        }
    }
    while (!valido);



}

void TurnoManager::mostrarTurno(Turno turno)
{
    Paciente paciente;
    Medicos medico;

    int posPac, posMedico;

    posPac = _repoPaciente.buscarPorDni(turno.getDniPaciente());
    paciente = _repoPaciente.leer(posPac);

    posMedico = _repoMedico.buscarPorId(turno.getIdMedico());
    medico = _repoMedico.leer(posMedico);

    cout << "+-----------------------------------------------------+" << endl;
    cout << "PACIENTE: " << paciente.getApellido() << ", "<< paciente.getNombre() << endl;
    cout << "DNI: " << turno.getDniPaciente() << endl;
    cout << "MEDICO: " << medico.getApellido() << ", " << medico.getNombre() << endl;
    cout << "ESPECIALIDAD: " << medico.getEspecialidad() << endl;
    cout << "FECHA: ";
    turno.getFechaTurno().mostrar();
    cout << endl;
    cout << "HORA: " <<turno.getHora() << endl;
    cout << "ESTADO: "<< turno.getEstado() << endl;
    cout << "COSTO: $" << turno.getCostoConsulta() << endl;
    cout << "+-----------------------------------------------------+" << endl;

}

void TurnoManager::listarTurnos()
{
    int cantidad= _repoTurno.getCantidadRegistros();
    Turno reg;
    for(int i=0; i<cantidad; i++)
    {
        reg= _repoTurno.leer(i);

        if(reg.getEliminado()==false)
        {

            mostrarTurno(reg);
            cout << endl;
        }

    }

}

void TurnoManager::listarTurnoPendientePorPaciente()
{
    Turno turno;
    bool valido;
    char dni[9];
    int  pos;

    do
    {
        system("cls");
        valido=true;

        cout << " INGRESE 0 (CERO) PARA CANCELAR LA OPERACION..." << endl << endl;
        cout << "DNI paciente:  ";

        cargarCadena(dni,9);
        if (cancelacionUsuario(dni))
        {
            system("pause");
            return;
        }

        if(!dniValido(dni))
        {
            cout << "DNI invalido. Intente nuevamente..." << endl;
            system("pause");
            valido=false;
        }
        else
        {
            pos= _repoTurno.buscarPorDni(dni);
            if (pos==-1)
            {
                cout << "El DNI ingresado no posee turnos pendientes..." << endl;
                system("pause");
                return;

            }
        }

    }while(!valido);



    int cantidadRegistros = _repoTurno.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){
        turno= _repoTurno.leer(i);

        if (strcmp(dni,turno.getDniPaciente())==0
            && strcmp(turno.getEstado(),"PENDIENTE")==0
            && !turno.getEliminado()){

            mostrarTurno(turno);
            cout << "-----------------------------------------" << endl;
        }

    }


}


void TurnoManager::listarPorPaciente()///NO SERIA POR APELLIDO?
{
    int cantidadTotal = _repoTurno.getCantidadRegistros();
    int cantidadActivos= _repoTurno.getCantidadActivos();
    Turno *vec = new Turno[cantidadActivos];
    Turno reg;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }


    int posVec =0;

    for(int i=0; i<cantidadTotal; i++)
    {

        reg= _repoTurno.leer(i);

        if(reg.getEliminado()==false)
        {

            vec[posVec]=reg;
            posVec++;

        }

    }



    Turno aux;

    for(int i = 0; i < cantidadActivos - 1; i++)
    {
        for(int j = i + 1; j < cantidadActivos; j++)
        {
            Paciente p1 = _repoPaciente.leer(_repoPaciente.buscarPorId(vec[i].getIdPaciente()));
            Paciente p2 = _repoPaciente.leer(_repoPaciente.buscarPorId(vec[j].getIdPaciente()));

            if(strcmp(p1.getApellido(), p2.getApellido()) > 0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(int i = 0; i < cantidadActivos; i++)
    {
        mostrarTurno(vec[i]);
        cout << endl;
    }

    delete[] vec;

}

void TurnoManager::listarPorMedico()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (vec[x].getIdMedico() > vec[x+1].getIdMedico())
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por Medico"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}
void TurnoManager::listarTurnoPendientePorMedico(const char* dni)///pasamos ID a traves del menuMedico
{
    int  idMedico, contPendientes;
    Turno turno;

    idMedico = _managerMedico.recuperarIdMedico(dni);
    if(idMedico == -1)
    {
        cout << "DNI NO ENCONTRADO..." << endl;
    }
    else
    {
        contPendientes = 0;
        int cantidadRegistros = _repoTurno.getCantidadRegistros();
        for (int i=0; i<cantidadRegistros; i++)
        {
            turno = _repoTurno.leer(i);
            if (turno.getIdMedico() == idMedico && strcmp(turno.getEstado(), "PENDIENTE") == 0)
            {
                mostrarTurno (turno);
                cout <<"-----------------------------------------------" << endl;
                contPendientes ++;
            }
        }
        if (contPendientes == 0)
        {
            cout << "SIN TURNOS PENDIENTES..." << endl;
        }
    }
}


void TurnoManager::listarPorEstado()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (strcmp (vec[x].getEstado(), vec[x+1].getEstado())> 0 )
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por estado"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void TurnoManager::listarPorFecha()
{
    int cantidadRegistros = _repoTurno.getCantidadRegistros();
    Turno *vec = new Turno[cantidadRegistros];
    Turno aux;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }
    _repoTurno.leer(vec, cantidadRegistros);



    for (int i=0; i<cantidadRegistros; i++)
    {
        for (int x=0; x<cantidadRegistros -1; x++)
        {

            if (vec[x].getFechaint() > vec[x+1].getFechaint())
            {
                aux = vec[x];
                vec [x] = vec[x+1];
                vec[x+1]= aux;
            }
        }
    }

    cout <<               "Turno listados por Fecha"                << endl;

    for (int i=0; i<cantidadRegistros; i++)
    {

        mostrarTurno(vec[i]);

        cout << "---------------------------------------------------------------"<< endl;
    }

    delete []vec;
}

void TurnoManager::atenderTurno()
{
    Turno turno;
    bool valido;
    char dni[8];
    int  posTurno, opcion, cantRegistros;
    Historial historial;

    do
    {
        valido = false;
        cout << " INGRESE 0 (CERO) PARA CANCELAR..." << endl;
        cout << "INGRESE DNI DEL PACIENTE: ";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }


        cin.getline(dni,8);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << endl;

        if (cancelacionUsuario(dni))
        {
            cout << "OPORACION CANCELADA" << endl;
            return;
        }

        posTurno = _repoTurno.buscarPorDni (dni);
        if(posTurno==-1)
        {
            cout << "El DNI no posee turnos pendientes. " << endl;

        }
        else
        {
            valido = true;
            turno = _repoTurno.leer(posTurno);
            mostrarTurno (turno);
        }
    }
    while(!valido);

    do
    {
        valido=false;

        cout << "DESEA VER EL HISTORIAL DEL PACIENTE? 1.SI/ 2.NO " << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cantRegistros = _repoHistorial.getCantidadRegistros();
            for (int i=0; i<cantRegistros; i++)
            {

                historial = _repoHistorial.leer(i);
                if(turno.getIdPaciente() == historial.getIdPaciente() )
                {

                    _managerHistorial.mostrarHistorial(historial);
                    cout << "-------------------------------------------------" << endl;
                }

            }
            valido = true;
            break;
        case 2:
            valido =true;
            break;
        default:
            cout << "OPCION INCORRECTA..."<< endl;
            valido = false;
            break;
        }

    }
    while(!valido);

    do
    {
        valido = false;
        cout << "DESEA INGRESAR UN NUEVO DIAGNOSTICO? 1.SI/2.NO " << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            _managerHistorial.cargarHistorial(turno);
            valido = true;
            break;
        case 2:
            valido = true;
            break;
        default:
            cout << "OPCION INCORRECTA...." << endl;
            valido = false;
            break;

        }
    }
    while(!valido);
    turno.setEstado("ATENDIDO");

    if(_repoTurno.modificar(turno,posTurno))
    {
        cout << "TURNO ATENDIDO" << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    // terminar guardando estado turno...



}
/*
void MedicosManager::listarMedico()
{
            int cantidadRegistros = _repoMedicos.getCantidadRegistros();

            for (int i = 0; i<cantidadRegistros; i++)
            {
                Medicos reg = _repoMedicos.leer(i);
                if (!reg.getEliminado())
                {
                    mostrarMedico(reg);
                    cout << endl;
                }
            }
        }

        void MedicosManager::listarXId()
        {
            int id;

            cout << "Ingrese el ID: ";
            cin >> id;

            int posicion = _repoMedicos.buscarPorId(id);
            if (posicion >= 0)
            {
                Medicos reg = _repoMedicos.leer(posicion);
                mostrarMedico(reg);
            }
            else
            {
                cout << "No existe el registro con ID #" << id << endl;
            }
        }

        void MedicosManager::mostrarMedico(Medicos medicos)
        {
            cout << "-------------------MEDICOS-------------------" << endl;
            cout << endl;
            cout << "ID: " << medicos.getIdMedico()<< endl;
            cout << "Nombre: " << medicos.getNombre()<< endl;
            cout << "Apellido: " << medicos.getApellido()<< endl;
            cout << "DNI: " << medicos.getDni()<< endl;
            cout << "Especialidad: " << medicos.getEspecialidad()<< endl;
            cout << "Telefono; " << medicos.getTelefono()<< endl;
            cout << "Matricula; " << medicos.getMatricula()<< endl;

        }

        bool MedicosManager::existeId(int id)
        {
            return _repoMedicos.buscarPorId(id) > 0;//mayor a 0 no? o vamos a hacer que 0 sea un nro posible de id?
        }
*/
int TurnoManager::generarId()
{
    return _repoTurno.getCantidadRegistros() + 1;
}
/*
        void MedicosManager::hacerCopiaDeSeguridad()
        {
            int cantidadRegistros = _repoMedicos.getCantidadRegistros();
            Medicos *vec = new Medicos[cantidadRegistros];

            if (vec == nullptr)
            {
                cout << "Falla al realizar backup" << endl;
                return;
            }

            _repoMedicos.leer(vec, cantidadRegistros);
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

        void MedicosManager::restaurarCopiaDeSeguridad()
        {

            int cantidadRegistros = _archivoBkp.getCantidadRegistros();
            Medicos *vec = new Medicos[cantidadRegistros];

            if (vec == nullptr)
            {
                cout << "Falla al restaurar backup" << endl;
                return;
            }

            _archivoBkp.leer(vec, cantidadRegistros);
            _repoMedicos.vaciar();
            if (_repoMedicos.guardar(vec, cantidadRegistros))
            {
                cout << "Backup restaurado correctamente" << endl;
            }
            else
            {
                cout << "Falla al restaurar backup" << endl;
            }

            delete []vec;


        }

        void MedicosManager::listarMedicoPorApellido()
        {
            int cantidadRegistros = _repoMedicos.getCantidadRegistros();
            Medicos *vec = new Medicos[cantidadRegistros];
            Medicos aux;


            if (vec == nullptr)
            {
                cout << "Falla asignacion de memoria" << endl;
                return;
            }
            _repoMedicos.leer(vec, cantidadRegistros);



            for (int i=0; i<cantidadRegistros; i++)
            {
                for (int x=0; x<cantidadRegistros -1; x++)
                {

                    if (strcmp (vec[x].getApellido(), vec[x+1].getApellido())> 0 ||
                            (strcmp(vec[x].getApellido(), vec[x+1].getApellido()) == 0
                             && strcmp(vec[x].getNombre(), vec[x+1].getNombre()) > 0))
                    {
                        aux = vec[x];
                        vec [x] = vec[x+1];
                        vec[x+1]= aux;
                    }
                }
            }

            cout <<               "Medicos listados por apellido"                << endl;

            for (int i=0; i<cantidadRegistros; i++)
            {

                cout << endl;
                cout << "Apellido: " << vec[i].getApellido()<< endl;
                cout << "Nombre: " << vec[i].getNombre()<< endl;
                cout << "ID: " << vec[i].getIdMedico()<< endl;
                cout << "DNI: " << vec[i].getDni()<< endl;
                cout << "Especialidad: " << vec[i].getEspecialidad()<< endl;
                cout << "Telefono; " << vec[i].getTelefono()<< endl;
                cout << "Matricula; " << vec[i].getMatricula()<< endl;

                cout << "---------------------------------------------------------------"<< endl;
            }

            delete []vec;
        }

        void MedicosManager::listarMedicoPorEspecialidad()
        {
            int cantidadRegistros = _repoMedicos.getCantidadRegistros();
            Medicos reg;
            char especialidad [30];

            cout << "Ingrese especialidad a consultar:  " << endl;
            cin.getline(especialidad,30);



            for (int i = 0; i<cantidadRegistros; i++)
            {
                reg = _repoMedicos.leer(i);
                if (!reg.getEliminado() && strcmp (especialidad, reg.getEspecialidad()) == 0)
                {
                    mostrarMedico(reg);
                    cout << endl;
                }
            }
        }

        */






int TurnoManager::turnosDisponiblesPorMedico( Medicos medico, Turno opciones[])
{

    int opcionesTotal=0;
    Fecha hoy;
    hoy.setHoy();

    char hora[6];

    for(int i=0; i<5; i++) ///DIAS POSIBLES (LUN-VIER)
    {

        if(medico.getDiasAgenda()[i]) ///DIAS HABILITADOS DEL MEDICO
        {

            Fecha dias[2];

            obtenerDias(i+1,dias,hoy);///CARGA LOS PROXIMOS 2 LUNES/MARTES/ETC

            for(int j=0; j<2; j++) ///RECORRE EL VEC DE DIAS CARGADOS
            {

                for(int k=0; k<5; k++) ///RECORRE LOS POSIBLES TURNOS/HORARIOS
                {

                    if(cargarHoraTurno(k+1,hora)) ///CARGA EL CHAR
                    {

                        if(turnoOcupado(medico.getIdMedico(),dias[j],hora)==false) ///CHEQUEA QUE EL TURNO NO ESTE OCUPADO
                        {

                            cout << opcionesTotal+1 << ") ";
                            cout << "Medico :" << medico.getNombre() << " " << medico.getApellido() << " -";
                            dias[j].mostrar();
                            cout << " -"<< hora << endl;


                            ///SETTEA Y GUARDA EN EL VECTOR LOS POSIBLES TURNOS CON FECHA Y HORA
                            opciones[opcionesTotal].setIdMedico(medico.getIdMedico());
                            opciones[opcionesTotal].setFechaTurno(dias[j]);
                            opciones[opcionesTotal].setHora(hora);

                            opcionesTotal++;

                        }

                    }


                }


            }



        }

    }
    return opcionesTotal;
}




bool TurnoManager::turnoOcupado(int idMedico, Fecha fecha, const char *hora)
{

    Turno turno;

    int cantidad= _repoTurno.getCantidadRegistros();


    for(int i=0; i<cantidad; i++)
    {

        turno= _repoTurno.leer(i);

        if(turno.getIdMedico()== idMedico
                && turno.getFechaTurno().esIgual(fecha)
                && strcmp(turno.getHora(),hora)==0
                &&strcmp(turno.getEstado(),"PENDIENTE")==0 )
        {

            return true;

        }



    }

    return false;


}
