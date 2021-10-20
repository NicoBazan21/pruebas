#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "dataWearHouse.h"
#include "tipo.h"
#include "colores.h"



void mostrarColores(eColores hola)
{

    printf("  %d   %14s\t\n",
            hola.id,
            hola.descColor
            );

}

int listarColores(eColores lista[], int tam)
{
    int todoOk=0;

    if(lista!=NULL&&tam>0)
    {
        system("cls");
        printf("\t ***Tipos de bicicleta***\n");
        printf("-----------------------------------------------\n");
        printf("  Id\t    Descripcion\n");
        printf("-----------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            mostrarColores(lista[i]);
        }
        todoOk=1;
    }
    return todoOk;
}


int cargarColores(eColores lista[], int tam, char tipo[], int id)
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && tipo != NULL && id > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(id==lista[i].id)
            {
                strcpy(tipo, lista[i].descColor);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
