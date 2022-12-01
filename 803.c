#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char frase[25];
    int conta = 0,conte = 0,conti = 0,conto = 0,contu = 0;
    
    
    gets(frase);
    
    
    for(int i = 0; i < frase[i];i++){
        
        if(frase[i] == 'a' || frase[i] == 'A'){
            conta = conta + 1;
            
        }
        else if(frase[i] == 'e' || frase[i] == 'E'){
            conte = conte + 1;
            
        }
        else if(frase[i] == 'i' || frase[i] == 'I'){
            conti = conti + 1;
            
        }
        else if(frase[i] == 'o' || frase[i] == 'O'){
            conto = conto + 1;
            
        }
        else if(frase[i] == 'u' || frase[i] == 'U'){
            contu = contu + 1;
            
        }
        
        
    }
    
    printf("a %d\n",conta);
    printf("e %d\n",conte);
    printf("i %d\n",conti);
    printf("o %d\n",conto);
    printf("u %d",contu);
	return 0;
}