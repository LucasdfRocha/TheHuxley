#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int i,j;
    float matriz[12][8];
    float menor = 10;
    char ano[10], dia[10];
    char posicao[15];
    
    for (i = 0;i < 12; i++){
        for (j = 0; j<8; j++){
            
           scanf("%f",&matriz[i][j]); 
           
            if (matriz[i][j] < menor){
                
                menor = matriz[i][j];
        
                switch(i){
                
                    case 0:
                        
                        strcpy(ano,"Janeiro");
                        break;
                    case 1:
                    
                        strcpy(ano,"Fevereiro");
                        break;
                    case 2:
                    
                        strcpy(ano,"Marco");
                        break;
                    case 3:
                    
                        strcpy(ano,"Abril");
                        break;
                    case 4:
                    
                        strcpy(ano,"Maio");
                        break;
                    case 5:
                    
                        strcpy(ano,"Junho");
                        break;
                    case 6:
                    
                        strcpy(ano,"Julho");
                        break;
                    case 7:
                    
                        strcpy(ano,"Agosto");
                        break;
                    case 8:
                    
                        strcpy(ano,"Setembro");
                        break;
                    case 9:
                    
                        strcpy(ano,"Outubro");
                        break;
                    case 10:
                    
                        strcpy(ano,"Novembro");
                        break;
                        
                    case 11:
                    
                        strcpy(ano,"Dezembro");
                    break;
                }
            
            
                if(j == 0 || j%2 == 0){
                    
                    strcpy(dia,"Sabado");
                    
                }
                else{
                    
                    strcpy(dia,"Domingo");
                }
        
            if (j == 0 || j == 1){
                
                strcpy(posicao,"Primeiro");
            }
            else if (j == 2 || j == 3){
                
                strcpy(posicao,"Segundo");
            }
            else if (j == 4 || j == 5){
                
                strcpy(posicao,"Terceiro");
            }
            else if (j == 6 || j == 7){
                
                strcpy(posicao,"Quarto");
            }
        }
    }
}
    if (menor > 0.5){
        
        printf("Proximo ano eu tento denovo...");
    }
    else{
    
    printf("O melhor dia e no %s %s de %s ",posicao,dia,ano);
    }
    
	return 0;
}