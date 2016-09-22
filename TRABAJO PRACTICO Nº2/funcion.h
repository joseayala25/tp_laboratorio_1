#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado;

}Persona;

void inicializararraypersona(Persona elvectordni[],int cantidadelemento);
int buscarprimeraocurrencia(Persona elvectordni[],int cantidadelemento);
void mostrarordenado(Persona*elvectordni,int cantidadelelemento);
int buscardni(Persona lista[],char dni[]);


int esnumerico(char str[]);
int esalfanumerico(char str[]);
int esSoloLetras(char str[]);

void consiguecadena(char mensaje[],char input[]);
int consiguecadenaletra(char mensaje[],char input[]);
int consiguecadenanumero(char mensaje[],char input[]);

int menu_generico(char *mensaje,int desde,int hasta);
#endif // FUNCIONES_H_INCLUDED



