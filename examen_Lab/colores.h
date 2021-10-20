#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{

    int id;
    char descColor[20];

}eColores;

#endif // COLORES_H_INCLUDED

void mostrarColores(eColores hola);
int listarColores(eColores lista[], int tam);
int cargarColores(eColores lista[], int tam, char tipo[], int id);
