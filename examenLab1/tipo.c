#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "dataWearHouse.h"
#include "tipo.h"



void mostrarTipo(eTipo hola)
{

    printf("  %d   %14s\t\n",
            hola.id,
            hola.tipoDesc
            );

}

int listarTipos(eTipo lista[], int tam)
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
            mostrarTipo(lista[i]);
        }
        todoOk=1;
    }
    return todoOk;
}


int cargarTipo(eTipo lista[], int tam, char tipo[], int id)
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && tipo != NULL && id > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(id==lista[i].id)
            {
                strcpy(tipo, lista[i].tipoDesc);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int cargarDescTipo(eTipo tipo[], int tam, int idTipo, char descTipo[])
{
    int todoOk=0;

    if(tipo!= NULL && tam > 0 && descTipo!= NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(tipo[i].id==idTipo)
            {
                strcpy(descTipo, tipo[i].tipoDesc);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
