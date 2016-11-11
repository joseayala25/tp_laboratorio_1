#include <stdio.h>
#include <stdlib.h>

#include "FUNCIONES.h"
#include <string.h>
//#include <conio.h>
#include <windows.h>

#define SLEEP_TIME 1200
//#define CLEAR_SCREEN "cls"
#define LENGTH 1000




/** \brief guarda los datos de la pelicula en la memoria
 * \param peliculas puntero donde guardar los datos
 * \param largoArray largo del array
 */


void agregar_Pelicula( sMovie* peliculas, int largoArray )///<---------------------------------------------------------------------------
{
    if( peliculas != NULL && largoArray > 0 )
    {
        int error;
        int indice_libre;
        sMovie aux_Pelicula;

        indice_libre = buscar_Libre( peliculas, largoArray );///v////<---------------------------------------------------------------------------

        if( indice_libre >= 0 )
        {
            error = solicitar_Ingreso_Pelicula( &aux_Pelicula, 3 );///<---------------------------------------------------------------------------

            if( error == 0 )
            {
                peliculas[indice_libre] = aux_Pelicula;
                system("cls");
                printf("\nPelicula cargada correctamente.\n\n");
                system("pause");
            }

        }
        else if( indice_libre == -2 )
        {
            system("cls");
            printf("\nNo hay lugar para cargar pelicula\n\n");
            system("pause");
        }
        else if( indice_libre == -1 )
        {
            system("cls");
            printf("\nError al cargar la pelicula\n\n");
            system("pause");
        }
    }
}


int cargarDesdeArchivo( sMovie *peliculas, int length )
{
    int retorno = -1;

    if( peliculas != NULL && length > 0 )
    {
        FILE *pArchBin;
        int leyoArch = 0;

        pArchBin = fopen("movies.dat", "rb");

        if( pArchBin == NULL)
		{
			retorno = -2;
			pArchBin = fopen("movies.dat", "wb");
		}
		else
        {
            retorno = 0;
            leyoArch = 1;
        }

        if( leyoArch == 1 )
        {
            fread( peliculas , sizeof(sMovie) , length , pArchBin );
            fclose( pArchBin );
        }
    }

	return retorno;

}



/** \brief da de baja la pelicula que ingresamos
 *
 * \param peliculas puntero al array donde buscar la pelicula ingresada
 * \param largoArray largo del array
 */

void borrar_Pelicula( sMovie* peliculas, int largoArray )
{
    if( peliculas != NULL && largoArray > 0 )
    {
        int error;
        char titulo_A_Buscar[20];
        int index_A_Borrar;
        system("cls");

        error = getStringConIntentos( titulo_A_Buscar, 20, "Ingrese el titulo de la pelicula que desea eliminar: ", "Error! Titulo invalido", 3 );///<---------------------------------------------------------------------------

        if( error == 0 )
        {
            index_A_Borrar =busca_Index_Pelicula_PorTitulo( peliculas, largoArray, titulo_A_Buscar );///<---------------------------------------------------------------------------
            if( index_A_Borrar >= 0 )
            {
                peliculas[index_A_Borrar].estado = 0;

                system("cls");
                printf("\nPelicula eliminada correctamente.\n\n");
                system("pause");
            }
            if( index_A_Borrar == -2 )
            {
                system("cls");
                printf("\nNo existe una pelicula con ese titulo.\n\n");
                system("pause");
            }
            if( index_A_Borrar == -1 )
            {
                system("cls");
                printf("\nError al eliminar la pelicula.\n\n");
                system("pause");
            }
        }
    }
}



/** \brief modifica los datos de la pelicula ingresados
 *
 * \param peliculas puntero al array para modificar los datos
 * \param largoArray largo del array
 */


void modificar_Pelicula (sMovie* peliculas, int largoArray)
{
    if( peliculas != NULL && largoArray > 0 )
    {
        char titulo_A_Modificar[20];
        int index_A_Modificar;
        int error;

        system("cls");
        error = getStringConIntentos( titulo_A_Modificar, 20, "Ingrese el titulo de la pel""\xA1""cula que desea modificar: ", "Error! Titulo inv""\xA0""lido.", 3);///<---------------------------------------------------------------------------

        if( error == 0 )
        {
            index_A_Modificar = busca_Index_Pelicula_PorTitulo( peliculas, largoArray, titulo_A_Modificar);///<---------------------------------------------------------------------------

            if( index_A_Modificar >= 0 )
            {
                error = solicitar_Modificar_Pelicula( &peliculas[index_A_Modificar], 3);///<---------------------------------------------------------------------------
                if( error == 0 )
                {
                    system("cls");
                    printf("\nModificacion realizada correctamente.\n\n");
                    system("pause");
                }
            }
            else if( index_A_Modificar == -2 )
            {
                system("cls");
                printf("\nNo existe una pelicula con ese titulo.");
                system("pause");
            }

        }
    }
}


/** \brief genera la pagina con todos los datos ingresados en el array
 * \param peliculas puntero al array donde buscar los datos
 * \param largoArray largo del array
 */



void generar_Pagina( sMovie* peliculas , int largoArray )
{

    int i;

    if( peliculas != NULL )
    {
        char head[375] = "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>";
        char body[9390] = "";
        char foot[225] = "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";
        char total[10000] = "";

        char fijo1[100] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
        char fijo2[40] = "' alt=''></a><h3><a href='#'>";
        char fijo3[35] = "</a></h3><ul><li>G&eacutenero: ";
        char fijo4[20] = "</li><li>Puntaje: ";
        char fijo5[30] = "</li><li>Duraci&oacuten: ";
        char fijo6[20] = "</li></ul><p>";
        char fijo7[20] = "</p></article>";
        char aux[50];

        FILE *punt_ArchHTML;

		punt_ArchHTML = fopen( "WebPage/index.html", "w" );

		if( punt_ArchHTML != NULL )
		{
            strcat( total , head );

            for( i=0 ; i<largoArray ; i++ )
            {
                if( peliculas[i].estado == 1 )
                {
                    strcat( body , fijo1 );
                    strcat( body , peliculas[i].linkImagen );
                    strcat( body , fijo2 );
                    strcat( body , peliculas[i].titulo );
                    strcat( body , fijo3 );
                    strcat( body , peliculas[i].genero );
                    strcat( body , fijo4 );

                    sprintf( aux , "%d", peliculas[i].puntaje );
                    strcat( body , aux );

                    strcat( body , fijo5 );

                    sprintf( aux , "%d" , peliculas[i].duracion );
                    strcat( body , aux );

                    strcat( body , fijo6 );
                    strcat( body , peliculas[i].descripcion );
                    strcat( body , fijo7 );

                    strcat( total, body);

                    strcpy( body, "");
                }
            }

            strcat( total , foot );

            fprintf( punt_ArchHTML, "%s", total );
		}

        fclose(punt_ArchHTML);

        system("cls");
        printf("\nPagina web generada correctamente.\n\n");
        system("pause");

    }
    else
    {
        system("cls");
        printf("\nNo se pudo generar la pagina web.\n\n");
        system("pause");
    }
}


/** \brief
 *
 * \param peliculas
 * \param largoArray
 */


void do_Exit( sMovie* peliculas, int largoArray )
{
     int respuesta;
    int error;

    system("cls");

    respuesta = preguntarPorSiOPorNo( "\nDesea guardar los cambios realizados? (S/N) ", "\nError en la respuesta", 3 );

    system("cls");

    if( respuesta == 1 )
    {
        error = guardarEnArchivo( peliculas, largoArray );
        if( error == 0 )
        {
            printf("\nSe guardo la informacion con exito.\n\n");
        }
        else
        {
            printf("\nNo se pudo guardar en el fichero.\n\n");
        }
    }
    else
    {
        printf("\nNo se guardaron los cambios.\n\n");
    }
}









/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/


/** \brief Inizializa el array de peliculas con 'estado' en cero
 * \param peliculas Array de peliculas.
 * \param largoArray Largo del array.
 * \return [0]=Inicializado correctamente /[-1]=Error al inicializar
 *
 */



int inicializar_pelicula( sMovie *peliculas, int largoArray )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( peliculas != NULL && largoArray > 0 )
    {
        int i;

        for( i=0; i<largoArray ; i++ )
        {
            peliculas[i].estado = 0;
        }

        retorno = 0;

    }
    return retorno;
}


/** \brief Guarda los datos en el archivo binario "movies.dat".
 * \param peliculas Array de peliculas.
 * \param length Largo del array.
 * \return [0]=Guardado Exitoso / [-1]=Error de argumentos / [-2]=Error al guardar.
 */


int guardarEnArchivo( sMovie *peliculas, int largoArray )///<----------------------------------------------------------------------------
{
    int retorno = -1;

    if( peliculas != NULL && largoArray > 0 )
    {
        FILE *pArchBin;

        pArchBin = fopen("movies.dat","wb");

        if( pArchBin == NULL )
        {
            retorno = -2;
        }
        else
        {
            fwrite( peliculas , sizeof(sMovie) , largoArray , pArchBin );
            fclose( pArchBin );
            retorno = 0;
        }

    }

	return retorno;

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



/** \brief Solicita el ingreso de una pelicula al usuario (Titulo, genero, duracion, puntaje, descripcion y URL de la imagen) y la carga en la variable del tipo 'sMovie' de la que se recibe un puntero como parámetro.
 *
 * \param peliculaAux Puntero a la variable auxiliar del tipo 'sMovie' donde se van a almacenar los datos guardados.
 * \param intentos Cantidad de intentos permitidos.
 * \return [0]=Ingreso correcto/[-1]=Error en el ingreso.
 *
 */
int solicitar_Ingreso_Pelicula( sMovie* peliculaAux, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( peliculaAux != NULL && intentos > 0 )
    {
        int error;

        system("cls");
        error = getStringConIntentos( peliculaAux->titulo, 20, "Ingrese el titulo de la pelicula: ", "\nError! Titulo invalido.", intentos );

        if( error == 0 )
        {
            system("cls");
            error = getStringConIntentos( peliculaAux->genero, 20, "Ingrese el g""\x82""nero de la  pelicula: ", "\nError! G""\x82""nero invalido.", intentos );


        }
        if( error == 0 )
        {
            system("cls");
            error = getInt ( &peliculaAux->duracion, "Ingrese la duraci""\xA2""n de la  pelicula: ", 1, 1, 1, 1000, "\nError! Duraci""\xA2""n invalida.", intentos );

        }
        if( error == 0 )
        {
            system("cls");
            error = getStringConIntentos( peliculaAux->descripcion, 50,"Ingrese la descripci""\xA2""nn de la pelicula: ", "\nError! Descripci""\xA2""n invalida.", intentos );

        }
        if( error == 0 )
        {
            system("cls");
            error = getInt ( &peliculaAux->puntaje, "Ingrese el puntaje de la  pelicula: ", 1, 1, 0, 10, "\nError! Puntaje invalido.", intentos );

        }
        if( error == 0)
        {
            system("cls");
            error = getStringConIntentos( peliculaAux->linkImagen, 150, "Ingrese la URL de la imagen de la pelicula (Google imagenes): ", "\nError! URL inv""\xA0""lida.", intentos );

        }
        if( error == 0 )
        {
            peliculaAux->estado = 1;
            retorno = 0;
        }
    }

    return retorno;
}



/** \brief Busca un lugar libre en el array de peliculas y devuelve su indice.
 * \param peliculas Array de peliculas.
 * \param largoArray Largo del array.
 * \return [Indice libre]=Si hay un lugar libre devuelve el subindice del array libre/[-1]=Error de argumentos/[-2]=No hay lugar libre
 */
int buscar_Libre( sMovie *peliculas, int largoArray )///<---------------------------------------------------------------------------
{
	int retorno = -1;
	int hay_Lugar = 0;
	int i;

	if( peliculas != NULL && largoArray > 0 )
    {
        for( i=0; i < largoArray; i++)
        {
            if( peliculas[i].estado == 0 )
            {
                retorno = i;
                hay_Lugar = 1;
                break;
            }
        }

        if( !hay_Lugar )
        {
            retorno = -2;
        }

    }

	return retorno;
}


/** \brief Busca el subindice de una pelicula dentro del array por el titulo.
 * \param peliculas Array de peliculas.
 * \param largoArray Largo del array.
 * \param tituloABuscar Titulo de la pelicula buscada.
 * \return [Indice de la pelicula]=Si se encontró la pelicula/[-1]=Error de argumentos/[-2]=No se encontró la pelicula.
 *
 */
int busca_Index_Pelicula_PorTitulo( sMovie *peliculas, int largoArray, char *tituloABuscar )///<---------------------------------------------------------------------------
{
    int retorno = -1;
    if( peliculas != NULL && largoArray > 0 && tituloABuscar != NULL && tituloABuscar[0]!='\0' )
    {
        int i;
        int encontroPelicula = 0;

        for( i=0 ; i<largoArray ; i++ )
        {
            if( peliculas[i].estado == 1 && (stricmp(tituloABuscar, peliculas[i].titulo) == 0) )
            {
                encontroPelicula = 1;
                retorno = i;
            }
        }

        if( encontroPelicula == 0 )
        {
            retorno = -2;
        }

    }
    return retorno;
}



/** \brief Funcion de uso interno que solicita la modificacion al usuario, mostrandole un menú con cada atributo de las peliculas.
 *
 * \param pelicula Puntero que apunta a la pelicula que se va a modificar.
 * \param intentos Cantidad de intentos que se le solicita el ingreso al usuario en caso de fallar.
 * \return [0]=Modificacion exitosa/[-1]=Error de argumentos/[-2]=Error al modificar la pelicula.
 *
 */
int solicitar_Modificar_Pelicula( sMovie *pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int opcion;
        int error;

        system("cls");

        opcion = menu_generico( "Seleccione el atributo que desea modificar:\n1)Titulo\n2)Genero\n3)Duracion\n4)Puntaje\n5)Descripcion\n6)URL de la imagen\n7)Volver al menu principal\n", 1, 7, 3, "Error! Opcion invalida" );

        switch(opcion)
        {
            case 1:
                error = cambiar_Titulo( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 2:
                error = cambiar_Genero( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 3:
                error = cambiar_Duracion( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 4:
                error = cambiar_Puntaje( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 5:
                error = cambiar_Descripcion( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 6:
                error = cambiar_URLImagen( pelicula , intentos );///<---------------------------------------------------------------------------
                break;
            case 7:
                break;
        }

        if( error == 0 )
        {
            retorno = 0;
        }
        else
        {
            retorno = -2;
        }


    }

    return retorno;

}

/** \brief Agrega una película al array de peliculas.
 * \param pelicula puntero al array
 * \param  intentos cantidad de intentos que puede hacer
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 */
int cambiar_Titulo( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        char tituloAux[20];
        system("cls");

        error = getStringConIntentos( tituloAux, 20, "Ingrese el nuevo titulo de la pelicula:", "Error! Titulo inv""\xA0""lido.", intentos );

        if( error == 0 )
        {
            strcpy( pelicula->titulo, tituloAux );
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}



/** \brief cambia el genero de la pelicula
 *
 * \param pelicula puntero al array para cambiar
 * \param intentos cantidad de intentos que se puede hacer
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 *
 */
int cambiar_Genero( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        char generoAux[20];
        system("cls");

        error = getStringConIntentos( generoAux, 20, "Ingrese el nuevo genero de la pelicula:", "Error! Genero inv""\xA0""lido.", intentos );

        if( error == 0 )
        {
            strcpy( pelicula->genero, generoAux );
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}



/** \brief cambiar la duracion de la pelicula
 * \param pelicula puntero al array para cambiar
 * \param intentos cantidad de intentos para cambiar
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 */
int cambiar_Duracion( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        int duracionAux;
        system("cls");

        error = getInt( &duracionAux, "Ingrese la nueva duraci""\xA2""n de la pelicula: ", 1, 1, 0, 10, "Error! Duraci""\xA2""n incorrecta.", intentos);

        if( error == 0 )
        {
            pelicula->duracion = duracionAux ;
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}



/** \brief cambio del puntaje de la pelicula
 * \param pelicula puntero al array para cambiar
 * \param intentos cantidad de los intentos para cambiar
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 */
int cambiar_Puntaje( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        int puntajeAux;
        system("cls");

        error = getInt( &puntajeAux, "Ingrese el nuevo puntaje de la pelicula: ", 1, 1, 0, 10, "Error! Puntaje incorrecto.", intentos);

        if( error == 0 )
        {
            pelicula->puntaje = puntajeAux ;
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}



/** \brief cambia la descripcion de la pelicula
 * \param pelicula es el puntero al array para cambiar
 * \param intentos es la cantidad de intentos que se puede hacer para cambiar la descripcion
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 */
int cambiar_Descripcion( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        char descripcionAux[50];
        system("cls");

        error = getStringConIntentos( descripcionAux, 50, "Ingrese la nueva descripci""\xA2""n de la pelicula:", "Error! Descripci""\xA2""n inv""\xA0""lida.", intentos );

        if( error == 0 )
        {
            strcpy( pelicula->descripcion, descripcionAux );
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}



/** \brief cambia el URLimagen  de la pelicula
 * \param pelicula es el puntero al array
 * \param intentos es la cantidad de intentos que se puede hacer
 * \return [0]=cambio correcto/[-1]=Error en el cambio y [-2]= no hubo cambio
 *
 */
int cambiar_URLImagen( sMovie* pelicula, int intentos )///<---------------------------------------------------------------------------
{
    int retorno = -1;

    if( pelicula != NULL && intentos > 0 )
    {
        int error;
        char URLAux[150];
        system("cls");

        error = getStringConIntentos( URLAux, 150, "Ingrese la nueva URL de la imagen de la pelicula:", "Error! URL inv""\xA0""lida.", intentos );

        if( error == 0 )
        {
            strcpy( pelicula->linkImagen, URLAux );
            retorno = 0;
        }
        else if( error == -1 )
        {
            retorno = -2;
        }
    }

    return retorno;

}




/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/
/****************************************************************************************************************************/




/** \brief Analiza una cádena de caracteres y nos dice si dicha cádena es exactamente igual a "0".
 * \param cadena Cádena a analizar.
 * \return [0]=NO es una cadena de la forma "0" / [1]=La cadena es igual a "0".
 */
int esStringCero(char* cadena)///<-----------------------------------------------------------------------------------------
{
    if(cadena[0]=='0' && cadena[1]=='\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief Imprime un menú y pide el ingreso de opción la cantidad de veces indicada.
 * \param menu  Opciones del menú, separadas por '\n', no debe pasarse el mensaje que pide el ingreso de la opción.
 * \param opcionMin Opción mínima del menú.
 * \param opcionMax Opción máxima del menú.
 * \param cantidadPreguntas Cantidad de veces que se le va a preguntar a la persona en caso de fallo.
 * \param mensajeError  Mensaje mostrado en caso de ingresar una opción inválida.
 * \return Opción seleccionada por la persona, si ingreso una opción inválida en todos los intentos retorna [-1].
 */
int menu_generico(char* menu, int opcionMin, int opcionMax, int cantidadPreguntas, char* mensajeError)///<---------------------------------------------------------------
{
    int respuesta;
     int error;
    int contadorIntentos=0;

    do
    {
        system("cls");
        printf("%s", menu);
        printf("\n\nIngrese la opci""\xE0""n deseada: ");
        fflush(stdin);
        error = getInt(&respuesta, "", 1, 1, opcionMin, opcionMax, mensajeError, 1);

        if( error != -1)
        {
            return respuesta;
            break;
        }

        contadorIntentos++;
    }while( contadorIntentos < cantidadPreguntas );

    return -1;
}


/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea entero y que no sobrepase los límites dados.
 * \param miEntero  Dirección donde se almacena el entero, solo en caso de ingreso exitoso.
 * \param mensaje  Mensaje mostrado al usuario cuando se pide el ingreso.
 * \param tieneMinimo  Si NO tiene mínimo debe pasarse [0], si tiene mínimo debe pasarse [1].
 * \param tieneMaximo  Si NO tiene máximo debe pasarse [0], si tiene máximo debe pasarse [1].
 * \param minimo  Límite inferior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param maximo  Límite superior INCLUSIVO, en caso de no tenerlo se debe pasar [0].
 * \param msjError  Mensaje mostrado al usuario en caso de ingreso incorrecto.
 * \return [0]=Ingreso exitoso / [-1]=Ingreso no validado.
 */
 int getInt(int* miEntero, char* mensaje,  int tieneMinimo,  int tieneMaximo, int minimo, int maximo, char* msjError, int intentos)///<---------------------------------------------------------------------
{
     int retorno = -1;
    int contadorIntentos = 0;
    char buffer[601]; //Buffer para lectura de la entrada por teclado del usuario.
    int aux; //Auxiliar utilizado para analizar maximos y minimos sin asignar.
     int verificaMaxYMin;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(buffer); //Se lee el ingreso del usuario.

        if(!esStringCero(buffer)) //Si el usuario NO ingresó "0" se usa atoi (ya que atoi retorna [0] como código de error y no se puede diferenciar error del ingreso de "0").
        {
            aux = atoi(buffer);
            if(aux != 0) //Si no es error se chequean maximos y minimos, etc.
            {
                verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
                if(verificaMaxYMin)
                {
                    *miEntero = aux;
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("\n%s\n", msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
            }
            else //Si 'aux' es igual a [0] significa que hay error (porque ya se validó que sea !=0).
            {
                system("cls");
                printf("\n%s\n", msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }
        }
        else //Si el usuario ingreso "0".
        {
            //Se verifica Maximos y Minimos.
            aux = 0;
            verificaMaxYMin = verificarMaxYMinEntero(&aux, &tieneMinimo, &tieneMaximo, &minimo, &maximo);
                if(verificaMaxYMin)
                {
                    *miEntero = aux;
                    retorno = 0;
                    break;
                }
                else
                {
                    system("cls");
                    printf("\n%s\n", msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
        }

        contadorIntentos++;

    }while( contadorIntentos < intentos );

    return retorno;
}



/** \brief (Función de uso interno de "getInt") Verifica que un número se encuentre entre el minimo y el máximo dado.
 * \param numero  Numero a evaluar.
 * \param tieneMinimo  [0]=No tiene minimo [1]=Tiene minimo.
 * \param tieneMaximo  [0]=No tiene máximo [1]=Tiene máximo.
 * \param minimo Minimo a evaluar.
 * \param maximo Máximo a evaluar.
 * \return [0]=No cumple con los límites / [1]=Cumple con los límites.
 *
 */
 int verificarMaxYMinEntero(int* numero,  int* tieneMinimo,  int* tieneMaximo, int* minimo, int* maximo)
{
    //Si NO tiene minimo NI máximo.
    if(!*tieneMinimo && !*tieneMaximo)
    {
        return 1;
    }

    //Si tiene minimo y tiene maximo.
    else if(*tieneMinimo && *tieneMaximo)
    {
        if(*numero >= *minimo && *numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si tiene minimo y NO tiene maximo.
    else if(*tieneMinimo && !*tieneMaximo)
    {
        if(*numero >= *minimo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //Si NO tiene minimo y tiene maximo.
    else if(!*tieneMinimo && *tieneMaximo)
    {
        if(*numero <= *maximo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}



/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea string del largo permitido y en caso de error muestra un mensaje.
 * \param miCadena  Cadena de caracteres donde voy a almacenar el ingreso en caso exitoso.
 * \param largoMiCadena Largo de 'miCadena'.
 * \param mensaje  Mensaje que se muestra al usuario al pedir el ingreso.
 * \param msjError  Mensaje mostrado al usuario en caso de ingreso erroneo.
 * \return [0]=Se obtubo exitosamente el string / [-1]=Error al obtener el string.
 */
 int getString(char *miCadena, int largoMiCadena, char *mensaje, char *msjError)
{
    char buffer[601];
    int largoAux;
    printf("%s", mensaje);
    fflush(stdin);

    gets(buffer);

    largoAux = strlen(buffer);

    if( largoAux >= largoMiCadena || largoAux <= 0)
    {
        system("cls");
        printf("%s", msjError);
        Sleep(SLEEP_TIME);
        return -1;
    }
    else
    {
        strcpy(miCadena, buffer);
        return 0;
    }
}

/** \brief Muestra un mensaje, lee una entrada por teclado, valida que sea string del largo permitido y en caso de error muestra un mensaje.
 * \param miCadena  Cadena de caracteres donde voy a almacenar el ingreso en caso exitoso.
 * \param largoMiCadena  Largo de 'miCadena'.
 * \param mensaje  Mensaje que se muestra al usuario al pedir el ingreso.
 * \param msjError  Mensaje mostrado al usuario en caso de ingreso erroneo.
 * \param intentos  Cantidad de intentos para pedir el string al usuario.
 * \return [0]=Se obtubo exitosamente el string / [-1]=Error al obtener el string.
 *
 */
 int getStringConIntentos(char* miCadena, int largoMiCadena, char* mensaje, char* msjError,  int intentos)///<---------------------------------------------------------------------------
{
     int retorno = -1;
    char buffer[601];
    int contadorIntentos = 0;
    int largoLectura;

    if( miCadena!=NULL && intentos>0 && largoMiCadena>0 )
    {
        do{
            printf("%s", mensaje);
            fflush(stdin);

            gets(buffer);

            largoLectura = strlen(buffer);

            if( largoLectura < largoMiCadena && largoLectura > 0)
            {
                strcpy(miCadena, buffer);
                retorno = 0;
                break;
            }
            else
            {
                system("cls");
                printf("%s", msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }

            contadorIntentos++;

        }while( contadorIntentos < intentos );
    }

    return retorno;
}


/** \brief Normaliza el formato de una cadena de caracteres.
 * \param miCadena  Cadena de caracteres a normalizar.
 * \param largoMiCadena Largo de 'miCadena'.
 * \param tipoNormalizacion  ['1']=Lleva todo el string a minúsculas.
                                    ['2']=Lleva todo el string a mayúsculas.
                                    ['3']=Primera letra en mayúscula, las demás en minúsculas.
 * \return [0]=Normalización exitosa / [-1]=Error en la normalización.
 */
 int normalizarString(char* miCadena, int largoMiCadena, int tipoNormalizacion)
{
    int i=0;
    int largo;

    largo = strlen(miCadena);

    if( largo > (largoMiCadena-1))
    {
        return -1;
    }
    else
    {
        switch(tipoNormalizacion)
        {
            case 1:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    miCadena[i] = tolower(miCadena[i]);
                }
                return 0;
                break;

            case 2:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    miCadena[i] = toupper(miCadena[i]);
                }
                return 0;
                break;

            case 3:
                for( i=0 ; i<(largoMiCadena-1) ; i++ )
                {
                    if( i == 0 )
                    {
                        miCadena[i] = toupper(miCadena[i]);
                    }
                    else if( miCadena[i] == ' ')
                    {
                        miCadena[(i+1)] = toupper(miCadena[(i+1)]);
                        i++;
                    }
                    else
                    {
                        miCadena[i] = tolower(miCadena[i]);
                    }
                }
                return 0;
                break;

            default:
                return -1;
                break;
        }
    }
}


/** \brief Pregunta algo al usuario donde puede responder por Si o por No.
 *
 * \param mensaje (char[]) Mensaje que se le muestra al usuario al pedir la respuesta.
 * \param msjError (char[]) Mensaje que se le muestra al usuario en caso de respuesta incorrecta.
 *
 * \return ( int) [0]=Usuario eligio NO / [1]=Usuario eligió SI / [-1]=Respuesta incorrecta.
 *
 */
 int preguntarPorSiOPorNo(char* mensaje, char* msjError, int intentos)///<---------------------------------------------------------------
{
     int retorno = -1;
    int contadorIntentos = 0;
    char buffer[601]; ///Buffer donde se lee la respuesta.
     int error; ///Almacenamiento de el error retornado.

    if( mensaje!=NULL && intentos>0 )
    do
    {
        ///Se pide ingreso de 's' o 'n' al usuario.
        error = getString(buffer, 601, mensaje, msjError);

        if( error == 0 )
        {
            ///Se convierte la respuesta a minúsculas para evaluarla.
            normalizarString(buffer, 601, 1);

            ///Se analiza la respuesta obtenida.
            if( buffer[1] == '\0' )
            {
                if( buffer[0] == 's' )
                {
                    retorno = 1;
                    break;
                }
                else if( buffer[0] == 'n' )
                {
                    retorno = 0;
                    break;
                }
                else
                {
                    system("cls");
                    printf("%s",msjError);
                    Sleep(SLEEP_TIME);
                    system("cls");
                }
            }
            else
            {
                system("cls");
                printf("%s",msjError);
                Sleep(SLEEP_TIME);
                system("cls");
            }
        }

        contadorIntentos++;

    }while( contadorIntentos < intentos );

    return retorno;
}

