#pragma once
#include "fecha.h"

class Paciente{
private:
    char _nombre[30];
    char _apellido[30];
    char _dni [9];
    char _email[30];//agregue datos de contacto
    char _telefono[15];//agregue datos de contacto
    char _domicilio[30];//agregue datos de contacto
    bool _eliminado;
    Fecha _fechaNacimiento;
    ///HASTA ACA HERENCIA
    int _idPaciente;
    int _idObraSocial;
    char _obraSocial[30];



public:
    Paciente();
    void setEliminado(bool eliminado);
    void setIdPaciente(int ID);
    void setIdObrasocial(int ID);

    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDni(const char* dni);
    void setEmail(const char* email);
    void setTelefono(const char* telefono);
    void setDomicilio(const char* domicilio);
    void setObraSocial(const char* obraSocial);
    void setFechaNacimiento(Fecha fecha);


    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getEmail();
    const char* getTelefono();
    const char* getDomicilio();
    const char* getObraSocial();
    int getIdPaciente();
    int getIdObraSocial();
    bool getEliminado();
    Fecha getFechaNacimiento();




};


