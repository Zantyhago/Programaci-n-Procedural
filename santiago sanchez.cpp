#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct nodo{
    char nombre[25];
    int legajo;
    int anyo;
    struct nodo *sig;
};

typedef struct nodo *puntero;

void headmaker(puntero &xcab){
    xcab=NULL;
}

void insertar(puntero &xcab){
    int xleg;
    puntero nuevo;
    printf("Ingrese legajo (0 para finalizar): \n");
    scanf("%d",&xleg);
    while (xleg != 0){
        nuevo =(puntero) malloc(sizeof(struct nodo));
        nuevo->legajo=xleg;
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(nuevo->nombre);
        printf("Ingrese anyo que cursa: \n");
        scanf("%d",&nuevo->anyo);
        nuevo->sig = xcab;
        xcab = nuevo;
        printf("Ingrese legajo (0 para terminar): \n");
        scanf("%d",&xleg);
    }
}

void primerisos(puntero xcab){
    if(xcab != NULL){
        if(xcab->anyo==1){
           puts(xcab->nombre);
           printf("Legajo: %d\n",xcab->legajo);
           primerisos(xcab->sig);
        }
        else{
            primerisos(xcab->sig);
        }
    }
}

void busca (puntero xcab, int xleg){
    while((xcab != NULL )&& (xcab->legajo != xleg))
        xcab = xcab->sig;
    if (xcab == NULL)
        printf("No se encontro el legajo.\n");
    else
        printf("Cursa el anyo %d.\n",xcab->anyo);
}

void eliminador(puntero &xcab, int xanyo){
    puntero anterior, p, aux;
    aux=xcab;
    while(aux != NULL){
        if(xcab->anyo==xanyo){
            p=xcab;
            xcab=xcab->sig;
            free (p);
        }
        else{
            p=xcab;
            anterior=xcab;
            while ((p != NULL) && (p->anyo != xanyo)){
                anterior = p;
                p=p->sig;
            }
            if (p != NULL){
                anterior->sig = p->sig;
                free(p);
                printf("Los datos de un alumno fueron eliminados.\n");
            }
            else
                printf("No se encuentro el alumno.\n");
        }
    aux=aux->sig;
    }
}

void muestraActu(puntero xcab){
	printf("Lista actualizada: \n");
	while(xcab != NULL){
		printf("Nombre: \n");
		puts(xcab->nombre);
		printf(" Legajo: %d",xcab->legajo);
		printf(" Anyo: %d",xcab->anyo);
		xcab=xcab->sig;
	}
}

main(){
    puntero alumnos;
	int xleg,xanyo;
	headmaker(alumnos);
	insertar(alumnos);
    printf("Datos de los alumnos que cursan primero: \n");
	primerisos(alumnos);
	printf("Ingrese legajo del alumno para saber que año cursa: ");
	scanf("%d",&xleg);
	busca(alumnos,xleg);
    printf("Ingrese anyo que desea eliminar: ");
    scanf("%d",&xanyo);
	eliminador(alumnos,xanyo);
	muestraActu(alumnos);
}
