#include <stdio.h>
#include <string.h>
#include <string.h>

int main(){
	
	int resposta_sistema;

	//APRESENTAÇÃO DO SISTEMA
	printf("BEM VINDO AO GESTOR DE LUCROS!\n");
	printf("\n");
	printf("De uma maneira geral, neste sistema voce consegue trabalhar com lucros de investimentos e, lucros em produtos ou servicos.\n");
	printf("\n");

	printf("DESEJA TRABALHAR C/ PRODUTOS/SERVICOS(1) OU INVESTIMENTOS(2): ");
	scanf("%d", &resposta_sistema);

	if(resposta_sistema == 2){
		
	//VETORES DE ARMAZENAMENTO
	int tempo_de_investimento[99] = {0};
	float porcentagem_de_investimento[99] = {0};
	float valor_investido[99] = {0};
	float total_rendimentos[99] = {0};
	float rendimento_final = 0;
	
	//VARIAVEIS DE AUXILIO
	float rendimento=0, porcentagem=0, juros=0;
	int cond_parada;
	int j, k;
	
	int i=0;
	
	while(1){ //CAPTAÇÃO DOS INVESTIMENTOS
		
		printf("INVESTIMENTO %d\n", i+1);
		
		printf("TEMPO DE INVESTIMENTO: ");
		scanf("%d", &tempo_de_investimento[i]);
		
		printf("PORCENTAGEM DO INVESTIMENTO: ");
		scanf("%f", &porcentagem_de_investimento[i]);
		
		printf("VALOR INVESTIDO: ");
		scanf("%f", &valor_investido[i]);
		
		porcentagem = (float)(porcentagem_de_investimento[i]/100);
		
		for( j=0; j<tempo_de_investimento[i]; j++){
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
	for( k=0; k<i+1; k++){
		rendimento_final += total_rendimentos[k];
	}
	
	for(k=0; k<i+1; k++){ //PRINT DE TODOS OS GASTOS
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
	
	}

	else if(resposta_sistema == 1){
		getchar();
		
	int num_gastos;
	int i, j; 
	float totalDeGastos = 0; 
	
	// pergunta ao usuario quantos gastos ele deseja cadastrar
	printf("DIGITE A QUANTIDADE DE GASTOS FINANCEIROS QUE VOCÊ DESEJA CAlCULAR: ");
	scanf("%d",&num_gastos);
	getchar();
	
	char gasto[num_gastos][40]; // "gasto" armazanará o nome dos gastos da pessoa/empresa;
	
	//matriz dos nomes dos gastos
	for(i = 0; i<num_gastos; i++){
		printf("ESCREVA O NOME DO GASTO FINANCEIRO QUE DESEJA CALCULAR: ");
		scanf("%40[^\n]", gasto[i]);
		getchar();			
	}
	
	//printa a matriz dos nomes dos gastos
	printf("\n");
	printf("---------------------GASTOS---------------------\n");
	for(i = 0; i<num_gastos; i++){
		printf("%s\n", gasto[i]);	
	}
	printf("------------------------------------------------\n");
	printf("\n");
	
	//matriz dos valores dos gastos financeiros 
	
	float valorDoGasto[num_gastos][1];
	float *ponteiro_valor_gasto; // uso de ponteiro
	ponteiro_valor_gasto = &valorDoGasto[0][0];
	
	for(i = 0; i<num_gastos; i++){
		for(j = 0; j<1;j++){
			printf("ESCREVA O VALOR DO GASTO EM '%s':", gasto[i]);
			scanf("%f", &valorDoGasto[i][j]);	
			totalDeGastos += valorDoGasto[i][j];		
		}
	}
		
	printf("\n");
	// printa a matriz ddos valores dos gastos finaceiros
	printf("---------------VALORES DOS GASTOS---------------\n");
	for(i = 0; i<num_gastos; i++){
		for(j = 0; j<1;j++){
			printf("%.2f\n",ponteiro_valor_gasto[i]); // o ponteiro foi usado para printar os valores dos gastos		
		}
	}	
	printf("------------------------------------------------\n");
	printf("\n");	
	//print o total de gastos
	printf("************************************************\n");
	printf("TOTAL DOS GASTOS: R$ %.2f\n", totalDeGastos);
	printf("************************************************\n");
	
	
	// VENDA DE PRODUTOS OU PRESTAÇÃO DE SERVIÇOS
	printf("\n\n");
	printf("____________________________________________________________________________________\n");
	printf("  ARRECADAÇÃO FINANCEIRA ATRAVÉS DA VENDA DE PRODUTOS OU DA PRESTAÇÃO DE SERVIÇOS\n");
	printf("____________________________________________________________________________________\n");
	printf("\n\n");

	int num_prod_serv;
	printf("QUANTOS PRODUTOS/SERVIÇOS VOCÊ DESEJA CALCULAR?");
	scanf("%d", &num_prod_serv);
	getchar();
	
	char produtoOuServico[num_prod_serv][40]; 
	int quantidade_prod_serv[num_prod_serv][1];
	
	printf("\n");
	//matriz dos nomes dos produtos a serem vendidos ou dos serviços prestados
	for(i = 0; i<num_prod_serv; i++){
		printf("ESCREVA O NOME DO PRODUTO OU DO SERVIÇO PRESTADO: ");
		scanf("%40[^\n]", produtoOuServico[i]);
		getchar();				
	}
	
	//printa a matriz dos nomes produtos/serviços
	printf("\n");
	printf("---------------PRODUTOS/SERVIÇOS----------------\n");
	for(i = 0; i<num_prod_serv; i++){
		printf("%s\n", produtoOuServico[i]);	
	}
	printf("------------------------------------------------\n");
			
	float valor_arrecadado[num_prod_serv][1]; // armazenará o valor de cada produto/serviço;
	float TotalDaArrecadacao = 0;
	
	//matriz dos valores dos produtos/serviços e matriz das quantidades de cada um
	printf("\n");
	for(i = 0; i<num_prod_serv; i++){
		for(j = 0; j < 1; j++){
		printf("ESCREVA O VALOR RECEBIDO POR '%s': ", produtoOuServico[i]);
		scanf("%f", &valor_arrecadado[i][j]);	
		printf("QUANTAS UNIDADES DESSE PRODUTO FORAM VENDIDAS? OU QUANTAS VEZES VOCÊ PRESTOU ESSE MESMO SERVIÇO?: ");
		scanf("%d", &quantidade_prod_serv[i][j]);
		TotalDaArrecadacao += valor_arrecadado[i][j] * quantidade_prod_serv[i][j];
		}
	}
	
	
	printf("\n");
	printf("----------VALORES DOS PRODUTOS/SERVIÇOS---------\n");
    // printa a matriz dos valores dos produtos/serviços
	for(i = 0; i<num_prod_serv; i++){
		for(j = 0; j<1;j++){
			printf("%.2f\n",valor_arrecadado[i][j]);			
		}	
	}
	
	printf("------------------------------------------------\n");	
	//Retorna ao usuário o valor total recebido pelos produtos vendidos e/ou pelos serviçoes prestados:
	printf("\n");
	printf("************************************************\n");
	printf("RECEBIMENTOS:  R$ %.2f\n", TotalDaArrecadacao);
	printf("************************************************\n");
	
	
	// Cálculo do lucro final: 
	
	float lucroFinal;
	
	lucroFinal = TotalDaArrecadacao - totalDeGastos;
	printf("\n\n");
	printf("************************************************\n");
	printf("LUCRO FINAL: R$ %.2f\n", lucroFinal);
	printf("************************************************\n");
	}


	else{
		printf("RESPOSTA INVALIDA!");
	}
	
	
	return 0;

	}

