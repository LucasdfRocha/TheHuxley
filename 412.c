#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int id;
  float grauProx,taxa;
  char texto[2000];
  struct Node *next;
}node;

node *sortTaxa(node *head) {
  node *aux = head;
  node *temp = head;

  while(aux != NULL) {
    while(temp != NULL) {
      if(aux->taxa > temp->taxa) {
        float taxa = aux->taxa;
        int id = aux->id;
        char texto[10000];
        strcpy(texto, aux->texto);

        aux->id = temp->id;
        aux->taxa = temp->taxa;
        strcpy(aux->texto, temp->texto);

        temp->id = id;
        temp->taxa = taxa;
        strcpy(temp->texto, texto);
      }
      temp = temp->next;
    }
    temp = head;
    aux = aux->next;
  }
  return head;
}
node *inserirFeed( int id, float taxa, char texto[],node *head) {
  node *aux = (node*)malloc(sizeof(node));

  if(aux == NULL) {
    return 0;
  }

  aux->id = id;
  aux->taxa = taxa;
  strcpy(aux->texto, texto);

  if(head == NULL) {
    aux->next = NULL;
    head = aux;
  } else {
    node *Atual = head;
    while(Atual->next != NULL) {
      Atual = Atual->next;
    }
    Atual->next = aux;
    aux->next = NULL;
  }

  return head;
}

node *prioridade(node *head, node *amigos, node *feed) {

  node *FeedAtual = feed;
  node *Atual = amigos;

  while(Atual != NULL) {
    while(FeedAtual != NULL) {
      if(Atual->id == FeedAtual->id) {
        //calculo citado na questao
        FeedAtual->taxa = (FeedAtual->taxa * 0.2) + (Atual->grauProx * 0.8);
      }
      FeedAtual = FeedAtual->next;
    }
    FeedAtual = feed;
    Atual = Atual->next;
  }

  FeedAtual = feed;
  while(FeedAtual != NULL) {
    head = inserirFeed(FeedAtual->id, FeedAtual->taxa, FeedAtual->texto,head);
    FeedAtual = FeedAtual->next;
  }
  head = sortTaxa(head);
  return head;
}


node *InserirLista(node *head, int id, float prox) {
    node *aux = (node *)malloc(sizeof(node));

    aux->grauProx = prox;
    aux->id = id;

  if(head == NULL) {
    aux->next = NULL;
    head = aux;
  } else {
    node *Atual = head;
    while(Atual->next != NULL) {
      Atual = Atual->next;
    }
    Atual->next = aux;
    aux->next = NULL;
  }
  return head;
}


void printFeed(node *head) {
 
    node *Atual = head;
    while(Atual != NULL) {
      if(head != Atual) {
        putchar('\n');
      }
      printf("%d %.2f %s", Atual->id, Atual->taxa, Atual->texto);
      Atual = Atual->next;
    }
  
}
void printLista(node *head) {

    node *Atual = head;
    while(Atual != NULL) {
      if(head != Atual) {
        putchar('\n');
      }
      printf("%d %.1f", Atual->id, Atual->grauProx);
      Atual = Atual->next;
    }
  
}
int main() {
  int m, Tamanho;
  
  scanf(" %d %d", &Tamanho,&m);

  node *amigos = NULL;

  if(m > 20000 || m < 1) {
    return 0;
  }

  for(int i = 0; i < m; i++) {
    int id;
    float next;

    scanf("%d %f", &id,&next);
   

    if(next < 0 || next > 1) {
      return 0;
      
    } else {
      amigos = InserirLista(amigos, id, next);
    }
  }

  node *feedList = NULL;

  int feed;
  scanf(" %d", &feed);

  for (int i = 0; i < feed; i++) {
    int id;
    float taxa;
    char texto[2000];

    scanf(" %d %f", &id,&taxa);
    scanf(" %[^\n]s", texto);

    if(taxa > 1 || taxa < 0) {
      return 0;
    } else {
      feedList = inserirFeed(id, taxa, texto,feedList);
    }
  }
  node *feedFinal = NULL;
  feedFinal = prioridade(feedFinal, amigos, feedList);
 

  node *current = feedFinal;
  for(int i = 0; i < Tamanho; i++) {
    printf("%d ", current->id);
    printf("%s", current->texto);
    putchar('\n');
    current = current->next;
  }

}