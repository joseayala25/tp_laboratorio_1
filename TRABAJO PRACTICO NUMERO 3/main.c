/**************************************
*Programa: trabajo practico N�3
*
*
*Objetivos:
*   -Definir una estructura �movie� con los datos de una pelicula:
*       T�tulo
*       G�nero
*       Duraci�n
*       Descripci�n
*       Puntaje
*       Link de imagen
*
*
*
*   -Realizar un programa que permita agregar, borrar y modificar peliculas en un archivo binario
*    mediante un men�::
*               1. Agregar pel�cula
*               2. Borrar pel�cula
*               3. Modificar pel�cula
*               4. Generar p�gina web
*               5. Salir
*
*   -La opci�n 3, listar� las peliculas pero no por pantalla, sino generando un archivo html
*      (descargar template de ejemplo, archivo template.zip).
*
*   -Crear una funci�n que reciba un array de estructuras movie y el nombre del archivo html de
*     salida, y se encargue de generarlo.
*
*   -En el archivo de la template, index.html, se encontrar� la porci�n de c�digo html que se debe
*    repetir para cada pel�cula, dentro de este bloque, se debe cargar ciertas partes con los datos
*    de cada pel�cula, a continuaci�n se muestra un bloque y en color rojo lo que se debe variar
*    seg�n la pelicula.
*
*
*
*Version:1.0
*Autor:Jose Ayala.
***************************************/








#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"
#include <string.h>
#include <windows.h>
#define SLEEP_TIME 1200
#define LENGTH 10



int main()
{






    int opcion,error;

    sMovie peliculas[LENGTH];

    inicializar_pelicula(peliculas, LENGTH);

    error = cargarDesdeArchivo( peliculas, LENGTH );

    switch( error )
    {
        case 0:
            printf("\nSe cargaron las estructuras exitosamente.\n\n");
            break;
        case -1:
            printf("\nNo se pudo abrir el fichero.\n\n");
            break;
        case -2:
            inicializar_pelicula( peliculas, LENGTH );
            //chargeWithFakeData( peliculas, LENGTH );
            printf("\nNo existe el archivo de datos, se cre""\xA2"" exitosamente.\n\n");
            break;
    }

    system("pause");


    do
    {
        opcion = menu_generico("1)Agregar pelicula\n2)Borrar pelicula\n3)Modificar pelicula\n4)Generar pagina web\n5)Salir\n", 1, 5, 3, "Error! Opcion invalida.");

        switch(opcion)
        {
            case 1:
                agregar_Pelicula( peliculas, LENGTH );
                break;
            case 2:
                borrar_Pelicula( peliculas, LENGTH );
                break;
            case 3:
                modificar_Pelicula( peliculas, LENGTH );
               break;
            case 4:
                generar_Pagina( peliculas, LENGTH );
                break;
            case 5:
                do_Exit( peliculas, LENGTH );
                break;

        }



    }while( opcion != 5 );

    return 0;
}
