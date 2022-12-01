#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    int tamanho[100],i, j , k, l,final, ordemMatriz;
    int tam = 0, pararLoop = 0;

    while (pararLoop == 0){
        scanf(" %d", &tamanho[tam]);

        if (tamanho[tam]<=0){
            pararLoop++;
        } else
        tam++;
    }

    for (k=0;k<tam;k++){ 

        ordemMatriz = tamanho[k];

        int **matriz = (int** )calloc(ordemMatriz+10,sizeof(int));
        for(i=0; i<ordemMatriz; i++){
            matriz[i] = (int*)calloc(ordemMatriz+10,sizeof(int));
        }

        for(i=0;i<ordemMatriz;i++){ 
            for(j=0;j<ordemMatriz;j++){
                matriz[i][j]=1;
                }
        }
        final = round(ordemMatriz/2.0); 

        for(l=1;l<=final;l++){ 

            for (i=l; i<(ordemMatriz-l);i++){ 
                for (j=l; j<(ordemMatriz-l);j++){
                    matriz[i][j]++;
                }
            }
        }

        if(ordemMatriz == 1){
            printf("1\n");
        }else{
            for(i=0;i<ordemMatriz;i++){
                for(j=0;j<ordemMatriz;j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
        }
        free(matriz);
        printf("\n");
    }
    printf("Fim");
}