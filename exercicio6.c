#include <stdio.h>
typedef struct{
	int dia;
	int mes;
}tnasc;

typedef struct{
	int leite;
	float alim;
	int ano;
	char abate[2];
	tnasc tnasc;
}tgado;

int qtd=0; 

void addGado(tgado g[]){
	printf("Quantidade de leite: ");
	scanf("%d", &g[qtd].leite);
	printf("Quantidade alimento: ");
	scanf("%f", &g[qtd].alim);
	printf("Ano: ");
	scanf("%d", &g[qtd].ano);
	printf("Abate (S/N): ");
	fflush(stdin);//limpar buffer teclado
	gets(g[qtd].abate);
	printf("Dia nascimento: ");
	scanf("%d", &g[qtd].tnasc.dia);
	printf("Mes nascimento: ");
	scanf("%d", &g[qtd].tnasc.mes);
	qtd++;
}

void totalProducao(tgado g[]){
	int i, soma=0;
	for(i=0;i<qtd;i++){
		soma= soma + g[i].leite;
	}
	printf("Total de leite produzido: %d L", soma);
}

void totalConsumido(tgado g[]){
	int i;
	float soma=0;
	for(i=0;i<qtd;i++){
		soma= soma + g[i].alim;
	}
	printf("Total de alimentacao consumido: %.1f KG", soma);
}

void listarAbate(tgado g[]){
	int i;
	for(i=0;i<qtd;i++){
		if(g[i].leite < 40 || g[i].ano > 5){
			printf("\n**  Gado  %d **\n", i+1);
			printf("Quantidade de leite: %d \n",  g[i].leite);
			printf("Quantidade alimento: %.1f\n",  g[i].alim);
			printf("Ano: %d\n", g[i].ano);
			printf("Abate: %s\n",g[i].abate);
			printf("Dia nascimento: %d\n", g[qtd].tnasc.dia);
			printf("Mes nascimento: %d\n", g[qtd].tnasc.mes);
			printf("____________________________\n");
		}
		
	}
}
int menu(){
	int op;
	printf("*** Sistema de Cadastro de Gado ***\n");
	printf("1- Cadastrar Gado\n");
	printf("2- Quantidade de leite\n");
	printf("3- Quantidade de alimento\n");
	printf("4- Abate\n");
	printf("0- Sair\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	tgado gados[100];
	char nome[30];
	int opcao;
	do{
		opcao = menu();
		switch(opcao){
			case 1: printf("\n** Cadastrar Gado** \n");
				addGado(gados);
				printf("Item cadastrado!");
				break;
			case 2: printf("\n** Quantidade total de leite** \n");
				totalProducao(gados);
				break;
			case 3: printf("\n** Quantidade total de alimentacao ***\n");
				totalConsumido(gados);
				break;
			case 4: printf("\n** Lista dos gados para ir ao abate ***\n");
				listarAbate(gados);
				break;
			case 0: printf("Saindo...\n");
				break;
			default: printf("Opcao invalida!!\n");	
		}
		getch();//pausa
		system("cls"); // limpa tela
	}while(opcao!=0);
	return 0;
}
