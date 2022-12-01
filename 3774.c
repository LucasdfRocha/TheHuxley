#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int raizes(float A,float B,float C,float *x1,float *x2){
    
    float delta;    
    int qtd = 0;
    
    delta = pow(B,2) - (4*A*C);
    
    if(delta == 0){
        qtd = 1;
        
        *x1= (-B + sqrt(delta))/(2.0*A);
        

        
    }
    else if(delta < 0){
        qtd = 0;
    }
    else{
        qtd = 2;
        *x1= (-B + sqrt(delta))/(2.0*A); 
	    *x2= (-B - sqrt(delta))/(2.0*A);
    
    }
    return qtd;
}

float main() {

    float A,B,C;
    float x1,x2;
    int func;
    
    scanf("%f %f %f",&A,&B,&C);
    
    func = raizes(A,B,C,&x1,&x2);
    
    
    if (x2 == 0 && x1 == 0){
	    printf("%d\n",func);
	}
	else if (x2 == 0){
        printf("%.2f\n",x1);
	    printf("%d\n",func);
	}
	else{
	    printf("%.2f %.2f\n",x1,x2);
	    printf("%d\n",func);
	}
}