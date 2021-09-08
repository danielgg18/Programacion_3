#include <stdio.h>


int pila_vacia () {

    /*Cuando la pila esta vacia*/    
    
}


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

int *pila;
int *tope;

int iTamanio_pila;

    printf ("Cual es el tamano de la pila? ");
    scanf ("%d", &iTamanio_pila);


    pila=(int *) malloc (sizeof (int) *iTamanio_pila);
    
    tope = pila+iTamanio_pila;
    
    printf ("Tope: %p\t Pila %p\n", tope, pila);
     
    push(10, &tope);
    push(20, &tope);
    push(30, &tope);
    push(40, &tope);
    push(50, &tope);
    
    printf ("Tope: %p\t Pila %p\n", tope, pila);

    
    pop(&tope);
    pop(&tope);
    printf ("Tope: %p\t Pila %p\n", tope, pila);
    
    push(60, &tope);

    
    
    free(pila);    
    system ("PAUSE");
       
}