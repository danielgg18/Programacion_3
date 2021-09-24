#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_VALOR -1
 
typedef struct nodo {
   int informacion;
   char sNombre[20];
   struct nodo *siguiente; //Apuntador que apunta a una struct nodo
} tipoNodo;

typedef tipoNodo *pNodo; //Apuntador a toda una estructura


/*
   Name: cola_vacia
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
   Regresa:
   	  1: Si la cola está vacÃ­a
   	  0: Si la cola no está vacÃ­a
*/
int cola_vacia(pNodo inicio){
	if(!inicio){
		return 1;
	}else
		return 0;
}

/*
   Name: cola_llena
   Description: Revisar si hay espacio en la memoria.
   Regresa:
   	  1: Si la memoria está llena
   	  0: Si la memoria no está llena
*/
int cola_llena(){
	
	if ( (pNodo)malloc(sizeof(tipoNodo))== NULL )
		return 1;
	else
		return 0;

}

/*
   Name: ver_cabecera
   Description: Mostrar el primer elemento de la cola
   Parámetros: 
      cabecera: Tipo apuntador al primer elemento de la cola
*/
void ver_cabecera(pNodo cabecera){
	if(cola_vacia(cabecera)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);
	} else 
		printf("El inicio de la cola es: %d %s\n", cabecera->informacion, cabecera->sNombre);
}


/*
   Name: ver_cola
   Description: Mostrar todos los elementos de la cola
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
*/
void ver_cola(pNodo inicio){

	pNodo aux;
	
	if(cola_vacia(inicio)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);	
	}else {
		aux = inicio;	
		printf("\nCola: ");
			while (aux != NULL){
				printf("%d ", aux->informacion);
				aux = aux->siguiente;
			}	
		printf("\n");
	}
}


/*
   Name: enCola
   Description: Agregar un nuevo elemento a la cola
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
	  final: Tipo apuntador al último elemento de la cola
	  x: Entero, informacion que se le asignara al elemento de la cola nuevo.
*/
void enCola(pNodo *inicio, pNodo *final, int x, char nombre[20]){
	pNodo nuevo;
	
	if(cola_llena()){ 	/* Revisar que no está llena la memoria */
				fprintf(stderr, "Memoria llena.\n");
	}else {
		nuevo = (pNodo)malloc(sizeof(tipoNodo)); //Se reserva el espacio en memoria para el incio
		nuevo->informacion = x;
        strcpy(nuevo->sNombre, nombre);
   		nuevo->siguiente = NULL;
   
		if(cola_vacia(*inicio)){
			*inicio = *final= nuevo;
		}else {
			(*final)->siguiente = nuevo;
			*final = nuevo;
		} 			
	}
}


/*
   Name: deCola
   Description: Eliminar y mostrar el primer elemento de la cola.
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
      final: Tipo apuntador al último elemento de la cola
   Regresa:
   	  x: Entero, el informacion del elemento de la cola que se eliminará.
   	  ERROR_VALOR : En caso de que la cola esté vacía.
*/
int deCola(pNodo *inicio, char nombre[20]){
	pNodo aux;
	int x;

	if(cola_vacia(*inicio)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);
		return ERROR_VALOR;
	}

	aux = *inicio;
	x = (*inicio)->informacion;
    strcpy(nombre,aux->sNombre);
	*inicio = (*inicio)->siguiente;
	
	return x;
}

/******************/
int main(){
	pNodo inicio = NULL, 
		  final = NULL;

	int eOpcion = 0, 
		eNumero;
    char sNombre[20];

	do{
		fflush(stdin);
		//system("cls");
		printf("\t*******\n\t Colas\n\t*******\n");
		printf("1. Agregar\n2. Eliminar\n3. Ver Frente\n4. Ver Cola\n5. Salir\n");
		printf("Selecione una opci%cn: ", 162);
		scanf("%d", &eOpcion);

		switch(eOpcion){
			case 1: printf("Ingrese el nuevo elemento: \n");
					scanf("%d", &eNumero);
                    printf("Ingresa el nombre del elemento: \n");
                    fflush(stdin);
                    gets(sNombre);
					enCola(&inicio, &final, eNumero, sNombre);
					break;

			case 2: eNumero = deCola(&inicio, sNombre);
					if (eNumero!= ERROR_VALOR)
						printf("Se elimin%c el elemento %d de la cola\n", 162, eNumero);
					break;

			case 3: ver_cabecera(inicio);
					getch();
					break;

			case 4: ver_cola(inicio);
					getch();
					break;

			case 5: break;

			default: printf("Error en la selecci%cn. \n", 162);
					 break;

		} // switch

	} while(eOpcion != 5);
			
	getch();
	return 0;
}