#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    //definida pela questao ja, representando os dias no ano
    int matriz[20][12];
    int mesInicial,anoInicial,mesFinal,anoFinal;
    int acumulador = 0;
    
    
    for (int i = 0; i< 20;i++){
        for (int j = 0; j< 12;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
    scanf("%d %d",&mesInicial,&anoInicial);
	scanf("%d %d",&mesFinal,&anoFinal);
	
    mesInicial--;
    mesFinal--;
	
	for (int i = 2000; i<= anoInicial;i++){
        for (int j = 0; j< 12;j++){
        
        if(j == mesInicial  && i == anoInicial) 
            break;
        acumulador -= matriz[i-2000][j];
            
        }
    }
    for (int i = 2000; i<= anoFinal;i++){
        for (int j = 0; j< 12;j++){
        
        if(j == mesFinal + 1 && i == anoFinal) 
            break;
        acumulador += matriz[i-2000][j];
            
        }
    }
    
	printf("%d",acumulador);
	return 0;
}
