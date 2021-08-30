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

         printf("\nIngresa el nombre del Alumno %d: ", iIndice + 1);
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

/*
	Name: Funcion imprime
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Imprime los datos del alumno y saca el promedio de los valores
        Parametros: 
            arreglo: apuntador a un arreglo dinamico 
            MAX: numero de elementos del arreglo dinamico 
		Regresa: Un valor de tipo void
*/
void imprime(Alumno arreglo, int MAX)
{
    int iContador; //Variable que recorre el arreglo
    float Promedio; //Variable que guarda el promedio de cada alumno
    
    printf("\n\t|||Alumnos|||");
    //estructura de control para imprimir la informacion de cada uno de los alumnos
    for ( iContador = 0; iContador < MAX; iContador++)
    {
        printf("\nNombre: %s\n", arreglo[iContador].Nombre);
        printf("Valor 1: %d\n", arreglo[iContador].Valor1);
        printf("Valor 2: %d\n", arreglo[iContador].Valor2);
        printf("Valor 3: %d\n", arreglo[iContador].Valor3);
        
        Promedio = ((arreglo[iContador].Valor1 + arreglo[iContador].Valor2 + arreglo[iContador].Valor3)/3);
        printf("Promedio: %.2f\n", Promedio);
        
    }
}

//Funcion principal
int main(){
    
    //Variables locales
    Alumno arreglo; //Declaramos la variable de arreglo de tipo Alumno que será el parámetro de las funciones
    int iElementos;
    
    printf ("Cuantos elementos necesitas: ");
    scanf ("%d",&iElementos);
    
    arreglo = (Alumno) malloc (sizeof(InfoAlumnos)*iElementos);

    ingresa(arreglo, iElementos);
    
    imprime(arreglo, iElementos);

free(arreglo);
system("PAUSE"); //detiene la ejecucion del programa
return 0;

}