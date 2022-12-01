#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	float ph;
	
	scanf("%f",&ph);
	
	if(ph > 7.0){
	    printf("Basica");
	    
	}
	else if(ph < 7.0){
	    printf("Acida");
	    
	}
	else{
	    printf("Neutra");
	}
	
	
}