
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    int n,k,caracter;
    
    char c;
    
    scanf("%d %d",&n,&k);
    scanf(" %c",&c);
    
    int tamanho = 2*n - 1;
    int ordem  = tamanho + 1;
    char mat[tamanho][tamanho];
    
    
    if (k == 1){
        for (int i = 1; i < tamanho + 1;i++){
             caracter = c;   
            int cont = 1;
            
            for(int j = 1; j < tamanho + 1; j++){
                printf("%c",caracter);
                
                
                
                if (i <= ordem/2){
                    if(j+1 <= ordem/2){
                        if(cont < i){
                            cont++;
                            caracter++;
                        }
                    }
                    else{
                        if(cont > tamanho - j){
                            cont--;
                            caracter--;
                            
                        }
                    }
                }else{
                        if(j+1 <=  ordem/2){
                            if(cont < tamanho-i+1){
                                cont++;
                                caracter++;
                            }
                
                        }
                        else{
                            if(cont > tamanho - j){
                                cont--;
                                caracter--;
                            }
                        }
                }
                if(caracter == 'a' - 1){
                    
                    caracter = 'z';
            
                }
                else if(caracter == 'z' + 1){
                    caracter = 'a';
                }
            }
            putchar('\n');
        }
       putchar('\n');
     }
     else if(k == -1){
         for(int v = 1;v< tamanho + 1; v++){
             int cont = 1;
             caracter = c + ordem/2 - 1;
             
             while(caracter > 'z'){
                 
                 caracter = caracter - 'z' + 'a' - 1;
             }
             for(int j = 1; j < tamanho+1; j++){
                printf("%c", caracter);
                if(v <= ordem/2){
                    if(j+1 <=  ordem/2){
                        if(cont < v){
                            cont++;
                            caracter--;
                        }
                    }else{
                        if(cont > tamanho-j){
                            cont--;
                            caracter++;
                        }
                    }
                }else{
                    if(j+1 <=  ordem/2){
                        if(cont < tamanho-v+1){
                            cont++;
                            caracter--;
                        }
                    }else{
                        if(cont > tamanho-j){
                            cont--;
                            caracter++;
                        }
                    }
                }
                if(caracter == 'z' + 1){
                    caracter = 'a';
                }else if(caracter == 'a' -1){
                    caracter = 'z';
                }
            }
            printf("\n");
         }
    }
  return 0; 
}