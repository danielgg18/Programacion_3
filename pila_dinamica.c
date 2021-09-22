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
#include <string.h>
 
typedef struct nodo {
   int iValor;
   char sNombre[20];
   struct nodo *siguiente;	//apuntador a un nodo
} tipoNodo;
 
typedef tipoNodo *pNodo;
 
/* Funciones con pilas: */
void Push(pNodo *ultimo, int iValor, char nombre[20]) {
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->iValor = iValor;
   strcpy(nuevo->sNombre, nombre);
   
   /* A�adimos la pila a continuaci�n del nuevo nodo */
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
 
   Push(&pila, 10, "Diez");
   Push(&pila, 20, "Veinte");
   Push(&pila, 30, "Treinta");
   printf("Push: %i %s , Pop: %d\n",pila->iValor,pila->sNombre,Pop(&pila));
   printf("Push: %i %s , Pop:%d\n",pila->iValor,pila->sNombre,Pop(&pila));
   Push(&pila, 40, "Cuarenta");
   Push(&pila, 50, "Cincuenta");

   printf("Push: %i %s , Pop: %d\n",pila->iValor,pila->sNombre, Pop(&pila));
   printf("Push: %i %s , Pop: %d\n", pila->iValor,pila->sNombre,Pop(&pila));
   Push(&pila, 60, "Sesenta");
   printf("Push: %i %s , Pop: %d\n", pila->iValor,pila->sNombre,Pop(&pila));
   printf("Push: %i %s , Pop: %d\n", pila->iValor,pila->sNombre,Pop(&pila));
   printf("Push: %i %s , Pop: %d\n",pila->iValor,pila->sNombre, Pop(&pila));
   

   getche();
   return 0;
}
