
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gets.h"


typedef struct
{
    int idDuenio;
    char nombre[100];
    char apellido[100];
    char localidad[100];
    char telefono[100];
    int edad;
    char sexo;
    int estado;
}sDuenio;

/** \brief Harcodea un listado de dueños con todos sus datos
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \return void
 *
 */
void hardcodearDuenio(sDuenio duenio[]);

/** \brief Inicializa el vector de estado en LIBRE (0)
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return void
 *
 */
void inicializarDuenio(sDuenio duenio[],int tam );

/** \brief Muestra el listado de dueños
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return void
 *
 */
void mostrarDuenio(sDuenio duenio[],int tamDuenio);

/** \brief Busca una posicion libre (0) dentro del vector de estado
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return int retorna la posicion del vector libre si lo encontro, o (-1) si no lo encontro
 *
 */
int buscarLibreDuenio(sDuenio duenio[],int tam);

/** \brief Busca el maximo de idDuenio y lo incrementa
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return int retorna el maximo incrementado en uno
 *
 */
int generarIDDuenio(sDuenio duenio[],int tam);

/** \brief Agrega una mascota al listado
 *
 * \param recibe el vector de dueños
 * \param recibe el tamaño de dueños
 * \return retorna (0)ok, (-1) no encontro espacio disponible dentro del vector estado
 *
 */
int altaDuenio(sDuenio duenio[],int tam);

/** \brief Se pide ingresar al usuario el id de mascota, y cambia el valor de sus datos
 *
 * \param duenio[] sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return int retorna (0) ok ,(-1) no se encontro el vector
 *
 */
int modificarDuenio(sDuenio duenio[], int tamDuenio);

/** \brief Calcula el promedio entre varones y mujeres del total de dueños
 *
 * \param duenio sDuenio recibe el vector de dueños
 * \param tam int recibe el tamaño de dueños
 * \return void retorna el promedio de varones y mujeres ya calculado
 *
 */
void promedioEntreVaronesYMujeres(sDuenio duenio[], int tam);



