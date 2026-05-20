#ifndef ARANCEL_H_INCLUDED
#define ARANCEL_H_INCLUDED

class Arancel{
private:
    int idArancel, idObraSocial;
    char especialidad[30];
    float precio;
    bool eliminado;

public:
    Arancel();
    void cargar();
    void mostrar();
    void setEliminado(bool e);
    void setIdArancel(int ida);
    void setIdObraSocial(int idos);
    void setPrecio(float p);

    int getIdArancel();
    int getIdObraSocial();
    const char* getEspecialidad();
    float getPrecio();
    bool getEliminado();


};

#endif // ARANCEL_H_INCLUDED
