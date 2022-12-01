#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int contador(char *conc2,char caracter){
    
    int tamanho = strlen(conc2);
    int cont = 0;
    for (int e = 0; e < tamanho;e++){
        if(conc2[e] == caracter){
            cont++;
        }
        
    }
    return cont;
    
    
}
int main() {
   
    int n;
    char *palavras;
    char verificador[10];
    char *conc;
   
    scanf("%d",&n);

    int k;
    palavras = malloc(100 + sizeof(char));
    conc = malloc(100 + sizeof(char));
    for(k = 0;k <= n; k++){
       
        gets(palavras);
        strcat(conc,palavras);
        
       
    }
    scanf("%s",verificador);
    
        
     for(int j = 0;j<strlen(verificador);j++){
        
        int resultado = contador(conc,verificador[j]);
        printf("%c = %d\n",verificador[j],resultado);
        
        
     }
     
     
    
    return 0;
}
