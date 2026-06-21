#include "medicosManager.h"
#include "medicosArchivo.h"
#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;




void MedicosManager::altaMedico()
{
    Usuarios usuario;
    UsuariosArchivo repoUsuarios;

    char nombre[30],apellido[30],especialidad[30],dni[12],matricula[15],telefono[15], domicilio[30];
    char email[30];
    Fecha fechaNacimiento, hoy;
    hoy.setHoy();
    float honorarios;
    int opcion;
    bool eliminado, fechaValida,ingresar,valido,diasAgenda [5] = {false};

    Carga cargar [7] =
    {
        {"Nombre: ", nombre, 30},
        {"Apellido: ", apellido, 30},
        {"DNI: ", dni, 9},
        {"Matricula: ", matricula, 15},
        {"Telefono: ", telefono, 15},
        {"Domicilio: ", domicilio, 30},
        {"Email: ", email, 30}
    };

    Medicos m;

    cout << "-------------------MEDICOS-------------------" << endl;
    cout << endl;
    cout << "Ingrese '0' en caso de querer cancelar la carga" << endl;
    cout << endl;

    for (int i=0; i < 7; i++)
    {

        do
        {
            valido=true;
            ingresar =true;
            cout << cargar [i].texto;
            valido=cargarCadena(cargar[i].pDestino,cargar[i].tamanio);

            if(i==0 || i==1){
                if(!soloLetras(cargar[i].pDestino)){
                    valido=false;
                }
            }


            if (i == 2)
            {
                if(!dniValido(cargar[i].pDestino)){
                    valido=false;
                }

                if (_repoMedicos.buscarCoincidenciaDni (cargar[i].pDestino))
                {
                    cout << "Ya existe un paciente con ese DNI..." << endl;
                    return;
                }
            }
            if (i==4)
            {
                if(!soloNumeros(cargar[4].pDestino))
                {
                    valido = false;

                }
            }
            if (cancelacionUsuario(cargar[i].pDestino) )
            {
                system("pause");
                return;
            }

            todoMayuscula (cargar[i].pDestino);

            if(!valido){
                cout << "Invalido. Vuelva a intentarlo..." << endl;
            }
        }
        while (!valido);
    }

    do
    {
        fechaValida=true;
        cout << "Fecha de nacimiento: " <<endl;
        fechaValida=fechaNacimiento.cargar();
        if(!fechaValida)
        {
            cout << "Fecha invalida. Vuelva a intentarlo..."<< endl;
            system("pause");

        }else if(!fechaNacimiento.esMenor(hoy)){
            cout << "Fecha invalida. Vuelva a intentarlo..."<< endl;
            fechaValida=false;
            system("pause");
        }

    }while(!fechaValida);


    do
    {
        mostrarEspecialidades();
        cout << "Elija una especialidad: " << endl;
        cin >> opcion;
        cin.ignore();
        valido = cargarEspecialidad(opcion,especialidad);
    }
    while(!valido);

    do
    {
        valido = true;
        cout << "Valor consulta: " ;
        cin >> honorarios;
        cin.ignore();

        if (cancelacionUsuario (honorarios))
        {
            cout << "Carga cancelada por el usuario..." << endl;
            return;
        }

        valido = validacionImportes (honorarios);

    }
    while (!valido);
    system("cls");
    cout << "           DIAS DE ATENCION        " << endl;
    for (int i=0; i<5; i++)
    {
        do
        {

            cout << "Presione 1. para habilitar agenda." << endl;
            cout << "Presione 2. para no agregar dia." << endl;
            cout << "0. para cancelar carga. " << endl;
            mostrarDiaAgenda(i);
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "Agregado.." << endl;
                system ("pause");
                diasAgenda [i] = true;
                valido = true;
                break;
            case 2:
                valido = true;
                break;
            case 0:
                cout << "Carga cancelada por el usuario..." << endl;
                return;
            default:
                cout << "OPCION INCORRECTA..." << endl;
                system ("pause");
                valido = false;
                break;
            }
        }
        while (!valido);
        system("cls");
    }


    eliminado = false;
    m.setNombre(nombre);
    m.setApellido(apellido);
    m.setDni(dni);
    m.setEspecialidad(especialidad);
    m.setTelefono(telefono);
    m.setMatricula(matricula);
    m.setHonorarios(honorarios);
    m.setIdMedico(generarId());
    m.setEliminado(eliminado);
    m.setDiasAgenda(diasAgenda);
    m.setEmail(email);
    m.setDomicilio(domicilio);
    m.setFechaNacimiento(fechaNacimiento);

    usuario.setIdUsuario(repoUsuarios.getCantidadRegistros()+1);
    usuario.setDni(m.getDni());
    usuario.setNombreUsuario(m.getDni());
    usuario.setPassword("1234");
    usuario.setRol(2);
    usuario.setEliminado(false);
    usuario.setNombre(nombre);
    usuario.setApellido(apellido);
    usuario.setTelefono(telefono);
    usuario.setDomicilio(domicilio);
    usuario.setEmail(email);
    usuario.setFechaNacimiento(fechaNacimiento);


    mostrarMedico (m);





    if(_repoMedicos.guardar (m))
    {
        cout << "Se guardo el medico exitosamente!" << endl;

        if(repoUsuarios.guardar(usuario))
        {

            cout << "Tambien se genero el usuario." << endl;

        }
        else
        {

            cout << "Pero no se pudo generar el usuario..." << endl;
        }
    }
    else
    {
        cout << "No se pudo guardar el medico..." << endl;
    }

    system("pause");

}

void MedicosManager::bajaMedico()
{
    Medicos reg;

    int id, pos;

    cout << "Ingrese el ID del medico a dar de baja:";
    cin>>id;
    cout << endl;

    pos=_repoMedicos.buscarPorId(id);

    if(pos==-1)
    {
        cout << "El id ingresado no existe." << endl;
        return;
    }

    reg= _repoMedicos.leer(pos);
    reg.setEliminado(true);

    bool eliminado=_repoMedicos.modificar(reg,pos);

    if(eliminado)
    {
        cout << "El medico se ha dado de baja exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo dar de baja el medico." << endl;
    }




}

void MedicosManager::listarMedicos()
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

void MedicosManager::mostrarPorId()
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

void MedicosManager::listarMedicoEspecialidad(const char* especialidad)
{
    int coincidencias = 0;
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();

    Medicos m;

    for (int i = 0; i<cantidadRegistros; i++)
    {
        m = _repoMedicos.leer(i);
        if (!m.getEliminado() && strcmp(especialidad, m.getEspecialidad())==0)
        {
            cout << "idMedico: " << m.getIdMedico() << endl;
            cout << "Medico: " << m.getApellido() << ", " << m.getNombre() << endl;
            cout << "Especialidad: " << m.getEspecialidad() << endl;
            cout << "-------------------------------------------------------------" << endl;
            coincidencias ++;

        }

    }

    if (coincidencias ==0)
    {
        cout << "NO HAY COINCIDENCIAS PARA LA ESPECIALIDAD EN CONSULTA..." << endl;
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
    cout << "Domicilio: " << medicos.getDomicilio() << endl;
    cout << "Telefono: " << medicos.getTelefono()<< endl;
    cout << "Email: " << medicos.getEmail() << endl;
    cout << "Matricula: " << medicos.getMatricula()<< endl;
    cout << "Valor consulta: " << medicos.getHonorarios() << endl;
    cout << "Dias Atencion: " << endl;
    const bool* diasAgenda = medicos.getDiasAgenda();
    for (int i=0; i<5; i++)
    {

        if(diasAgenda [i]== true)
        {
            mostrarDiaAgenda(i);
        }
    }

}

bool MedicosManager::existeId(int id)
{
    return _repoMedicos.buscarPorId(id) > 0;
}

int MedicosManager::generarId()
{
    return _repoMedicos.getCantidadRegistros() + 1;
}

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
    int cantTotal = _repoMedicos.getCantidadRegistros();
    int cantActivos= _repoMedicos.getCantidadActivos();

    Medicos *vec = new Medicos[cantActivos];
    Medicos aux,reg;


    if (vec == nullptr)
    {
        cout << "Falla asignacion de memoria" << endl;
        return;
    }


    int posVec=0;

    for(int i=0;i<cantTotal;i++){

        reg=_repoMedicos.leer(i);

        if(!reg.getEliminado()){
            vec[posVec]=reg;
            posVec++;
        }

    }

    for (int i=0; i<cantActivos-1; i++)
    {
        for (int j=i+1; j<cantActivos; j++)
        {

            if (strcmp (vec[i].getApellido(), vec[j].getApellido())> 0 ||
                    (strcmp(vec[i].getApellido(), vec[j].getApellido()) == 0
                     && strcmp(vec[i].getNombre(), vec[j].getNombre()) > 0))
            {
                aux = vec[i];
                vec [i] = vec[j];
                vec[j]= aux;
            }
        }
    }

    cout <<               "Medicos listados por apellido"                << endl;

    for (int i=0; i<cantActivos; i++){
        mostrarMedico(vec[i]);
        cout <<"----------"<< endl;

    }

    delete []vec;
}

void MedicosManager::listarMedicoPorEspecialidad()
{
    int cantidadTotal = _repoMedicos.getCantidadRegistros();
    int cantActivos= _repoMedicos.getCantidadActivos();
    Medicos reg, aux;

    Medicos *vec;
    vec= new Medicos[cantActivos];
    if(vec==nullptr){
        cout << "Error" << endl;
        return;
    }

    int posVec=0;

    for(int i=0;i<cantidadTotal;i++){
        reg=_repoMedicos.leer(i);

        if(!reg.getEliminado()){
            vec[posVec]=reg;
            posVec++;
        }
    }

    for(int i=0;i<cantActivos-1;i++){

        for(int j=i+1;j<cantActivos;j++){

            if(strcmp(vec[i].getEspecialidad(),vec[j].getEspecialidad())>0){

                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;

            }
        }

    }

    for (int i = 0; i<cantActivos; i++)
    {
        mostrarMedico(vec[i]);
        cout << "----------" << endl;
    }

    delete []vec;
}



int MedicosManager::recuperarIdMedico (const char* dni)
{
    int cantidadRegistros = _repoMedicos.getCantidadRegistros();
    Medicos medico;

    for (int i=0; i<cantidadRegistros; i++)
    {
        medico = _repoMedicos.leer(i);
        if (strcmp(medico.getDni(), dni)==0)
        {
            return medico.getIdMedico();
            break;
        }

    }
    return -1;
}

void MedicosManager::modificarMedico()
{
    char nombre[30], apellido[30], dni [9], especialidad[30], matricula[15],
     telefono[15], domicilio[30], email[30];
    Fecha fechaNacimiento, hoy;
    hoy.setHoy();
    float honorarios;
    bool fechaValida, ingreso,diasAgenda [5] = {false}, valido;
    int  pos, eleccion;

    Medicos m;



    do{
        valido = true;
        cout << "Ingrese el DNI del medico a modificar: ";
        cargarCadena(dni,9);
        if(!dniValido(dni)){
            valido=false;
        }
        if (cancelacionUsuario(dni))
        {
            system("pause");
            return;
        }
        if(!valido){
            cout << "DNI invalido. Intente nuevamente..." << endl;
        }

    }while(!valido);



    pos=_repoMedicos.buscarPorDni(dni);

    if(pos==-1)
    {
        cout << "El DNI ingresado no esta registrado a un medico existente." << endl;
        return;
    }

    m= _repoMedicos.leer(pos);


    int opcion;
    do
    {
        system("cls");
        ingreso = true;

        cout << "-----------------------------" << endl;
        cout << "Seleccionar que campo desea cambiar:" << endl;
        cout << "1-Nombre" << endl;
        cout << "2-Apellido" << endl;
        cout << "3-Fecha nacimiento" << endl;
        cout << "4-DNI" << endl;
        cout << "5-Domicilio" << endl;
        cout << "6-Telefono" << endl;
        cout << "7-Email" << endl;
        cout << "8-Honorarios" << endl;
        cout << "9-Dias atencion" << endl;
        cout << "10-Especialidad" << endl;
        cout << "11-Matricula" << endl;
        cout << "12-Cancelar" << endl;
        cout << "0-Guardar y salir" << endl;
        cout << "-----------------------------" << endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            do{
                system("cls");
                valido=true;
                cout << "Nombre: ";
                valido=cargarCadena(nombre,30);

                if(!soloLetras(nombre)){
                    valido=false;
                }
                if(!valido){
                    cout << "Nombre invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            todoMayuscula(nombre);
            m.setNombre(nombre);

            break;
        case 2:
            do{
                system("cls");
                valido=true;
                cout << "Apellido: ";
                valido=cargarCadena(apellido,30);

                if(!soloLetras(apellido)){
                    valido=false;
                }
                if(!valido){
                    cout << "Apellido invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            todoMayuscula(apellido);
            m.setApellido(apellido);


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

            m.setFechaNacimiento(fechaNacimiento);
            break;
        case 4:
             do{
                valido = true;

                system("cls");
                cout << "DNI: ";
                valido=cargarCadena(dni,9);

                if(!dniValido(dni)){
                    cout << "DNI invalido. Vuelva a intentarlo..." << endl;
                    system("pause");
                    valido = false;
                }
                else if(strcmp(dni, m.getDni()) != 0 &&
                        _repoMedicos.buscarCoincidenciaDni(dni)){
                    cout << "Ya existe un paciente con este DNI." << endl;
                    system("pause");
                    valido = false;
                }

            }while(!valido);

            m.setDni(dni);

            break;
        case 5:
            do{
                system("cls");
                valido = true;
                cout << "Domicilio: ";
                valido=cargarCadena(domicilio,30);

                if(!letrasYNumeros(domicilio)){
                    valido=false;
                }
                if(!valido){
                    cout << "Domicilio invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            todoMayuscula(domicilio);
            m.setDomicilio(domicilio);

            break;

        case 6:
            do{
                system("cls");
                valido = true;
                cout << "Telefono: ";
                valido=cargarCadena(telefono,15);

                if(!soloNumeros(telefono)){
                    valido=false;
                }
                if(!valido){
                    cout << "Telefono invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            m.setTelefono(telefono);

            break;
        case 7:
            do{
                system("cls");
                valido = true;
                cout << "Email: ";
                valido=cargarCadena(email,30);

                if(!valido){
                    cout << "Email invalido. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            todoMayuscula(email);
            m.setEmail(email);

            break;
        case 8:
            do
            {
                valido = true;
                cout << "Valor consulta: " ;
                cin >> honorarios;
                cin.ignore();

                valido = validacionImportes (honorarios);

            }
            while (!valido);

            m.setHonorarios(honorarios);

            break;

        case 9:
            cout << "           DIAS DE ATENCION        " << endl;
            for (int i=0; i<5; i++)
            {
                do
                {

                    cout << "Presione 1. para habilitar agenda." << endl;
                    cout << "Presione 2. para no agregar dia." << endl;
                    cout << "0. para cancelar carga. " << endl;
                    mostrarDiaAgenda(i);
                    cin >> opcion;

                    switch (opcion)
                    {
                    case 1:
                        cout << "Agregado.." << endl;
                        system ("pause");
                        diasAgenda [i] = true;
                        valido = true;
                        break;
                    case 2:
                        valido = true;
                        break;
                    case 0:
                        cout << "Carga cancelada por el usuario..." << endl;
                        return;
                    default:
                        cout << "OPCION INCORRECTA..." << endl;
                        system ("pause");
                        valido = false;
                        break;
                    }
                }
                while (!valido);
                system("cls");
            }
            m.setDiasAgenda(diasAgenda);
            break;

        case 10:
            do
            {
                mostrarEspecialidades();
                cout << "Elija una especialidad: " << endl;
                cin >> opcion;
                cin.ignore();
                valido = cargarEspecialidad(opcion,especialidad);
            }
            while(!valido);

            m.setEspecialidad(especialidad);
            break;

        case 11:
            do{
                system("cls");
                valido = true;
                cout << "Matricula: ";
                valido=cargarCadena(matricula,15);

                if(!soloNumeros(matricula)){
                    valido=false;
                }
                if(!valido){
                    cout << "Matricula invalida. Vuelva a intentarlo..."<< endl;
                    system("pause");
                }
            }while(!valido);

            m.setMatricula(matricula);

        case 12:
            cout << "MODIFICACION CANCELADA...." << endl;
            cout << "NO SE GUARDARON CAMBIOS... " << endl;
            return;

            break;
        default:
            cout << "Opcion invalida... intente nuevamente" << endl;
            system("pause");
            break;

        }


    }
    while(opcion!=0);


    bool modificado=_repoMedicos.modificar(m,pos);

    if(modificado)
    {
        cout << "Los datos del medico han sido modificados exitosamente" << endl;
    }
    else
    {
        cout << "No se ha podido modificar los datos del medico." << endl;
    }

}

