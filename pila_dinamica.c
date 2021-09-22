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
 
/*
	Name:Push 
	Copyright: 
	Author: 
	Date: 17/09/21 11:50
	Description: Funcion que agrega un elemento a la pila
   Parámetros: 
			ultimo: apuntador al último elemento de la pila 
					POR REFERENCIA			
         iValor: entero con el dato a ingresar
			nombre: cadena de caracteres con el dato a ingresar
		Regreso:
			void
*/

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

/*
	Name:Pop
	Copyright: 
	Author: 
	Date: 17/09/21 11:50
	Description: Funcion que elimina un elemento de la pila
   Parámetros: 
			pila: apuntador al último elemento de la pila 
					POR REFERENCIA			
		Regreso:
			entero
*/
int Pop(pNodo *pila, char cadena[20]) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int iValor;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a pila toda la pila menos el primer elemento */
   *pila = nodo->siguiente;
   /* Guardamos el valor de retorno */
   iValor = nodo->iValor;
   strcpy(cadena,nodo->sNombre); 
   /* Borrar el nodo */
   free(nodo);
   return iValor;
} 

//Funcion principal
int main() {
   pNodo pila = NULL;
   char sNombre[20];
 
   Push(&pila, 10, "Diez");
   Push(&pila, 20, "Veinte");
   Push(&pila, 30, "Treinta");
   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   Push(&pila, 40, "Cuarenta");
   Push(&pila, 50, "Cincuenta");

   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   Push(&pila, 60, "Sesenta");
   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   //printf("Pop: %d %s \n",Pop(&pila,sNombre),sNombre);
   

   getche();
   return 0;
}
