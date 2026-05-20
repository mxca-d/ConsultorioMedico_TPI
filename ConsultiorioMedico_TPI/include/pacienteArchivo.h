#pragma once


class PacienteArchivo{


public:
    PacienteArchivo();
    PacienteArchivo(const char* nombre);

    bool guardar(Paciente p);
    int getCantidadRegistros();
    Paciente leer(int pos);
    bool modificar(Paciente reg, int pos);
    int buscarPorId(int id);


private:
    char _nombreArchivo[30];

};



