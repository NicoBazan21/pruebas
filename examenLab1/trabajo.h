#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"

typedef struct{

    int id;
    int idBici;
    int idServ;
    int dia;
    int mes;
    int anio;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

