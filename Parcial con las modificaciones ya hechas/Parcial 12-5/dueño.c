#include "dueño.h"
#define LIBRE 0
#define OCUPADO 1
#include "gets.h"


void hardcodearDuenio(sDuenio duenio[])
{
    int i;
    int idDuenio[10] = {1,2,3,4,5};
    char nombre[10][100] = {"Marta","Luis","Yesica","Franco","Omar"};
    char apellido[10][100] = {"Fernandez","Guitierez","Estrada","Armani","Calvo"};
    char localidad[10][100] = {"Banfield","Lomas","Temperley","Lanus","Berazategui"};
    char telefono[10][100] = {"42645845","14523645","14528956","47451414","42524185"};
    int edad[10]= {25,40,58,31,54};
    char sexo[10]= {'f','m','f','m','m'};
    int estado[10]= {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    for(i = 0; i < 10; i++)
    {
        duenio[i].idDuenio = idDuenio[i];
        duenio[i].edad = edad[i];
        duenio[i].sexo = sexo[i];
        duenio[i].estado = estado[i];
        strcpy(duenio[i].nombre,nombre[i]);
        strcpy(duenio[i].apellido,apellido[i]);
        strcpy(duenio[i].localidad,localidad[i]);
        strcpy(duenio[i].telefono,telefono[i]);
    }
}


void inicializarDuenio(sDuenio duenio[],int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        duenio[i].estado = LIBRE; // inicializa el vector de estado en libre
        duenio[i].idDuenio = 0; // inicializa el vectord de idDuenio en 0
    }
}
void mostrarDuenio(sDuenio duenio[],int tamDuenio)
{
    int i;
    printf("*********NOMBRE********APELLIDO*******LOCALIDAD********TELEFONO**EDAD**SEXO**ID\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0; i<tamDuenio; i++)
    {
        if(duenio[i].estado == OCUPADO) // muestra las dueños que estan con estado OCUPADO en forma de tabla
        {
            printf("%15s %15s %15s %15s %4d %4c %4d\n",duenio[i].nombre, duenio[i].apellido, duenio[i].localidad,duenio[i].telefono,duenio[i].edad, duenio[i].sexo,duenio[i].idDuenio);

        }
    }
    printf("-------------------------------------------------------------------------------\n");
}
int buscarLibreDuenio(sDuenio duenio[], int tam)
{
    int i;
    int retorno = -1;
    for(i = 0; i < tam; i++)
    {
        if(duenio[i].estado == LIBRE) // busca una posicion libre dentro del vector
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int generarIDDuenio(sDuenio duenio[],int tam)
{
    int i;
    int max;
    for(i = 0; i < tam; i++)
    {
        if(i == 0 || (duenio[i].idDuenio > max && duenio[i].estado != LIBRE)) // busca el maximo de los id hardcodeados
        {
            max = duenio[i].idDuenio;
        }
    }
    return max+1; // retorna ese maxima +1
}

int altaDuenio(sDuenio duenio[],int tam)
{
    int aux;
    int retorno = -1;

    aux = buscarLibreDuenio(duenio,tam);

    if(aux != -1) // si retorna algo distinto de -1, encontro espacio libre
    {
        getString("Ingrese el Nombre: ",duenio[aux].nombre);
        getString("Ingrese el Apellido: ",duenio[aux].apellido);
        getString("Ingrese localidad: ",duenio[aux].localidad);
        getString("Ingrese su telefono: ",duenio[aux].telefono);
        duenio[aux].edad = getInt("Ingrese una edad: ","Error, ingrese una edad valida (1 - 130)",1,130);
        duenio[aux].sexo = getCharacter("Ingrese un sexo (m/f): ","Error, ingrese 'm' para masculino o 'f' para femenino",'a','z');
        duenio[aux].idDuenio = generarIDDuenio(duenio,tam);
        duenio[aux].estado = OCUPADO;
        retorno = 0;
    }
    return retorno;
}


int modificarDuenio(sDuenio duenio[], int tamDuenio)
{
    int aux;
    int i;
    int opcion;
    int retorno;
    aux = getInt("Ingrese el ID a modificar:\n","Error,ingrese un ID valido(ID de duenios comienza en N°1)",1,10);

    for(i = 0; i < tamDuenio; i++)
    {
        if(duenio[i].idDuenio == aux && duenio[i].estado == OCUPADO) // comprueba que el id ingresado coincida con los idDuenio y si el estado es OCUPADO
        {
            opcion = getInt("Ingrese el campo a modificar: \n1. Nombre\n2. Apellido\n3. Localidad\n4. Telefono\n5. edad\n6. Sexo\n","Error, ingrese una opcion valida.\n",1,6);
            printf("*************************\n");
            switch(opcion)
            {
                case 1:
                    getString("Ingrese el Nombre: ",duenio[i].nombre);
                break;
                case 2:
                    getString("Ingrese el Apellido: ",duenio[i].apellido);
                break;
                case 3:
                    getString("Ingrese la Localidad: ",duenio[i].localidad);
                break;
                case 4:
                    getString("Ingrese el numero de Telefono: ",duenio[i].telefono);
                break;
                case 5:
                    duenio[i].edad = getInt("Ingrese la Edad: ","Ingrese una edad valida (1 - 130)",1,130);
                break;
                case 6:
                    duenio[i].sexo = getCharacter("Ingrese sexo: ('m' o 'f'): ","Error, reingrese un sexo valido('m' para masculino / 'f' para femenino)",'a','z');
                break;
                default:
                break;
            }
            retorno = 0; // todo ok
            break;
        }else
        {
            retorno = -1; // no encontro id
        }
    }
    return retorno;
}
void promedioEntreVaronesYMujeres(sDuenio duenio[], int tam)
{
    int i;
    int contadorTotalDuenios = 0;
    int contadorMujeres = 0;
    float porcentajeMujeres;
    for(i = 0; i < tam; i++)
    {
        if(duenio[i].estado == OCUPADO)
        {
            contadorTotalDuenios++; // cuenta los duenios disponibles
        }
        if(duenio[i].sexo == 'f')
        {
            contadorMujeres++;
        }
    }
    porcentajeMujeres = (float)contadorMujeres / contadorTotalDuenios * 100; // porcentaje mujeres

    printf("El porcentaje de mujeres es de: %% %.2f\n", porcentajeMujeres);
    printf("-----------------------------------------------\n");
}
