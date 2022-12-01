#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct qNode{
    int prioridade;
    char id;
    struct qNode *next;
    
}qNode;

void enqueue(struct qNode **head, struct qNode **tail, int var,char id2);
void printQueue(struct qNode *head);
int dequeue(struct qNode **head, struct qNode **tail);

int main() {
	
	qNode *head = NULL;
	qNode *tail = NULL;
	int num;
	char decisao[10];
	char letra;
	
	do{
	    
	    scanf("%s",decisao);
	    
	    if(strcmp("PRT",decisao) == 0){
	        printQueue(head);
	        putchar('\n');
	    }
	    if(strcmp("ADD",decisao) == 0){
	        scanf("\n%c %d",&letra,&num);
	        enqueue(&head,&tail,num,letra);
	    }
	    if(strcmp("RUN",decisao) == 0){
	        dequeue(&head,&tail);
	    }
	    
	}while(strcmp("EXT",decisao) != 0);
	
	return 0;
}
void enqueue(qNode **head,qNode **tail, int var,char id2){

	qNode *novo = (qNode *)malloc(sizeof(qNode));
	
	novo->prioridade = var;
	novo->id = id2;
	printf("Process [%c|%d] enqueued!\n",novo->id,novo->prioridade);
	
	if((*head)== NULL){
	    
	    *tail = novo;
	    *head= novo;
	    novo->next = NULL;
	
	}
	else{
	    if((*head)->prioridade < var){
	        novo->next = *head;
	        *head = novo;
	    }
	    else{
	        qNode *n = *head;
	        qNode *aux = n->next;
	        while(aux != NULL && aux->prioridade > var){
	            n = n->next;
	            aux = aux->next;
	        }
	        if(aux == NULL){
	            (*tail)->next = novo;
	            (*tail) = novo;
	            novo->next = NULL;
	        }
	        else{
	            n->next = novo;
	            novo->next = aux;
	        }
	    }
	} 
}

int dequeue(qNode **head,qNode **tail){
	qNode *temp = *head;
	int valorAux;
	
  
    if((*head)==NULL){
        printf("Empty process queue!\n");
    } 
    else{
    
        temp = *head;
        valorAux = temp->prioridade;
	    *head = (*head)->next;
	    if ((*head) == NULL){
		    *tail = NULL;
    	}
    	   printf("Process [%c|%d] dequeued!\n",temp->id,temp->prioridade);
    	  free(temp); 
    }
}
void printQueue(qNode *head){ 
    
	if(head == NULL){
		printf("Empty process queue!");
	}
	else{
        qNode *aux = head;
        
		while(aux !=NULL){
		    
		    if(aux->next != NULL){
			    printf("[%c|%d] => ",aux->id, aux->prioridade);
		    }
		    else{
		         printf("[%c|%d]",aux->id, aux->prioridade);
		    }
			aux= aux->next;
		}
		
	}
}