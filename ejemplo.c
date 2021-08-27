#include <stdio.h>	//Definicion de la biblioteca "stdio.h"
#define MAX 10	//Definicion de uina constante llamada MAX, que será susbtituida por un 5

/*
  Name: arreglo estatico.c
  Copyright: EM 2021
  Author: Esther Martinez
  Date: 12/08/21 22:00
  Description: Programa ejemplo de un arreglo estático de 5 elementos. 
               Curso Programación I.
               
               
*/
/*
	Name: Funcion inicializa
	Copyright: 
	Author: 
	Date: 18/08/21 11:30
	Description: Funcion que inicializa un arreglo de MAX elementos en valores del 0 hasta MAX-1
		Parametros: iaArreglo: arreglo de MAX elementos enteros
		Regresa: void
*/


void inicializa (int iaArreglo[MAX])
{
     int iIndice;   //Declaración de una variable de tipo entero que sirve de indice de recorrido
     for (iIndice=0; iIndice<MAX; iIndice++)
            iaArreglo[iIndice] = iIndice ;
}

/*
	Name: Funcion sumaDos
	Copyright: 
	Author: 
	Date: 18/08/21 11:51
	Description: Funcion que incrementa el valor de cada elemto en 2
		Parametros: iaArreglo: arreglo de MAX elementos enteros
		Regresa: void
*/
void sumaDos (int iaArreglo[MAX])
{
     int iIndice;
     for ( iIndice=0; iIndice<MAX; iIndice++)
            iaArreglo[iIndice] = iaArreglo[iIndice] + 2;
}

/*
	Name: Funcion imprimeArreglo
	Copyright: 
	Author: 
	Date: 18/08/21 11:54
	Description: Funcion que imprime cada elemento del arreglo
		Parametros: iaArreglo: arreglo de MAX elementos enteros
		Regresa: void
*/
void imprimeArreglo (int iaArreglo[MAX])
{
     int iIndice;
     for (iIndice=0; iIndice<MAX; iIndice++)
          printf(" %i  ", iaArreglo[iIndice]);+
     
     printf("\n");
}


//Funcion principal

main()
{
  int iaVector[MAX];  			// arreglo local

  inicializa(iaVector);         // inicializa el vector en 0
  imprimeArreglo(iaVector);     // imprime en pantalla los valores del vector
  
  sumaDos (iaVector);           // suma dos a los elementos del vector
  imprimeArreglo(iaVector);     // imprime en pantalla los valores del vector
  
  sumaDos (iaVector);           // suma dos a los elementos del vector
  imprimeArreglo(iaVector);     // imprime en pantalla los valores del vector
  

  system("PAUSE");            // detiene la ejecución del programa.
}
