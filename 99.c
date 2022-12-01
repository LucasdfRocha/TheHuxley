#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct{
    int id;
    float temperatura;
    char fumaca;
} Key;
    
int main() {
    int casos, qtd;
    float soma = 0, media = 0;
    
    scanf("%d",&casos);
 
    for(int j = 0; j < casos; j++){
        scanf("%d", &qtd);
        Key vetor[qtd];
        for (int i = 0; i < qtd; i++){
            scanf("%d %f %c", &vetor[i].id, &vetor[i].temperatura, &vetor[i].fumaca);
            soma = soma + vetor[i].temperatura;
        }
 
        media = soma / qtd;
 
        printf("TESTE %d\n", j + 1);
        for(int i = 0; i < qtd; i++){
            if(vetor[i].temperatura > (1.15*media) || vetor[i].fumaca == 'S'){
                printf("%d\n", vetor[i].id);
            }
        }
 
        soma = 0;
    }
 
    return 0;
}