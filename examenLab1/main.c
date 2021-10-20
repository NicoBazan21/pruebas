#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"

#define TAM 10
#define TAM_MIN 1
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4


int main()
{
    char seguir = 'n';
    char seguro;

    int nextId = 1;

    eBicicleta lista[TAM];
    eFecha fecha[TAM];

    char auxMarca[20];
    int auxTipo;

    int tipoMin = 1000;
    int tipoMax = 1004;

    int auxColor;
    int colorMin = 5000;
    int colorMax = 5004;

    char material;

    float rodado;

    int encontrarId;
    int buscarId;
    int orden;

    int ordenAsc = 1;
    int ordenDesc =2;

    int entrar = 0;


    inicializarBicicletas(lista, TAM);

    int dia;
    int mes;
    int anio;
    int diaMin = 1;
    int diaMax = 30;
    int mesMax = 12;
    int anioMin = 2000;
    int anioMax=2021;


    eTipo tipo[TAM_T] = {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"},
    };

    eColores colores[TAM_C] = {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"},
    };
    eServicio servicio[TAM_S] = {
        {20000, "Limpieza", 30},
        {20001, "Parche", 400},
        {20002, "Centrado", 500},
        {20003, "Cadena", 450},
    };





    fflush(stdin);
    do{
        switch(menu())
        {
            case 1:
                if(buscarLibre(lista, TAM) > -1)
                {
                    pedirCadena(auxMarca, 20, "Ingrese Marca: ", "Error, marca invalida. Ingrese marca nuevamente: ");
                    listarTipos(tipo, TAM_T);
                    pedirEntero(&auxTipo, "Ingrese el tipo de bicicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, tipoMax);
                    listarColores(colores, TAM_C);
                    pedirEntero(&auxColor, "Ingrese color de biicleta por id: ", "Error, id de tipo invalido. Reingrese: ", tipoMin, colorMax);
                    ingresarRodado(&rodado);

                    printf("Ingrese material carbono o alumunio (c o a): ");
                    fflush(stdin);
                    scanf("%c", &material);

                    while(material != 'c' && material != 's')
                    {
                        printf("Error. Reingrese material, carbono o alumunio (c o a): ");
                        fflush(stdin);
                        scanf("%c", &material);
                    }

                    pedirEntero(&dia,"Ingrese dia: ", "Error. Invalido Reingrese dia: ",diaMin,diaMax);
                    pedirEntero(&mes,"Ingrese mes: ", "Error. Invalido Reingrese mes: ",diaMin,mesMax);
                    pedirEntero(&anio,"Ingrese anio: ", "Error. Invalido Reingrese anio: ",anioMin,anioMax);

                addBicicleta(lista, TAM, nextId, auxMarca, auxTipo, auxColor, material,fecha, dia, mes, anio, rodado);
                nextId++;
                }
                else
                {
                    printf("No hay lugar en el sistema.\n");
                }
                entrar = 1;
                break;
            case 2:
                if(entrar)
                {
                    mostrarBicicletas(lista, TAM, tipo, TAM_T, colores, TAM_C, fecha);
                    modificarBicicleta(lista, TAM, fecha);
                }
                else
                {
                    printf("Primero se deben ingresar empleados \n");
                }

                break;
            case 3:
                if(entrar)
                {
                    mostrarBicicletas(lista, TAM, tipo, TAM_T, colores, TAM_C, fecha);
                    if(bajaBicicleta(lista,TAM))
                    {
                        printf("Baja exitosa. \n");
                    }
                }
                else
                {
                    printf("Primero debe ingresar una bicicleta. \n");
                }
                break;

            case 4:
                if(entrar)
                {
                pedirEntero(&orden, "Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ","Error. Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ",ordenAsc,ordenDesc );
                //ordenarBicicletas(lista, TAM, orden, fecha);
                mostrarBicicletas(lista, TAM, tipo, TAM_T, colores, TAM_C, fecha);
                }
                else
                {
                    printf("Primero se deben ingresar bicicletas \n");
                }
                break;
            case 5:
                listarTipos(tipo, TAM_T);
                break;
            case 6:
                listarColores(colores, TAM_C);
                break;
            case 7:
                listarServicio(servicio, TAM_S);
                break;
            case 8:
                break;
            case 10:
                pedirCaracter(&seguir, "Desea salir? s/n", "Saliendo...", 's');
                break;
            default:
                printf("Opcion incorrecta.\n");
                fflush(stdin);
                break;
        }

        system("pause");
    }while(seguir != 's');

    return 0;
}
