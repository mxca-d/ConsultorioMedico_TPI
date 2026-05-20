#include <iostream>
#include "fecha.h"
#include <string>
#include <chrono>

using namespace std;


int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

bool Fecha::setDia( int dia){
    if(fechaValida(dia,_mes,_anio)){
        _dia=dia;
    return true;
    }else{
        return false;
    }
}


bool Fecha::setMes(int mes){
    if(fechaValida(_dia,mes,_anio)){
        _mes=mes;
    return true;
    }else{
        return false;
    }
}


bool Fecha::setAnio(int anio){
    if(fechaValida(_dia,_mes,anio)){
        _anio=anio;
        return true;
    }else{
        return false;
    }

}


bool Fecha::fechaValida(int dia, int mes, int anio){
bool valido=true, esBisiesto;

    if(anio>=1900){
        if(anio%400==0){
            esBisiesto=true;
        } else if(anio%100==0){
            esBisiesto=false;
        } else if(anio%4==0){
            esBisiesto=true;
        }else{
            esBisiesto=false;
        }


        if(mes>=1 && mes<=12)
        {

            if(dia>=1 && dia<=31)
            {

                if(mes==2)
                {
                    if(esBisiesto==true)
                    {

                        if(dia>29)
                        {
                            valido=false;

                        }
                    }
                    else if( dia>28)
                    {
                        valido=false;

                    }
                }


                if(mes==4 || mes==6 || mes==9 || mes==11){

                    if(dia>30){
                        valido=false;

                    }
                }


            }else{
            valido=false;

            }


        }else{
            valido=false;

        }

    }else{
        valido=false;
    }

    return valido;

}

Fecha::Fecha(int dia, int mes, int anio){


    if(fechaValida(dia,mes,anio)){
        _anio=anio;
        _mes=mes;
        _dia=dia;
    }else{
        _anio=0;
        _mes=0;
        _dia=0;
    }


}

Fecha::Fecha(){
    setHoy();

}


void Fecha::agregarDia(){

    if(fechaValida(_dia+1,_mes,_anio)){
        _dia++;
    }else{
        _dia=1;

        if(_mes==12){
            _mes=1;
            _anio++;
        }else{
            _mes++;
        }

    }

}

void Fecha::agregarDias(int cant){


    if(cant>0){
        for(int i=0;i<cant;i++){

            agregarDia();
        }
    }else{
        cant=cant*-1;
        for (int i=0;i<cant;i++){
            restarDia();
        }
    }



}




void Fecha::restarDia(){
    if(fechaValida(_dia-1,_mes,_anio)){
        _dia--;

    }else{
        if(_mes==1){
            _dia=31;
            _mes=12;
            _anio--;
        }else{
            _mes--;
        if(fechaValida(31,_mes,_anio)){
            _dia=31;
        }else if(fechaValida(30,_mes,_anio)){
            _dia=30;
        }else if(fechaValida(29, _mes,_anio)){
            _dia=29;
        }else if(fechaValida(28,_mes,_anio)){
            _dia=28;
        }
        }

    }
}


std::string Fecha::toString(){

    string textoDia, textoMes, textoAnio, textoCompleto;

    if(_dia<10){

        textoDia= "0"+ to_string(_dia);//to_string() convierte numeros a string
    }else{
        textoDia= to_string(_dia);
    }

    if(_mes<10){
        textoMes="0"+to_string(_mes);

    }else{
        textoMes=to_string(_mes);
    }

    textoAnio=to_string(_anio);

    textoCompleto= textoDia + "/" + textoMes + "/" + textoAnio;

    return textoCompleto;

}


bool Fecha::cargar(){

    int dia, mes, anio;

    cout << "Ingresar dia:";
    cin>> dia;
    cout << endl;
    cout << "Ingresar dia:";
    cin>> mes;
    cout << endl;
    cout << "Ingresar dia:";
    cin>> anio;
    cout << endl;

    if(fechaValida(dia,mes,anio)){
        _dia=dia;
        _mes=mes;
        _anio=anio;
        return true;
    }else{
    return false;
    }
}


void Fecha::setHoy() {
    // Obtener la fecha actual del sistema
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&now_c);

    // Asignar los valores a la fecha
    _dia = localTime->tm_mday;
    _mes = localTime->tm_mon + 1; // tm_mon va de 0 a 11
    _anio = localTime->tm_year + 1900; // tm_year es el número de años desde 1900
}

void Fecha::mostrar(){

    cout << _dia << "/" << _mes << "/" << _anio << endl;


}
