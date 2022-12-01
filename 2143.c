#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
	struct node *novo;
	char itens[39];
	int temItens;
	int espacos;
}node;
node *tail = NULL;
node *head = NULL;

int enfileirar(char *produto, int espaco, int espaco2);
float condicoesCompra(char *produto, float preco[]);

void main(){
	int espaco2 = 0,i;
	float valorItem[10];
    float valor=0;
	char decisao[32];
	char selecionado[40][40];
    int true = 1;

	for (i = 0; i < 10; i++){
		while(true){
			scanf("%s", decisao);
			espaco2 = enfileirar(decisao, i, espaco2);

			if(getchar() == '\n') 
				break;
			else if(ungetc(getchar(), stdin) == '\n') 
				break;

		}
	}

	tail->temItens = 1;

    int k = 0;
	while(k<10){
		scanf("%f", &valorItem[k]);
        k++;
	}
	while(scanf("%s", selecionado[i]) != EOF){
		valor = valor + condicoesCompra(selecionado[i], valorItem);
	}
	printf("Compras realizadas com sucesso. Voce gastou R$%.2f.", valor);
}
int enfileirar(char *produto, int espaco, int espaco2){
	node *novo = malloc(sizeof(node));

	strcpy(novo->itens, produto);
	novo->espacos = espaco;
	novo->temItens = 0;
	novo->novo = NULL;

	if(espaco2 != espaco){
		tail->temItens = 1;
	}
	else if (head == NULL){
		tail = novo;
		head = novo;
	} 
	tail->novo = novo;
	tail = tail->novo;

	return espaco;
}

float condicoesCompra(char *produto, float preco[]){
	node *aux2 = NULL;
	node *aux = head;
	float acumulador = 0;
	
	if(head == NULL){
		printf("Nao temos %s disponivel no momento.\n", produto);
		return 0;
	}
	while(strcmp(produto,aux->itens)  || aux->temItens == 0){
		if (aux->novo == NULL) {
			printf("Nao temos %s disponivel no momento.\n", produto);
			return 0;
		} 
		else {
			aux2 = aux;
			aux = aux->novo;
		}
	}

	if(aux->espacos != 5) {
		acumulador = acumulador + preco[aux->espacos];
	}
	else {
		printf("Opa, um item 0800!\n");
		acumulador=0;
	} 

	if(aux != head){
		aux2->novo = aux->novo; 
		aux2->temItens = 1;
	}
	else {
		head = head->novo;
	} 
	return acumulador;
}
