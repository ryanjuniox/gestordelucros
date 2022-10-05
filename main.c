#include <stdio.h>

int main(){
	
	int flag_teste=1;
	char empresario, tipo_de_venda, local_de_venda;
	
	int qtde_funcionarios;
	
	if(flag_teste == 1){
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
	
}