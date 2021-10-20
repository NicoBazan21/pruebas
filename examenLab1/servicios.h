#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{

    int id;
    char descServ[25];
    int precio;

}eServicio;

#endif // SERVICIOS_H_INCLUDED

void mostrarServicio(eServicio hola);

int listarServicio(eServicio lista[], int tam);

int cargarServicio(eServicio lista[], int tam, char tipo[], int id);
