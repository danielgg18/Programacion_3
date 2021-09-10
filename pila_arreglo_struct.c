/*
	Name: pila_arreglo_struct.c
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:29
	Description: Programa que presenta una pila de una estructura
					(struct) con un campo entero
				en un arreglo dinámico 
	
*/

// Directivas al preprocesador
#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0


typedef struct {
	int iElemento;
}nNodo;


/*
	Name: pila_vacia
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que verifica si una pila está vacía
		Parámetros: 
			pila: apuntador al último elemento de la pila
		Regreso:
			VERDADERO: 	Si la pila está vacía
			FALSO: 		Si la pila no está vacía
			
*/
int pila_vacia ( nNodo *pila) {

    /*Cuando la pila esta vacia*/  
	  if (pila == NULL){
    	return VERDADERO; // es verdadero esta vacia la pila
	} else {
		
		return FALSO; // es falso
	}  
    
}

/*
	Name: pila_llena
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que verifica si una pila está llena
		Parámetros: 
			pila: apuntador al último elemento de la pila
			tope: apuntador al tope de la pila
		Regreso:
			VERDADERO: 	Si la pila está vacía
			FALSO: 		Si la pila no está vacía
			
*/

int pila_llena (nNodo *pila, nNodo *tope) {

    /*Cuando la pila esta llena*/   
	 if (pila == tope){
	 	
	 	return VERDADERO; // Si está llena la pila
	 	
	 } else {
	 	
	 	return FALSO; // Si no está llena la pila
	 } 
    
}

/*
	Name: ver_tope
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que muestra el último elemento de una pila
		Parámetros: 
			pila: apuntador al último elemento de la pila
		Regreso:
			void
			
*/
void ver_tope (nNodo *pila) {

    /*Como ver tope*/    
    printf("Tope: %i\tDireccion es: %p\n", pila->iElemento, pila ); 
								
}

/*
	Name: ver_pila
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que muestra el último elemento de una pila
		Parámetros: 
			pila: apuntador al último elemento de la pila 
			tope: apuntador al tope de la pila
			iTamanio_pila : entero con el tamaño de la pila
		Regreso:
			void
	
*/
void ver_pila(nNodo *pila, nNodo *tope, int iTamanio_pila) {

    /*Como ver la pila desde tope*/   
    nNodo *Aux;

    printf("\nLos elementos de la pila son: \n");
	
	for (Aux=pila-1; Aux>=tope-iTamanio_pila; Aux--){
		ver_tope(Aux);
	}
	
}





/*
	Name: push
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que agrega un elemento a una pila
		Parámetros: 
			elemento: entero con el dato a ingresar
			pila: apuntador al último elemento de la pila 
					POR REFERENCIA
			tope: apuntador al tope de la pila
		Regreso:
			void
			
*/
void push (int elemento, nNodo **pila, nNodo *tope) {
     
     if ( pila_llena(*pila,tope) == 1){
     	
     	printf("\nLa pila esta llena\n");
     	
	 } else { 
	 
		printf("\tPUSH\t");
     	(*pila)->iElemento = elemento;
     	ver_tope(*pila);
		(*pila)++; //sube un espacio el apuntador pila
 	}
     
}


/*
	Name: pop
	Copyright: 
	Author: Esther Martínez
	Date: 09/09/21 21:17
	Description: Función que elimina un elemento a una pila
		Parámetros: 
			pila: apuntador al último elemento de la pila 
					POR REFERENCIA
		Regreso:
			void		
*/
void pop (nNodo **pila) {
     
     
     if(pila_vacia(*pila) == 1){
		
		printf("\nLa pila esta vacia\n");
	} else {
		(*pila)--; 			// baja un espacio el apuntador pila
		printf("\n\tPOP:\t");
     	ver_tope(*pila);
	}
		
}


// Función principal
int main() {

	nNodo *pila;
	nNodo *tope;
	
	int iTamanio_pila;
	
	    printf ("Cual es el tamano de la pila? ");
	    scanf ("%d", &iTamanio_pila);
	
	    pila=(nNodo *) malloc (sizeof (nNodo) *iTamanio_pila);
	    
	    tope = pila+iTamanio_pila; //apuntamos el tope al final de la pila
	    
	    printf ("Pila: %p\t Tope %p\n", pila, tope);
	
	    push(10, &pila, tope);
	    push(20, &pila, tope);
	    push(30, &pila, tope);
	    push(40, &pila, tope);
	    push(50, &pila, tope);
	    
		ver_pila(pila,tope, iTamanio_pila);
	
	    pop(&pila);
	    ver_pila(pila,tope, iTamanio_pila);
	    
		pop(&pila);
		ver_pila(pila,tope, iTamanio_pila);
	    
	    push(60, &pila, tope);
	
	    ver_pila(pila,tope, iTamanio_pila);
	    
	    free(pila);    
	    system ("PAUSE");
	    return 0;
	       
}