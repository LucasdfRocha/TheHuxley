#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct pokemons{
    
    char nome[20];
    char tipo[20];
    float ataque;
    float defesa;
};
int main() {
    
    int num;
    int i;
    
    struct pokemons inimigos;
    
    
    scanf("%s %s %f %f", inimigos.nome,inimigos.tipo,&inimigos.ataque,&inimigos.defesa);
    scanf("%d",&num);
    struct pokemons ash[num];
    
    
    for( i = 0; i< num; i++){
        
        scanf("%s %s %f %f", ash[i].nome,ash[i].tipo,&ash[i].ataque,&ash[i].defesa);
        
        if(strcmp(ash[i].tipo,"grama") == 0 && strcmp(inimigos.tipo,"agua") == 0){
            
            ash[i].ataque = 1.5 * ash[i].ataque;
            
        }
        else if(strcmp(ash[i].tipo,"agua") == 0 && strcmp(inimigos.tipo,"fogo") == 0){
            
            ash[i].ataque = 1.5 * ash[i].ataque;
            
        }
        else if(strcmp(ash[i].tipo,"fogo") == 0 && strcmp(inimigos.tipo,"grama") == 0){
            
            ash[i].ataque = 1.5 * ash[i].ataque;
            
        }
        
    }
    for(i = 0; i< num; i++){
        for (int x = i+1;x < num;x++){
                if (ash[i].ataque < ash[x].ataque){
                    struct pokemons aux = ash[i];
                    ash[i] = ash[x];
                    ash[x] = aux;
                }
                else if(ash[i].ataque == ash[x].ataque && strcmp(ash[i].nome,ash[x].nome) > 0){
                    
                    struct pokemons aux = ash[i];
                    ash[i] = ash[x];
                    ash[x] = aux;
                } 
        }
    }
    for (int j = 0; j<num;j++){
        printf("\n%d. %s",j+1,ash[j].nome);
    
    }
        
    
    
    
    
    
    
    
    
	return 0;
}