/***********************************************
*PROGRAMA:TRABAJO PRACTICO N°1
*
*OBJETIVO:
        HACER UNA CALCULADORA
        CREAR UNA BIBLIOTECA APARTE CON LAS FUNCIONES MATEMATICAS DEL MENU
        DOCUMENTAR TODAS LAS FUNCIONES

*VERSION 1.0 05/09/16
*AUTOR:JOSE AYALA

***********************************************/






#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"


int main()
{
    float numero_ingre_A;
    float numero_ingre_B;
    char no_definido[]="no definido";
    int opcion;
    int flag_num_1=0;
    int flag_num_2=0;
    char seguir='s';
    int aux_factor;
    float aux_factor_validar;
    int bien_A;
    int bien_B;

    do
    {
        system("cls");
        if(flag_num_1==0)
            printf("1- Ingresar 1er operando (A=%s)\n",no_definido);
        else
            printf("1- Ingresar 1er operando (A=%f)\n",numero_ingre_A);
        if(flag_num_2==0)
            printf("2- Ingresar 2do operando (B=%s)\n",no_definido);
        else
            printf("2- Ingresar 2do operando (B=%f)\n",numero_ingre_B);
            fflush(stdin);

        opcion=menu_generico("3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operacione\n9- Salir\n",1,9);
        system("cls");

    switch(opcion)
    {
        case 1:
            printf("ingrese el primer operando:");
            bien_A=scanf("%f",&numero_ingre_A);
            if(bien_A)
                flag_num_1=1;
            else
            {
                system("cls");
                printf("ingrese un numero no un caracter\n\n");
                system("pause");
            }


            break;
        case 2:
            printf("ingrese el segundo operando:");
            bien_B=scanf("%f",&numero_ingre_B);
            if(bien_B)
                flag_num_2=1;
            else
            {
                system("cls");
                printf("ingrese un numero no un caracter\n\n");
                system("pause");
            }

            break;

        case 3:

            if(flag_num_1==1&&flag_num_2==1)
            {
                printf("el resultado de la suma:%f\n",sumar_los_num(numero_ingre_A,numero_ingre_B));
            }
            else
            {
                if(flag_num_1==1&&flag_num_2==0)
                {
                    printf("ingrese el segundo operando\n");
                    system("pause");
                }
                if(flag_num_1==0&&flag_num_2==1)
                {
                    printf("ingrese el primer operando\n");
                    system("pause");
                }
            }
            if(flag_num_1==0&&flag_num_2==0)
            {
                printf("ingrese los dos operando\n");
                system("pause");
            }

            break;

        case 4:
            if(flag_num_1==1&&flag_num_2==1)
            {
                printf("el resultado de la resta:%f\n",restar_los_num(numero_ingre_A,numero_ingre_B));
            }
            else
            {
                if(flag_num_1==1&&flag_num_2==0)
                {
                    printf("ingrese el segundo operando\n");
                    system("pause");
                }
                if(flag_num_1==0&&flag_num_2==1)
                {
                    printf("ingrese el primer operando\n");
                    system("pause");
                }
            }
            if(flag_num_1==0&&flag_num_2==0)
            {
                printf("ingrese los dos operando\n");
                system("pause");
            }
            break;


        case 5:
            if(flag_num_1==1&&flag_num_2==1)
            {
                if(numero_ingre_B==0)
                {
                    printf("no se puede dividir\n");
                    system("pause");
                }
                else
                {
                    printf("el resultado de la division:%f\n",dividir_los_num(numero_ingre_A,numero_ingre_B));
                    system("pause");
                }

            }
            else
            {
                if(flag_num_1==1&&flag_num_2==0)
                {
                    printf("ingrese el segundo operando\n");
                    system("pause");
                }
                if(flag_num_1==0&&flag_num_2==1)
                {
                    printf("ingrese el primer operando\n");
                    system("pause");
                }
            }
            if(flag_num_1==0&&flag_num_2==0)
            {
                printf("ingrese los dos operando\n");
                system("pause");
            }
            break;


        case 6:
            if(flag_num_1==1&&flag_num_2==1)
            {
                printf("el resultado de la multiplicacion:%f\n",multiplicar_los_num(numero_ingre_A,numero_ingre_B));
                system("pause");
            }
            else
            {
                if(flag_num_1==1&&flag_num_2==0)
                {
                    printf("ingrese el segundo operando\n");
                    system("pause");
                }
                if(flag_num_1==0&&flag_num_2==1)
                {
                    printf("ingrese el primer operando\n");
                    system("pause");
                }
            }
            if(flag_num_1==0&&flag_num_2==0)
            {
                printf("ingrese los dos operando\n");
                system("pause");
            }
            break;


        case 7:
            if(flag_num_1)
            {
                if(numero_ingre_A>=0&&numero_ingre_A<=69)
                {
                    aux_factor=(int)numero_ingre_A;
                    aux_factor_validar=numero_ingre_A-aux_factor;

                    if(aux_factor_validar==0)
                    {
                        printf("el resultado del factorial:%d\n",factorial_del_num(numero_ingre_A));
                        system("pause");
                    }
                    else
                    {
                        printf("error, ingresar un numero entero\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("ingrese un numero entre 0 y 69\n");
                    system("pause");
                }

            }
            else
            {
                printf("ingrese el primer operando\n");
                system("pause");
            }
            break;


        case 8:
            if(flag_num_1==1&&flag_num_2==1)
            {
                printf("el resultado de la suma:%f\n",sumar_los_num(numero_ingre_A,numero_ingre_B));
                printf("el resultado de la resta:%f\n",restar_los_num(numero_ingre_A,numero_ingre_B));
                printf("el resultado de la multiplicacion:%f\n",multiplicar_los_num(numero_ingre_A,numero_ingre_B));
                if(numero_ingre_B==0)
                {
                    printf("no se puede dividir\n");
                }
                else
                {
                    printf("el resultado de la division:%f\n",dividir_los_num(numero_ingre_A,numero_ingre_B));
                }

                if(numero_ingre_A>=0&&numero_ingre_A<=12)
                {
                    aux_factor=(int)numero_ingre_A;
                    aux_factor_validar=numero_ingre_A-aux_factor;

                    if(aux_factor_validar==0)
                    {
                        printf("el resultado del factorial:%d\n",factorial_del_num(numero_ingre_A));
                        system("pause");
                    }
                    else
                    {
                        printf("error, ingresar un numero entero\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("ingrese un numero entre 0 y 69\n");
                    system("pause");
                }
            }
            else
            {
                if(flag_num_1==1&&flag_num_2==0)
                {
                    printf("ingrese el segundo operando\n");
                    system("pause");
                }
                if(flag_num_1==0&&flag_num_2==1)
                {
                    printf("ingrese el primer operando\n");
                    system("pause");
                }
            }
            if(flag_num_1==0&&flag_num_2==0)
            {
                printf("ingrese los dos operando\n");
                system("pause");
            }
            break;


        case 9:
            seguir='n';
            break;
        default:
            break;
    }

    }while(seguir=='s');

    return 0;
}
