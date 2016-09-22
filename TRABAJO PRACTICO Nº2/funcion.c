#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcion.h"

/** \brief Verifica si el valor recibido es numerico
 * \param str array con la cadena a ser analizada
 * \return 1 sis es numerico y 0 si no lo es
 */

int esnumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0'||str[i]>'9')
            return 0;
        i++;
    }
    return 1;
}
/** \brief Verifica si el valor recibido contiene solo letras
 * \param str array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */

int esSoloLetras(char str[])
{

   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
/** \brief Verifica si el valor recibido contiene solo letras y números
 * \param str array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */

int esalfanumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]<'0'||str[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}
/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input array donde se cargará el texto ingresado
 * \return void
 */

void consiguecadena(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s",input);
}
/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo etras
 */


int consiguecadenaletra(char mensaje[],char input[])
{

    char aux[256];
    consiguecadena(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/** \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int consiguecadenanumero(char mensaje[],char input[])
{
    char aux[256];
    consiguecadena(mensaje,aux);
    if(esnumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}








/** \brief Inicializa un array de personas con el valor recibido
 * \param elvectordni es el array a ser inicializado
 * \param cantidadelemento indica la longitud del array
 * \return void
 */



void inicializararraypersona(Persona elvectordni[],int cantidadelemento)
{
    int i;
    for(i=0;i<cantidadelemento;i++)
    {
        elvectordni[i].estado = -1;
    }
}
/** \brief Busca la primer ocurrencia de un valor en un array de persona
 * \param lista es el array en el cual buscar
 * \param cantidadelemento indica la longitud del array
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */

int buscarprimeraocurrencia(Persona lista[],int cantidadelemento)
{
    int indice=-1;
    int i;
    for(i=0;i<cantidadelemento;i++)
    {
        if(lista[i].estado==-1)
        {
            indice= i;
            break;
        }
    }
    return indice;
}
/** \brief Busca el dni atraves de la pocision del indice
 * \param lista es el array en el cual buscar
 * \param dni es la cadena a buscar en el array lista
 * \return Si no hay ocurrencia (-1) y si la hay, la posicion de la misma
 */


int buscardni(Persona lista[],char dni[])
{
    int indice=-1;
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i].dni==-1);
        {
            indice=i;
            break;
        }
    }
    return indice;
}
/** \brief Ordena los apellidos de las personas alfabeticamente y lo muestra ordenado con sus datos
 * \param elvectordni es array donde bucar los apellidos
 * \param cantidadelemento indica la longitud del array
 * \return void
 */

void mostrarordenado(Persona* elvectordni,int cantidadelelemento)
{
    Persona Aux;
    int i,j;
    for(i=0;i<cantidadelelemento-1;i++)
    {
        if(elvectordni[i].estado!=0)
        {
            continue;
        }
        for(j=i+1;j<cantidadelelemento;j++)
        {
            if(elvectordni[i].estado!=0)
            {
                continue;
            }

            if(strcmp(elvectordni[i].nombre,elvectordni[j].nombre)>0)
            {
                Aux=elvectordni[i];
                elvectordni[i]=elvectordni[j];
                elvectordni[j]=Aux;
            }
        }
    }

    for(i=0; i<cantidadelelemento; i++)
    {
        if(elvectordni[i].estado==0)
        {
            printf("%s - %d - %d\n",elvectordni[i].nombre,elvectordni[i].edad,elvectordni[i].dni);
        }
    }
 system("pause");
}


/** \brief Recibe un string para imprimir por consola
 * \param Recibe un valor para marcar un rango de limite de inicio
 * \param recibe un valor para marcar un rango de limite de final
 * \return retorna la opcion del menu
 *
 */


int menu_generico(char *mensaje,int desde,int hasta)
{
    int opcion_menu;
    int flag=0;
    int ok;
    do
    {
        if(flag)
        {
            system("cls");
            printf("ERROR, INGRESE UNA OPCION VALIDA\n\n");
        }
        puts(mensaje);
        fflush(stdin);
        ok=scanf("%d",&opcion_menu);
        flag=1;

    }while(!((opcion_menu>=desde&&opcion_menu<=hasta)&&(ok)));

    return opcion_menu;
}





