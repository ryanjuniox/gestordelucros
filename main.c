#include <stdio.h>

int main(){
	
	//VARIAVEIS DE DADOS
	int flag_teste=1;
	char empresario, tipo_de_venda, local_de_venda;
	char definicao_variaveis[99];
	float definicao_custo[99];
	
	//VARIAVEIS DE FUNCIONARIOS
	int qtde_funcionarios;
	float salarios_funcionarios[qtde_funcionarios];
	float custo_total_funcionarios=0;
	
	if(flag_teste == 1){

		//RECEPÇÃO DE DADOS DO USUÁRIO
		printf("RESPONDA CONFORME SUA REALIDADE! \n");
	
		printf("EMPRESARIO INDIVIDUAL (I) ou TENHO FUNCIONARIOS (F): ");
		scanf("%c", &empresario);
		getchar();
		
		printf("oferece PRODUTOS (P) ou SERVICOS (S): ");
		scanf("%c", &tipo_de_venda);
		getchar();
		
		printf("Oferecidos de forma ONLINE (O) ou FISICO (F): ");
		scanf("%c", &local_de_venda);
		getchar();
	}
	
	else{
		empresario = "I";
		tipo_de_venda = "P";
		local_de_venda = "O";
	}
	
	//RECEPÇÃO DE DADOS P/ EMPRESARIOS C/ FUNCIONARIOS
	if(empresario == "F"){
			printf("QUANTIDADE FUNCIONARIOS: ");
			scanf("%d", qtde_funcionarios);
	}
	else if(empresario == "I"){
		printf("NAO POSSUI FUNCIONARIOS");
	}
	
	else{
		printf("RESPOSTA NAO IDENTIFICADA");
	}

	//CALCULO DE CUSTO FUNCIONARIO

	if(qtde_funcionarios > 0){
		for(int i=0; i<qtde_funcionarios; i++){
			printf("ESCREVA O CUSTO DO FUNCIONARIO %d: ", i+1);
			scanf("%f", &salarios_funcionarios[i]);
		}
		for(int i=0; i<qtde_funcionarios; i++){
			custo_total_funcionarios += salarios_funcionarios[i];
		}
	}
	
	//CALCULO DE CUSTO P/ PRODUTO OU SERVIÇO

	if(tipo_de_venda == "P"){
		int i=0;
		printf("DEFINA OS CUSTOS, PARA TERMINAR DIGITE -1");
		while(definicao_variaveis != -1){
			printf("ESCREVA O NOME DO CUSTO: ");
			scanf("%s", &definicao_variaveis[i]);
			printf("DEFINA O VALOR GASTO: ");
			scanf("%f",&definicao_custo[i]);
		}
	}

	else if(tipo_de_venda == "S"){

	}

	else{
		printf("NAO IDENTIFICADA");
	}
	
}