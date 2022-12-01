#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int vetor[20];

    for (int i = 0; i < 20; i++)
    {
        vetor[i] = 999;
    }
    
    for (int i =0;i<20;i++){
        
        scanf("%d\n",&vetor[i]);
        
    }
    int i = 0;
    while(vetor[i] != 999){

        int j = i;
        if (j >0){
            
            printf("\nChave: %d\n",vetor[j]);
            printf("Estado Atual: ");
            int k = 0;
            while(vetor[k] != 999){
                if(vetor[k+1] == 999){
                    printf("%d",vetor[k]);
                }else{
                    printf("%d | ",vetor[k]);

                }
                k++;
            }
        }
            putchar('\n');
        
        while (vetor[j] < vetor[j-1] && j > 0)
        {   
    
            int aux = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor[j] = aux;
            --j;
            
            int l = 0;
            while(vetor[l] != 999){
                
                if(vetor[l+1] == 999){
                    printf("%d",vetor[l]);
                }else{
                    printf("%d | ",vetor[l]);

                }
                l++;    
            }
            putchar('\n');
       
        }
    i++;
    }
    printf("\nResultado Final: ");

    int v = 0;
    while(vetor[v] != 999){
        
      if(vetor[v+1] == 999){
                    printf("%d",vetor[v]);
                }else{
                    printf("%d | ",vetor[v]);

                }
        v++;
        
    }    
    return 0;
}