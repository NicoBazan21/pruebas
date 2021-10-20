#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct{

    int id;
    char tipoDesc[20];


}eTipo;


#endif // TIPO_H_INCLUDED

void mostrarTipo(eTipo hola);

int listarTipos(eTipo lista[], int tam);

int cargarTipo(eTipo lista[], int tam, char tipo[], int id);

int cargarDescTipo(eTipo tipo[], int tam, int idTipo, char descTipo[]);
