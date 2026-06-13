#pragma once
#include <string>

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
    void agregarDia();
    void restarDia();

public:
    int getDia();
    int getMes();
    int getAnio();

    bool setDia(int dia);
    bool setMes(int mes);
    bool setAnio(int anio);

    bool fechaValida(int dia, int mes, int anio);

    Fecha(int dia, int mes, int anio);
    Fecha();
    void setHoy();
    bool cargar();
    void agregarDias(int cant);
    void mostrar();
    Fecha obtenerFechaBase(int opcion);
    bool esMenor(Fecha fecha2);
    bool esIgual(Fecha fecha2);
    void obtenerDias(int opcion, Fecha *dias, Fecha hoy);


    std::string toString();
};

