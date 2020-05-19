#include "mascota.h"
#include "due�o.h"
typedef struct
{
    int idDuenio;
    int cantidadMascotas;
}Duenio_Mascota;

/** \brief Muestra todos los due�os con su listado de mascotas
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \return void
 *
 */
void mostrarMascotaConSuDuenio(sMascota mascota[], int tamMascota,sDuenio duenio[],int tamDuenio);

/** \brief Se pide ingresar al usuario el id de mascota, y cambia el valor de sus datos
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tam int recibe el tama�o de mascotas
 * \return int retorna (0) ok ,(-1) no se encontro el vector
 *
 */
int modificarMascota(sMascota mascota[],int tamMascota,sDuenio duenio[], int tamDuenio);

/** \brief Muestra las mascotas con sus respectivos due�os
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \return void
 *
 */
void mostrarMascota(sMascota mascota[],int tamMascota,sDuenio duenio[], int tamDuenio,sRaza tipoRaza[],int tamRaza);

/** \brief Muestra los due�os que tienen mas de una mascota
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \return void
 *
 */
void clientesConMasDeUnaMascota(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio);

/** \brief Muestra las mascotas de mas de 3 a�os de edad con sus due�os
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \return void
 *
 */
void mascotasConMasTresAnios(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio);

/** \brief Ordena y muestra las mascotas por un tipo en particular
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \param orden int recibe el orden de ordenamiento
 * \return void
 *
 */
void OrdenasMascotasPorTipo(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden, sRaza tipoRaza[] , int tamRaza);

/** \brief Realiza una baja de mascota por el id del due�o
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \param idDuenio int recibe el id del due�o ingresado
 * \return void
 *
 */
void bajaMascotaPorDuenio(sMascota mascota[], int tamMascota, int idDuenio);

/** \brief Realiza una baja logica del due�o y a su vez elimina todas sus mascotas
 *
 * \param duenio[] sDuenio  recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \return int retorna (0)ok, (-1) no encontro espacio disponible dentro del vector estado
 *
 */
int bajaDuenioEnCascada(sDuenio duenio[],int tamDuenio, sMascota mascota[], int tamMascota);

/** \brief Ordena el listado de due�os por la cantidad de mascotas que tienen
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el vector de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \param orden recibe el orden del ordenamiento del listado de due�os
 * \return void
 *
 */
void ordenarDueniosPorCantidadMascotas(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden);

/** \brief Ordena el listado de due�os por la cantidad de mascotas y sus nombres
 *
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el vector de mascotas
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamDuenio int recibe el tama�o de due�os
 * \param orden recibe el orden del ordenamiento del listado de due�os
 * \return void
 *
 */
void ordenarDueniosPorCantidadMascotasYNombre(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden);

/** \brief Lista los due�os segun el sexo de su mascota
 *
 * \param duenio[] sDuenio recibe el vector de due�os
 * \param tamduenio int recibe el tama�o de due�os
 * \param mascota[] sMascota recibe el vector de mascotas
 * \param tamMascota int recibe el tama�o de mascotas
 * \return void
 *
 */
void listarDueniosMascotasMismoSexo(sDuenio duenio[], int tamduenio, sMascota mascota[],int tamMascota);
