#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct qNode{
    int valor;
    struct qNode *next;
    
}qNode;

void enqueue(struct qNode **head, struct qNode **tail, int var);
void printQueue(struct qNode *head);
int isEmpty(struct qNode *head);
int dequeue(struct qNode **head, struct qNode **tail);

int main() {
	
	qNode *head = NULL;
	qNode *tail = NULL;
	int num;
	char decisao[10];
	
	do{
	    
	    scanf("%s",decisao);
	    
	    if(strcmp("Imprimir",decisao) == 0){
	        printQueue(head);
	        putchar('\n');
	    }
	    if(strcmp("Enfileirar",decisao) == 0){
	        scanf("%d",&num);
	        enqueue(&head,&tail,num);
	    }
	    if(strcmp("Desenfileirar",decisao) == 0){
	        dequeue(&head,&tail);
	    }
	    
	}while(strcmp("Finalizar",decisao) != 0);
	
	return 0;
}

void enqueue(qNode **head,qNode **tail, int var){

	struct qNode *novo = (struct qNode *)malloc(sizeof(struct qNode));
	
	if(novo !=NULL){ 
		novo->valor = var;
		novo->next = NULL;
		
		if ((*head) == NULL){ 
			*head = novo;
			*tail = novo;
		} 
		else{
		
			(*tail)->next = novo; 
			*tail = novo; 
		}
	}
	else{
		printf("Nao existe memoria disponivel\n");
	}

}

int dequeue(struct qNode **head, struct qNode **tail){
	qNode *temp;
	int aux;
  
    if((*head)==NULL){
        printf("lista vazia. Remocao nao eh possivel\n");
    } 
    else{
    
        temp = *head;
	    *head = (*head)->next;
	    if ((*head) == NULL){
		    *tail = NULL;
    	}
    	  free(temp); 
    }
}
void printQueue(struct qNode *head){ 
	
	if(head == NULL){
		printf("Fila vazia\n");
	}
	else{
        qNode *aux = head;
        
		while(aux !=NULL){
		    if(aux->next != NULL){
			    printf("%d ", aux->valor);
		    }
		    else{
		        printf("%d", aux->valor);
		    }
			aux= aux->next;
		}
		
	}

}