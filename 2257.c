#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char calculo(char valor[],int x){
    
    for(int i = 0; i<strlen(valor);i++){
        
        if (valor[i] - 48 ==  x + 1 || valor[i] - 48 ==  x - 1){
            
            return 'a';
            
        }
    }
    
}
int main() {
    
	int x;
	char valor[50];
	
	scanf("%s %d",&valor,&x);
	
	if (calculo(valor,x) == 'a'){
	    printf("sim");
	}
	else{
	    printf("nao");
	}
	
	
}