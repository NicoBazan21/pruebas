#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "colores.h"
#include "tipo.h"
#include "servicios.h"


int menu()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 10;

    system("cls");
    printf("\t ***Nomina de Bicicletas***\n");
    printf("------------------------------------\n");
    printf(" 1. ALTA BICICLETA\n");
    printf(" 2. MODIFICAR BICICLETA\n");
    printf(" 3. BAJA BICICLETA\n");
    printf(" 4. LISTAR BICICLETAS\n");
    printf(" 5. LISTAR TIPOS\n");
    printf(" 6. LISTAR COLORES\n");
    printf(" 7. LISTAR SERVICIOS\n");
    printf(" 8. ALTA TRABAJO\n");
    printf(" 10. Salir\n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}


void mostrarBicicleta(eBicicleta hola, eFecha fecha, eTipo tipo, eColores color)
{

    printf("  %d\t%10s \t%c\t %10s%10s \t %.2f%d/%d/%d\n",
            hola.id,
            hola.marca,
            hola.marterial,
            tipo.tipoDesc,
            color.descColor,
            hola.rodado,
            fecha.dia,
            fecha.mes,
            fecha.anio
            );

}

int mostrarBicicletas(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColores color[],int tamC, eFecha fecha[])
{
    int todoOk=0;

    int holis=0;


    if(lista != NULL && tam >0 && fecha != NULL)
    {
        system("cls");
        printf("\t ***Listado de Bicicleats***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id\t    Marca\tTipo\t Material\t  Color\t Rodado\t Fecha\n");
        printf("-----------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
           if(lista[i].isEmpty == 0)
           {
                mostrarBicicleta(lista[i], fecha[i], tipo[i], color[i]);
                holis=1;
           }
        }
        if(!holis)
        {
            printf("No hay personas para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}


/*int ordenarBicicletas(eBicicleta list[], int len, int order, eFecha fecha[], eTipo tipo, int tam_T)
{
    int todoOk=0;

    int holis=0;

    char auxTipo[20];

    eBicicleta auxiliar;
    eFecha auxiliarFecha;

    if(list != NULL && len >0)
    {
        system("cls");
        printf("\t ***Listado de bicicletas***\n");
        printf("----------------------------------------------------------------------\n");
        printf("  Id\t    Marca\t Tipo\t Color\t Material\t Fecha de creacion\n");
        printf("----------------------------------------------------------------------\n");



        for(int i=0;i<len-1;i++)
        {
            for(int j = i+1; j < len; j++)
            {
                cargarDescTipo(tipo, tam_T, tipo.id, auxTipo);

                if(order==1 &&
                ((strcmp(list[i].aux, list[j].lastName)>0) ||
                ((strcmp(list[i].lastName, list[j].lastName)==0) && (list[i].sector>list[j].sector))))
                {
                    auxiliar=list[i];
                    auxiliarFecha=fecha[i];

                    list[i]=list[j];
                    fecha[i]=fecha[j];

                    list[j]=auxiliar;
                    fecha[j]=auxiliarFecha;
                }
                else
                {
                if(order==2 &&
                ((strcmp(list[i].lastName, list[j].lastName)<0) ||
                ((strcmp(list[i].lastName, list[j].lastName)==0) && (list[i].sector<list[j].sector))))
                    {
                        auxiliar=list[i];
                        list[i]=list[j];
                        list[j]=auxiliar;
                    }
                }
            }
        }
        for(int h = 0; h < len; h++)
        {
            if(list[h].isEmpty == 0)
            {
                mostrarBicicleta(list[h], fecha[h]);
                holis=1;
            }
        }
        if(!holis)
        {
            printf("No hay personas para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}
*/


int inicializarBicicletas(eBicicleta list[], int len)
{
    int todoOk = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len;i++)
        {
            list[i].isEmpty=1;//esto significa que esta vacío
        }
        todoOk=1;
    }

    return todoOk;
}


int validarNumCadenas(char* name, int tam)
{
    int todoOk= 0;
    int okey;
    int error = 1;

    if(name != NULL && tam > 0)
    {
        do{
            error=0;
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);
                if(okey == 0)
                {
                    printf("Error. Ingreso con caracteres invalidos. Ingrese nuevamente: ");
                    gets(name);
                    tam=strlen(name);
                    error = 1;
                }
            }

        }while(error == 1);

        todoOk=1;
    }
    return todoOk;
}

int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[])
{
    int todoOk =0;
    char entrada[256];
    int tamEntrada;

    if(cadena != NULL && tam > 0 && mensajeUno != NULL && mensajeError != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        gets(entrada);
        tamEntrada = strlen(entrada);

        validarNumCadenas(entrada, tamEntrada);

        while(tamEntrada > tam || tamEntrada < 1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(entrada);
            tamEntrada=strlen(entrada);
        }

        strcpy(cadena, entrada);
        todoOk=1;
    }

    return todoOk;
}


int pedirCaracter(char *caracter, char mensajeUno[], char mensajeError[], char si)
{
    int todoOk = 0;

    if(caracter != NULL && mensajeError != NULL && mensajeUno != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%c", caracter);

        if(*caracter != si)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%c", caracter);
        }
    }


    return todoOk;
}

int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max)
{
    int todoOk =0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%f", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }

        todoOk=1;
    }


    return todoOk;
}

int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max)
{
    int todoOk=0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%d", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }

    todoOk=1;
    }

    return todoOk;
}

int buscarLibre(eBicicleta lista[], int tam)
{
    int libre = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}

//addBicicleta(lista, TAM, nextId, auxMarca, auxTipo, auxColor, material ,fecha , dia, mes, anio);
int addBicicleta(eBicicleta list[], int len, int id, char marca[],int tipo,int color,char material, eFecha fecha[], int dia, int mes, int anio, float rodado)
{
    int todoOk = -1;
    int libre;

    if(list != NULL && len > 0 && id > 0 && marca != NULL && tipo > -1 && color > -1 && fecha != NULL && dia > 0 && mes > 0 && anio > 0)
    {
        libre = buscarLibre(list, len);
        todoOk=1;

        strlwr(marca);
        marca = toupper(marca);

        fecha[libre].dia=dia;
        fecha[libre].mes=mes;
        fecha[libre].anio=anio;

        //no valido el buscar libre, porque ya antes pasó en el main por una validacion
            list[libre].id=id;
            strcpy(list[libre].marca, marca);
            list[libre].rodado=rodado;
            list[libre].idTipo=tipo;
            list[libre].idColor=color;
            list[libre].marterial=material;
            list[libre].isEmpty=0;

    }

    return todoOk;
}



int findBicicletaById(eBicicleta* list, int len,int iDe)
{
    int indice = -1;

    if(list != NULL && len > 0 && (iDe > 0 && iDe <= len))
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == iDe && list[i].isEmpty == 0)
            {
                indice=i;
                break;
            }
        }
    }
        if(indice == -1)
        {
            printf("No existe la bicicleta. \n");
        }
    return indice;
}

int bajaBicicleta(eBicicleta* list, int len)
{
    int todoOk = 0;
    int indice;
    char seguro;

    if(list != NULL && len > 0)
    {
        printf("Ingrese id para dar de baja: ");
        scanf("%d", &indice);

        printf("Esta seguro?: ");
        fflush(stdin);
        scanf("%c", &seguro);

        while(seguro != 's' && seguro != 'n')
        {
            printf("Error. Esta seguro de dar de baja?: ");
            fflush(stdin);
            scanf("%c", &seguro);
        }

        if(seguro == 's')
        {
             list[indice].isEmpty=1;

            todoOk=1;
        }
    }

    return todoOk;
}

int menuModificacion()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 4;

    printf("\t *** Modificacion de datos ***\n");
    printf("------------------------------------\n");

    printf("1. Modificar tipo\n");
    printf("2. Modificar rodado\n");
    printf("3. Salir \n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}

/*int printBicicleta(eBicicleta* list, int len, eFecha fecha[])
{
    int todoOk=0;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t ***Listado de personas***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id\t    Nombre\tApellido\t Salario\t Sector\t\n");
        printf("-----------------------------------------------------\n");

        for(int h = 0; h < len; h++)
        {
            if(list[h].isEmpty == 0)
            {
                mostrarBicicleta(list[h], fecha[h]);
            }
        }
    }

    return todoOk;
}
*/
int ingresarRodado(float* rodado)
{
    int todoOk = 0;
    float aux;

    if(rodado!=NULL)
    {
        printf("Ingrese rodado(20, 26, 27.5, 29): ");
        fflush(stdin);
        scanf("%f",&aux);
        while(aux != 20 && aux != 26 && aux != 27.5 && aux != 29)
        {
            printf("Rodado invalido. Reingrese el rodado.\n");
            fflush(stdin);
            scanf("%f",&aux);
        }
        *rodado=aux;
    todoOk = 1;
    }
    return todoOk;
}

int modificarBicicleta(eBicicleta lista[], int tam, eFecha fecha[])
{
    int todoOk=0;
    int indice;
    int buscarId;
    char confirmar;
    char auxMarca[20];
    int marcaCambio = 0;
    float auxRodado;
    int rodadoCambio = 0;

    char seguir = 'n';

    int min = 0;
    int max =1000;

    if(lista != NULL && tam > 0)
    {
        printf("\n");
        printf("     ***  Menu Modificar  ***\n\n");

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
                do{
                    system("cls");
                    switch(menuModificacion())
                    {
                        case 1:
                            pedirCadena(auxMarca, 20, "Ingrese marca: ", "Error, marca invalida. Ingrese marca nuevamente: ");
                            strlwr(auxMarca);
                            auxMarca[0] = toupper(auxMarca[0]);

                            strcpy(lista[indice].marca, auxMarca);
                            marcaCambio=1;
                            break;
                        case 2:
                            ingresarRodado(&auxRodado);
                            lista[indice].rodado=auxRodado;
                            rodadoCambio=1;
                            break;
                        default:
                            printf("Opcion invalida\n");
                            break;
                    }
                    system("pause");
                }while(seguir == 'n');
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion. \n");
            }
            if(marcaCambio)
            {
                printf("Se ha cambiado la marca a: %s\n", lista[indice].marca);
            }
            if(rodadoCambio)
            {
                printf("Se ha cambiado el rodado a: %.2f \n", lista[indice].rodado);

            }
        }
    }
    return todoOk;

}

