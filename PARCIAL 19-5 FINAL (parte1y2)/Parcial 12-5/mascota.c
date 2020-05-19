#include "mascota.h"
#define LIBRE 0
#define OCUPADO 1
#include "gets.h"
void hardcodearMascota(sMascota mascota[])
{
    int i;
    int idMascota[20]= {100,101,102,103,104,105,106,107,108,109,110};
    int idDuenio[20]= {1,1,2,2,2,3,3,4,4,4,5}; // se le asigna dueños a cada mascotas
    int idRaza[20] = {1,2,3,4,5,6,7,8,9,10,11};
    char nombre[20][100]= {"Wiskas","Melchor","Pochoclo","Banana","Perla","Cata","SubZero","Michetti","Carlos","Mati","Kevin"};
    char tipo[20][100]= {"Gato","Gato","Perro","Perro","Gato","Raro","Perro","Gato","Gato","Perro","Perro"};
    //char raza[20][100]= {"Vengala","Callejero","Pug","Caniche","Ragdoll","Reptil","Pitbull","Persa","Gato Siames","Bulldog","Labrador"};
    int edad[20]= {2,10,1,6,9,1,11,2,6,8,9};
    float peso[20]= {6.45,8.55,9.50,33.00,4.38,7.54,45.53,9.85,8.47,8.96,52.79};
    char sexo[20]= {'f','f','m','m','m','m','m','m','m','m','m'};
    int estado[20]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    for(i = 0; i < 20; i++)
    {
        mascota[i].idMascota = idMascota[i];
        mascota[i].idDuenio = idDuenio[i];
        mascota[i].idRaza = idRaza[i];
        mascota[i].edad = edad[i];
        mascota[i].peso = peso[i];
        mascota[i].sexo = sexo[i];
        mascota[i].estado = estado[i];
        strcpy(mascota[i].tipo,tipo[i]);
        //strcpy(mascota[i].raza,raza[i]);
        strcpy(mascota[i].nombre,nombre[i]);
    }
}
void hardcodearTipoRaza(sRaza tipoRaza[])
{
    int i;
    int idRaza[40] = {1,2,3,4,5,6,7,8,9,10,11};
    char Descripcion[40][100] = {"Vengala","Callejero","Pug","Caniche","Ragdoll","Reptil","Pitbull","Persa","Gato Siames","Bulldog","Labrador"};
    char pais[40][100] = {"Aleman","Frances","Portugues","Sueco","Noruego","Italiano","Brasilero","Español","Argentino","Canadiense","Belga"};
    for(i = 0; i < 40; i++)
    {
        tipoRaza[i].idRaza = idRaza[i];
        strcpy(tipoRaza[i].Descripcion,Descripcion[i]);
        strcpy(tipoRaza[i].pais, pais[i]);
    }
}
void mostrarDescripcionRazaSegunId(sMascota mascota[], int tamMascota, sRaza tipoRaza[],int tamRaza)
{
    int i;
    int j;
    printf("    ID RAZA     DESCRIPCION         PAIS\n");
    printf("----------------------------------------\n");
    for(i = 0;i < tamMascota;i++)
    {
        if(mascota[i].estado == OCUPADO)
        {
            for(j = 0;j < tamRaza ; j++)
            {
                if(mascota[i].idRaza == tipoRaza[j].idRaza)
                {
                    printf("%8d %15s %15s\n" ,mascota[i].idRaza, tipoRaza[j].Descripcion,tipoRaza[j].pais);
                }
            }

        }
    }
    printf("---------------------------------------\n");
}
void inicializarMascota(sMascota mascota[],int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        mascota[i].estado = LIBRE; // inicializa todas las posiciones del vector de estado es 0
        mascota[i].idMascota = 0; // inicializa el idMascota
    }
}

int buscarLibreMascota(sMascota mascota[], int tam)
{
    int i;
    int retorno = -1;
    for(i = 0; i < tam; i++)
    {
        if(mascota[i].estado == LIBRE) // busca espacio libre
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int generarIDMascota(sMascota mascota[],int tam)
{
    int i;
    int max;
    for(i = 0; i < tam; i++)
    {
        if(i==0 || ((mascota[i].idMascota > max) && (mascota[i].estado != LIBRE))) //busca el maximo de las idMascota hardcodeados
        {
            max = mascota[i].idMascota;
        }
    }
    return max + 1; // retorna el maximo + 1
}
int altaMascota(sMascota mascota[],int tam)
{
    int aux;
    aux = buscarLibreMascota(mascota, tam);
    int retorno = -1;
    if(aux != -1) // si devuelve algo distinto a -1, encontro espacio libre
    {
        getString("Ingrese nombre: ", mascota[aux].nombre);
        do
        {
           getString("Ingrese el Tipo (perro / raro / gato): ",mascota[aux].tipo);
        }
        while((strcmpi(mascota[aux].tipo,"Perro")==0||strcmpi(mascota[aux].tipo,"Gato")==0||strcmpi(mascota[aux].tipo,"Raro")==0)!=1);
        mascota[aux].idRaza = getInt("Seleccione la raza que desea agregar raza\n1) Vengala\n2) Callejero\n3) Pug\n4) Caniche\n5) Ragdoll\n6) Reptil\n7) Pitbull\n8) Persa\n9) Gato Siames\n10) Bulldog\n11) Labrador\n","ERROR, reingrese una opcion valida",1,11);
        mascota[aux].edad = getInt("Ingrese una edad: ","Error, ingrese una edad (1 - 100)",1,100);
        mascota[aux].peso = getFloat("ingrese un peso: ","Error, ingrese un peso valido",0,150);
        mascota[aux].sexo = getCharacter("Ingrese sexo ('m'o'f'): ","Error, ingrese 'm' para masculino 0 'f' para femenino",'a','z');
        mascota[aux].idDuenio=getInt("Ingrese ID del duenio: ","Error, ingrese un ID disponible (max = 20 mascotas)",1,20);
        mascota[aux].idMascota = generarIDMascota(mascota,tam); // id autoincrementable
        mascota[aux].estado = OCUPADO;
        retorno = 0;
    }
    return retorno;
}
/*int modificarMascota(sMascota mascota[],int tamMascota, sDuenio duenio[], int tamDuenio)
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
            opcion = getInt("Ingrese el campo a modificar: \n1. Nombre\n2. Tipo\n3. ID raza\n4. Edad\n5. Peso\n6. Sexo7. Modificar Duenio\n","Error, ingrese una opcion valida.\n",1,7);
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
}*/

int bajaMascota(sMascota mascota[], int tam)
{
    int aux;
    int i;
    char confirmacion;
    int retorno = -1;
    aux = getInt("ingrese ID a eliminar: ","error, reingrese un ID valido(100 - 120)",100,120);
    for(i = 0; i < tam; i++)
    {
        if(mascota[i].idMascota == aux && mascota[i].estado == OCUPADO)// comprobacion del id ingresado
        {
            confirmacion = getCharacter("Desea eliminar? (s/n): ","Error, ingrese 's' para continuar o 'n' para cancelar:",'a','z');
            if(confirmacion == 's')
            {
                mascota[i].estado = LIBRE; // cambia el estado a libre si encontro el id
                retorno = 0;

            }else
            {
                retorno = 1; // no encontro el id
            }
            break;
        }

    }
    return retorno;


}
void listarMascotasPorTipo(sMascota mascota[], int tamMascota)
{
    int i;
    printf("**********************RARO*********************\n");
    printf("-----------------------------------------------\n");
    printf("          NOMBRE               RAZA        EDAD\n");
    printf("-----------------------------------------------\n");
    for(i = 0; i < tamMascota;i++) // recorre el vector
    {
        if(strcmpi(mascota[i].tipo, "raro")==0 && mascota[i].estado == OCUPADO) // filtra todos las mascotas == "raro" y los muestra
        {
            printf("%15s \t%12s %8d\n", mascota[i].nombre, mascota[i].raza, mascota[i].edad);
        }
    }
    printf("\n");
    printf("**********************GATO*********************\n");
    printf("-----------------------------------------------\n");
    printf("          NOMBRE               RAZA        EDAD\n");
    printf("-----------------------------------------------\n");
    for(i = 0; i < tamMascota;i++) // recorre el vector
    {
        if(strcmpi(mascota[i].tipo, "gato")==0 && mascota[i].estado == OCUPADO) // filtra todos las mascotas == "gato" y los muestra
        {
            printf("%15s \t%12s %8d\n", mascota[i].nombre, mascota[i].raza, mascota[i].edad);
        }
    }
    printf("\n");
    printf("*********************PERRO*********************\n");
    printf("-----------------------------------------------\n");
    printf("          NOMBRE               RAZA        EDAD\n");
    printf("-----------------------------------------------\n");
    for(i = 0; i < tamMascota;i++)
    {
        if(strcmpi(mascota[i].tipo, "perro")==0 && mascota[i].estado == OCUPADO) // filtra todos las mascotas == "perro" y los muestra
        {
            printf("%15s \t%12s %8d\n",  mascota[i].nombre, mascota[i].raza, mascota[i].edad);
        }
    }
    printf("\n");

}
float promedioEdadesMascotas(sMascota mascota[], int tam)
{
    int i;
    int cantidadMascotas = 0;
    int edadTotalMascotas = 0;
    float promedio;
    for(i = 0; i < tam; i++)
    {
        if(mascota[i].estado == OCUPADO)// filtra los ocupados
        {
            cantidadMascotas++; // cuenta la cantidad de mascotas
            edadTotalMascotas = edadTotalMascotas + mascota[i].edad; // suma las edades de mascotas
        }

    }
    promedio = (float)edadTotalMascotas / cantidadMascotas; // calcula el promedio
    return promedio;
}
void promedioEdadesMascotasPorTipo(sMascota mascota[], int tam)
{
    int i;
    int cantidadPerros = 0;
    int cantidadGatos = 0;
    int cantidadRaros = 0;
    int edadTotalRaros = 0;
    int edadTotalGatos = 0;
    int edadTotalPerros = 0;
    float promedioPerros;
    float promedioGatos;
    float promedioRaros;
    for(i = 0; i < tam ;i++)
    {
        if(mascota[i].estado == OCUPADO && strcmpi(mascota[i].tipo,"perro")==0)
        {
            cantidadPerros++; // contador de la cantidad de perros
            edadTotalPerros = edadTotalPerros + mascota[i].edad; // edad total de las suma de los perros
        }
    }
    promedioPerros = (float)edadTotalPerros / cantidadPerros; // calcula promedio de perros
    printf("--------------------------------------------------\n");
    printf("El promedio de edades entre los perros es de: %.2f\n", promedioPerros);
    printf("--------------------------------------------------\n");


    for(i = 0; i < tam ;i++)
    {
        if(mascota[i].estado == OCUPADO && strcmpi(mascota[i].tipo,"gato")==0)
        {
            cantidadGatos++; // contador de la cantidad de gatos
            edadTotalGatos = edadTotalGatos + mascota[i].edad; // edad total de las suma de los gatos
        }
    }
    promedioGatos = (float)edadTotalGatos / cantidadGatos; // calcula promedio de gatos
    printf("El promedio de edades entre los gatos es de: %.2f\n", promedioGatos);
    printf("--------------------------------------------------\n");

    for(i = 0; i < tam ;i++)
    {
        if(mascota[i].estado == OCUPADO && strcmpi(mascota[i].tipo,"raro")==0)
        {
            cantidadRaros++; // contador de la cantidad de raros
            edadTotalRaros = edadTotalRaros + mascota[i].edad;  // edad total de las suma de los raros
        }
    }
    promedioRaros = (float)edadTotalRaros / cantidadRaros; // calcula promedio de raros
    printf("El promedio de edades entre los raros es de: %.2f\n", promedioRaros);
    printf("--------------------------------------------------\n");

}



