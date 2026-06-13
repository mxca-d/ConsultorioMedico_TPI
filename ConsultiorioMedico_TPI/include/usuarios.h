#pragma once

class Usuarios
{
    public:
        Usuarios();

        void setNombreUsuario(const char* usuario);
        void setPassword (const char* password);
        void setDni(const char* dni);
        void setRol (int rol);

        void setEliminado (bool eliminado);

        const char* getNombreUsuario();
        const char* getPassword ();
        int getNumeroRol ();
        const char* getDni();
        const char* getRol();
        bool getEliminado ();

    private:

        char _nombreUsuario [20];
        char _password [15];
        char _dni [8];
        char _rol [30];
        bool _eliminado;
};

