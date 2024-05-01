#include <stdio.h>
#include <malloc.h>

struct nodo{
    int number;
    struct nodo *sig;
};

typedef struct nodo *rodolfo;

void insercion(rodolfo &cab){
    int num;
    rodolfo anterior, p, nuevo;
    printf("\nIngrese un numero: ");
    scanf("%d",&num);
    if(num != 0){
        nuevo=(rodolfo)malloc(sizeof(struct nodo));
        nuevo->number=num;
        nuevo->sig=NULL;
        if(cab==NULL)
            cab=nuevo;
        else{
            p=cab;
            while(p!=NULL){
                anterior=p;
                p=p->sig;
            }
            anterior->sig=nuevo;
        }
        insercion(cab);
    }
    return;
}

void muestra(rodolfo cab){
    printf("\n*Listado de datos:");
    while(cab!=NULL){
        printf("\n%d",cab->number);
        cab=cab->sig;
    }
    printf("\n");
return;
}

void busca(rodolfo cab){
    int elem;
    printf("\nIngrese el dato a buscar: ");
    scanf("%d",&elem);
    while((cab!=NULL)&&(cab->number!=elem))
        cab=cab->sig;
    if(cab==NULL)
        printf("\n*No se encontra el dato.\n");
    else
        printf("\n*El dato fue encontrado.\n");
}

void modifica(rodolfo cab){
    int viejo, nuevo;
    printf("\nIngrese el valor a modificar: ");
    scanf("%d",&viejo);
    printf("\nIngrese el valor nuevo: ");
    scanf("%d",&nuevo);
    while((cab!=NULL)&&(cab->number!=viejo))
        cab=cab->sig;
    if(cab!=NULL){
        cab->number=nuevo;
        printf("\n*El valor fue modificado.\n");
    }
    else
        printf("\n*No se encontra el dato.\n");
}

void elimina(rodolfo &cab){
    rodolfo anterior, p;
    int dato;
    printf("\nIngrese el numero a suprimir: ");
    scanf("%d",&dato);
    if(cab->number==dato){
        p=cab;
        cab=cab->sig;
        free(p);
    }
    else{
        p=cab;
        anterior=cab;
        while((p!=NULL)&&(p->number!=dato)){
            anterior=p;
            p=p->sig;
        }
        if(p!=NULL){
            anterior->sig=p->sig;
            free(p);
            printf("\n*El nodo fue eliminado de la lista.\n");
        }
        else
            printf("\n*El nodo no fue encontrado.\n");
        return;
    }
}

void ordena(rodolfo cab){
    rodolfo k, cota, p;
    int aux;
    cota=NULL;
    k=NULL;
    while(k!=cab){
        k=cab;
        p=cab;
        while(p->sig!=cota){
            if(p->number>p->sig->number){
                aux=p->sig->number;
                p->sig->number=p->number;
                p->number=aux;
                k=p;
            }
            p=p->sig;
        }
        cota=k->sig;
    }
    printf("\n*La lista fue ordensada.\n");
}

void deletea(rodolfo &cab){
    rodolfo p;
    while(cab!=NULL){
        p=cab;
        cab=cab->sig;
        free(p);
    }
    printf("\n*La lista fue deleteada.\n");
    return;
}

main(){
    int opcion;
    rodolfo cabeza=NULL;
    insercion(cabeza);
    do{
        printf("\n Seleccione una opcion:\n 1) Mostrar lista.\n 2) Buscar un elemento.\n 3) Modificar un nodo.\n 4) Eliminar un nodo.\n 5) Ordenar la lista.\n 6) Eliminar la lista.\n - 0 para terminar -\nRespuesta: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                muestra(cabeza);
                break;
            case 2:
                busca(cabeza);
                break;
            case 3:
                modifica(cabeza);
                break;
            case 4:
                elimina(cabeza);
                break;
            case 5:
                ordena(cabeza);
                break;
            case 6:
                deletea(cabeza);
                break;
        }
    }while(opcion!=0);
    printf("\nchauchis :3\n");
}
