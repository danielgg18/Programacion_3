/*************************************************************************************************************************
                  UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
                  FACULTAD DE CONTADURIA Y ADMINISTRACION

                       LICENCIATURA EN INFORMATICA
                           ESTRUCTURA DE DATOS
  Name: listaDoble.c 
  Description: Programa que permite el gestiomiento una lista doblemente ligada.           

***************************************************************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0



typedef struct nodo {
    int NumCanciones;   //Variable de tipo entero
    char NomArtista[30];
    char NomAlbum[30];
    float Precio;
    int Num;
	struct nodo *anterior; //Apuntador que apunta a una estructura nodo
	struct nodo *siguiente; //Apuntador que apunta a una estructura nodo   struct nodo *liga; //Apuntador que apunta a una estructura nodo
} tipoNodo; 
 
typedef tipoNodo *pNodo; //Apuntador de nombre pNodo que apunta a un tipoNodo


/* Nombre: Funcion creainicio
   Fecha: 02/11/2021
   
   Descripcion:	Funcion que crea una lista y agrega 
   				los elementos por el inicio.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void creainicio(pNodo *P){
	pNodo Q;
	int opc;
    char artista[30], album[30];
	
	system("cls");
    printf("\n\t\t\tCREA INICIO\n");
    
    *P = (pNodo) malloc (sizeof(tipoNodo));

    printf("\n****Ingresa los datos del %clbum****\n",160);
	printf("Nombre del %clbum: ", 160);
	fflush(stdin);
	gets(album);
	strcpy((*P)->NomAlbum, album);
	printf("\nNombre del artista: ");
	fflush(stdin);
	gets(artista);
	strcpy((*P)->NomArtista, artista);	
	printf("\nN%cmero de canciones del %clbum: ", 163, 160);
    scanf("%d",&(*P)->NumCanciones);
	printf("\nCosto del %clbum: $", 160);
    scanf("%f",&(*P)->Precio);
	printf("\nN%cmero de referencia del %clbum: ", 163, 160);
    scanf("%d",&(*P)->Num);
    
    (*P)->anterior=NULL;
    (*P)->siguiente=NULL;
    
    
    do {
    	Q = (pNodo) malloc (sizeof(tipoNodo));

    	printf("\n****Ingresa los datos del %clbum****\n",160);
		printf("Nombre del %clbum: ", 160);
		fflush(stdin);
		gets(album);
		strcpy(Q->NomAlbum, album);
		printf("\nNombre del artista: ");
		fflush(stdin);
		gets(artista);
		strcpy(Q->NomArtista, artista);
		printf("\nN%cmero de canciones del %clbum: ", 163, 160);
		scanf("%d",&Q->NumCanciones);
		printf("\nCosto del %clbum: $", 160);
		scanf("%f",&Q->Precio);
		printf("\nN%cmero de referencia del %clbum: ", 163, 160);
    	scanf("%d",&Q->Num);
    	
        Q->siguiente=*P;
        Q->anterior=NULL;
        (*P)->anterior=Q;
        
        *P=Q;
        
        printf("\nDesea agregar otro elemento:\nSi:1\tNo:0\n");
        scanf("%d", &opc);
    } while (opc == 1); 
}

/* Nombre: Funcion creafinal
   Fecha: 02/11/2021
   
   Descripcion:	Funcion que crea una lista y 
   				agrega los elementos por el final.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void creafinal (pNodo *P){
	pNodo Q, T;
	int opc;
    char artista[30], album[30];
	
	system("cls");
    printf("\n\t\t\tCREA FINAL\n");
    
    *P = (pNodo) malloc (sizeof(tipoNodo));

    printf("\n****Ingresa los datos del %clbum****\n",160);
	printf("Nombre del %clbum: ", 160);
	fflush(stdin);
	gets(album);
	strcpy((*P)->NomAlbum, album);
	printf("\nNombre del artista: ");
	fflush(stdin);
	gets(artista);
	strcpy((*P)->NomArtista, artista);	
	printf("\nN%cmero de canciones del %clbum: ", 163, 160);
    scanf("%d",&(*P)->NumCanciones);
	printf("\nCosto del %clbum: $", 160);
    scanf("%f",&(*P)->Precio);
	printf("\nN%cmero de referencia del %clbum: ", 163, 160);
    scanf("%d",&(*P)->Num);
    
    (*P)->siguiente=NULL;
    (*P)->anterior=NULL;
    T=*P;

	do {
    	Q = (pNodo) malloc (sizeof(tipoNodo));
    	
        printf("\n****Ingresa los datos del %clbum****\n",160);
		printf("Nombre del %clbum: ", 160);
		fflush(stdin);
		gets(album);
		strcpy(Q->NomAlbum, album);
		printf("\nNombre del artista: ");
		fflush(stdin);
		gets(artista);
		strcpy(Q->NomArtista, artista);	
		printf("\nN%cmero de canciones del %clbum: ", 163, 160);
		scanf("%d",&Q->NumCanciones);
		printf("\nCosto del %clbum: $", 160);
		scanf("%f",&Q->Precio);
		printf("\nN%cmero de referencia del %clbum: ", 163, 160);
    	scanf("%d",&Q->Num);
        
        Q->siguiente=NULL;
        Q->anterior=*P;
        T->siguiente=Q;
        
        T=Q;
        
        printf("\nDesea agregar otro elemento:\nSi:1\tNo:0\n");
        scanf("%d", &opc);
    } while (opc == 1); 
}

/* Nombre: Funcion recorreiterativo
   Fecha: 10/10/2019
   
   Descripcion:Funcion que imprime los elementos de una lista iterativamente.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void recorreiterativo (pNodo P){
	pNodo Q;
	
	if (P == NULL)
	{
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        Q=P;
        
        do {
            printf("\n\t\t*INFO. ALBUM*\n");
            printf("\nAlbum: %s\n", Q->NomAlbum);
            printf("\nArtista: %s\n", Q->NomArtista);
            printf("\nTotal de canciones: %d\n", Q->NumCanciones);
            printf("\nPrecio: $%.2f\n", Q->Precio);
            printf("\nNum de referencia: %d\n", Q->Num);

            Q=Q->siguiente;
        } while (Q != NULL);
    }

}

/* Nombre: Funcion recorreiterativoinv
   Fecha: 02/11/2021
   
   Descripcion:Funcion que imprime los elementos de una lista iterativamente de forma inversa.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void recorreiterativoinv (pNodo P){
	pNodo Q;

    if (P == NULL)
	{
		printf("\n\tNo existen elementos en la lista\n");
	} else {
	
        Q=P;
        while (Q->siguiente != NULL){
            Q=Q->siguiente;
        }

        
        do {
            printf("\n\t\t*INFO. ALBUM*\n");
            printf("\nAlbum: %s\n", Q->NomAlbum);
            printf("\nArtista: %s\n", Q->NomArtista);
            printf("\nTotal de canciones: %d\n", Q->NumCanciones);
            printf("\nPrecio: $%.2f\n", Q->Precio);
            printf("\nNum de referencia: %d\n", Q->Num);

            Q=Q->anterior;
        } while (Q != NULL);
	
    }
}


/* Nombre: Funcion recorrecursivo
   
   Descripcion:Funcion que imprime los elementos de una lista recursivamente.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void recorrecursivo (pNodo P, pNodo inicio){
	
    if (P == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
		printf("\n\t\t*INFO. ALBUM*\n");
		printf("\nAlbum: %s\n", P->NomAlbum);
		printf("\nArtista: %s\n", P->NomArtista);
		printf("\nTotal de canciones: %d\n", P->NumCanciones);
		printf("\nPrecio: $%.2f\n", P->Precio);
		printf("\nNum de referencia: %d\n", P->Num);

		if (P->siguiente != inicio){
            recorrecursivo(P->siguiente, inicio);
        }
        
	}
}

/* Nombre: Funcion insertafinal
   
   Descripcion:Funcion que agrega un elemento al final de la lista.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void insertafinal(pNodo P){
	
	pNodo Q, T;
    char artista[30], album[30];

    if (P == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        system("cls");
        printf("\n\t\t\tINSERTE AL FINAL\n");
	    
        T=P;
        while (T->siguiente != NULL){
            T=T->siguiente;
        }
        
        Q = (pNodo) malloc (sizeof(tipoNodo));
        
        printf("\n****Ingresa los datos del %clbum****\n",160);
		printf("Nombre del %clbum: ", 160);
		fflush(stdin);
		gets(album);
		strcpy(Q->NomAlbum, album);
		printf("\nNombre del artista: ");
		fflush(stdin);
		gets(artista);
		strcpy(Q->NomArtista, artista);	
		printf("\nN%cmero de canciones del %clbum: ", 163, 160);
		scanf("%d",&Q->NumCanciones);
		printf("\nCosto del %clbum: $", 160);
		scanf("%f",&Q->Precio);
		printf("\nN%cmero de referencia del %clbum: ", 163, 160);
		scanf("%d",&Q->Num);
        
        Q->siguiente=NULL;
        Q->anterior=T;
        T->siguiente=Q;

    }
}


/* Nombre: Funcion insertantes
   
   Descripcion:Funcion que agrega un elemento a la lista antes de un elemento tomado como referencia.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void insertantes (pNodo *P) {
	pNodo Q, X, T, Ultimo;
	int REF;
	int BAND=TRUE;
    char artista[30], album[30];
	
    if (REF <= 0){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        Ultimo=T=Q=*P;
        while (Ultimo->siguiente != *P){
           Ultimo=Ultimo->siguiente;
        }

        printf("\n\nIngresa la referencia: ");
        scanf("%d", &REF);
        //Q=*P;
        
        while (Q->Num != REF && BAND==TRUE){
            if (Q->siguiente != NULL){
                T=Q;
                Q=Q->siguiente;
            } else {
                BAND=FALSE;
            }
        }
        
        if (BAND == TRUE ){
            X = (pNodo) malloc (sizeof(tipoNodo));
            
            printf("\n****Ingresa los datos del %clbum****\n",160);
			printf("Nombre del %clbum: ", 160);
			fflush(stdin);
			gets(album);
			strcpy(X->NomAlbum, album);
			printf("\nNombre del artista: ");
			fflush(stdin);
			gets(artista);
			strcpy(X->NomArtista, artista);	
			printf("\nN%cmero de canciones del %clbum: ", 163, 160);
			scanf("%d",&X->NumCanciones);
			printf("\nCosto del %clbum: $", 160);
			scanf("%f",&X->Precio);
			printf("\nN%cmero de referencia del %clbum: ", 163, 160);
			scanf("%d",&X->Num);
            
            if (*P==Q){
                X->anterior=NULL;
                X->siguiente=*P;
                (*P)->anterior=X;
                *P=X;
            }else{
                T->siguiente=X;
                X->anterior=T;
                X->siguiente=Q;
                Q->anterior=X;

            }

        }
    }
}


/* Nombre: Funcion eliminaprimero
   
   Descripcion:Funcion que elimina el primero elemento de una lista.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/

void eliminaprimero (pNodo *P){
	pNodo Q;
	
	if ((*P) == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        Q=*P;
        
        if (Q->siguiente != NULL){
            *P=Q->siguiente;
            (*P)->anterior=NULL;
        }else {
            *P=NULL;
        }

        free(Q);
        }
}


/* Nombre: Funcion eliminaultimo
   
   Descripcion:Funcion que elimina el ultimo elemento de una lista.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void eliminaultimo (pNodo *P){
	pNodo Q,T;
	
	if ((*P) == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        if ((*P)->siguiente==NULL){
            free(P);
            *P=NULL;
        }else {
            Q=*P;
            while (Q->siguiente != NULL){
                T=Q;
                Q=Q->siguiente;
            }
            T->siguiente=NULL;
            free(Q);
        }
    }
}

/* Nombre: Funcion eliminaX
   
   Descripcion:Funcion que elimina un elemento dado de una lista.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
		X: valor a eliminar
*/
void eliminaX (pNodo *P, int X){
	pNodo Q, T;
	int BAND=TRUE;	

	if ((*P) == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
        Q=*P;
        
        while (Q->Num !=X && BAND==TRUE){
            if (Q->siguiente != NULL){
                T=Q;
                Q=Q->siguiente;
            } else {
                BAND=FALSE;
            }
        }
        
        if (BAND==FALSE){
            printf("El elemento no fue encontrado");
        }else {
            if (*P==Q){
                *P=Q->siguiente;
                (*P)->anterior= NULL;
            } else {
                T->siguiente=Q->siguiente;
                (Q->siguiente)->anterior=T;
            }
            free(Q);
        }	
    }
}


/* Nombre: Funcion buscarrecursivo
   
   Descripcion:Funcion que busca un elemento en una lista de forma recursiva.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
		X: valor a buscar
        inicio: indica el inicio de la lista
*/
void buscarrecursivo(pNodo P, pNodo inicio, int X){
	if (P == NULL){
		printf("\n\tNo existen elementos en la lista\n");
	} else {
		if (P->Num == X){
			printf("El elemento fue encontrado\n");
		}else{
            if (P->siguiente != NULL){
                buscarrecursivo(P->siguiente, inicio, X);
            }else{
		        printf("El elemento no se encuentra en la lista\n");
	        }
        }
            
    }
}


//Funcion principal main
main(){
	pNodo P = NULL;
	int X;
	char opcion;
	
	    do{
    	system ("cls");
		printf ("\n\t\t\tLISTA DOBLE\n");
    	printf ("\n 1) CREA INICIO");
    	printf ("\n 2) CREA FINAL");
    	printf ("\n 3) RECORRE ITERATIVO");
    	printf ("\n 4) RECORRE RECURSIVO");
    	printf ("\n 5) INSERTA AL FINAL");
    	printf ("\n 6) INSERTA ANTES");
    	printf ("\n 7) ELIMINA PRIMERO");
    	printf ("\n 8) ELIMINA ULTIMO");
    	printf ("\n 9) ELIMINA ELEMENTO");
    	printf ("\n a) BUSCA ELEMENTO (RECURSIVO)");
    	printf ("\n b) RECORRE ITERATIVO INVERSO");
    	printf ("\n 0) SALIR");

    	printf ("\n\n Seleccione una opcion: ");
		scanf ("%c", &opcion);
		
		switch (opcion){
			case '1':
				creainicio(&P);
				break;
			case '2':
			    creafinal(&P);
				break;
			case '3':
				recorreiterativo(P);
				printf("\n");
	           	break;
			case '4':
				recorrecursivo(P, P);
				printf("\n");
	           	break;

			case '5':
				insertafinal(P);
				break;
			case '6':
				insertantes(&P);
				break;
			case '7':
				eliminaprimero(&P);
				break;
			case '8':
				eliminaultimo(&P);
				break;
			case '9':
				printf("\n\nIngresa el elemento a eliminar: ");
				scanf("%d", &X);
				eliminaX(&P, X);
				break;
			case 'a':
			case 'A':
				printf("\n\nIngresa el elemento a buscar: ");
				scanf("%d", &X);
				buscarrecursivo(P, P, X);
				break;
			case 'b':
			case 'B':
				recorreiterativoinv(P);
				printf("\n");
				break;
			case '0':
				break;
			default:
				printf ("\n Opcion no valida. Intenta de nuevo.\n\n");
				break;
		}
		system("pause");
	} while (opcion!='0');
	
	return 0;
	
}