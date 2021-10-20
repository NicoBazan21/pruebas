#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "trabajo.h"

int pedirTrabajo(int idTrabajo, eBicicleta lista[], int tam, eServicio servicio[],int tamS, eFecha fecha[], eTrabajo hacer[])
{
    int todoOk=0;
    //int libre;
    int buscarId;
    int indice;

    char confirmar;

    int trabajo;

    int min = 0;
    int max = 1000;

    if(idTrabajo > -1 && lista != NULL && servicio != NULL && fecha != NULL)
    {
        printf("\n");
        printf("     ***  Menu Servicios  ***\n\n");

        pedirEntero(&buscarId, "Ingrese el id: ", "Error. Id Invalido. Ingrese id nuevamente: ", min, max);
        indice=findBicicletaById(lista, tam, buscarId);
        printf("\n");

        if(indice == -1)
        {
            printf("No existe esta bicicleta. \n");
        }
        else
        {
            printf("Marca de la bicicleta ingresada: %s \n", lista[indice].marca);
            pedirCaracter(&confirmar, "\nDesea modificarlo? s/n", "Cancelando...", 's');

            if(confirmar=='s')
            {
                system("cls");
                printf("Ingrese el servicio que desea usar: ");
                scanf("%d", &trabajo);

                for(int i = 0; i < tamS; i++)
                {

                }



                todoOk=1;
            }



        }

    }
    return todoOk;
}
