#pragma once

class Usuarios
{
    public:
        Usuarios();

        void setNombreUsuario(const char* usuario);
        void setPassword (const char* password);
        void setRol (int rol);
        void setEliminado (bool eliminado);
        void setIdMedico(int id);///
        void setIdUsuario(int id);///

        int getIdMedico();///
        int getIdUsuario();///
        const char* getNombreUsuario();
        const char* getPassword ();
        const char* getRol();
        bool getEliminado ();

    private:
        int _idUsuario;///NUEVO ATRIBUTO
        char _nombreUsuario [20];
        char _password [15];
        char _rol [30];
        bool _eliminado;
        int _idMedico; ///NUEVO ATRIBUTO

        //DNI
};

