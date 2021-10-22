#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_VALOR -1
 
typedef struct nodo {
   int informacion;
   char sNombre[12];
   //Apuntador que apunta a una struct nodo
} tipoNodo;

typedef tipoNodo *pNodo; //Apuntador a toda una estructura

<<<<<<< HEAD
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
=======
>>>>>>> parent of 90b1790 (Update lista.c)

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
		eNumero;
    char sNombre[12];

	do{
		fflush(stdin);
		//system("cls");
		printf("\t*******\n\t Lista ligada\n\t*******\n");
<<<<<<< HEAD
		printf("1. Crear lista desde el inicio\n2. Crear lista desde el final\n3. Ver Extremos\n4. Ver Cola\n5. Salir\n");
=======
		printf("1. Agregar\n2. Eliminar\n3. Ver Extremos\n4. Ver Cola\n5. Salir\n");
>>>>>>> parent of 90b1790 (Update lista.c)
		printf("Selecione una opci%cn: ", 162);
		scanf("%d", &eOpcion);

		switch(eOpcion){
<<<<<<< HEAD
			case 1: printf("Ingrese el numero de canciones del album: \n");
					scanf("%d", &numCanciones);
                    printf("Ingresa el nombre del album: \n");
                    fflush(stdin);
                    gets(album);
					printf("Ingresa el nombre del artista: \n");
=======
			case 1: printf("Ingrese el nuevo elemento: \n");
					scanf("%d", &eNumero);
                    printf("Ingresa el nombre del elemento: \n");
>>>>>>> parent of 90b1790 (Update lista.c)
                    fflush(stdin);
                    gets(sNombre);
					enCola(&inicio, &final, eNumero, sNombre);
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