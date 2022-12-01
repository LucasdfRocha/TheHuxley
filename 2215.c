#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define true 1

typedef struct qnode{
	int valor; 
	struct node *next;
}Node;



Node* insertList(Node *head, int valor);
void printList(Node *head);
Node* removeList(Node *head);
void soma(Node *var1,Node *var2);
Node* criar();

Node* criar(){
	return NULL;
}

Node* insertList(Node *head, int valor){
	Node *new = (Node *) malloc(sizeof(Node));
	if (new == NULL)
		return NULL;
	new->valor = valor;
	new->next = head;
	head=new;
	return head;
}

void printList(Node *head){
	while (head != NULL) {
		printf("%d ", head->valor);
		head = head->next;
	}
	putchar('\n');
}

Node* removeList(Node *head){
	Node *excluir;
	
	while(head->valor == 0){
		excluir = head;
		head = excluir->next;
		free(excluir);
	}
	return head;
}

void soma(Node *var1,Node *var2){

	int resto = 0, soma = 0;
	Node *valorFim = criar();

	while(true){

		if((var1 != NULL) && (var2 != NULL)){
			if((var1->valor + var2->valor + resto) >= 10){
				soma = ((var1->valor + var2->valor + resto)%10);
				valorFim = insertList(valorFim,soma);
				var1 = var1->next;
				var2 = var2->next;	
				resto = 1;
			}
			else{

				soma = (var1->valor + var2->valor);
				valorFim = insertList(valorFim,soma+resto);
				var1 = var1->next;
				var2 = var2->next;
				resto = 0;
			}
		}
			else if(var1 == NULL){

    			if(var2->valor + resto >= 10){
    				soma = ((var2->valor + resto)%10);
    				valorFim = insertList(valorFim,soma);
    				var2 = var2->next;
    				resto = 1;
			}
			else{

				valorFim = insertList(valorFim,var2->valor+resto);
				resto = 0;
				var2 = var2->next;
			}	
		}
		else if(var2 == NULL){

			if(var1->valor + resto >= 10){
				soma = ((var1->valor + resto)%10);
				valorFim = insertList(valorFim,soma);
				var1 = var1->next;	
				resto = 1;
			}
			else{

				valorFim = insertList(valorFim,var1->valor+resto);
				var1 = var1->next;
				resto = 0;
			}	
		}
		if((var1 == NULL) && (var2 == NULL)){
			if(resto != 0){
				valorFim = insertList(valorFim,resto);
				break;
			}
			else {
				break;
			}	
		}
	}

	valorFim = removeList(valorFim);
	printList(valorFim);
}

void main(){

	Node *Numero1 = criar();
	Node *Numero2= criar();
	Node *resultado = criar();
	
	int valor;
	char letra;
	
	while(scanf("%d%c", &valor, &letra)){
		Numero1 = insertList(Numero1,valor);
         if(letra == '\n') 
            break;
	}
	getchar();

	while(scanf("%d%c", &valor, &letra)){
		
		Numero2= insertList(Numero2,valor);
		if(letra == '\n') 
		break;
		
		
	}
	getchar();
    
    if(Numero1 == NULL && Numero2== NULL) printf("Lista vazia!\n");
    
    else if(Numero1 == NULL){

    	while(Numero2!= NULL){

    		resultado = insertList(resultado,Numero2->valor);
            Numero2= Numero2->next;
    		
    	}
    	printList(resultado);
    }
    else if(Numero2== NULL){

    	while(Numero1 != NULL){

    		resultado = insertList(resultado,Numero1->valor);
            Numero1 = Numero1->next;
    		
    	}
    	printList(resultado);
    }
    else{
    	soma(Numero1,Numero2);
    }
}