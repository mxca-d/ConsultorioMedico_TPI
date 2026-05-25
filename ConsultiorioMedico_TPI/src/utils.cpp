#include "utils.h"
#include <cstring>

bool horaValida(const char* hora){

    if(strlen(hora) != 5){//verifica cant char
        return false;
    }

    if(hora[2] != ':'){// verifica que esten los :
        return false;
    }

    if(hora[0] < '0' || hora[0] > '9'){// verifica rango
        return false;
    }

    if(hora[1] < '0' || hora[1] > '9'){
        return false;
    }

    if(hora[3] < '0' || hora[3] > '9'){
        return false;
    }

    if(hora[4] < '0' || hora[4] > '9'){
        return false;
    }

    int horas = (hora[0] - '0') * 10 + (hora[1] - '0');//resto 48= '0' y lo convierto en decena para sumar

    int minutos = (hora[3] - '0') * 10 + (hora[4] - '0');

    if(horas < 0 || horas > 23){//verifico que no supere las hs
        return false;
    }

    if(minutos < 0 || minutos > 59){//verifico q no supere los minutos
        return false;
    }

    return true;
}
