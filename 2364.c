#include <stdio.h>
#include <math.h>

//para ambas as funcoes saberem os valores
int qtdPessoas = 0,valorArrec = 0;valorPP;


int calculo(int qtdPessoas)
{
        if (qtdPessoas == 1)
        {
            return valorPP;
        }
       if (qtdPessoas % 2 == 0)
       {
              return qtdPessoas + calculo(qtdPessoas - 1);
       }

       else
       {
              return valorPP + calculo(qtdPessoas - 1);
       }
}

int main()
{
       int bbb;
       
       scanf("%d", &bbb);
       valorPP = bbb;
       int valor10m = 1;
       
       do
       {
              if (valorArrec < 10000000)
              {
                     qtdPessoas += 1;
                     
              }
              if (qtdPessoas > 1)
              {
                     valorArrec = calculo(qtdPessoas);
              }

       } while (valorArrec < 10000000);
       
       if(bbb == 10000000){
           printf("%d pessoas precisam assistir ao jogo.", valor10m);
           exit(0);
       }

       printf("%d pessoas precisam assistir ao jogo.", qtdPessoas);

       return 0;
}
