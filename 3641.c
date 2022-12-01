#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct lista{
    
    int id;
    char nome[10];
    int posicao;
}lista;
int main() {
    
    
    int qtd;
    char pessoa[10];
    int id,vetor[qtd],n;
    char temp[10],temp2[10],temp3[10];
    
    scanf("%d",&qtd);
    
    lista Node[qtd];
    
    for(int i = 0;i<qtd;i++){
        scanf("%s %d",Node[i].nome,&Node[i].id);
        
        Node[i].posicao = i;
    }
    
    for(int i= 1; i<=qtd-1 ; i++) {
        for(int j = qtd -1; j>=i; j--) {
            if (Node[j].id%2 == 0 && Node[j-1].id%2 == 0 ) {
                if(Node[j].posicao < Node[j-1].posicao){
                    
                    int aux = Node[j].id;
                    Node[j].id = Node[j-1].id;
                    Node[j-1].id = aux;
                }
                    
            }
            else if (Node[j].id%2 == 0 && Node[j-1].id%2 != 0 ){
                
                int temp = Node[j].id;
                strcpy(temp2,Node[j].nome);
                int temp3 = Node[j].posicao;
                
                Node[j].id = Node[j-1].id;
                strcpy(Node[j].nome,Node[j-1].nome);
                Node[j].posicao = Node[j-1].posicao;
                
                Node[j-1].id = temp;
                strcpy(Node[j-1].nome,temp2);
                Node[j-1].posicao = temp3;
                
            }
                
        }
    }
    
     for(int i = 0;i<qtd;i++){
        printf("%s\n",Node[i].nome);
        
    }
    


	return 0;
}