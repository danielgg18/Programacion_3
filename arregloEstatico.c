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
	Date: 26/08/21 
	Description: Estructura que almacena los datos de cada disco
		Parametros: cTitulo: titulo del disco
                    iCanciones: numero de canciones que hay en el disco
                    fPrecio: cuanto costo el disco

*/

typedef struct 
{
    char cTitulo[32];
    int iCanciones;
    float fPrecio;
} CompraDiscos;

typedef CompraDiscos iaInfoDisco[MAX]; //Definimos un tipo de dato CompraDiscos y lo nombramos iaInfoDiscos con un tamaño MAX

/*
	Name: Funcion ingresa
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Solicita los datos del disco 
        Parametros: aDisco: arreglo de MAX elementos enteros
		Regresa: Un valor de tipo void
*/
void ingresa (iaInfoDisco aDisco)
{
     int iIndice;   //Declaracion de una variable de tipo entero que sirve de indice de recorrido
     for (iIndice=0; iIndice<MAX; iIndice++){

         puts("\nIngresa el nombre del disco: ");
         fflush(stdin);
         gets(aDisco[iIndice].cTitulo);
         puts("\nIngresa el total de canciones: ");
         scanf("%i", &aDisco[iIndice].iCanciones);
         puts("\nIngresa el precio del disco: ");
         scanf("%f", &aDisco[iIndice].fPrecio);
     }
}           

/*
	Name: Funcion imprime
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Imprime los datos del disco 
        Parametros: aDisco: arreglo de MAX elementos enteros
		Regresa: Un valor de tipo void
*/
void imprime(iaInfoDisco aDisco)
{
    int iContador; //Variable que recorre el arreglo
    
    printf("\t|||Discos comprados|||");
    
    //estructura de control para imprimir la informacion de cada uno de los discos
    for ( iContador = 0; iContador < MAX; iContador++)
    {
        printf("\n***Disco %d***\n", iContador + 1);
        printf("Nombre del disco: %s\n", aDisco[iContador].cTitulo);
        printf("Num. de Canciones: %d\n", aDisco[iContador].iCanciones);
        printf("Precio: %.2f\n", aDisco[iContador].fPrecio);
    }
}

//Funcion principal
int main(){
    
    //Variables locales
    iaInfoDisco aDisco; //Declaramos la variable de aDisco de tipo iaInfoDisco que será el parámetro de las funciones
    
    ingresa(aDisco);
    imprime(aDisco);

system("PAUSE"); //detiene la ejecucion del programa
return 0;

}