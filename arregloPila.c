#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0


typedef struct {
    char sNombre[20];
    int iValor;
} nNodo;

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
        Parametros: Ninguno
		Regresa:
            VERDADERO si esta vacia la pila  
            FALSO si no esta vacia
*/
int pila_llena () {

    /*Cuando la pila esta llena*/    
    
}

void ver_tope () {

    /*Como ver tope*/    
    
}

void ver_pila() {

    /*Como ver la pila desde tope*/    
    
}



void push (int elemento, int **tope) {
     
     
}



void pop (int **tope) {
     
}


main() {

nNodo *inicio;
nNodo *tope;

int iTamanio_pila;

    printf ("Cual es el tamano de la pila? ");
    scanf ("%d", &iTamanio_pila);


    inicio = (nNodo *) malloc (sizeof (nNodo) *iTamanio_pila); //Se reserva un espacio de memoria de nNodo * tamaño de la pila
    
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