#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int movCima[4]={-1, 1, 0, 0};
int movLateral[4]={0,0,-1,1};
int pontuacaoTot = 0;

typedef struct Mapa{
char nomeMapa[105]; 
int linhas, colunas;
int palavra;
int P;
int **placar;
int **next;
}Mapa;

int logicaCircular(int linha, int coluna);
int movimentacaoNoMapa(Mapa Mapa[], int a, int b, int c);
int palindromo(char palavra[]);

int main(){

    int tamanho; 
    scanf("%d", &tamanho);

    Mapa mapa[tamanho];

    int i = 0;
    while(i<tamanho){
        scanf("%d %d\n%s", &mapa[i].linhas, &mapa[i].colunas, mapa[i].nomeMapa); 

        mapa[i].P = 0; 
        mapa[i].palavra = palindromo(mapa[i].nomeMapa);
        
        //pamela, tive que cometer esse crime da alocacao dinamica porque tinha um
        //caso que nao tava indo de jeito nenhum, so solucionei desse jeito
        mapa[i].placar = (int*) malloc(50 * sizeof(int*));
        mapa[i].next = (int*) malloc(50 * sizeof(int*));

        int j = 0;
        while (j < mapa[i].linhas){
            mapa[i].placar[j] = (int*) malloc(mapa[i].colunas * sizeof(int));
            mapa[i].next[j] = (int*) malloc(mapa[i].colunas * sizeof(int));
            
            for(int l = 0; l < mapa[i].colunas; l ++){
                scanf("%d,%d", &mapa[i].next[j][l], &mapa[i].placar[j][l]);
            }
            j++;
        }
        i++;
    }

    pontuacaoTot = movimentacaoNoMapa(mapa, 0, 0, 0);
    printf("%d\n", pontuacaoTot);
    for(int p = 0; p < tamanho; p++){
        printf("%s %d\n", mapa[p].nomeMapa, mapa[p].P);
    }
    return 0;
}
int logicaCircular(int x, int y){
    // logica dita no texto da questao do exemplo Exemplo: c?lula atual [0][3] em uma matriz de tamanho [5][5], se a instru??o for ir pra cima, ent?o a pr?xima c?lula ? a [4][3]. 
    //O mesmo racioc?nio circular vale para as outras 3 bordas.
    return (((x % y) + y) % y);
}

int movimentacaoNoMapa(Mapa Mapa[], int a, int b, int c){
    //0 cima  1 baixo 2 esquerda 3 direita 4 vertigem
    while(!(b == Mapa[a].linhas - 1) || !(c == Mapa[a].colunas - 1)){
        if(Mapa[a].next[b][c] != 4){

            Mapa[a].P += Mapa[a].placar[b][c] * (1 + Mapa[a].palavra);
            pontuacaoTot += Mapa[a].placar[b][c] * (1 + Mapa[a].palavra);

            int proximaLinha = logicaCircular(b + movCima[Mapa[a].next[b][c]], Mapa[a].linhas), 
            proxColuna = logicaCircular(c + movLateral[Mapa[a].next[b][c]], Mapa[a].colunas);

            b = proximaLinha; c = proxColuna;

        }
        else{
            a = Mapa[a].placar[b][c]; 
            b = (pontuacaoTot / Mapa[a].colunas) % Mapa[a].linhas; 
            c = pontuacaoTot % Mapa[a].colunas;
        }
    }
    pontuacaoTot = pontuacaoTot + Mapa[a].placar[b][c] * (1 + Mapa[a].palavra);
    Mapa[a].P = Mapa[a].P + Mapa[a].placar[b][c] * (1 + Mapa[a].palavra);
    return pontuacaoTot;
}

int palindromo(char palavra[]){
    //verificando se ? palindromo ou nao (funcao ja utilizada antes)

    int tamanhoPalavra;
    tamanhoPalavra = strlen(palavra);

    int true = 1, false = 0;

    for (int i = 0, j = tamanhoPalavra - 1; i <= j; i ++, j --){
        if (palavra[i] != palavra[j]){ 
            return false;
        }
        else{
            return true;
        }
    }
}
