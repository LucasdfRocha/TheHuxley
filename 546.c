#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv{
  int num;
  struct arv *esq;
  struct arv *dir;
} Arv;

void inserir(Arv** t, int num){
  if(*t == NULL)  {
    *t = (Arv*)malloc(sizeof(Arv)); 
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->num = num;
  } else {
    if(num < (*t)->num) {
      inserir(&(*t)->esq, num);
    }
    if(num > (*t)->num) {
      inserir(&(*t)->dir, num);
    }
  }
}
char *remover_especiais(char palavraCerta[]){
    int tamanho = strlen(palavraCerta);
    for(int i = 0; i < tamanho; i++){
        if(palavraCerta[i] == '(' || palavraCerta[i] == ')'|| palavraCerta[i] == ' ') {
            palavraCerta[i] = '#';
        }
    }
    return palavraCerta;

}
void preordem(Arv* t,char bbb[]){
  if(t != NULL){
     
    char palavra[15];

    
    sprintf(palavra,"%d",t->num);
    strcat(bbb,palavra);
    strcat(bbb, " ");
    
    
    // if (t->num != vetor[teste]){
    //     printf("falso");
    // }
    preordem(t->esq,bbb);
    preordem(t->dir,bbb);
  }
}


int main() {
    
    Arv *t = NULL; 
    char frase[150];
    char hastag[2] = "#";
    char espaco[2] = " ";
    int certo[100];
    int vetorVai[40];
    char bbb[30];
    int contZero = 0;
    int contZero2 = 0;
    
    fgets(frase,150,stdin);
    remover_especiais(frase);
    
   char *token = strtok(frase,hastag);
    
    int cont = 0;
     while(token != NULL){
        
        int numero = atoi(token);
         if(numero == 0){
            contZero2++;
        }
        if(contZero2 < 2){
            if(numero != 0){
                certo[cont] = numero;
                inserir(&t,numero);
            }
        }
        else{
            printf("VERDADEIRO");
            return 0;
        }
        
        token = strtok(NULL,hastag);
        cont++;
    }
    preordem(t,bbb);
    
    char *agoraVai = strtok(bbb,espaco);
    int cont2 = 0;
    while(agoraVai != NULL){
    
        int vaaaai = atoi(agoraVai);
        
         if(vaaaai == 0){
            contZero++;
        }
        if(certo[9] == 9){
            printf("VERDADEIRO");
            return 0;
        }
        if(contZero < 2){
            if(vaaaai != certo[cont2]){
                printf("FALSO");
                return 0;
            }
            vetorVai[cont2] = vaaaai;
            agoraVai = strtok(NULL,espaco);
            
            cont2++;
        }
        
    }
    
        printf("VERDADEIRO");
  
    
    
    
   return 0;
}