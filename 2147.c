#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pessoa
{
    char lugar[30];
    char nome[30];
} pessoa;

typedef struct qNode
{
    pessoa estudante;
    struct qNode *next;
}qNode;



char* prioridade(char *prior)
{
    char str1[40];
    char *correto;
    strcpy(str1,prior);
    correto = strtok(str1,":");
    if(correto==NULL)
    {
        return NULL;
    }
    strcpy(prior,correto);

    return prior;
    
}
char* defUltimo(char *string, char *res)
{
    char str2[40];
    char *teste;
    strcpy(str2,string);
    teste = strtok(str2,":");
    teste = strtok(NULL,":");
    if(teste==0)
    {
        return res;
    }
    strcpy(string,teste);
    
    return string;
}

int contador(qNode *head)
{
    int i=0;
    qNode *aux=head;
    while(aux!=NULL)
    {
        i++;
        aux = aux->next;
    }
    return i;
}
void desenfileirar(qNode **head, char *lugar)
{
    qNode *temp = *head;

    if((*head) != NULL)
    {    
        if(strcmp(lugar,"RU")==0)
        {
            printf("%s almocou no %s e esta voltando pra aula\n",(*head)->estudante.nome,(*head)->estudante.lugar);
        }
        if(strcmp(lugar, "Area 2")==0)
        {
            printf("%s almocou na %s e esta voltando pra aula\n",(*head)->estudante.nome,(*head)->estudante.lugar);
        }
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        printf("Nao ha mais ninguem para comer aqui\n");
    }
    
}

void enfileirar(qNode **head, char *nome, char *lugar)
{
    qNode *novo = (qNode *)malloc(sizeof(qNode));
    strcpy(novo->estudante.lugar, lugar);
    strcpy(novo->estudante.nome, nome);
    novo->next = NULL;

    if((*head)!= NULL)
    {
        qNode *aux = *head;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = novo;
        novo->next = NULL;
    }
    else
    {
        *head = novo;
    }
    if(strcmp(lugar,"RU")==0)
    {
        printf("%s foi para a fila do %s\n", novo->estudante.nome, lugar);
    }
    if(strcmp(lugar, "Area 2")==0)
    {
        printf("%s foi para a fila da %s\n", novo->estudante.nome, lugar);
    }
}

int main()
{
    qNode *head_A2 = NULL;
    qNode *head_RU = NULL;

	char A2_Antigo[40];
    char RU_Antigo[40];
    char *RU, *A2,  *ultimoFila,*primeiroFila;
    char  regiao[50], regiaoCerto[40];
    int contadorA2,contadorRu;
	int true = 1;
    fgets(RU_Antigo,40,stdin);
    fgets(A2_Antigo,40,stdin);
    
    RU = defUltimo(RU_Antigo, A2);
    A2 = defUltimo(A2_Antigo, A2);
    
    while(true)
    {
        if(fgets(regiao,50,stdin)==NULL)
        {
            break;
        } 
        strcpy(regiaoCerto,regiao);

        ultimoFila = defUltimo(regiaoCerto, A2);
        primeiroFila = prioridade(regiao);
        for(int v = 0;v<=strlen(primeiroFila);v++)
        {
            if(primeiroFila[v]=='\n')
            {
                primeiroFila = strtok(primeiroFila,"\n");
                break;
            }
        }
        if(strcmp(primeiroFila,"SAIU")==0)
        {
            if(strcmp(ultimoFila,"AREA2\n")==0 || strcmp(ultimoFila,"AREA2")==0)
            {
                desenfileirar(&head_A2, "Area 2");
            }
            if(strcmp(ultimoFila,"RU\n")==0||strcmp(ultimoFila,"RU")==0)
            {
                desenfileirar(&head_RU, "RU");
            }
        }
        else {
         if(ultimoFila==NULL||(strcmp(ultimoFila,A2)!=0 && strcmp(ultimoFila,RU)!=0))
            {
                contadorRu = contador(head_RU);
                contadorA2 = contador(head_A2);
                if(contadorRu<contadorA2)
                {
                    enfileirar(&head_RU,primeiroFila, "RU");
                }
                else
                {
                    enfileirar(&head_A2, primeiroFila, "Area 2");
                }
            }
            
            else
            {
                if((strcmp(ultimoFila,A2)==0))
                {
                    enfileirar(&head_A2, primeiroFila, "Area 2");
                }
                else if(strcmp(ultimoFila,RU)==0)
                {
                    enfileirar(&head_RU,primeiroFila, "RU");
                }
            }
        }
    }
        
    
    return 0;
}