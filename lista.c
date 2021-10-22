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
		printf("1. Agregar\n2. Eliminar\n3. Ver Extremos\n4. Ver Cola\n5. Salir\n");
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