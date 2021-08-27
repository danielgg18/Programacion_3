/*
	Name: arregloEstatico.c
	Copyright: 
	Author: Daniel García García
	Date: 26/08/21 
	Description: Programa de un arreglo estatico de estructuras
		
    */


#include <stdio.h> //Definicion de la biblioteca "stdio.h"
#include <string.h> //Definicion de la biblioteca "string.h"

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

struct CompraDiscos
{
    char cTitulo[32];
    int iCanciones;
    float fPrecio;
} iaInfoDisco[3]; //arreglo en el que se guarda la informacion de cada disco


//Funcion principal
int main(){

    int iContador; //Variable que recorre el arreglo
    
    //Se almacena la informacion en cada miembro de la estructura
    strcpy(iaInfoDisco[0].cTitulo, "Rust in Peace");
    iaInfoDisco[0].iCanciones = 12;
    iaInfoDisco[0].fPrecio = 568.78;

    strcpy(iaInfoDisco[1].cTitulo, "Hellboy");
    iaInfoDisco[1].iCanciones = 15;
    iaInfoDisco[1].fPrecio = 499.50;

    strcpy(iaInfoDisco[2].cTitulo, "Bonded by blood");
    iaInfoDisco[2].iCanciones = 8;
    iaInfoDisco[2].fPrecio = 723.32;

    printf("\t|||Discos comprados|||");
    
    //estructura de control para imprimir la informacion de cada uno de los discos
    for ( iContador = 0; iContador < 3; iContador++)
    {
        printf("\n***Disco %d***\n", iContador + 1);
        printf("Nombre del disco: %s\n", iaInfoDisco[iContador].cTitulo);
        printf("Num. de Canciones: %d\n", iaInfoDisco[iContador].iCanciones);
        printf("Precio: %.2f\n", iaInfoDisco[iContador].fPrecio);
    }
    



system("PAUSE"); //detiene la ejecucion del programa
return 0;

}