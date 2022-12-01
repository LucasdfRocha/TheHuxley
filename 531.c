#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int vetor[150];
    int cont = 0;

   while(scanf("%d",&vetor[cont])!= EOF){
       cont++;
   }
    
    int menor,selecionado;
    for(int i= 0; i< cont-1; i++){
        selecionado = vetor[i];
        menor = i;
        
        for(int j=i+1; j<cont; j++){
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }
        printf("Menor elemento neste passo: %d\n",vetor[menor]);
        
        if(selecionado > vetor[menor]){
            vetor[i] = vetor[menor];
            vetor[menor] = selecionado;
        }
        
        printf("Estado Atual: ");
        
        for(int h = 0; h < cont; h++){
            if(h < (cont -1)){
                printf("%d | ",vetor[h]);
            }
            else{
                printf("%d",vetor[h]);
            }
        }
        putchar('\n');
        putchar('\n');
        
    }
    
    printf("Resultado Final: ");
    for(int b = 0; b<cont;b){
    
        if(b < (cont - 1)){
        printf("%d | ",vetor[b]);
        }
        else{
            printf("%d",vetor[b]);
        }
        b++;
    }
    
	return 0;
}