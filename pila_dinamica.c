/*
	Name:pila_dinamica.c 
	Copyright: 
	Author: 
	Date: 17/09/21 11:50
	Description: Ejemplo de pilas dinamicas trabajando elemento por elemento
*/

//Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodo {
   int iValor;
   struct nodo *siguiente;	//apuntador a un nodo
} tipoNodo;
 
typedef tipoNodo *pNodo;
 
/* Funciones con pilas: */
void Push(pNodo *ultimo, int iValor) {
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->iValor = iValor;
   
   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->siguiente = *ultimo;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   *ultimo = nuevo;
}

int Pop(pNodo *pila) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int iValor;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a pila toda la pila menos el primer elemento */
   *pila = nodo->siguiente;
   /* Guardamos el valor de retorno */
   iValor = nodo->iValor; 
   /* Borrar el nodo */
   free(nodo);
   return iValor;
} 


int main() {
   pNodo pila = NULL;
 
   Push(&pila, 10);
   Push(&pila, 20);
   Push(&pila, 30);
   printf("%d, ", Pop(&pila));
   printf("%d, ", Pop(&pila));
   Push(&pila, 40);
   Push(&pila, 50);

   printf("%d, ", Pop(&pila));
   printf("%d, ", Pop(&pila));
   Push(&pila, 60);
   printf("%d, ", Pop(&pila));
   printf("%d\n", Pop(&pila));
   printf("%d\n", Pop(&pila));
   

   getche();
   return 0;
}
