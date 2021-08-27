/*
	Name: arregloEstatico.c
	Copyright: 
	Author: Daniel García García
	Date: 26/08/21 
	Description: Programa de un arreglo estatico de estructuras
		
    */


#include <stdio.h> //Definicion de la biblioteca "stdio.h"
#include <string.h> //Definicion de la biblioteca "string.h"
#define MAX 3       //Definicion de uina constante llamada MAX, que sera susbtituida por un 3

/*
	Name: Estructura principal
	Copyright: 
	Author: Daniel García García
	Date: 19/08/21 08:33
	Description: Estructura que almacena los datos de cada disco
		Parametros: cTitulo: titulo del disco
                    iCanciones: numero de canciones que hay en el disco
                    fPrecio: cuanto costo el disco

*/

typedef struct CompraDiscos
{
    char cTitulo[32];
    int iCanciones;
    float fPrecio;
} 

typedef iaInfoDisco CompraDiscos
/*
	Name: ingresa
	Copyright: 
	Author: 
	Date: 18/08/21 11:30
	Description: Funcion que inicializa un arreglo de MAX elementos en valores del 0 hasta MAX-1
		Parametros: iaInfoDisco: arreglo de MAX elementos enteros
		Regresa: void
*/


void ingresa (int iaInfoDisco[MAX])
{
     int iIndice;   //Declaracion de una variable de tipo entero que sirve de indice de recorrido
     for (iIndice=0; iIndice<MAX; iIndice++){

         puts("\nIngresa el nombre del disco: ");
         gets("%c", iaInfoDisco[iIndice].cTitulo);
         puts("\nIngresa el total de canciones: ");
         scanf("%i", iaInfoDisco[iIndice].iCanciones);
         puts("\nIngresa el precio del disco: ");
         scanf("%f", iaInfoDisco[iIndice].fPrecio);
     }
            

void imprime(int iaInfoDisco[MAX])
{
    int iContador; //Variable que recorre el arreglo
    
    printf("\t|||Discos comprados|||");
    
    //estructura de control para imprimir la informacion de cada uno de los discos
    for ( iContador = 0; iContador < MAX; iContador++)
    {
        printf("\n***Disco %d***\n", iContador + 1);
        printf("Nombre del disco: %s\n", iaInfoDisco[iContador].cTitulo);
        printf("Num. de Canciones: %d\n", iaInfoDisco[iContador].iCanciones);
        printf("Precio: %.2f\n", iaInfoDisco[iContador].fPrecio);
    }
}

//Funcion principal
int main(){

    void ingresa(int iaInfoDisco[MAX]);

    void imprime(int iaInfoDisco[MAX]);



system("PAUSE"); //detiene la ejecucion del programa
return 0;

}