#include <stdio.h>
#include <string.h>
#include<locale.h>

typedef struct{
	
	char nome[30];
	int tempo_inv;
	float porcentagem_inv;
	float valor_inv;
	float total_inv;
	float rendimento_final;
	float total_rendimentos;
	
}Investimento;

//struct para os gastos financeiros;
typedef struct Gasto tipo_gasto;
struct Gasto{
	char nome_do_gasto[40];
	float valor_do_gasto;
};
	 
//struct para produtos e servicos;
typedef struct produtos_servicos tipo_produtos_servicos;
struct produtos_servicos{
	char nome_porduto_servico[40];
	float valorProd_ser;
	int quant_prod_serv;
};

	// FUNÇÕES QUE SERÃO USADAS EM GASTOS: 
void imprime_nome_gastos(tipo_gasto *gastos, int num_gastos){
	int i;
	printf("\n");
	printf("---------------------GASTOS---------------------\n");
	for(i = 0; i<num_gastos; i++){
		printf("%s\n", gastos[i].nome_do_gasto);	
	}
	printf("------------------------------------------------\n");
	printf("\n");
	
}

void imprime_valores(tipo_gasto *gastos, int num_gastos){
	int i;
	printf("\n");
	printf("---------------VALORES DOS GASTOS---------------\n");
	for(i = 0; i<num_gastos; i++){
		printf("%.2f\n",gastos[i].valor_do_gasto); 		
	}	
	printf("------------------------------------------------\n");
	printf("\n");
	
}


void imprimeTotalDeGastos(float totalDeGastos){
	printf("************************************************\n");
	printf("TOTAL DOS GASTOS: R$ %.2f\n", totalDeGastos);
	printf("************************************************\n");	
}
 
void preenche_gastos(tipo_gasto *gastos, int num_gastos, float *totalDeGastos){ 
	int i;
	for(i = 0; i<num_gastos; i++){			
		printf("ESCREVA O NOME DO GASTO FINANCEIRO QUE DESEJA CALCULAR: ");
		scanf("%40[^\n]", gastos[i].nome_do_gasto);
		getchar();
	}
	imprime_nome_gastos(gastos, num_gastos);
	
	for(i = 0; i<num_gastos; i++){
		printf("ESCREVA O VALOR DO GASTO EM '%s':", gastos[i].nome_do_gasto);
		scanf("%f", &gastos[i].valor_do_gasto);
		*totalDeGastos += gastos[i].valor_do_gasto;
	}

}

	//FUNÇOES USADAS EM PRODUTOS E SERVIÇOS:
void imprime_nome_prodserv(tipo_produtos_servicos *produtoOuServico, int num_prod_serv){
	printf("\n");
	printf("---------------PRODUTOS/SERVIÇOS----------------\n");
	int i;
	for(i = 0; i<num_prod_serv; i++){
		printf("%s\n", produtoOuServico[i].nome_porduto_servico);	
	}
	printf("------------------------------------------------\n");	
	printf("\n");	
}

void preenche_prod_serv(tipo_produtos_servicos *produtoOuServico, int num_prod_serv, float *TotalDaArrecadacao){
	int i;
	for(i=0; i<num_prod_serv; i++){
		printf("ESCREVA O NOME DO PRODUTO OU DO SERVIÇO PRESTADO: ");
		scanf("%40[^\n]", produtoOuServico[i].nome_porduto_servico);
		getchar();				
	}
	
	imprime_nome_prodserv(produtoOuServico,num_prod_serv);

	for(i = 0; i<num_prod_serv; i++){
		printf("ESCREVA O VALOR (UNITARIO) RECEBIDO POR '%s': ", produtoOuServico[i].nome_porduto_servico);
		scanf("%f", &produtoOuServico[i].valorProd_ser);	
		printf("QUANTAS UNIDADES DESSE PRODUTO FORAM VENDIDAS? OU QUANTAS VEZES VOCÊ PRESTOU ESSE MESMO SERVIÇOS?: ");
		scanf("%d", &produtoOuServico[i].quant_prod_serv);
		*TotalDaArrecadacao += produtoOuServico[i].valorProd_ser * produtoOuServico[i].quant_prod_serv;
	}
}

 void imprime_valoresProd_serv(tipo_produtos_servicos *produtoOuServico, int num_prod_serv){
 	int i;
	printf("\n");
	printf("----------VALORES DOS PRODUTOS/SERVIÇOS---------\n");
	for(i = 0; i<num_prod_serv; i++){
		printf("%.2f\n",produtoOuServico[i].valorProd_ser);				
	}
	printf("------------------------------------------------\n");	
 }

void imprime_recebimentos(float TotalDaArrecadacao){
	//Retorna ao usuário o valor total recebido pelos produtos vendidos e/ou pelos serviços prestados:
	printf("\n");
	printf("************************************************\n");
	printf("RECEBIMENTOS:  R$ %.2f\n", TotalDaArrecadacao);
	printf("************************************************\n");
}

float imprime_lucro_final(float TotalDaArrecadacao, float totalDeGastos){
	// calcula e retorna ao usuario o seu lucro final
	float lucroFinal;
	lucroFinal = TotalDaArrecadacao - totalDeGastos;
	printf("\n\n");
	printf("************************************************\n");
	printf("LUCRO FINAL: R$ %.2f\n", lucroFinal);
	printf("************************************************\n");

	return lucroFinal;
}
	//função que escreverá em um arquivo quais foram os gastos e seus respectivos valores; quais foram os produtos/serviços, seus respectivos valores
	// e quantidades; e o lucro final
void imprimirArquivo(tipo_gasto *gastos, tipo_produtos_servicos *produtoOuServico, int num_gastos, int num_prod_serv, float lucroFinal){
	FILE *arquivo;
	int i;
	if((arquivo = fopen("Gastos e Produtos_Servicos.txt","a+"))==NULL){
		printf("Não foi possível abrir o arquivo");
		return;
	}
	else{
		fprintf(arquivo,"Gastos:\n");
		fprintf(arquivo,"\n");
		for(i=0;i<num_gastos;i++){
			fprintf(arquivo, "    %s: R$ %.2f\n",gastos[i].nome_do_gasto, gastos[i].valor_do_gasto);
		}
		fprintf(arquivo, "\n");

		fprintf(arquivo,"Produtos/Serviços:\n");
		fprintf(arquivo,"\n");
		for(i=0;i<num_prod_serv;i++){
			fprintf(arquivo, "    %s: %d x R$ %.2f\n",produtoOuServico[i].nome_porduto_servico,produtoOuServico[i].quant_prod_serv,produtoOuServico[i].valorProd_ser);
		}
		fprintf(arquivo, "\n");

		fprintf(arquivo, "Lucro Final: R$ %.2f\n", lucroFinal);
		fprintf(arquivo,"\n\n");
	}
	fclose(arquivo);
}


float calculo_rendimentos(int tempo_de_investimento, float valor_do_investimento, float porcentagem_de_investimento){
	float porcentagem=0, juros=0, rendimento=0;
	int i;
	porcentagem = (float)(porcentagem_de_investimento/100);
	for(i=0; i<tempo_de_investimento; i++){
		juros = valor_do_investimento * porcentagem;
		rendimento += juros+valor_do_investimento;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int resposta_sistema;

	//APRESENTA??O DO SISTEMA
	printf("BEM VINDO AO GESTOR DE LUCROS!\n");
	printf("\n");
	printf("De uma maneira geral, neste sistema voce consegue trabalhar com lucros de investimentos e, lucros em produtos ou servicos.\n");
	printf("\n");

	printf("DESEJA TRABALHAR C/ PRODUTOS/SERVICOS(1) OU INVESTIMENTOS(2): ");
	scanf("%d", &resposta_sistema);
	getchar();

	if(resposta_sistema == 2){
		
	//VETORES DE ARMAZENAMENTO
	Investimento investimento[99];
	float rendimento_final = 0;
	
	//VARIAVEIS DE AUXILIO
	float rendimento=0, porcentagem=0, juros=0;
	int cond_parada;
	int j, k;
	int i=0;
	
	while(1){ //CAPTA??O DOS INVESTIMENTOS
		
		printf("NOME: ");
		scanf("%[^\n]s", &investimento[i].nome);
		getchar();
		
		printf("TEMPO DE INVESTIMENTO: ");
		scanf("%d", &investimento[i].tempo_inv);
		
		printf("PORCENTAGEM DO INVESTIMENTO: ");
		scanf("%f", &investimento[i].porcentagem_inv);
		
		printf("VALOR INVESTIDO: ");
		scanf("%f", &investimento[i].valor_inv);
		
		investimento[i].total_rendimentos = calculo_rendimentos(investimento[i].tempo_inv, investimento[i].valor_inv, investimento[i].porcentagem_inv);
		
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
		rendimento_final += investimento[k].total_rendimentos;
	}
	
	for(k=0; k<i+1; k++){ //PRINT DE TODOS OS GASTOS
		printf("INVESTIMENTO (%s)\n",investimento[k].nome);
		printf("TEMPO DE INVESTIMENTO: %d\n", investimento[k].tempo_inv);
		printf("PORCENTAGEM DE INVESTIMENTO: R$ %.2f\n", investimento[k].porcentagem_inv);
		printf("VALOR INVESTIDO: R$ %.2f\n", investimento[k].valor_inv);
		printf("RENDIMENTOS TOTAIS: R$ %.2f\n", investimento[k].total_rendimentos);
		printf("\n");
	}
	
	printf("**********************************************\n");
	printf("TOTAL DE TODOS OS RENDIMENTOS: R$ %.2f\n", rendimento_final);
	printf("**********************************************\n");
	
	}

	else if(resposta_sistema == 1){

		int num_gastos;
		float totalDeGastos = 0; 
		
		// pergunta ao usuario quantos gastos ele deseja cadastrar
		printf("DIGITE A QUANTIDADE DE GASTOS FINANCEIROS QUE VOCÊ DESEJA CALCULAR: ");
		scanf("%d",&num_gastos);
		getchar();
		
		
		tipo_gasto gastos[num_gastos];  
		
		//chamando a funcao que preenche a struct Gasto e calcula o tatao dos gastos
		preenche_gastos(gastos, num_gastos, &totalDeGastos);
		// chamando a função que  imprime os valores dos gastos 
		imprime_valores(gastos, num_gastos);
		//chamdo a funcao que imprime o total dos gastos
		imprimeTotalDeGastos(totalDeGastos);		
		
		// VENDA DE PRODUTOS OU PRESTACAO DE SERVICOS
		printf("\n\n");
		printf("____________________________________________________________________________________\n");
		printf("  ARRECADAÇÃO FINANCEIRA ATRAVÉS DA VENDA DE PRODUTOS OU DA PRESTAÇÃO DE SERVIÇOS\n");
		printf("____________________________________________________________________________________\n");
		printf("\n\n");
	
		int num_prod_serv;
		printf("QUANTOS PRODUTOS/SERVIÇOS VOCÊ DESEJA CALCULAR?");
		scanf("%d", &num_prod_serv);
		getchar();
		
		tipo_produtos_servicos produtoOuServico[num_prod_serv]; 
		float TotalDaArrecadacao = 0;	
		float lucro;
			
		//chamando funcao que preenche a struct de produtos e servicos, printa seus nomes e calcula o total arrecadado
	 	preenche_prod_serv(produtoOuServico, num_prod_serv, &TotalDaArrecadacao);
		//chamando funcao que imprime o valor individual de cada produto ou servico
		imprime_valoresProd_serv(produtoOuServico,num_prod_serv);
		// chamando a funcao que imprime o total dos recebimentos(receita gerada nas vendas ou prestacao de servicos)
		imprime_recebimentos(TotalDaArrecadacao);
		// chamando a funcao que calcula o lucro final
		lucro = imprime_lucro_final(TotalDaArrecadacao, totalDeGastos);

		//chamando a funcao que imprime os gastos, produtos/servicos e o lucro final no arquivo "Gastos e Produtos_Servicos.txt"
		imprimirArquivo(gastos, produtoOuServico, num_gastos, num_prod_serv, lucro);



	}
	else{
		printf("RESPOSTA INVALIDA!");
	}
	
	return 0;

	}
