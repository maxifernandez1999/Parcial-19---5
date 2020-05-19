#include "mascota_dueño.h"
#include "gets.h"
#define LIBRE 0
#define OCUPADO 1

void mostrarMascotaConSuDuenio(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio)

{
    int i;
    int j;
    for(i = 0;i < tamDuenio; i++)
    {
        if(duenio[i].estado == OCUPADO)
        {
            //muestra los duenios
            printf("Nombre: %s\n",duenio[i].nombre);
            printf("Apellido: %s\n",duenio[i].apellido);
            printf("Localidad: %s\n",duenio[i].localidad);
            printf("Telefono: %s\n",duenio[i].telefono);
            printf("-----------------------------------------------------------\n");
            printf("**********NOMBRE***********TIPO***********ID RAZA*************\n");
            printf("-----------------------------------------------------------\n");
            for(j = 0; j < tamMascota; j++)
            {
                if(mascota[j].estado == OCUPADO && duenio[i].idDuenio == mascota[j].idDuenio) // relaciona pk con fk
                {
                    //muestra sus respectivas mascotas
                    printf("%15s %15s %15d\n",mascota[j].nombre,mascota[j].tipo,mascota[j].idRaza);
                }
            }
        printf("-----------------------------------------------------------\n");
        }
    }
}
int modificarMascota(sMascota mascota[],int tamMascota, sDuenio duenio[], int tamDuenio)
{
    int aux;
    int i;
    int opcion;
    int retorno;
    aux = getInt("Ingrese el ID a modificar : \n","Error,ingrese un ID valido(ID de mascotas comienza en N°100)",100,120);

    for(i = 0; i < tamMascota; i++)
    {
        if(mascota[i].idMascota == aux && mascota[i].estado == OCUPADO) // comprueba si los id de las mascotas son igual al ingresado y si el estado es ocupado
        {
            opcion = getInt("Ingrese el campo a modificar: \n1. Nombre\n2. Tipo\n3. ID raza\n4. Edad\n5. Peso\n6. Sexo\n7. Modificar Duenio\n","Error, ingrese una opcion valida.\n",1,7);
            printf("*************************\n");
            switch(opcion)
            {
                case 1:
                    getString("Ingrese el Nombre: ",mascota[i].nombre);
                break;
                case 2:
                    getString("Ingrese el Tipo: ",mascota[i].tipo);
                break;
                case 3:
                    mascota[i].idRaza = getInt("Ingrese ID de la raza: ","Ingrese un ID valido(1 - 11)", 1, 11);
                break;
                case 4:
                    mascota[i].edad = getInt("Ingrese Edad: ","Ingrese una edad valida (0 - 100)",1,100);
                break;
                case 5:
                    mascota[i].peso = getFloat("Ingrese Peso: ","Ingrese un peso valido (0 - 150)",0,150);
                break;
                case 6:
                    mascota[i].sexo = getCharacter("Ingrese sexo: ('m' o 'f'): ","Error, reingrese un sexo valido('m' para masculino / 'f' para femenino)",'a','z');
                break;
                case 7:
                    mostrarDuenio(duenio,tamDuenio);
                    modificarDuenio(duenio,tamDuenio);
                break;
                default:
                break;
            }
            retorno = 0; // retorna 0, todo ok
            break;
        }else
        {
            retorno = -1; // -1 no encontro id
        }
    }
    return retorno;
}


void mostrarMascota(sMascota mascota[],int tamMascota, sDuenio duenio[], int tamDuenio,sRaza tipoRaza[],int tamRaza)
{
    int i;
    int j;
    int h;
    printf("*********NOMBRE************TIPO*********RAZA************EDAD************PESO*****SEXO****ID********NOMBRE DUENIO\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    // muestra mascotas con sus duenios
    for(i=0; i<tamMascota; i++)
    {
        if(mascota[i].estado == OCUPADO) // filtra los ocupados
        {
            for(j=0;j<tamDuenio;j++)
            {
                if(duenio[j].estado == OCUPADO)
                {
                    for(h = 0; h < tamRaza;h++)
                    {
                        if(duenio[j].idDuenio == mascota[i].idDuenio && mascota[i].idRaza == tipoRaza[h].idRaza)
                        {
                            printf("%15s %15s %15s %10d \t\t%.2f \t%4c \t%4d %15s\n", mascota[i].nombre, mascota[i].tipo, tipoRaza[h].Descripcion, mascota[i].edad, mascota[i].peso,mascota[i].sexo,mascota[i].idMascota, duenio[j].nombre);

                        }
                    }
                }
            }
        }
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void clientesConMasDeUnaMascota(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio)
{
    int i;
    int j;
    Duenio_Mascota auxDuenioMascota[tamDuenio];

    for(i = 0;i < tamDuenio; i++)
    {
        auxDuenioMascota[i].idDuenio = duenio[i].idDuenio; // relaciona dos estructuras
        auxDuenioMascota[i].cantidadMascotas = 0; // inicializa el vector de cantidades de mascotas en 0
    }
    for(i=0; i<tamDuenio; i++)
    {
        for(j=0; j<tamMascota; j++)
        {
            if(mascota[j].estado==OCUPADO && auxDuenioMascota[i].idDuenio == mascota[j].idDuenio) // relaciones fk con pk
            {
                auxDuenioMascota[i].cantidadMascotas++; // incrementa la cantidad de mascotas de los duenios
            }
        }
    }
    printf("DUENIOS CON MAS DE UNA MASCOTA\n");
    printf("------------------------------\n");
    printf("    NOMBRE MASCOTA    CANTIDAD\n");
    for(i=0;i<tamDuenio;i++)
    {
        if(auxDuenioMascota[i].cantidadMascotas > 1) // si esa cantidad de mascotas es mayor a 1 lo muestro
        {
           for(j=0;j<tamDuenio; j++)
           {
               if(auxDuenioMascota[i].idDuenio == duenio[j].idDuenio)
               {
                   printf("\t%2s \t%10d\n ", duenio[j].nombre, auxDuenioMascota[i].cantidadMascotas);
               }
           }
        }
    }
    printf("\n");
}
void mascotasConMasTresAnios(sMascota mascota[], int tamMascota, sDuenio duenio[],int tamDuenio)
{
    int i;
    int j;
    printf("MASCOTAS CON MAS DE TRES ANIOS CON SUS DUENIOS\n");
    printf("------------------------------------------------\n");
    printf("    NOMBRE MASCOTA        EDAD     NOMBRE DUENIO\n");
    printf("------------------------------------------------\n");
    printf("\n");
    for(i = 0; i < tamDuenio; i++)
    {
        for(j=0;j<tamDuenio; j++)
        {
            if(mascota[j].idDuenio == duenio[i].idDuenio && mascota[j].edad > 3) // relaciona las llaves y filtra las mascotas con mas de 3 años para mostrarlo
            {
                printf("\t%7s \t%4d %15s\n ", mascota[j].nombre, mascota[j].edad, duenio[i].nombre);
            }
        }

    }
    printf("-----------------------------------------------\n");


}
void ordenarDueniosPorCantidadMascotas(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden)
{
    int i;
    int j;
    Duenio_Mascota auxDuenioMascota[tamDuenio];
    Duenio_Mascota auxiliar;
    sDuenio auxiliarDuenio;
    for(i = 0;i < tamDuenio; i++)
    {
        auxDuenioMascota[i].idDuenio = duenio[i].idDuenio;
        auxDuenioMascota[i].cantidadMascotas = 0; // inicializa el vector de cantidad de mascotas en 0
    }
    for(i=0; i < tamDuenio; i++)
    {
        for(j=0; j<tamMascota; j++)
        {
            if(auxDuenioMascota[i].idDuenio == mascota[j].idDuenio) // relaciona fk con pk
            {
                auxDuenioMascota[i].cantidadMascotas++; // incrementa la cantidad de mascotas de los dueños
            }
        }
    }
    switch(orden)
    {
        case 1: // ordena las cantidades de mascotas de menor a mayor
            for(i = 0; i < tamDuenio-1; i++)
            {
                for(j = i+1; j < tamDuenio; j++)
                {
                    if(auxDuenioMascota[i].cantidadMascotas > auxDuenioMascota[j].cantidadMascotas)
                    {
                        auxiliar = auxDuenioMascota[i]; // swapeo auxDuenioMascota
                        auxDuenioMascota[i] = auxDuenioMascota[j];
                        auxDuenioMascota[j] = auxiliar;

                        auxiliarDuenio = duenio[i]; // swapeo de Duenio
                        duenio[i] = duenio[j];
                        duenio[j] = auxiliarDuenio;
                    }
                }
            }
        break;
        case 2: // ordena las cantidades de mascotas de mayor a menor
            for(i = 0; i < tamDuenio-1; i++)
            {
                for(j = i+1; j < tamDuenio; j++)
                {
                    if(auxDuenioMascota[i].cantidadMascotas < auxDuenioMascota[j].cantidadMascotas)
                    {
                        auxiliar = auxDuenioMascota[i];
                        auxDuenioMascota[i] = auxDuenioMascota[j];
                        auxDuenioMascota[j] = auxiliar;

                        auxiliarDuenio = duenio[i];
                        duenio[i] = duenio[j];
                        duenio[j] = auxiliarDuenio;
                    }
                }
            }
        break;
    }

    printf("          NOMBRE        APELLIDO      LOCALIDAD        TELEFONO        EDAD     SEXO     CANT MASCOTAS\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    for(i = 0;i<tamDuenio;i++)
    {
        if(duenio[i].estado ==  OCUPADO) // muestra todos los datos ya ordenados
        {
            printf("%15s %15s %15s %15s %10d %8c %10d\n" ,  duenio[i].nombre,
                                                            duenio[i].apellido,
                                                            duenio[i].localidad,
                                                            duenio[i].telefono,
                                                            duenio[i].edad,
                                                            duenio[i].sexo,
                                                            auxDuenioMascota[i].cantidadMascotas);
        }
    }
    printf("\n");
}
void ordenarDueniosPorCantidadMascotasYNombre(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden)
{
    int i;
    int j;
    Duenio_Mascota auxDuenioMascota[tamDuenio];
    Duenio_Mascota auxiliar;
    sDuenio auxiliarDuenio;
    for(i = 0;i < tamDuenio; i++)
    {
        auxDuenioMascota[i].idDuenio = duenio[i].idDuenio;
        auxDuenioMascota[i].cantidadMascotas = 0; // inicializa el vector de cantidad de mascotas en 0
    }
    for(i=0; i < tamDuenio; i++)
    {
        for(j=0; j<tamMascota; j++)
        {
            if(auxDuenioMascota[i].idDuenio == mascota[j].idDuenio) // relacion fk con pk
            {
                auxDuenioMascota[i].cantidadMascotas++; // incrementa la cantidad de mascotas de los dueños
            }
        }
    }
    switch(orden)
    {
        case 1: // ordena las cantidades de mascotas de menor a mayor y como segundo criterio, en orden alfabetico de la a a la z
            for(i = 0; i < tamDuenio-1; i++)
            {
                for(j = i+1; j < tamDuenio; j++)
                {
                    if(auxDuenioMascota[i].cantidadMascotas > auxDuenioMascota[j].cantidadMascotas)
                    {
                        auxiliar = auxDuenioMascota[i];
                        auxDuenioMascota[i] = auxDuenioMascota[j];
                        auxDuenioMascota[j] = auxiliar;

                        auxiliarDuenio = duenio[i];
                        duenio[i] = duenio[j];
                        duenio[j] = auxiliarDuenio;
                    }else
                    {
                        if(auxDuenioMascota[i].cantidadMascotas == auxDuenioMascota[j].cantidadMascotas && strcmp(duenio[i].nombre, duenio[j].nombre) > 0)
                        {
                            auxiliar = auxDuenioMascota[i];
                            auxDuenioMascota[i] = auxDuenioMascota[j];
                            auxDuenioMascota[j] = auxiliar;

                            auxiliarDuenio = duenio[i];
                            duenio[i] = duenio[j];
                            duenio[j] = auxiliarDuenio;

                        }
                    }
                }
            }
        break;
        case 2: // ordena las cantidades de mascotas de mayor a menor y como segundo criterio, en orden alfabetico de la z a la a
            for(i = 0; i < tamDuenio-1; i++)
            {
                for(j = i+1; j < tamDuenio; j++)
                {
                    if(auxDuenioMascota[i].cantidadMascotas < auxDuenioMascota[j].cantidadMascotas)
                    {
                        auxiliar = auxDuenioMascota[i];
                        auxDuenioMascota[i] = auxDuenioMascota[j];
                        auxDuenioMascota[j] = auxiliar;

                        auxiliarDuenio = duenio[i];
                        duenio[i] = duenio[j];
                        duenio[j] = auxiliarDuenio;
                    }else
                    {
                        if(auxDuenioMascota[i].cantidadMascotas == auxDuenioMascota[j].cantidadMascotas && strcmp(duenio[i].nombre, duenio[j].nombre) < 0)
                        {
                            auxiliar = auxDuenioMascota[i];
                            auxDuenioMascota[i] = auxDuenioMascota[j];
                            auxDuenioMascota[j] = auxiliar;

                            auxiliarDuenio = duenio[i];
                            duenio[i] = duenio[j];
                            duenio[j] = auxiliarDuenio;

                        }
                    }
                }
            }
        break;
    }

    printf("          NOMBRE        APELLIDO      LOCALIDAD        TELEFONO        EDAD     SEXO     CANT MASCOTAS\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    for(i = 0;i<tamDuenio;i++)
    {
        if(duenio[i].estado ==  OCUPADO) // muestra todos los datos ya ordenados
        {
            printf("%15s %15s %15s %15s %10d %8c %10d\n" ,  duenio[i].nombre,
                                                            duenio[i].apellido,
                                                            duenio[i].localidad,
                                                            duenio[i].telefono,
                                                            duenio[i].edad,
                                                            duenio[i].sexo,
                                                            auxDuenioMascota[i].cantidadMascotas);
        }
    }
    printf("\n");
}
void OrdenasMascotasPorTipo(sMascota mascota[], int tamMascota, sDuenio duenio[], int tamDuenio, int orden, sRaza tipoRaza[] , int tamRaza)
{
    int i;
    int j;
    sMascota aux;
    switch(orden)
    {
        case 1:
            for(i = 0; i < tamMascota -1; i++)
            {
                for(j = i+1; j < tamMascota; j++)
                {
                    if((mascota[j].estado == OCUPADO) && (strcmpi(mascota[j].tipo, mascota[i].tipo) < 0))
                    {
                        aux = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = aux;
                    }
                }
            }
            mostrarMascota(mascota,tamMascota,duenio,tamDuenio,tipoRaza,tamRaza);
        break;
        case 2:
            for(i = 0; i < tamMascota -1; i++)
            {
                for(j = i+1; j < tamMascota; j++)
                {
                    if((mascota[j].estado == OCUPADO) && (strcmpi(mascota[j].tipo, mascota[i].tipo) > 0))
                    {
                        aux = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = aux;
                    }
                }
            }
            mostrarMascota(mascota,tamMascota,duenio,tamDuenio,tipoRaza,tamRaza);
        break;
        default:
        break;
    }

}
void bajaMascotaPorDuenio(sMascota mascota[], int tamMascota,int idDuenio)
{
    int i;
    for(i = 0;i < tamMascota; i++)
    {
       if(mascota[i].idDuenio == idDuenio)
       {
           mascota[i].estado = LIBRE;
       }
    }
}
int bajaDuenioEnCascada(sDuenio duenio[], int tamDuenio,sMascota mascota[], int tamMascota) // BORRADO DE DUENIO EN CASCADA
{
    int aux;
    int i;
    char confirmacion;
    int retorno = -1;
    aux = getInt("ingrese ID a eliminar: ","error, ingrese un ID valido (1 - 10)",1,10);
    for(i = 0; i < tamDuenio; i++)
    {
        if(duenio[i].idDuenio == aux && duenio[i].estado == OCUPADO)
        {
            confirmacion = getCharacter("Desea eliminar? (s/n): ","Error, ingrese 's' para continuar o 'n' para cancelar: ",'a','z');
            if(confirmacion == 's')
            {
                bajaMascotaPorDuenio(mascota, tamMascota, aux);
                duenio[i].estado = LIBRE;
                retorno = 0;
            }else
            {
                retorno = 1;
            }
            break;
        }
    }
    return retorno;


}
void listarDueniosMascotasMismoSexo(sDuenio duenio[], int tamduenio, sMascota mascota[],int tamMascota)
{
    int i;
    int j;
    printf("***************MASCOTA MASCULINO**************\n");
    printf("----------------------------------------------\n");
    printf("         NOMBRE DUENIO         SEXO DE SU MASCOTA\n");
    printf("----------------------------------------------\n");
    for(i = 0; i< tamduenio;i++)
    {
        if(duenio[i].estado == OCUPADO)
        {
            for(j = 0;j < tamMascota;j++)
            {
                if(duenio[i].idDuenio == mascota[j].idDuenio && mascota[j].sexo == 'm')
                {
                    printf("\t%10s %20c\n ",duenio[i].nombre,mascota[j].sexo);
                }
            }
        }
    }
    printf("****************MASCOTA FEMENINO**************\n");
    printf("----------------------------------------------\n");
    printf("         NOMBRE DUENIO         SEXO DE SU MASCOTA\n");
    printf("----------------------------------------------\n");
    for(i = 0; i< tamduenio;i++)
    {
        if(duenio[i].estado == OCUPADO)
        {
            for(j = 0;j < tamMascota;j++)
            {
                if(duenio[i].idDuenio == mascota[j].idDuenio && mascota[j].sexo == 'f')
                {
                    printf("\t%10s %20c\n ",duenio[i].nombre,mascota[j].sexo);
                }
            }
        }
    }
    printf("\n");
}
