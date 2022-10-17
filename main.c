#include <stdio.h>

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
		
	// Variáveis do controle de gastos : 
	
	int i=0, n = 30; // "i" será usada como indice do vetor ValorDeGastos; "n" será o tamanho de tal vetor;
	char gasto[40]; // "gasto" armazanará o nome dos gastos da pessoa/empresa;
	float valorDoGasto[n]; 
	char continuar; 
	float totalDeGastos = 0; 
	
	// soma de todos os gastos financeiros:
	
	while(1){
		
		printf("ESCREVA O NOME DO GASTO FIANCEIRO QUE DESEJA CALCULAR: ");
		fgets(gasto,sizeof(gasto),stdin);
		
		printf("ESCREVA O VALOR DESSE GASTO FINANCEIRO: ");
		scanf("%f", &valorDoGasto[i]);
		
		totalDeGastos += valorDoGasto[i];
		getchar();
		i++;
		
		//pergunta ao usuário se deseja proseguir com os calculos.
		//Por "s" entende-se que que sim e por "n" endende-se que não há mais gastos a serem contabilizados.
						
		printf("DESEJA CONTINUAR? (s/n): ");
		scanf("%s",&continuar);
			
		if(continuar == 'n'){
			break;
			
		}
		
		else{
			while(continuar != 's'  && continuar !='n'){ //ao digitar uma resposta diferente de "s" ou "n" o usuário receberá uma mensagem de alerta 
			//e uma nova chance de digitar a resposta certa.
				printf("INVÁLIDO!\n");
				getchar();
				
				printf("DESEJA CONTINUAR? (s/n): ");
				scanf("%c",&continuar);

			}
				
		if(continuar == 'n' ){
			break;
		}						
		}	
		getchar();
		
	}
	
	// Retorno ao usuário do valor total de seus gastos.
	
	printf("\n");
	printf("************************************************\n");
	printf("TOTAL DOS GASTOS: R$ %.2f\n", totalDeGastos);
	printf("************************************************\n");
	
	
	
	// Variáveis do controle de recebimentos financieros : 
	
	int j=0, m = 30; // "j" será usada como indice do vetor produtoOuServico; "m" será o tamanho de tal vetor;
	char produtoOuServico[40]; // "produtoOuServico" armazanará o nome do produto ou serviço oferecido pela pessoa/empresa;
	float valor_arrecadado[m]; // armazenará o valor de cada produto / serviço;
	float TotalDaArrecadacao = 0;	

	printf("\n\n");
	printf("____________________________________________________________________________________\n");
	printf("  ARRECADAÇÃO FINANCEIRA ATRAVÉS DA VENDA DE PRODUTOS OU DA PRESTAÇÃO DE SERVIÇOS\n");
	printf("____________________________________________________________________________________\n");
	printf("\n\n");


	getchar();
	//Soma de todos os recebimentos da pessoa/empresa: 
	while(1){
		printf("PRODUTO / SERVIÇO: ");
		fgets(produtoOuServico,sizeof(produtoOuServico),stdin);
		
		printf("ESCREVA O VALOR DO PRODUTO VENDIDO OU O VALOR DO SERVIÇO PRESTADO: ");
		scanf("%f", &valor_arrecadado[j]);
		
		TotalDaArrecadacao += valor_arrecadado[j];
		getchar();
		i++;		
				
		printf("DESEJA CONTINUAR? (s/n): ");
		scanf("%s",&continuar);
			
		if(continuar == 'n'){
			break;
			
		}
		
		else{
			while(continuar != 's' && continuar !='n'){
				printf("INVÁLIDO!\n");
				getchar();
				printf("DESEJA CONTINUAR? (s/n): ");
				scanf("%c",&continuar);

						
			}	
		}
		if(continuar == 'n'){
			break;
		}
		getchar();
		
	}
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