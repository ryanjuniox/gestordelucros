#include <stdio.h>

int main(){
	
	//VETORES DE ARMAZENAMENTO
	int tempo_de_investimento[99] = {0};
	float porcentagem_de_investimento[99] = {0};
	float valor_investido[99] = {0};
	float total_rendimentos[99] = {0};
	float rendimento_final = 0;
	
	//VARIAVEIS DE AUXILIO
	float rendimento=0, porcentagem=0, juros=0;
	int cond_parada;
	
	int i=0;
	
	while(1){
		
		printf("INVESTIMENTO %d\n", i+1);
		
		printf("TEMPO DE INVESTIMENTO: ");
		scanf("%d", &tempo_de_investimento[i]);
		
		printf("PORCENTAGEM DO INVESTIMENTO: ");
		scanf("%f", &porcentagem_de_investimento[i]);
		
		printf("VALOR INVESTIDO: ");
		scanf("%f", &valor_investido[i]);
		
		porcentagem = (float)(porcentagem_de_investimento[i]/100);
		
		for(int j=0; j<tempo_de_investimento[i]; j++){
			juros = valor_investido[i]*porcentagem;
			rendimento += juros+valor_investido[i];
		}
		
		total_rendimentos[i] = rendimento;
		
		printf("\n");
		
		printf("DESEJA CONTINUAR? SIM (1) NAO (0): ");
		scanf("%d", &cond_parada);
		
		printf("\n");
		
		if(cond_parada == 1){
			i++;
			porcentagem = 0;
			rendimento = 0;
		}
		else{
			break;
		}
		
	}
	for(int k=0; k<i+1; k++){
		rendimento_final += total_rendimentos[k];
	}
	
	for(int k=0; k<i+1; k++){
		printf("INVESTIMENTO %d\n", k+1);
		printf("TEMPO DE INVESTIMENTO: %d\n", tempo_de_investimento[k]);
		printf("PORCENTAGEM DE INVESTIMENTO: R$ %.2f\n", porcentagem_de_investimento[k]);
		printf("VALOR INVESTIDO: R$ %.2f\n", valor_investido[k]);
		printf("RENDIMENTOS TOTAIS: R$ %.2f\n", total_rendimentos[k]);
		printf("\n");
	}
	
	printf("**********************************************\n");
	printf("TOTAL DE TODOS OS RENDIMENTOS: R$ %.2f\n", rendimento_final);
	printf("**********************************************\n");
	
	return 0;
	
}