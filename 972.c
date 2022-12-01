#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int num;
    
    
    scanf("%d",&num);
    while(num != - 1){
        int achou = 0;
        for(int i = 2; i < num;i++){
            if (num%i == 0){
                achou =+ 1;
                printf("0\n");
                break;
            }
        }
        if(num == 1 || num == 0){
            printf("0\n");
        }
        else if(achou == 0){
            printf("1\n");
        }
        
        scanf("%d",&num);
    }
	return 0;
}