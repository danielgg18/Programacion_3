/*************************************************************************************************************************
                  UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
                  FACULTAD DE CONTADURIA Y ADMINISTRACION

                       LICENCIATURA EN INFORMATICA
                           ESTRUCTURA DE DATOS
  Name: ListaCircular.c 
  Description: Programa que permite el gestiomiento una lista.
  				Basado en la implementación del semestre 2020-1                 

***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0



typedef struct nodo {
   int informacion;   //Variable de tipo entero
   struct nodo *liga; //Apuntador que apunta a una estructura nodo
} tipoNodo; 
 
typedef tipoNodo *pNodo; //Apuntador de nombre pNodo que apunta a un tipoNodo

void creainicio(pNodo *P){
	pNodo Q, Ultimo;
	int opc;
	
	system("cls");
    printf("\n\t\t\tCREA INICIO\n");
    
    *P = (pNodo) malloc (sizeof(tipoNodo));
    printf("\n\nIngresa elemento: ");
    scanf("%d",&(*P)->informacion);
    (*P)->liga=*P;
    Ultimo= *P;
    
    do {
    	Q = (pNodo) malloc (sizeof(tipoNodo));
    	printf("\nIngresa elemento: ");
    	scanf("%d",&Q->informacion);
        Q->liga= *P;
        
        *P=Q;
        Ultimo->liga = *P;
        
        printf("\nDesea agregar otro elemento 0/1\n");
        scanf("%d", &opc);
    } while (opc == 1); 
}

void creafinal (pNodo *P){
	pNodo Q, T;
	int opc;
	
	system("cls");
    printf("\n\t\t\tCREA FINAL\n");
    
    *P = (pNodo) malloc (sizeof(tipoNodo));
    printf("\n\nIngresa elemento: ");
    scanf("%d",&(*P)->informacion);
    (*P)->liga=*P;
    T=*P;
    
    do {
    	Q = (pNodo) malloc (sizeof(tipoNodo));
    	printf("\nIngresa elemento: ");
    	scanf("%d",&Q->informacion);
        Q->liga= *P;
        
        T->liga=Q;
        T=Q;
        
        printf("\nDesea agregar otro elemento  0/1\n");
        scanf("%d", &opc);
    } while (opc == 1); 
}

void recorreiterativo (pNodo P){
	pNodo Q;
	
	Q=P;
	
	do {
		printf("%d ", Q->informacion);
		Q=Q->liga;
	} while (Q != P);
	
}

void recorrecursivo (pNodo P, pNodo Inicio){

	printf("%d ", P->informacion);
		
	if (P->liga!=Inicio){
		recorrecursivo(P->liga,Inicio);
	}
}

void insertafinal(pNodo P){
	
	system("cls");
    printf("\n\t\t\tINSERTE AL FINAL\n");
    
	pNodo Q, T;
	T=P;
	while (T->liga != P){
		T=T->liga;
	}
    
    Q = (pNodo) malloc (sizeof(tipoNodo));
    printf("\n\nIngresa elemento: ");
    scanf("%d",&Q->informacion);
    Q->liga=P;
    T->liga=Q;
}

void insertantes (pNodo *P) {
	pNodo Q, X, T, Ultimo;
	int REF;
	int BAND=TRUE;
	
	Ultimo=T=Q=*P;

	while (Ultimo->liga != *P){
		Ultimo=Ultimo->liga;
	}
	
	printf("\n\nIngresa la referencia: ");
    scanf("%d", &REF);
	
	while (Q->informacion != REF&&BAND==TRUE){
		if (Q->liga != *P){
			T=Q;
			Q=Q->liga;
		} else {
			BAND=FALSE;
		}
	}
	
	if (BAND== TRUE ){
	    X = (pNodo) malloc (sizeof(tipoNodo));
	    printf("\n\nIngresa elemento: ");
        scanf("%d",&(X)->informacion);
        if (*P==Q){
        	X->liga=*P;
        	*P=X;
        	Ultimo ->liga = *P;
        }else{
        	T->liga=X;
        	X->liga=Q;
        }

	}
}

void eliminaprimero (pNodo *P){
	pNodo Q, Ultimo;
	
	Ultimo=Q=*P;
	
	while (Ultimo->liga != *P){
		Ultimo=Ultimo->liga;
	}


	if (Q->liga != *P){
		*P=Q->liga;
		Ultimo->liga= *P;
	}else {
		*P=NULL;
	}
	free(Q);
}

void eliminaultimo (pNodo *P){
	pNodo Q,T;
	
	if ((*P)->liga==*P){
		free(P);
		*P=NULL;
	}else {
		Q=*P;
		while (Q->liga != *P){
			T=Q;
			Q=Q->liga;
		}
		T->liga=*P;
		free(Q);
	}
}

void eliminaX (pNodo *P, int X){
	pNodo Q, T;
	int BAND=TRUE;	

	Q=*P;
	
	if ( (*P)->informacion == X)
		eliminaprimero(&(*P));
	else {
	
		while (Q->informacion !=X && BAND==TRUE){
			if (Q->liga != *P){
				T=Q;
				Q=Q->liga;
			} else {
				BAND=FALSE;
			}
		}
		
		if (BAND==FALSE){
			printf("El elemento no fue encontrado");
		}else {
			if (*P==Q){
    			*P=Q->liga;
			} else {
				T->liga=Q->liga;
			}
			free(Q);
		
		}	
	}
}

void buscarrecursivo(pNodo P, pNodo Inicio, int X){
	
	if (P->informacion == X){
			printf("El elemento fue encontrado\n");
		}else{
			if(P->liga != Inicio){
				buscarrecursivo(P->liga, Inicio, X);
			} else {
				printf("El elemento no se encuentra en la lista\n");
			}
		}
}

main(){
	pNodo P = NULL;
	int opcion, X;
	
	    do{
    	system ("cls");
		printf ("\n\t\t\tLISTA\n");
    	printf ("\n 1) CREA INICIO");
    	printf ("\n 2) CREA FINAL");
    	printf ("\n 3) RECORRE ITERATIVO");
    	printf ("\n 4) RECORRE RECURSIVO");
    	printf ("\n 5) INSERTA AL FINAL");
    	printf ("\n 6) INSERTA ANTES");
    	printf ("\n 7) ELIMINA PRIMERO");
    	printf ("\n 8) ELIMINA ULTIMO");
    	printf ("\n 9) ELIMINA ELEMENTO");
    	printf ("\n 10) BUSCA ELEMENTO (RECURSIVO)");
    	printf ("\n 0) SALIR");

    	printf ("\n\n Seleccione una opcion: ");
		scanf ("%d", &opcion);
		
		switch (opcion){
			case 1:
				creainicio(&P);
				break;
			case 2:
			    creafinal(&P);
				break;
			case 3:
				recorreiterativo(P);
				printf("\n");
	           	break;
			case 4:
				recorrecursivo(P,P);
				printf("\n");
				break;
			case 5:
				insertafinal(P);
				break;
			case 6:
				insertantes(&P);
				break;
			case 7:
				eliminaprimero(&P);
				break;
			case 8:
				eliminaultimo(&P);
				break;
			case 9:
				printf("\n\nIngresa el elemento a eliminar: ");
				scanf("%d", &X);
				eliminaX(&P, X);
				break;
			case 10:
				printf("\n\nIngresa el elemento a buscar: ");
				scanf("%d", &X);
				buscarrecursivo(P, P, X);
				break;
			case 0:
				break;
			default:
				printf ("\n Opcion no valida. Intenta de nuevo.\n\n");
				break;
		}
		system("pause");
	} while (opcion);
	
	return 0;
	
}