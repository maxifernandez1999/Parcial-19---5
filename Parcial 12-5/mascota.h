#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idMascota;
    int idDuenio;
    int idRaza;
    char nombre[100];
    char tipo[100];
    char raza[100];
    int edad;
    float peso;
    char sexo;
    int estado;
}sMascota;

typedef struct{
    int idRaza;
    char Descripcion[100];
    char pais[100];
}sRaza;


/** \brief Harcodea un listado de razas con todos sus datos
 *
 * \param tipoRaza[] sRaza recibe el vector de razas
 * \return void
 *
 */
void hardcodearTipoRaza(sRaza tipoRaza[]);

/** \brief Hardodea un listado de mascotas con todos sus datos
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \return void
 *
 */
void hardcodearMascota(sMascota mascota[]);

/** \brief Inicializa los elementos del vector de estado en 0 (LIBRE)
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return void
 *
 */
void inicializarMascota(sMascota mascota[],int tam);

/** \brief Busca una posicion libre(0) dentro del vector de estado
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return int retorna la posicion del vector libre si lo encontro, o (-1) si no lo encontro
 *
 */
int buscarLibreMascota(sMascota mascota[],int tam);

/** \brief Busca el maximo de idMascota y lo incrementa
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return int retorna el maximo incrementado en uno
 *
 */
int generarIDMascota(sMascota mascota[],int tam);

/** \brief Se pide al usuario que ingrese un id y elimina de manera logica una mascota cambiando su estado
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return int retorno (0) completado con exito, (1) operacion cancelada, (-1) si no se encontro el Id
 *
 */
int bajaMascota(sMascota mascota[], int tam);

/** \brief Agrega una mascota al listado
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return int retorna (0)ok, (-1) no encontro espacio disponible dentro del vector estado
 *
 */
int altaMascota(sMascota mascota[],int tam);

/** \brief Se pide ingresar al usuario el id de mascota, y cambia el valor de sus datos
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return int retorna (0) ok ,(-1) no se encontro el vector
 *
 */
int modificarMascota(sMascota mascota[],int tam);

/** \brief Muestra listado de mascotas por su tipo en particular
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tamaño de mascotas
 * \return void
 *
 */
void listarMascotasPorTipo(sMascota mascota[], int tamMascota);

/** \brief Calcula el promedio de edades entre las mascotas
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return float retorna el promedio de edades
 *
 */
float promedioEdadesMascotas(sMascota mascota[], int tam);

/** \brief Calcula el promedio de edades entre las animales por un tipo en particular
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tamaño de mascotas
 * \return void
 *
 */
void promedioEdadesMascotasPorTipo(sMascota mascota[], int tam);

/** \brief Muestra el idRazas con sus datos
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tamaño de mascotas
 * \param tipoRaza[] sRaza recibe le vector de razas
 * \param tamRaza int recibe el tamaño de razas
 * \return void
 *
 */
void mostrarDescripcionRazaSegunId(sMascota mascota[], int tamMascota, sRaza tipoRaza[],int tamRaza);
