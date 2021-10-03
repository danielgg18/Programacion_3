#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_VALOR -1
 
typedef struct nodo {
   int informacion;
   char sNombre[12];
   struct nodo *anterior;
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
int cola_vacia(pNodo inicio, pNodo final){
	if(!inicio && !final){
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
   Name: ver_extremos
   Description: Mostrar el primer o el ultimo elemento de la cola
   Parámetros: 
      cabecera: Tipo apuntador al primer elemento de la cola
      ultimo: Tipo apuntador al ultimo elemento de la cola
*/
void ver_extremos(pNodo cabecera, pNodo ultimo){
	
    int opcion;
    
    if(cola_vacia(cabecera, ultimo)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);
	} else {
		printf("¿Qué extremo de la cola deseas ver?:\n1.Inicio\n2.Final\n");
        scanf("%d", &opcion);
        
        if (opcion == 1)
        {
            printf("El inicio de la cola es: %d-%s\n", cabecera->informacion, cabecera->sNombre);
        } else {
            printf("El final de la cola es: %d-%s\n", ultimo->informacion, ultimo->sNombre);
        }
        
    }
}

/*
   Name: ver_cola
   Description: Mostrar todos los elementos de la cola
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
*/
void ver_cola(pNodo inicio, pNodo final){

	pNodo aux;
    int opcion;
	
	if(cola_vacia(inicio, final)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);	
	}else {
        printf("¿Desde donde deseas recorrer la cola?:\n1.Inicio\n2.Final\n");
        scanf("%d", &opcion);
		
        if (opcion == 1){
            aux = inicio;	
		    printf("\nCola: ");
			while (aux != NULL){
				printf("%d-%s ", aux->informacion, aux->sNombre);
				aux = aux->siguiente;
			}	
		    
        } else {
            aux = final;	
		    printf("\nCola: ");
			while (aux != NULL){
				printf("%d-%s ", aux->informacion, aux->sNombre);
				aux = aux->anterior;
            }
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
void enCola(pNodo *inicio, pNodo *final, int x, char nombre[12]){
	
	pNodo nuevo;
	int opcion;
	
	if(cola_llena()){ 	/* Revisar que no está llena la memoria */
				fprintf(stderr, "Memoria llena.\n");
	}else {
		
		nuevo = (pNodo)malloc(sizeof(tipoNodo)); //Se reserva el espacio en memoria para el incio
		nuevo->informacion = x;
		strcpy(nuevo->sNombre, nombre);			
		nuevo->siguiente = NULL;
		nuevo->anterior = NULL;
	
		printf("¿Desde donde deseas encolar?:\n1.Inicio\n2.Final\n");
        scanf("%d", &opcion);
		
		if (opcion == 1)
		{
			if(cola_vacia(*inicio, *final)){
				*inicio = *final = nuevo;
			}else {
				(*inicio)->anterior = nuevo;
				nuevo->siguiente = *inicio;
				*inicio = nuevo;
			} 			
		} else {
			
			if(cola_vacia(*inicio, *final)){
				*inicio = *final = nuevo;
			}else {
				(*final)->siguiente = nuevo;
				nuevo->anterior = *final;
				*final = nuevo;
			} 			
		}
		
	}
}


/*
   Name: deCola
   Description: Eliminar el primer elemento de la cola.
   Parámetros: 
      inicio: Tipo apuntador al primer elemento de la cola
   Regresa:
   	  x: Entero, el informacion del elemento de la cola que se eliminará.
   	  ERROR_VALOR : En caso de que la cola esté vacía.
*/
int deCola(pNodo *inicio, pNodo *final){
	pNodo aux;
	int x, opcion;

	if(cola_vacia(*inicio, *final)){
		fprintf(stderr, "La cola est%c vac%ca\n", 160, 161);
		return ERROR_VALOR;
	} else {
		printf("¿Que elemento deseas eliminar?:\n1.Inicio\n2.Final\n");
        scanf("%d", &opcion);
		
		if (opcion == 1)
		{
			aux = *inicio;
			x = (*inicio)->informacion;
			//strcpy(nombre,aux->sNombre);
			*inicio = (*inicio)->siguiente;
		} else {
			aux = *final;
			x = (*final)->informacion;
			//strcpy(nombre,aux->sNombre);
			*final = (*final)->anterior;
		}
		
	}
	
	if(*inicio==NULL){
		*final = NULL;
	}
	
	free(aux);
	return x;
}

/******************/
int main(){
	pNodo inicio = NULL, 
		  final = NULL;

	int eOpcion = 0, 
		eNumero;
    char sNombre[12];

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

			case 2: eNumero = deCola(&inicio, &final);
					if (eNumero!= ERROR_VALOR)
						printf("Se eliminaron los elementos %d-%s de la cola\n", eNumero, sNombre);
					break;

			case 3: ver_extremos(inicio, final);
					getch();
					break;

			case 4: ver_cola(inicio, final);
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