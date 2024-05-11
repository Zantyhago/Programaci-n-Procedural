#include <stdio.h>
#define M 4
#define N 5

void carga (int arre[M][N]){
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++){
            printf("Ingrese numero (fila , columna): \n");
            scanf("%d",&arre[i][j]);
        }
}

int suma4col(int arre[M][N]){
    int i,acum=0;
    for(i=0;i<N;i++){
        acum+=arre[i][3];
    }
    return(acum);
}

int cantPar(int arre[M][N]){
    int i, cant=0,numF;
    printf("Ingrese numero de fila: \n");
    scanf("%d",&numF);
    for(i=0;i<N;i++){
        if(arre[numF-1][i]%2==0){
            cant++;
        }
    }
    return(cant);
}

void muestra10(int arre[M][N]){
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++){
            if(arre[i][j]<10)
                printf("La componente de la fila %d columna %d es menor a 10. \n",i,j);
        }

}

void cant65(int arre[M][N], int *cant6, int *cant5){
    int i,j;
    *cant5=0;
    *cant6=0;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++){
            if(arre[i][j]==6){
                *cant6=*cant6+1;
            }
            if(arre[i][j]==5){
                *cant5=*cant5+1;
            }
        }
    return;
}

int main(){
    int arre[M][N],cant6, cant5;
    carga(arre);
    printf("La suma de las componentes de la cuarta columna es %d: \n",suma4col(arre));
    printf("La cantidad de numeros pares de columna es : %d \n",cantPar(arre));
    muestra10(arre);
    cant65(arre,&cant6,&cant5);
    printf("La cantidad de componentes igual a 6 son: %d \n",cant6);
    printf("La cantidad de componentes igual a 5 son: %d \n",cant5);
}
