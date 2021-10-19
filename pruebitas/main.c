#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char nico[51];
    int hola;
    int cantidad;
    int error;

    fflush(stdin);
    gets(nico);

    cantidad = strlen(nico);

    printf("%d \n", cantidad);

        for(int i = 0; i < cantidad; i++)
        {
            hola = isalpha(nico[i]);
            if(hola == 0)
            {
                printf("Error. \n %d", hola);
                error=1;
            }
        }
        while(error==1)
        {
            error=0;
            for(int i = 0; i < cantidad; i++)
            {
                hola = isalpha(nico[i]);
                if(hola == 0)
                {
                    printf("Error. \n %d", hola);
                    error=1;
                    gets(nico);
                    cantidad = strlen(nico);
                }
            }
        }


    return 0;
}

/*int validarNumCadenas(char* name, int tam)
{
    int todoOk= 0;
    int okey;
    int error;

    if(name != NULL && tam > 0)
    {
        do{
            tamEntrada = strlen(entrada);
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);
                if(okey == 0)
                {
                    printf("Error. Ingreso con caracteres invalidos. Ingrese nuevamente: ");
                    gets(name);
                }
            }
        }while(error);

        todoOk=1;
    }
    return todoOk;
}
*/



    //hola = isalpha(nico);

    //printf("%d", hola);

    //hola = isalpha(nico[0]);
    //printf("%d", hola);
