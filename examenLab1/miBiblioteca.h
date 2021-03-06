#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "colores.h"
#include "tipo.h"
#include "servicios.h"


typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char marterial;
    float rodado;
    int isEmpty;


}eBicicleta;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

#endif // MIBIBLIOTECA_H_INCLUDED

/** \brief menu muestra opciones
 *
 * \return int devuelve la opcino seleccionada
 *
 */
int menu();

/** \brief se le pasa el indice de la estructura
 *
 * \param hola eEmployee muestra el empleado del indice
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta hola, eFecha fecha, eTipo tipo, eColores color);

/** \brief recibe una estructura entera
 *
 * \param lista[] eEmployee y muestra todos los empleados activos
 * \param tam int tama?o de la estructura
 * \return int retorna 1 ok o 0 fallo
 *
 */
int mostrarBicicletas(eBicicleta lista[],int tam, eTipo tipo[], int tamT, eColores color[],int tamC, eFecha fecha[]);

/** \brief recibe una estructura el tama?o y el criterio de orden
 *
 * \param list[] eEmployee se usa para mostrar a los empleados
 * \param len int el tama?o de la estructura
 * \param order int el criterio de orden 1 para ascendente y 2 para descendente

 * \return int
 *
 */
int ordenarBicicletas(eBicicleta list[], int len, int order, eFecha fecha[]);

/** \brief recibe la lista de empleados el tama?o
 *
 * \param list[] eEmployee inicializa todos los casilleros de los empleados en libres
 * \param len int   tama?o de la struct
 * \return int
 *
 */
int inicializarBicicletas(eBicicleta list[], int len);

/** \brief recibe la lista, el tama?o, el ide, el nombre, apellido, salario, y sector
 *
 * \param list eEmployee*  recibe todos los datos
 * \param len int   e inicializa el isempty en false
 * \param id int    para declarar que la posicion I en el array esta ocupada
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addBicicleta(eBicicleta list[], int len, int id, char marca[],int tipo,int color,char material, eFecha fecha[], int dia, int mes, int anio, float rodado);
/** \brief recibe un array y el tama?o
 *
 * \param name char*    valida que no existan caracteres ajenos a de tipo CHAR
 * \param tam int
 * \return int
 *
 */
int validarNumCadenas(char* name, int tam);

/** \brief pide una cadena de texto y un mensaje de pedido y otro de error
 *
 * \param cadena[] char recibe el array donde almacenar el texto
 * \param tam int   el tama?o del array a usar
 * \param mensajeUno[] char el mensaje de pedido
 * \param mensajeError[] char   el mensaje de error
 * \return int
 *
 */
int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[]);

/** \brief pide un caracter un mensaje de error y un mensaje de pedido
 *
 * \param caracter char*    recibe la vairable donde guardar el caracter
 * \param mensajeUno[] char el mensaje de pedido
 * \param mensajeError[] char   el mensaje de error
 * \param si char   el caracter esperado
 * \return int
 *
 */
int pedirCaracter(char *caracter, char mensajeUno[], char mensajeError[], char si);

/** \brief funcion que pide numeros flotantes, con un mensaje de pedido, un mensaje de error y parametros minimos o maximos
 *
 * \param numero float* variable donde se guardara el numero ingresado
 * \param mensajeUno[] char mensaje de pedido
 * \param mensajeError[] char   mensaje de error
 * \param min float minimo esperado
 * \param max float maximo esperado
 * \return int
 *
 */
int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max);

/** \brief funcion que pide numeros enteros, con un mensaje de pedido, un mensaje de error y parametros minimos o maximos
 *
 * \param numero int* variable donde se guardara el numero ingresado
 * \param mensajeUno[] char mensaje de pedido
 * \param mensajeError[] char   mensaje de error
 * \param min int   minimo esperado
 * \param max int   maximo esperado
 * \return int
 *
 */
int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max);

/** \brief funcion que busca espacios libres como isempty en 1
 *
 * \param lista[] eEmployee recibe el array de empleados
 * \param tam int   el tama?o del array
 * \return int
 *
 */
int buscarLibre(eBicicleta lista[], int tam);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findBicicletaById(eBicicleta* list, int len,int iDe);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int bajaBicicleta(eBicicleta* list, int len);

/** \brief funcion para modificar uno o todos los datos de una persona en un array de empleados
 *
 * \param lista[] eEmployee recibe la estructura de empleados
 * \param tam int   y recibe el tama?o del array
 * \return int
 *
 */
int modificarBicicleta(eBicicleta lista[], int tam, eFecha fecha[]);

/** \brief menu para la modificacion de datos de un empleado
 *
 * \return int  muestra las opciones disponibles y retorna la opcion ingresada
 *
 */
int menuModificacion();

int ingresarRodado(float* rodado);
