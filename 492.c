#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int profs;
    int qtd;
    char tam;
    int contCaps = 0;
    int contXic;

    for(profs = 0;profs < 14; profs++){

        scanf("%d", &qtd);
        scanf("%c", &tam);

        if(tam == 'p'|| tam == 'P') {

            qtd = qtd * 10;
            contCaps = contCaps + qtd;

        }

        else if (tam == 'g'|| tam == 'G' ) {
            
            qtd = qtd * 16;
            contCaps = contCaps + qtd;    

        }
    }

    contXic = (contCaps * 2)/7;

    printf("%d\n",contCaps);
    printf("%d",contXic);

    return 0;

}