#include <iostream>
#include "arancelManager.h"
#include "obraSocialManager.h"
#include "utils.h"
#include <cstring>

using namespace std;

void arancelManager::altaArancel(){

    Arancel reg;
    ObraSocialManager managerObraSocial;
    ObraSocialArchivo repoObraSocial;

    int id, pos, opcion;

    char especialidad[30];
    float cobertura;
    do{
        system("cls");
    cout << "Obras sociales disponibles:" << endl;
    managerObraSocial.listarObrasSociales();

    cout << "Ingrese ID de obra social: ";
    cin >> id;

    pos = repoObraSocial.buscarPorId(id);

    if(pos == -1){
        cout << "La obra social ingresada no existe." << endl;
        system("pause");
    }
    }while(pos==-1);

    bool especialidadValida;

    do{
        system("cls");
    mostrarEspecialidades();

    cout << "Seleccionar especialidad: ";
    cin >> opcion;

    especialidadValida = cargarEspecialidad(opcion, especialidad);

    if(!especialidadValida){
        cout << "Especialidad invalida." << endl;
        system("pause");
    }

    }while(!especialidadValida);



    do{
        cout << "Ingrese porcentaje de cobertura: ";
        cin >> cobertura;

        if(cobertura < 0 || cobertura > 100){
            cout << "Cobertura invalida. Debe estar entre 0 y 100." << endl;
        }

    }while(cobertura < 0 || cobertura > 100);

    int cantidad = _repoArancel.getCantidadRegistros();
    Arancel aux;

    for(int i = 0; i < cantidad; i++){
    aux = _repoArancel.leer(i);

    if(aux.getEliminado() == false &&
       aux.getIdObraSocial() == id &&
       strcmp(aux.getEspecialidad(), especialidad) == 0){

        cout << "Ya existe un arancel para esa obra social y especialidad." << endl;
        system("pause");
        return;
    }
    }

    reg.setIdArancel(cantidad + 1);
    reg.setIdObraSocial(id);
    reg.setEspecialidad(especialidad);
    reg.setCobertura(cobertura);
    reg.setEliminado(false);

    if(_repoArancel.guardar(reg)){
        cout << "Arancel guardado correctamente." << endl;
    }else{
        cout << "No se pudo guardar el arancel." << endl;
    }
}







void arancelManager::bajaArancel()
{
    Arancel reg;

    int id, pos;

    cout << "Ingrese el ID del arancel a dar de baja:";
    cin>>id;
    cout << endl;

    pos=_repoArancel.buscarPorId(id);

    if(pos==-1)
    {
        cout << "El id ingresado no existe." << endl;
        system("pause");
        return;
    }

    reg= _repoArancel.leer(pos);
    reg.setEliminado(true);

    bool eliminado=_repoArancel.modificar(reg,pos);

    if(eliminado)
    {
        cout << "El arancel se ha dado de baja exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo dar de baja el arancel." << endl;
    }




}

void arancelManager::listarAranceles()
{
    int cantidadRegistros = _repoArancel.getCantidadRegistros();

    for (int i = 0; i<cantidadRegistros; i++)
    {
        Arancel reg = _repoArancel.leer(i);
        if (!reg.getEliminado())
        {
            mostrarArancel(reg);
            cout << endl;
        }
    }
}


///ESTE METODO LO VAMOS A HACER PARA MOSTRAR SOLO UNO O PARA LISTAR ORDENANDO LOS ID? SINO DEBERIA LLAMARSE BUSCARPORID
void arancelManager::listarPorId(){
    int id;

    cout << "Ingrese el ID: ";
    cin >> id;

    int posicion = _repoArancel.buscarPorId(id);
    if (posicion >= 0)
    {
        Arancel reg = _repoArancel.leer(posicion);
        mostrarArancel(reg);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

void arancelManager::mostrarArancel(Arancel reg)///LE CAMBIE EL NOMBRE A REG, COMO ESTA DECLARADO EN EL .H
{
    cout << "-------------------ARANCELES-------------------" << endl;
    cout << endl;
    cout << "ID Arancel: " << reg.getIdArancel()<< endl;
    cout << "ID Obra Social: " << reg.getIdObraSocial() << endl;
    cout << "Especialidad: " << reg.getEspecialidad()<< endl;
    cout << "Porcentaje : %" << reg.getCobertura()<< endl;



}


///ESTE METODO TODAVIA NO LO USAMOS, EN EL ALTA YA SACAMOS LA CANT REGISTROS Y DIRECTAMENTE SUMAMOS +1
int arancelManager::generarId()
{
    return _repoArancel.getCantidadRegistros() + 1;
}


void arancelManager::hacerCopiaDeSeguridad()
{
    int cantidadRegistros = _repoArancel.getCantidadRegistros();
    Arancel *vec = new Arancel[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    _repoArancel.leer(vec, cantidadRegistros);
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

void arancelManager::restaurarCopiaDeSeguridad()
{

    int cantidadRegistros = _archivoBkp.getCantidadRegistros();
    Arancel *vec = new Arancel[cantidadRegistros];

    if (vec == nullptr)
    {
        cout << "Falla al restaurar backup" << endl;
        return;
    }

    _archivoBkp.leer(vec, cantidadRegistros);
    _repoArancel.vaciar();
    if (_repoArancel.guardar(vec, cantidadRegistros))
    {
        cout << "Backup restaurado correctamente" << endl;
    }
    else
    {
        cout << "Falla al restaurar backup" << endl;
    }

    delete []vec;


}

