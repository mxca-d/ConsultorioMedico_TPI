#ifndef MEDICOS_H
#define MEDICOS_H
#include <string>

class Medicos
{
private:
    char nombre[30], apellido[30], especialidad[30];
    char dni[12];
    char  matricula[15], telefono[15];
    int idMedico;
    bool eliminado;

public:
    Medicos();
    void cargar();
    void mostrar();
    void setEliminado(bool e);
    void setIdMedico(int idm);

    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEspecialidad();
    const char* getMatricula();
    const char* getTelefono();
    int getIdMedico();
    bool getEliminado();


};
#endif // MEDICOS_H
