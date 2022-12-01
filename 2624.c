#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n,i,j,k,l,m,o;
    int soma1 = 0 ,soma2 = 0,soma3 = 0;
    char sinal[3];
    
    scanf(" %d",&n);
    
    float matriz[n][n];
    float matriz2[n][n];
    float matriz3[n][n];
    
    for (i = 0;i<n;i++){
        for (j = 0;j<n;j++){
            
            scanf(" %f",&matriz[i][j]);
        }
    
     putchar('\n'); 
     
    }
    for (k = 0;k<n;k++){
        for (l = 0;l<n;l++){
            
            scanf(" %f",&matriz2[k][l]);
        }
        putchar('\n');
    }
    scanf("%s",sinal);
    
    if (sinal[0] == '+'){
        for(m = 0;m<n;m++){
            for(o = 0;o<n;o++){
                
                if(m%2 == 0){
                    
                    matriz3[m][o] = matriz[m][o] + matriz2[m][o];
                }
                else{
                    
                    matriz3[m][o] = matriz[m][o] - matriz2[m][o];
                }
                if(o<n-1){
                    printf("%.2f ",(float)matriz3[m][o]);
                }
                else{
                    printf("%.2f",(float)matriz3[m][o]);
                }
                    
                
            }
        
            putchar('\n');
        }
    }
    else{
    
        for(m = 0;m<n;m++){
            for(o = 0;o<n;o++){
                
                if(m%2 == 0){
                    
                    matriz3[m][o] = matriz[m][o] - matriz2[m][o];
                }
                else{
                    
                    matriz3[m][o] = matriz[m][o] + matriz2[m][o];
                }
                if(o<n-1){
                    printf("%.2f ",(float)matriz3[m][o]);
                }
                else{
                    printf("%.2f",(float)matriz3[m][o]);
                }
            }
        putchar('\n');
        }
    }
	return 0;
}