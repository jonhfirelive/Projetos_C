#include <stdio.h>
#include <stdlib.h>

int *vetA;
int *vetB;
int *vetC;

int tamMem;

int tamVetA; 
int tamVetB;
int tamVetC;

char *vetor;


int main(){
	
	int preencher_vetor(int vet);
	int realocar_memoria(int vet, int pos);
	int mostrarVetor(int vet[], int tam);
	int ordenaVetor (int vet1[],int tam,int id);
	
	
	tamMem=50000;
	

	vetA = malloc(tamMem*sizeof(int));
	vetB = malloc(tamMem*sizeof(int));
	vetC = malloc(tamMem*sizeof(int));

	vetor = "A";
	preencher_vetor(1);
	vetor = "B";
	preencher_vetor(2);
	vetor = "C";
	preencher_vetor(3);
	
	printf("\n\n_______CONJUNTOS__________\n");
	vetor = "A";
	mostrarVetor(vetA, tamVetA);
	vetor = "B";
	mostrarVetor(vetB, tamVetB);
	vetor = "C";
	mostrarVetor(vetC, tamVetC);
	
	printf("\n\n\conjuntos ordenados\n");
	ordenaVetor (vetA, tamVetA, 1);
	ordenaVetor (vetB, tamVetB, 2);
	ordenaVetor (vetC, tamVetC, 3);
	
	
	
	free(vetA);
	free(vetB);
	free(vetC);
	return 0;	
}

int preencher_vetor(int vet){
	int pos = 0;
	int test = 0;
	
	
	do{	
	    test = 0;
		printf("insira os valores do conjunto %s ou 0 para finalizar", vetor);

		switch(vet){
			case 1 :
				fflush(stdin);
				scanf("%i", &vetA[pos]);
				test = vetA[pos];
			break;
		
			case 2 :
				fflush(stdin);
				scanf("%i", &vetB[pos]);
				test = vetB[pos];		
			break;
			
			case 3 :
				fflush(stdin);
				scanf("%i", &vetC[pos]);
				test = vetC[pos];
					
			break;
	    }   
	    
		pos = pos + 1;
	
	}while(test != 0);
	realocar_memoria(vet, pos);

	printf("\n\n");
}


int realocar_memoria(int vet, int pos){

	switch(vet){
		case 1 :
			vetA =(int *) realloc( vetA, (pos)*sizeof(int));
			tamVetA = pos;             
		break;
	
		case 2 :
			vetB =(int *) realloc( vetB, (pos)*sizeof(int));
			tamVetB = pos;
		break;
		
		case 3 :
			vetC =(int *) realloc( vetC, (pos)*sizeof(int));
			tamVetC = pos;
		break;	
    } 
	printf("                        realocamento automatico de memoria realizado...\n"); 
}

int mostrarVetor(int *vet, int tam){
	int i;

	printf("\n\nconjunto %s {", vetor);
	    
		for (i=0;i<tam;i++){
			if(vet[i] != 0){
				printf("%i, ", vet[i]);
			}
		}
	
		//corrige o bug do retrocesso
		if(vet[0] > 0){
    		printf("\b\b}");
		}
		else{
	    	printf("}");
		}
}

int ordenaVetor (int *vet1,int tam,int id){
	int i, j, k;
	int aux;
	int alterou = 1;
	printf("o tamanho de tam inicialmente e %d\n", tam);
	
	//lacos responsaveis por ordenar crecentemente o vetor. 
	do{ 
		alterou = 1;
		
		for(i=0;i<tam-2 ;i++){
			
			if (vet1[i]	> vet1[i + 1]){
		    	aux = vet1[i];
		    	vet1[i] = vet1[i+1];
		    	vet1[i + 1]  = aux; 
		    	alterou = 0;		
			}		
		}	
	}
	while(alterou == 0);
	
	//lacos reponsaveis por retirar repeticoes do vetor e redefinir o  novo tamanho.
    
    /* Remove elementos com valor duplicado */
    for( i = 0; i < tam; i++ )
    {
        for( j = i + 1; j < tam; )
        {
            if( vet1[j] == vet1[i] )
            {
                for( k = j; k < tam; k++ )
                    vet1[k] = vet1[k + 1];
                tam--;
            }
            else
            {
                j++;
            }
        }
    }
    
    for(i=0;i<tam;i++){ 
    	switch(id){
			case 1 :
		    	if(vet1[i] != vetA[i]){
		    	 	vetA[i] = vet1[i];
				}
		    break;
			
			case 2 :
				if(vet1[i] != vetB[i]){
			    	vetB[i] = vet1[i];
			    }
			break;	
			case 3 :
				if(vet1[i] != vetC[i]){
			    	vetC[i] = vet1[i];
				}
			break;			
		}
    }
    
    
    printf("o tamanho de tam e %d\n", tam);
	for(j=0;j < (tam);j++){
		switch(id){
		    case 1 :
		    	 	printf("%i, ", vetA[j]);	 	
		    break;
					
			case 2 :
					printf("%i, ", vetB[j]);
			break;
				
			case 3 :
					printf("%i, ", vetC[j]);
			break;
		
    	}		
	}
   	printf("\n"); 
}


