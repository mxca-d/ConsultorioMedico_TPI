#pragma once

class Usuarios
{
public:
    Usuarios();

    void setNombreUsuario(const char* usuario);
    void setPassword (const char* password);
    void setRol (int rol);
    void setEliminado (bool eliminado);
    void setDni(const char* dni);
    void setIdUsuario(int id);///
    void setDomicilio (const char* domicilio);
    void setEmail (const char* email);
    void setTelefono (const char* telefono);
    void setNombre (const char* nombre);
    void setApellido (const char* apellido);

    const char* getDni();
    int getIdUsuario();
    int getNumeroRol();
    const char* getNombreUsuario();
    const char* getPassword ();
    const char* getNombre();
    const char* getApellido();
    const char* getDomicilio();
    const char* getTelefono();
    const char* getEmail();
    const char* getRol();
    bool getEliminado ();


private:
    int _idUsuario;///NUEVO ATRIBUTO
    char _nombreUsuario [20];
    char _password [15];
    char _nombre[30];
    char _apellido[30];
    char _telefono[15];
    char _email[30];
    char _domicilio[30] ;
    char _dni[9];
    char _rol [30];
    bool _eliminado;
};

