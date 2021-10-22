//Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_VALOR -1
 
typedef struct nodo {
   int canciones;
   char titulo[22];
   char artista[20];
   struct nodo *liga; //Apuntador que apunta a una struct nodo
} tipoNodo;

typedef tipoNodo *pNodo; //Apuntador a toda una estructura

void creaInicio(pNodo *liga, int numCanciones, char album[22], char nomArtista[20]){
	pNodo P, Q;

	P = (pNodo)malloc(sizeof(tipoNodo));
	P->canciones = numCanciones;
	strcpy(P->titulo, album);
	strcpy(P->artista, nomArtista);
	P->liga = NULL;
	
	do{
		Q = (pNodo)malloc(sizeof(tipoNodo));
		Q->canciones = numCanciones;
		strcpy(Q->titulo, album);
		strcpy(Q->artista, nomArtista);
		Q->liga = P;
		P = Q;
	} while (Q == NULL);
	
}

void creaFinal(pNodo *liga, int numCanciones, char album[22], char nomArtista[20]){
	pNodo P, Q, T;

	P = (pNodo)malloc(sizeof(tipoNodo));
	P->canciones = numCanciones;
	strcpy(P->titulo, album);
	strcpy(P->artista, nomArtista);
	P->liga = NULL;
	T = P;
	
	do{
		Q = (pNodo)malloc(sizeof(tipoNodo));
		Q->canciones = numCanciones;
		strcpy(Q->titulo, album);
		strcpy(Q->artista, nomArtista);
		Q->liga = NULL;
		T->liga= Q;
		T = Q;
	} while (Q == NULL);
	
}

int main(){
	pNodo inicio = NULL, 
		  final = NULL;

	int eOpcion = 0, 
		numCanciones;
    char album[22], nomArtista[20];

	do{
		fflush(stdin);
		//system("cls");
		printf("\t*******\n\t Lista ligada\n\t*******\n");
		printf("1. Crear lista desde el inicio\n2. Crear lista desde el final\n3. Ver Extremos\n4. Ver Cola\n5. Salir\n");
		printf("Selecione una opci%cn: ", 162);
		scanf("%d", &eOpcion);

		switch(eOpcion){
			case 1: printf("Ingrese el numero de canciones del album: \n");
					scanf("%d", &numCanciones);
                    printf("Ingresa el nombre del album: \n");
                    fflush(stdin);
                    gets(album);
					printf("Ingresa el nombre del artista: \n");
                    fflush(stdin);
					gets(nomArtista);
					creaInicio(&inicio, numCanciones, album, nomArtista);
					break;

			case 2: printf("Ingrese el numero de canciones del album: \n");
					scanf("%d", &numCanciones);
                    printf("Ingresa el nombre del album: \n");
                    fflush(stdin);
                    gets(album);
					printf("Ingresa el nombre del artista: \n");
                    fflush(stdin);
					gets(nomArtista);
					creaFinal(&inicio, numCanciones, album, nomArtista);
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