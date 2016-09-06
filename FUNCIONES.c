#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"

/** \brief muestra el menu en la consola
 *
 * \param recibe un string para imprimir por consola
 * \param recibe un valor para marcar un rango de limite de inicio
 * \param recibe un valor para marcar un rango de limite de final
 * \return retorna la opcion del menu
 *
 */

int menu_generico(char *mensaje,int desde,int hasta)
{
    char no_definido[]="no definido";
    int opcion;
    int flag=0;
    do
    {
        if(flag)
        {
            system("cls");
            printf("error,ingrese una opcion valida\n");
            system("pause");
            system("cls");
            printf("1- Ingresar 1er operando (A=%s)\n",no_definido);
            printf("2- Ingresar 2do operando (B=%s)\n",no_definido);
        }

        puts(mensaje);
        fflush(stdin);
        scanf("%d",&opcion);
        flag=1;
    }while(opcion<desde||opcion>hasta);

    return opcion;
}

/** \brief calcula la suma de los operando
 *
 * \param numero_ingre_A correspondiente a la variable A
 * \param numero_ingre_B correspondiente a la variable B
 * \return retorna el resultado de la suma
 *
 */

float sumar_los_num(float num_1,float num_2)
{
    return num_1+num_2;
}

/** \brief calcula la resta de los operando
 *
 * \param numero_ingre_A correspondiente a la variable A
 * \param numero_ingre_B correspondiente a la variable B
 * \return retorna el resultado de la resta
 *
 */

float restar_los_num(float num_1,float num_2)
{
    return num_1-num_2;
}

/** \brief calcula la multiplicacion de los operando
 *
 * \param numero_ingre_A correspondiente a la variable A
 * \param numero_ingre_B correspondiente a la variable B
 * \return retorna el resultado de la multiplicacion
 *
 */

float multiplicar_los_num(float num_1,float num_2)
{
    return num_1*num_2;
}

/** \brief calcula la division de los operando
 *
 * \param numero_ingre_A correspondiente a la variable A
 * \param numero_ingre_B correspondiente a la variable B
 * \return retorna el resultado de la division
 *
 */

float dividir_los_num(float dividendo,float divisor)
{
    return dividendo/divisor;
}


/** \brief calcula el factorial del operando
 *
 * \param numero_ingre_A correspondiente a la variable A
 * \return retorna el resultado del factorial
 *
 */

int factorial_del_num(int num)
{
    int valor;
    if(num==0)
        return 1;
    valor=num*factorial_del_num(num-1);
    return valor;
}
