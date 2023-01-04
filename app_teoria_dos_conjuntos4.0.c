#include <stdio.h>
#include <stdlib.h>
 //variaveis globais                                   arays/vetores declarados como ponteiros(*)
int *vetA;
int *vetB;
int *vetC;

int tamMem;
                
int *interceAB;
int *interceAC;
int *interceBC;
int *interceABC;

int *uniaoAB;
int *uniaoAC;
int *uniaoBC;
int *uniaoABC;

//                                                     <--
//                                                    variaveis de tamanho dos arrays.
int tamVetA; 
int tamVetB;
int tamVetC;

int taminterceAB=0;
int taminterceAC=0;
int taminterceBC=0;
int taminterceABC=0;

int tamuniaoAB=0;
int tamuniaoAC=0;
int tamuniaoBC=0;
int tamuniaoABC=0;


//                                                     <--
//                                                    variavel char ponteiro para indentificar o array pelo nome
char *vetor;                                          
//                                                     <--

int main(){
// Predeclaracao obrigatoria de funcoes
	int preencher_vetor(int vet);
	int realocar_memoria(int vet, int pos);
	int mostrarVetor(int vet[], int tam, int op);
	int ordenaVetor (int vet1[],int tam,int id);
	int intercessao(int vet1[],int vet2[],int tamVet1,int tamVet2,int id);
	int uniao(int vet1[],int vet2[],int tam1,int tam2,int id);
//  <--
// Disponibilidade de 50 mil campos/inteiros para os arrays
	tamMem=50000;
	
	vetA = malloc(tamMem*sizeof(int));
	vetB = malloc(tamMem*sizeof(int));
	vetC = malloc(tamMem*sizeof(int));	

	interceAB = malloc(tamMem*sizeof(int));
 	interceAC = malloc(tamMem*sizeof(int));
	interceBC = malloc(tamMem*sizeof(int));
	interceABC = malloc(tamMem*sizeof(int));
//<--
   interceAB[0] = 0;
   interceAC[0] = 0;
   interceBC[0] = 0;
   interceABC[0] =0;
   
   
	vetor = "A";
	preencher_vetor(1);
	vetor = "B";
	preencher_vetor(2);
	vetor = "C";
	preencher_vetor(3);
	
	printf("\n\n_______CONJUNTOS__________\n");
	vetor = "A";
	mostrarVetor(vetA, tamVetA, 1);
	vetor = "B";
	mostrarVetor(vetB, tamVetB, 1);
	vetor = "C";
	mostrarVetor(vetC, tamVetC, 1);
	
	printf("\n\n\conjuntos ordenados\n");
	ordenaVetor (vetA, tamVetA, 1);
	ordenaVetor (vetB, tamVetB, 2);
	ordenaVetor (vetC, tamVetC, 3);
	
	printf("\n\n_____INTERCESSOES__________\n");
	intercessao(vetA, vetB, tamVetA, tamVetB, 1);
    intercessao(vetA, vetC, tamVetA, tamVetC, 2);
	intercessao(vetB, vetC, tamVetB, tamVetC, 3);	
	intercessao(interceAB, vetC, taminterceAB, tamVetC, 4);
	
	vetor = "AB";
	mostrarVetor(interceAB, taminterceAB, 2);
	vetor = "AC";
	mostrarVetor(interceAC, taminterceAC, 2);
	vetor = "BC";
	mostrarVetor(interceBC, taminterceBC, 2);
	vetor =  "ABC";
	mostrarVetor(interceABC, taminterceABC, 2);
	
	printf("\n\n________UNIOES_____________\n");
	uniao(vetA, vetB, tamVetA, tamVetB, 1);
	uniao(vetA, vetC, tamVetA, tamVetC, 2);
	uniao(vetB, vetC, tamVetB, tamVetC, 3);
	uniao(uniaoAB, vetC, tamuniaoAB, tamVetC, 4);
	
	
	free(vetA);
	free(vetB);
	free(vetC);
	free(interceAB);
	free(interceAC);
	free(interceBC);
	free(interceABC);
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
			tamVetC = pos;realloc( vetC, (pos)*sizeof(int));
			tamVetC = pos;
		break;	
    } 
	printf("                        realocamento automatico de memoria realizado...\n"); 
}

int mostrarVetor(int *vet, int tam,int op){
	int i;
	
	switch(op){
		case 1 :
		    printf("\nconjunto %s {", vetor);
		break;
		case 2 :
			printf("\nintecessao %s {", vetor);
		break;
		case 3 :
			printf("\nuniao %s {", vetor);
		break;
	}
	
	    
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
			case 4 :
				if(vet1[i] != uniaoAB[i]){
				  	uniaoAB[i] = vet1[i];
				  	tamuniaoAB = i;
				}
			break;
			case 5 :
				if(vet1[i] != uniaoAC[i]){
				uniaoAC = vet1;
				tamuniaoAC = i;
				}
			break;
			case 6 :
				if(vet1[i] != uniaoBC[i]){
				uniaoBC = i;	
				}
			break;
			printf("o tamanho de tam e %s\n", tam);			
		}
		
    }
    

}

int intercessao(int *vet1,int *vet2,int tam1,int tam2,int id){
	int i, j;
	int pos;
	pos=0;
	
	for(i=0;i<tam1;i++){
		for(j=0;j<tam2;j++){
			if(vet1[j]==vet2[i]){
				switch(id){
		    	case 1 :
		    	 	interceAB[pos]=vet1[j];
					pos++;
					taminterceAB=pos;	
		    	break;		
				case 2 :
				 	interceAC[pos]=vet1[j];
					pos++;
					taminterceAC=pos;
					
				break;
				case 3 :
			 		interceBC[pos]=vet1[j];
					pos++;
					taminterceBC=pos;
				break;
				case 4 :
			 		interceABC[pos]=vet1[i];
					pos++;
					taminterceABC=pos;
				break;
				}
			}
		}
	}
}

int uniao(int *vet1,int *vet2,int tam1,int tam2,int id){
    int i,j;
    j=0;
    int vet[tam1+tam2];
    
	for(i=0;i<tam1+tam2;i++){
       if(i<tam1){
		vet[i]=vet1[i];
		}
		else{
		vet[i]=vet2[j];
		j=j++;
		}
		switch(id){
			case 1:
				uniaoAB[i]=vet[i];
				tamuniaoAB=i;
			break;
			
			case 2:
				uniaoAC[i]=vet[i];
				tamuniaoAC=i;
			break;
			
			case 3:
				uniaoBC[i]=vet[i];
				tamuniaoBC=i;
			break;
			
			case 4:
				uniaoABC[i]=vet[i];
				tamuniaoABC=i;
			break;
		}			
	}	
	
	
	
	
	
}


