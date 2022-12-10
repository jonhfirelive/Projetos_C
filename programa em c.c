#include <stdio.h>
#include <string.h>
#include <locale.h>
int main() 
{
	setlocale(LC_ALL,"portuguese");
	
	char usuario[10]="    "; 
	int senha=0;
	char usuarioservidor[10]="joão";
	int retorno = 0;
	
	printf("insira  o usuario\n");
	scanf("%s", &usuario);
	fflush(stdin);
	
	printf("digite a senha\n");
	scanf("%d", &senha);
	fflush(stdin);
	
	
	retorno = strcmp(usuario,usuarioservidor);
	
	
	//testa se usuario e senha sao validos
    if (usuario != "    ")  
	{	
		if(retorno == 0)
		{	
			printf("usuario validado com sucesso!\n");
			if(senha == 1234)
			{	
				printf("senha validada com sucesso!\n");
				printf("____________________________________________\n");
				printf("############# Bem vindo ao PDV #############\n");
				printf("____________________________________________\n");
			}
			else
			{	
				printf("senha nao encontrada!\n prencha os campos novamente.\n");
				printf("1.SAIR   2.TENTAR NOVAMENTE ");
				int escolha=0;
				scanf("%d", &escolha);
				
				switch(escolha)
				{	
					case 1 :
					break;
						
					case 2 :
						printf("\n\n...");
						main();
					break;
					
					default :
						printf("valor invalido");
					break;
					
				}
				
			}
			
		}
		else
		{	
			printf("usuario nao encontrado! prencha os campos novamente.\n");
			
		}
		
		
		
		
		
	}
	else
	{
		printf("campo usuario vazios");
	}








	
}
	