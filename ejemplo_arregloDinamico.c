/*
  Name: arreglodinamico.c
  Copyright: EM 2021
  Author: Daniel Garcia
  Date: 12/08/21 22:00
  Description: Programa ejemplo de un arreglo dinámico de n elementos. 
               Curso Programación.
               
               
*/
//Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>		//Incluye la funcion malloc

/*
	Name: Funcion inicializa
	Copyright: 
	Author: 
	Date: 25/08/21 11:21
	Description: Funcion que inicializa un arreglo dinamico de MAX elementos en valores de 0 hasta MAX-1
		Parámetros:
			A: apuntador a enteros (arreglo dinámico)
			MAX: numero de elementos en el arreglo
		Regresa: un valor de tipo void
*/

void inicializa (int *A, int MAX)
{
     int iIndice;    // variable contador del arreglo
     for (iIndice=0; iIndice<MAX; iIndice++)
            A[iIndice] = iIndice ;
}

/*
	Name: sumaDos
	Copyright: 
	Author: 
	Date: 25/08/21 11:21
	Description: Suma dos a cada uno de los elementos del arreglo dinámico
		Parámetros:
			A: apuntador a enteros (arreglo dinámico)
			MAX: numero de elementos en el arreglo
		Regresa: un valor de tipo void
*/

void sumaDos (int *A, int MAX)
{
     int iIndice;
     for ( iIndice=0; iIndice<MAX; iIndice++)
            A[iIndice] = A[iIndice] + 2;
}

/*
	Name: imprimeArreglo
	Copyright: 
	Author: 
	Date: 25/08/21 11:21
	Description: Imprime los elementos de un arreglo dinámico de MAX elementos
		Parámetros:
			A: apuntador a enteros (arreglo dinámico)
			MAX: numero de elementos en el arreglo
		Regresa: un valor de tipo void
*/

void imprimeArreglo (int *A, int MAX)
{
     int iIndice;
     for (iIndice=0; iIndice<MAX; iIndice++)
          printf(" %i  ", A[iIndice]);+
     
     printf("\n");
}

//Funcion principal
 main()
{
  int *vector;  	// apuntador a enteros que será un arreglo dinámico (local)
  int n;            //numero de elementos del arreglo
  
  
  printf ("Cuantos elementos necesitas: ");
  scanf ("%d",&n);
  
  /*
  	malloc es una función que reserva dinamicamente un espacio de memoria del tamaño de su parámetro
  	
  	sizeof es una función que regresa el tamaño en bytes de su parámetro
  	
  	(int *) es un cast o convertidor de tipo y va a convertir los bytes de malloc a apuntador a enteros
  	
  	
  */
  vector = (int *) malloc (sizeof(int)*n);

  inicializa(vector,n);         // inicializa el vector en 0
  imprimeArreglo(vector,n);     // imprime en pantalla los valores del vector
  
  sumaDos (vector,n);           // suma dos a los elementos del vector
  imprimeArreglo(vector,n);     // imprime en pantalla los valores del vector
  
  free(vector);		//libera la memoria empleada en el arreglo dinámico
  
  system("PAUSE");            // detiene la ejecución del programa.
}
