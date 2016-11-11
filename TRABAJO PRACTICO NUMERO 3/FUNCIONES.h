#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
    int estado; //[0]=No hay data cargada /[1]=Hay datos cargados.
}sMovie;


//Funciones de inicializacion
int inicializar_pelicula( sMovie *peliculas, int largoArray );

//Funciones del menú
void agregar_Pelicula( sMovie *peliculas, int largoArray );
void borrar_Pelicula( sMovie *peliculas, int largoArray );
void modificar_Pelicula ( sMovie *peliculas, int largoArray );
void generar_Pagina( sMovie* peliculas , int largoArray );
void do_Exit( sMovie *peliculas, int largoArray );


//Funciones internas
int solicitar_Ingreso_Pelicula( sMovie *peliculaAux, int intentos );
int buscar_Libre( sMovie *peliculas, int largoArray );
int busca_Index_Pelicula_PorTitulo( sMovie *peliculas, int largoArray, char *tituloABuscar );
int solicitar_Modificar_Pelicula( sMovie *pelicula, int intentos );

int cambiar_Titulo( sMovie *pelicula, int intentos );
int cambiar_Genero( sMovie *pelicula, int intentos );
int cambiar_Duracion( sMovie *pelicula, int intentos );
int cambiar_Puntaje( sMovie *pelicula, int intentos );
int cambiar_Descripcion( sMovie *pelicula, int intentos );
int cambiar_URLImagen( sMovie *pelicula, int intentos );
int guardarEnArchivo( sMovie *peliculas, int largoArray );
int cargarDesdeArchivo( sMovie *peliculas, int length );



//Prototipos de funciones


int esStringCero(char* cadena);///<-------------------
int menu_generico(char* menu, int opcionMin, int opcionMax, int cantidadPreguntas, char* mensajeError);///<-------------------
int getInt(int* retorno, char* mensaje,  int tieneMinimo,  int tieneMaximo, int minimo, int maximo, char* msjError, int intentos);///<-------------------
int verificarMaxYMinEntero(int* numero,  int* tieneMinimo,  int* tieneMaximo, int* minimo, int* maximo);///<-------------------
int getString(char *miCadena, int largoMiCadena, char *mensaje, char *msjError);///<-------------------
int getStringConIntentos(char* miCadena, int largoMiCadena, char* mensaje, char* msjError,  int intentos);///<-------------------
int normalizarString(char* miCadena, int largoMiCadena, int tipoNormalizacion);///<-------------------
int preguntarPorSiOPorNo(char* mensaje, char* msjError, int intentos);///<-------------------



#endif // FUNCIONES_H_INCLUDED

