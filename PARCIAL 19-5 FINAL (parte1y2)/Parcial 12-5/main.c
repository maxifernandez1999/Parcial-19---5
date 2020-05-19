#include <stdio.h>
#include <stdlib.h>
#include "mascota_dueño.h"
#define D 10
#define M 20
#define R 40 // 2 razas por tipo de mascota
#define LIBRE 0
#define OCUPADO 1
int main()
{
    sDuenio listadoDuenio[10];
    sMascota listadoMascota[20];
    sRaza tipoRaza[40];
    int opcion;
    int baja;
    int ordenarTipo;
    int ordCant;
    int ordCantNombres;
    float promedio;
    int retornoDuenio;
    int retornoMascota;
    int retornoAltaMascota;
    int retornoAltaDuenio;

    inicializarDuenio(listadoDuenio,D);
    inicializarMascota(listadoMascota,M);

    hardcodearDuenio(listadoDuenio);
    hardcodearMascota(listadoMascota);
    hardcodearTipoRaza(tipoRaza);

    printf("###### MENU VETERINARIA ######\n");
    printf("\n");
    do
    {
        printf("1) Mostrar listado de duenios\n");
        printf("2) Mostrar listado de mascotas\n");
        printf("3) Mostrar duenios con sus mascotas\n");
        printf("4) Agregar una mascota\n");
        printf("5) Eliminar una mascota\n");
        printf("6) Modificar una mascota\n");
        printf("7) Agregar un duenio\n");
        printf("8) Eliminar un duenio\n");
        printf("9) Ordenar mascotas por tipo y listarlos con su duenio\n");
        printf("10) Modificar un duenio\n");
        printf("11) Lista duenios con mas de una mascota\n");
        printf("12) Mascotas de mas de tres anios con sus dueños\n");
        printf("13) Listar las mascotas por tipo\n");
        printf("14) Ordenar duenios por cantidad de mascotas\n");
        printf("15) Ordenar duenios por cantidad de mascotas y por nombre\n");
        printf("16) Promedio de edad entre las mascotas\n");
        printf("17) Promedio de edad entre mascotas, por tipo\n");
        printf("18) Promedio entre cantidad de varones y de mujeres\n");
        printf("19) Listar los duenios que tienen mascotas del mismo sexo\n");
        printf("20) Salir\n");
        opcion = getInt("Ingrese una opcion: ","ERROR, reingrese una opcion valida: ",1,20);
        system("cls");
        switch(opcion)
        {
            case 1:
                mostrarDuenio(listadoDuenio, D);
            break;
            case 2:
                mostrarMascota(listadoMascota, M, listadoDuenio, D);
                mostrarDescripcionRazaSegunId(listadoMascota,M,tipoRaza,R);
            break;
            case 3:
                mostrarMascotaConSuDuenio(listadoMascota, M, listadoDuenio, D);
            break;
            case 4:
                printf("LISTADO DE DUENIOS DISPONIBLES\n");
                printf("\n");
                mostrarDuenio(listadoDuenio, D);
                retornoAltaMascota = altaMascota(listadoMascota,M);
                printf("\n");

                switch(retornoAltaMascota)
                {
                    case 0:
                        printf("\n");
                        printf("Agregado exitosamente\n");
                        printf("\n");
                    break;
                    case -1:
                        printf("NO se ha encontrado espacio disponible\n");
                    break;
                    default:
                    break;
                }
            break;
            case 5:
                mostrarMascota(listadoMascota,M, listadoDuenio,D);
                baja = bajaMascota(listadoMascota, M);
                switch(baja)
                {
                    case -1:
                        printf("NO SE HA ENCONTRADO EL ID!!!\n");
                    break;
                    case 0:
                        printf("Eliminado con exito\n");
                    break;
                    case 1:
                        printf("operacion cancelada\n");
                    break;
                    default:
                    break;
                }
            break;
            case 6:
                mostrarMascota(listadoMascota,M, listadoDuenio,D);
                mostrarDescripcionRazaSegunId(listadoMascota,M,tipoRaza,R);
                retornoMascota = modificarMascota(listadoMascota, M,listadoDuenio,D);
                switch(retornoMascota)
                {
                    case 0:
                        printf("modificado con exito\n");
                    break;
                    case -1:
                        printf("no se ha encontrado el id\n");
                    break;
                    default:
                    break;
                }
            break;
            case 7:
                retornoAltaDuenio = altaDuenio(listadoDuenio, D);
                switch(retornoAltaDuenio)
                {
                    case 0:
                        printf("\n");
                        printf("Agregado exitosamente\n");
                        printf("\n");
                    break;
                    case -1:
                        printf("NO se ha encontrado espacio disponible\n");
                    break;
                    default:
                    break;
                }
            break;
            case 8:
                mostrarDuenio(listadoDuenio,D);
                bajaDuenioEnCascada(listadoDuenio, D, listadoMascota,M);
            break;
            case 9:
                ordenarTipo = getInt("1) Ordenar mascotas por tipo de la 'a' a la 'z'\n2) Ordenar mascotas por tipo de la 'z' a la 'a'\n","Ingrese una opcion valida\n",1,2);
                switch(ordenarTipo)
                {
                    case 1:
                        OrdenasMascotasPorTipo(listadoMascota, M,listadoDuenio,D,1);
                    break;
                    case 2:
                        OrdenasMascotasPorTipo(listadoMascota, M,listadoDuenio,D,2);
                    break;
                    default:
                    break;
                }

            break;
            case 10:
                mostrarDuenio(listadoDuenio,D);
                retornoDuenio = modificarDuenio(listadoDuenio, D);
                switch(retornoDuenio)
                {
                    case 0:
                        printf("modificado con exito\n");
                    break;
                    case -1:
                        printf("no se ha encontrado el ID\n");
                    break;
                    default:
                    break;
                }
            break;
            case 11:
                 clientesConMasDeUnaMascota(listadoMascota,M,listadoDuenio,D);
            break;
            case 12:
                mascotasConMasTresAnios(listadoMascota, M, listadoDuenio, D);
            break;
            case 13:
                listarMascotasPorTipo(listadoMascota, M);
            break;
            case 14:
                ordCant = getInt("1) Ordenar de menor a mayor cantidad de mascotas\n2) Ordenar de mayor a menor cantidad de mascotas\nElija una opcion\n","Error, ingrese una opcion valida\n",1,2);
                switch(ordCant)
                {
                    case 1:
                        ordenarDueniosPorCantidadMascotas(listadoMascota,M,listadoDuenio,D,1);
                    break;
                    case 2:
                        ordenarDueniosPorCantidadMascotas(listadoMascota,M,listadoDuenio,D,2);
                    break;
                    default:
                    break;
                }
            break;
            case 15:
                ordCantNombres = getInt("1) Ordenar de menor a mayor cantidad de mascotas y de a - z los nombres\n2) Ordenar de mayor a menor cantidad de mascotas y de z - a los nombres\nElija una opcion\n","Error, ingrese una opcion valida",1,2);
                switch(ordCantNombres)
                {
                    case 1:
                        ordenarDueniosPorCantidadMascotasYNombre(listadoMascota,M,listadoDuenio,D,1);
                    break;
                    case 2:
                        ordenarDueniosPorCantidadMascotasYNombre(listadoMascota,M,listadoDuenio,D,2);
                    break;
                    default:
                    break;
                }
            break;
            case 16:
                promedio = promedioEdadesMascotas(listadoMascota,M);
                printf("---------------------------------------------------------------\n");
                printf("El promedio de edad entre todas las mascotas es: %.2f\n", promedio);
                printf("---------------------------------------------------------------\n");
            break;
            case 17:
                promedioEdadesMascotasPorTipo(listadoMascota,M);
            break;
            case 18:
                promedioEntreVaronesYMujeres(listadoDuenio,D);
            break;
            case 19:
                listarDueniosMascotasMismoSexo(listadoDuenio,D,listadoMascota,M);
            break;
            default:
            break;
        }
    }while(opcion != 20);


    return 0;
}
