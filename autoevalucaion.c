/*
	Name: autoevaluacion.c
	Copyright: 
	Author: Daniel García García
	Date: 30/08/21 
	Description: Programa de un arreglo dinamico de estructuras
		
    */

//Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>		//Incluye la funcion malloc

//se define un tipo de dato struct y lo nombramos InfoAlumnos
typedef struct {

    char Nombre[15];
    int Valor1;
    int Valor2;
    int Valor3;
} InfoAlumnos;

typedef InfoAlumnos *Alumno; //Definimos un apuntador a InfoAlumnos y lo nombramos Alumno con un tamaño MAX

/*
	Name: Funcion ingresa
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Solicita los datos del alumno
            arreglo: apuntador a un arreglo dinamico 
            MAX: numero de elementos del arreglo dinamico 
		Regresa: Un valor de tipo void
*/
void ingresa (Alumno arreglo, int MAX)
{
     
    int iIndice;   //Declaracion de una variable de tipo entero que sirve de indice de recorrido
     
     for (iIndice=0; iIndice < MAX; iIndice++){

         puts("\nIngresa el nombre del Alumno: ");
         fflush(stdin);
         gets(arreglo[iIndice].Nombre);
         puts("\nIngresa el primer valor del alumno: ");
         scanf("%i", &arreglo[iIndice].Valor1);
         puts("\nIngresa el segundo valor del alumno: ");
         scanf("%i", &arreglo[iIndice].Valor2);
         puts("\nIngresa el tercer valor del alumno: ");
         scanf("%i", &arreglo[iIndice].Valor3);
     }
}           