/*************************************************************************************************************************
                  UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
                  FACULTAD DE CONTADURIA Y ADMINISTRACION

                       LICENCIATURA EN INFORMATICA
                           ESTRUCTURA DE DATOS
  Nombre: proyectoFinal.c
  Autor: Daniel Garcia
  Fecha: 24/11/21
  Descripcion: Programa que registra en un archivo las transacciones que se realizan diariamente en un tienda de discos musicales.      

***************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


//Estructura que contiene la informacion de cada disco (vendido, devuelto, cambiado)
typedef struct nodo {
    int NumCanciones;   //Numero de canciones del disco
    char NomArtista[30];
    char NomAlbum[30];
    char TipoTran[12];
    float Precio;
    int Num;
	//struct nodo *anterior; //Apuntador que apunta a una estructura nodo
	struct nodo *siguiente; //Apuntador que apunta a una estructura nodo   struct nodo *liga; //Apuntador que apunta a una estructura nodo
} tipoNodo; 
 
typedef tipoNodo *pNodo; //Apuntador de nombre pNodo que apunta a un tipoNodo

/* Nombre: Funcion escribir_registros

   Descripcion:	Funcion que crea una lista y 
   				agrega los elementos por el final.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void escribir_registros(pNodo P)
{
 	tipoNodo nodo;
 	char opcion;  
 	pNodo Q;
	FILE *arch;

	arch=fopen("registros.dat","w+b");
	if(arch != NULL) {
		Q=P;
	 	rewind (arch);
		//fseek(arch, 0L, SEEK_SET);
		do {
			fprintf(arch,"Nombre del album:");
			strcpy(Q->NomAlbum, nodo.NomAlbum);
			strcpy(Q->NomArtista, nodo.NomArtista);
			nodo.NumCanciones = Q->NumCanciones;
			nodo.Precio = Q->Precio;
			nodo.Num = Q->Num;
			strcpy(Q->TipoTran, nodo.TipoTran);
			nodo.siguiente= NULL;
			fwrite(&nodo,sizeof(tipoNodo),1,arch);  //escritura del registro
	
			Q=Q->siguiente;
		} while (Q != NULL);
		fflush(stdin);
		fclose(arch);
	} else {
		fprintf(stderr, "No se pudo abrir el archivo.");
	}
}

/* Nombre: Funcion leer_registros

   Descripcion:	Funcion que crea una lista y 
   				agrega los elementos por el final.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void leer_registros (pNodo *P) {
  	tipoNodo nodo;
  	pNodo Q, T;
  	int tamanio=sizeof(tipoNodo);
	FILE *arch;

	arch=fopen("registros.dat","r+b");
	if(arch != NULL) {

		 rewind (arch);
 
	    if (fread (&nodo, tamanio, 1, arch) != 0 ){
	    	    *P = (pNodo) malloc (sizeof(tipoNodo));
	    	    (*P)->NumCanciones=nodo.NumCanciones;
	    		(*P)->siguiente=NULL;
	    		T=*P;
	    		printf("Primer elemento: %i\n", nodo.NumCanciones);
		}
	   	while (fread (&nodo, tamanio, 1, arch) != 0 ){
	   	   	Q = (pNodo) malloc (sizeof(tipoNodo));
	 		Q->NumCanciones=nodo.NumCanciones;
	        Q->siguiente= NULL;
	        
	        T->siguiente=Q;
	        T=Q;
	        
			printf("%i\n", nodo.NumCanciones);
	   	}
		fclose(arch);	
	} else {
		fprintf(stderr, "No hay archivo de lectura");
	}
}

/* Nombre: Funcion creafinal

   Descripcion:	Funcion que crea una lista y 
   				agrega los elementos por el final.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void creafinal (pNodo *P){
	pNodo Q, T;
	int opc; 
    char artista[30], album[30], transaccion[12];
	
	system("cls");
    printf("\n\t\t\tCREA FINAL\n");
    
    *P = (pNodo) malloc (sizeof(tipoNodo));

    printf("\n****Ingresa los datos del disco****\n");
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
	printf("\nConcepto: ");
	fflush(stdin);
	gets(transaccion);
	strcpy((*P)->TipoTran, transaccion);

    
    (*P)->siguiente=NULL;
    //(*P)->anterior=NULL;
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
		printf("\nConcepto: ");
		fflush(stdin);
		gets(transaccion);
		strcpy(Q->TipoTran, transaccion);
        
        Q->siguiente=NULL;
        //Q->anterior=*P;
        T->siguiente=Q;
        
        T=Q;
        
        printf("\nDesea agregar otro elemento:\nSi:1\tNo:0: ");
        scanf("%d", &opc);
    } while (opc == 1); 
}

/* Nombre: Funcion recorreiterativo
   
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
            printf("\n\t\t***INFO. ALBUM***\n");
            printf("\nAlbum: %s\n", Q->NomAlbum);
            printf("\nArtista: %s\n", Q->NomArtista);
            printf("\nTotal de canciones: %d\n", Q->NumCanciones);
            printf("\nPrecio: $%.2f\n", Q->Precio);
            printf("\nNum de referencia: %d\n", Q->Num);
			printf("\nTipo de transacci%cn: %s\n", 162, Q->TipoTran);

            Q=Q->siguiente;
        } while (Q != NULL);
    }

}

/* Nombre: Funcion insertafinal
   
   Descripcion:Funcion que agrega un elemento al final de la lista.

   Parametros: 
		P: Apuntador al primer elemento de la lista (apuntador a una estructura tipoNodo). 
*/
void insertafinal(pNodo P){
	
	pNodo Q, T;
    char artista[30], album[30], transaccion[12];

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
		printf("\nConcepto: ");
		fflush(stdin);
		gets(transaccion);
		strcpy(Q->TipoTran, transaccion);
        
        Q->siguiente=NULL;
        //Q->anterior=T;
        T->siguiente=Q;

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
	int opcion;
	
	    do{
        //funciones tentativas
    	system ("cls");
		printf ("\n\t\t\tRegistro diario de transacciones en una tienda de discos musicales\n(Venta, Cambio o Devoluci%cn)\n", 162);
    	//printf ("\n 1) CREA INICIO");
    	printf ("\n 1) Crear lista con los datos de cada transacci%cn", 162); //Se crea la lista desde el final
    	printf ("\n 2) Ver lista de transacciones"); //Recorre y muestra los elementos de la lista de manera iterativa
    	//printf ("\n 4) RECORRE RECURSIVO");
    	printf ("\n 3) Agregar datos de nueva transacci%cn", 162); // Se crea un nuevo nodo con los datos de la venta y se coloca al final
    	//printf ("\n 6) INSERTA ANTES");
    	//printf ("\n 7) ELIMINA PRIMERO");
    	printf ("\n 4) Cancelar la %cltima transacci%cn", 163, 162); //se elimina el ultimo nodo de la lista
    	//printf ("\n 9) Eliminar venta");
    	printf ("\n 5) Buscar una transacci%cn", 162); // se realiza una busqueda recursiva utilizando el numero de refrencia del disco y se imprime el registro
    	printf ("\n 6) Guardar la lista en un archivo");
		printf ("\n 7) Cargar el archivo donde se encuentra la lista");
    	printf ("\n 0) SALIR");

    	printf ("\n\n Seleccione una opcion: ");
		scanf ("%d", &opcion);
		
		switch (opcion){
			case 1:
			    creafinal(&P);
				break;
			case 2:
				recorreiterativo(P);
				printf("\n");
	           	break;
			case 3:
				insertafinal(P);
				break;
			case 4:
				eliminaultimo(&P);
				break;
			case 5:
				printf("\n\nIngresa el elemento a buscar: ");
				scanf("%d", &X);
				buscarrecursivo(P, P, X);
				break;
			case 6:
				printf("\n\nGuardar datos de la lista. ");
				escribir_registros(P);
				break;
			case 7:
				printf("\n\nCargar datos de la lista. ");
				//printf("\n\nLos elementos de la lista se reemplazarán. ");
				leer_registros(&P);
				break;
			case 0:
				break;
			default:
				printf ("\n Opcion no valida. Intenta de nuevo.\n\n");
				break;
		}
		system("pause");
		system ("cls");
	} while (opcion);
	
	return 0;
	
}