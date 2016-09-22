/**************************************
*Programa: trabajo practico Nº2
*
*
*Objetivos:
*   -Definir una estructura que represente una persona, con los campos
*    nombre, edad, dni y un flag de estado.
*   -Hacer un programa que defina un array de 20 items de esta estructura y con un
*    menu como el siguiente:
*               1-Agregar una persona
*               2-Borrar una persona
*               3-Imprimir una lista ordenada
*               4-Imprimir grafico de edades
*    se utilisara el campo de estado para indicar si el item de array esta
*    ocupado o no.
*    El grafico debera se en forma de barras donde agruparan 3 columnas:
*               -Menores de 18
*               -De 19 entre 35
*               -Mayores 35
*
*
*Version:1.0
*Autor:Jose Ayala.
***************************************/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

#define cant_emple 20

int main()
{
    Persona elvectordni[cant_emple];

    char nombrestr[50];
    char edadstr[50];
    char dnistr[50];

    int auxedad;
    int auxdni;
    char seguir='s';


    int resultadodebuscada;
    int lugarllibre;
    int opcion=0;

    int grafedad;
    int contmenor18=0;
    int contentre18_35=0;
    int contmayor35=0;
    int k;
    int mayor;
    int flag=0;

    inicializararraypersona(elvectordni,cant_emple);

    do{

        opcion=menu_generico("1.agregar Persona:\n2.borrar Persona:\n3.imprimir lista ordenada por nombre:\n4.imprimir grafico de edades:\n5.salir\n",1,5);
        switch(opcion)
        {
        case 1:
            system("cls");
            lugarllibre=buscarprimeraocurrencia(elvectordni,cant_emple);
            printf("\nALTA\n\n");
            if(lugarllibre == -1)
            {
                printf("\nno hay lugar para dar de alta\n");
                break;
            }
            if(!consiguecadenaletra("ingrese nombre: \n",nombrestr))
            {
                printf("\nerror, ingrese el nombre con letras\n");
                break;
            }
            if(!consiguecadenanumero("\ningrese edad \n",edadstr))
            {
                printf("\nerror,ingrese una edad \n");
                break;
            }
            grafedad=atoi(edadstr);
            if(!(grafedad>0&&grafedad<100))
            {
                printf("\nerror, ingrese edad valida entre 1 y 100\n");
            }
            if(grafedad<18)
            {
                contmenor18++;
            }
            else
            {
                if(grafedad>35)
                {
                    contmayor35++;
                }
                else
                {
                    contentre18_35++;
                }
            }


            if(!consiguecadenanumero("\ningrese dni\n",dnistr))
            {
                printf("\nerror, ingrese dni valido\n ");
                break;
            }
            auxdni = atoi(dnistr);
            auxedad = atoi(edadstr);


            if(!(buscardni(elvectordni,dnistr)!= -1))
            {
                printf("\nerror, el dni ya existe\n");
                break;
            }

            strcpy(elvectordni[lugarllibre].nombre,nombrestr);
            elvectordni[lugarllibre].edad=auxedad;
            elvectordni[lugarllibre].dni=auxdni;
            elvectordni[lugarllibre].estado=0;

            break;

        case 2:
            system("cls");
            if(!consiguecadenanumero("\ningrese dni para dar de baja\n",dnistr))
            {
                printf("\nel dni ingresado debe ser numerico\n");
                break;
            }
            resultadodebuscada=buscardni(elvectordni,dnistr);
            if(resultadodebuscada==-1)
            {
                printf("\nno se encuentra el dni\n");
                break;
            }
            elvectordni[resultadodebuscada].estado=-1;
            break;

        case 3:
            system("cls");
            printf("\nLISTAR\n");
            mostrarordenado(elvectordni,cant_emple);
            break;

        case 4:
            system("cls");
            printf("\nGRAFICO\n\n");
            if(contmenor18>=contentre18_35&&contmenor18>=contmayor35)
            {
                mayor=contmenor18;
            }
            else
            {
                if(contentre18_35>=contmenor18&&contentre18_35>=contmayor35)
                {

                    mayor=contentre18_35;

                }
                else
                {
                    mayor=contmayor35;
                }
            }
            for(k=mayor;k>0;k--)
            {
                if(k<10)
                {
                   printf("%02d|",k);
                }
                else
                {
                    printf("%02d|",k);
                }
                if(k<=contmenor18)
                {
                    printf("*");
                }
                if(k<=contentre18_35)
                {
                    printf("\t*");
                }
                if(k<=contmayor35)
                {
                    if(flag==0)
                    {
                       printf("\t\t*");
                    }
                    if(flag==1)
                    {
                       printf("\t*");
                    }
                }
                printf("\n");
            }
            printf("--+-----------------");
            printf("\n  |<18\t19-35\t>35");
            printf("\n   %d\t%d\t%d\n",contmenor18,contentre18_35,contmayor35);
            system("pause");
            break;
        case 5:
            system("cls");
            seguir='n';
            break;
        default:
            system("cls");
            printf("\ningrese un una opcion valida\n");
            system("pause");
            system("cls");
            break;

        }
    }while(seguir=='s');

    return 0;
}
















