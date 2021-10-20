#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

char marca[10][20] = {
    "",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Andrea",
    "Luis",
    "Diego",
    "Analia",
    "Camila"
};

char sexos[10] ={'m','m','f','m','f','f','m','m','f','f'};

int edades[10]={23,21,28,32,45,29,39,23,28,28};

float alturas[10] = {1.65,1.67,1.90,1.78,1.75,1.70,1.65,1.73,1.73,1.68};

int idLocalidades[10]={1001,1002,1000,1001,1001,1001,1003,1004,1004,1002};

int hardcodearPBicicletas(eBicicleta lista[], int tam, int cant, int* pId)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >=0 && cant <= tam && pId != NULL)
    {
        contador=0;
        for(int i = 0; i<cant;i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            //strcpy(lista[i].nombre, nombres[i]);//xq es string
            //ista[i].sexo=sexos[i];
            //lista[i].edad=edades[i];
            //lista[i].altura=alturas[i];
            //lista[i].idLocalidad=idLocalidades[i];
            lista[i].isEmpty = 1;
            contador++;
        }
    }
    return contador;
}
