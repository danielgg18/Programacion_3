#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0


typedef struct {
    int iInformacion;
    char sNombre[20];
} nNodo;

typedef nNodo *apNodo;

/*
	Name: pila_vacia
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Funcion que verifica si la pila esta vacia
        Parametros: Ninguno
		Regresa:
            VERDADERO si esta vacia la pila  
            FALSO si no esta vacia
*/
int pila_vacia () {

    if(tope - inicio == iTamanio_pila)
        return VERDADERO;
    else
        return FALSO;
}

/*
	Name: pila_llena
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Funcion que verifica si la pila esta llena
        Parametros:
            inicio: apuntador que apunta al ultimo elemento de la pila
            tope: apuntador que apunta al final de la pila
		Regresa:
            VERDADERO si esta llena la pila  
            FALSO si no esta llena
*/
int pila_llena (nNodo *inicio, nNodo *tope) {

   //si pila y tope apuntan al mismo lugar esta lleno
    if(inicio == tope)
        return VERDADERO;
    else

    
}

void ver_tope () {

    /*Como ver tope*/    
    
}

void ver_pila() {

    /*Como ver la pila desde tope*/    
    
}


/*
	Name: push
	Copyright: 
	Author: Daniel Garcia
	Date: 26/08/21 
	Description: Funcion que almacena un elemento a la pila
        Parametros:
            iInformacion: entero que contiene el valor del primer campo
            sNombre: cadena que contiene el valor del segundo campo
            tope: apuntador a nNodo y pasado por referencia
		Regresa:
            VERDADERO si esta llena la pila  
            FALSO si no esta llena
*/
void push (int iInformacion, char sNombre[20], apNodo *tope) {

    //cuando la pila esta llena marcar overflow y de lo contrario hacer las instrucciones de abajo 

    //if(pila_llena)

    *tope->iInformacion= iInformacion;
    strcpy(*tope->sNombre, sNombre);
    tope ++;
}



void pop (apNodo *tope) {
     
}


main() {

apNodo inicio;
apNodo tope;

int iTamanio_pila;

    printf ("Cual es el tamano de la pila? ");
    scanf ("%d", &iTamanio_pila);


    inicio = (apNodo) malloc (sizeof (nNodo) *iTamanio_pila); //Se reserva un espacio de memoria de nNodo * tamaño de la pila
    
    tope = inicio + iTamanio_pila;  //Se coloca el tope al final de la memoria
    
    printf ("Tope: %p\t Pila %p\n", tope, inicio);
     
    push(10, "Diez", &tope);
    push(20, "Veinte", &tope);
    push(30, "Treinta", &tope);
    push(40, "Cuarenta", &tope);
    push(50, "Cincuenta", &tope);
    
    printf ("Tope: %p\t Pila %p\n", tope, inicio);

    
    pop(&tope);
    pop(&tope);
    printf ("Tope: %p\t Pila %p\n", tope, inicio);
    
    push(60, "Sesenta", &tope);

    
    
    free(inicio);
    system ("PAUSE");
       
}