#include <stdio.h>
int main(){
	int vetorA[100];
	int vetorB[100];
	int vetorC[100];
	
	int vetorinterce[100];
	int vetorinterce2[100];
	int vetorinterce3[100];
	
	int uniaoAeB[100];
	int uniaoAeC[100];
	int uniaoBeC[100];
	
	
	int i, j, k;
	int x, y, z, a=0;
	int combinador=0;
	
	int tamUAB[100];
	
	for (i=0;i<100;i++){
	
		printf("insira os valores do conjunto A ou 0 para finalizar");
		scanf("%d", &vetorA[i]);
		fflush(stdin);
		if (vetorA[i]==0){
			break;
		}
   	}
   	printf("\n-------------------------------------------------------------\n");
   	for (j=0;j<100;j++){
	    
		printf("insira os valores do conjunto B ou 0 para finalizar");
		scanf("%d", &vetorB[j]);
		fflush(stdin);
		if (vetorB[j]==0){
			break;
		}
    }
	printf("\n-------------------------------------------------------------\n");	
   	for (k=0;k<100;k++){
   		printf("insira os valores do conjunto C ou 0 para finalizar");
   		scanf("%d", &vetorC[k]);
   		if (vetorC[k]==0){
   			break;
		   }
   		
	   }
	printf("\n\n_______CONJUNTOS__________"); 
	printf("\n\nconjunto A {");   
	for (x=0;x<i;x++){
		printf("%d, ", vetorA[x]);
	}
	
	//corrige o bug do retrocesso
	if(vetorA[0] > 0){
    	printf("\b\b}");
	}
	else{
	    printf("\b}");	
	}
	
	printf("\n\nconjunto B {");
	for (x=0;x<j;x++){
		printf("%d, ", vetorB[x]);
	}
	
	//corrige o bug do retrocesso
	if(vetorB[0] > 0){
    	printf("\b\b}");
	}
	else{
	    printf("}");	
	}
	
	printf("\n\nconjunto C {");
	for (x=0;x<k;x++){
		printf("%d, ",vetorC[x]);
	}
	
	//corrige o bug do retrocesso
	if(vetorC[0] > 0){
    	printf("\b\b}");
	}
	else{
	    printf("}");	
	}
	
	
	z=0;
		
	for(x=0;x<i;x++)
		for(y=0;y<j;y++)
			if (vetorA[x] == vetorB[y]){
				vetorinterce[z] = vetorB[y];
				z=z+1;
			}

	printf("\n\n_______INTERCESSAO_______");
	printf("\n\nintercessao de A e B {");
	for(x=0;x<z;x++){
	
		printf("%d,", vetorinterce[x]);
    }
    
    //corrige o bug do retrocesso
    if(vetorinterce[0] > 0){
    	printf("\b}");
	}
	else{
	    printf("}");	
	}
	
	z=0;
	
	for(x=0;x<i;x++)
		for(y=0;y<k;y++)
			if (vetorA[x] == vetorC[y]){
				vetorinterce2[z] = vetorA[y];
				z=z+1;
			}
	
	
	
	printf("\n\nintercessao de A e C {");
	for(x=0;x<z;x++){
	
		printf("%d,", vetorinterce2[x]);
    }
    //corrige o bug do retrocesso
    if(vetorinterce2[0] > 0){
    	printf("\b}");
	}
	else{
	    printf("}");	
	}
    
    
    z=0;
	vetorinterce3[x] = -1;
	for(x=0;x<j;x++)
		for(y=0;y<k;y++)
			if (vetorB[x] == vetorC[y]){
				vetorinterce3[z] = vetorB[y];
				z=z+1;
			}
	
	printf("\n\nintercessao de B e C {");
	for(x=0;x<z;x++){
		printf("%d,", vetorinterce3[x]);
    }
	if(vetorinterce3[0] > 0){
		printf("\b}");
	}
	else{
		printf("}");
	}
	

	for (x=0;x<i+j;x++){
	
	   if(x<i){
	   		for (y=0;y<i;y++){
	   		uniaoAeB[y]=vetorA[y];
	   		}
		}
		else{
			for (z=0;z<j;z++){
				
				if(a<y){
					a=y;	
				}
				else{
			    	a=a+1;
				}
			uniaoAeB[a]=vetorB[z];
		   	}
	    }
    }
	printf("\n\n_______UNIAO_________"); 
	printf("\n\nuniao de A e B {");
	for (y=0;y<x;y++){
	printf("%d,", uniaoAeB[y]);
	}
	 //corrige o bug do retrocesso
    if(uniaoAeB[0] > 0){
    	printf("\b}");
	}
	else{
	    printf("}");
	}
	
	a=0;
	for (x=0;x<i+k;x++){
	
	   if(x<i){
	   		for (y=0;y<i;y++){
	   		uniaoAeC[y]=vetorA[y];
	   		}
		}
		else{
			for (z=0;z<k;z++){
				
				if(a<y){
					a=y;	
				}
				else{
			    	a=a+1;
				}
			uniaoAeC[a]=vetorC[z];
		   	}
	    }
    }
    
    printf("\n\nuniao de A e C {");
	for (y=0;y<x;y++){
	printf("%d,", uniaoAeC[y]);
	}
	 //corrige o bug do retrocesso
    if(uniaoAeB[0] > 0){
    	printf("\b}");
	}
	else{
	    printf("}");
	}
	
	a=0;
	for (x=0;x<j+k;x++){
	
	   if(x<i){
	   		for (y=0;y<j;y++){
	   		uniaoBeC[y]=vetorB[y];
	   		}
		}
		else{
			for (z=0;z<k;z++){
				
				if(a<y){
					a=y;	
				}
				else{
			    	a=a+1;
				}
			uniaoBeC[a]=vetorC[z];
		   	}
	    }
    }
    
    printf("\n\nuniao de B e C {");
	for (y=0;y<x;y++){
	printf("%d,", uniaoBeC[y]);
	}
	 //corrige o bug do retrocesso
    if(uniaoAeB[0] > 0){
    	printf("\b}");
	}
	else{
	    printf("}");
	}
    return (0);
}





