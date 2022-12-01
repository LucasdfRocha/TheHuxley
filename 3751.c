#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct qNode{
   char palavra[100];
    int cont;
    struct qNode *next;
    
}qNode;

void *enqueue(qNode**tail,struct qNode **head,char var[]);
void separar(char var[]);
void printQueue(qNode *head);

char *remover_especiais(char palavraCerta[]){
    int tamanho = strlen(palavraCerta);
    for(int i = 0; i < tamanho; i++){
        if(palavraCerta[i] == '*' || palavraCerta[i] == '"'|| palavraCerta[i] == '#' || palavraCerta[i] == ':'|| palavraCerta[i] == '(' || palavraCerta[i] == '.'|| palavraCerta[i] == '$'){
            palavraCerta[i] = ' ';
        }
    }
    return palavraCerta;
        
}
int main() {
	
	qNode *head = NULL;
	qNode *tail = NULL;
	int num;
	char decisao[10];
	char str[150];
	char *palavraSep;
	char palavraMin[100];
	char letra;
	int true = 1;
	    
	    
	while(true){
        
        scanf(" %[^\n]s ", str);

        
        if(strcmp(str,"-1") == 0){
          break;  
        }

            remover_especiais(str);
        palavraSep = strtok(str," ");
        while (palavraSep != NULL)
            {
                
            
            for(int i = 0; i!=' ';i++){
                palavraMin[i] = tolower(palavraSep[i]);
            }    
            enqueue(&tail,&head,palavraMin);
            palavraSep = strtok (NULL, " ");
        }
        
	}
    printQueue(head);
	
	
	return 0;
}
void *enqueue(qNode **tail,qNode **head, char var[]){

	qNode *novo = (qNode *)malloc(sizeof(qNode));
	
	novo->cont = 1;
	strcpy(novo->palavra,var);
	
	
	if((*head)== NULL){
	    
	    novo->next = NULL;
	    *head= novo;
	    *tail = novo;
	
	}
	else{
	    
	    if((strcmp((*head)->palavra,novo->palavra) > 0)){
	        novo->next = *head;
	        *head = novo;
	        
	    }
	    else{
	        qNode *n = *head;
	        qNode *aux = n->next;
	        
	       if(strcmp(var,n->palavra) == 0){
	                (*head)->cont++;
	                return 0;
	       
	                
	       }
	   
	        while(aux != NULL && strcmp(aux->palavra,var) < 0){
	            n = n->next;
	            aux = aux->next;
	        }
	            
	            if(aux == NULL){
    	            (*tail)->next = novo;
    	            (*tail) = novo;
    	            novo->next = NULL;
	            }
    	        else{
    	            if(strcmp(var,aux->palavra) == 0){
    	                aux->cont++;
    	                return 0;
    	            }
    	                
        	            n->next = novo;
        	            novo->next = aux;

	            }
	    }
	}
 
}

void printQueue(qNode *head){ 
    
	if(head == NULL){
		printf("Empty process queue!");
	}
	else{
        qNode *aux = head;
        
		while(aux !=NULL){
		    
		    
	        printf("%s %d\n",aux->palavra, aux->cont);
		   
			aux= aux->next;
		}
		
	}
}

    
    
