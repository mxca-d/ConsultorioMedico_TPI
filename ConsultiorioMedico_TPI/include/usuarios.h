#pragma once

class Usuarios
{
    public:
        Usuarios();

        void setNombreUsuario(const char* usuario);
        void setPassword (const char* password);
        void setRol (int rol);
        void setEliminado (bool eliminado);

        const char* getNombreUsuario();
        const char* getPassword ();
        const char* getRol();
        bool getEliminado ();

    private:

        char _nombreUsuario [20];
        char _password [15];
        //DNI
        char _rol [30];
        bool _eliminado;
};

