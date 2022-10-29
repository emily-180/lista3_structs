
#include <stdio.h>
typedef struct{
	char nome[40];
	float potencia;
	float tempo;
}teletro;

int qtd=0; 

void addEletro(teletro e[]){
	printf("Nome: ");
	fflush(stdin);//limpar buffer teclado
	gets(e[qtd].nome);
	printf("Potencia: ");
	scanf("%f", &e[qtd].potencia);
	printf("Tempo Medio: ");
	scanf("%f", &e[qtd].tempo);	
	qtd++;
}

void listaEletro(teletro e[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n** Eletrodomestico %d **\n", i+1);
		printf("Nome: %s\n", e[i].nome);
		printf("Potencia: %.2f\n", e[i].potencia);
		printf("Tempo: %.2f\n", e[i].tempo);
		printf("____________________________\n");
	}
}

void buscaNome(teletro e[], char busca[40]){
	int  i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux, e[i].nome);
		strupr(nomeAux);
		if(strcmp(busca,nomeAux)==0){
			printf("\n** Eletrodomestico %d **\n", i+1);
			printf("Nome: %s\n", e[i].nome);
			printf("Potencia: %.2f\n", e[i].potencia);
			printf("Tempo: %.2f\n", e[i].tempo);
			printf("____________________________\n");
		}//fim if	
	}//fim for
}

void calcula(teletro e[], float valor, char busca[40]){
	int i;
	float consumo;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux, e[i].nome);
		strupr(nomeAux);
		if(strcmp(busca,nomeAux)==0){
			consumo = (e[i].potencia / 1000) * e[i].tempo;
			consumo = consumo * valor;
			printf("Consumo diario:  R$ %.2f\n", consumo);
			consumo = consumo * 30;
			printf("Consumo mensal:  R$ %.2f", consumo);
		}
	}
}

int menu(){
	int op;
	printf("*** Sistema de Cadastro de Eletrodomestico ***\n");
	printf("1- Cadastrar Eletro\n");
	printf("2- Listar Eletro\n");
	printf("3- Buscar eletro por nome\n");
	printf("4- Reprovados ou Aprovados\n");
	printf("5- Maior media geral\n");
	printf("0- Sair\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	teletro eletros[100];
	char nome[40];
	int opcao;
	float valor;
	do{
		opcao = menu();
		switch(opcao){
			case 1: printf("\n** Cadastrar Eletro** \n");
				addEletro(eletros);
				printf("Item cadastrado!");
				break;
			case 2: printf("\n** Listar Eletros** \n");
				listaEletro(eletros);
				break;
			case 3: printf("** Buscar eletro por nome **\n");
				printf("Digite o nome: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);	
				buscaNome(eletros, nome);
				break;	
			case 4:printf("** Consumo diario e mensal ***\n");
				printf("Digite o nome: ");
				fflush(stdin);
				gets(nome);
				strupr(nome);	
				printf("Digite o valor do KW: ");
				scanf("%f", &valor);
				calcula(eletros, valor, nome);
				break;
			case 0: printf("Saindo...\n");
				break;
			default: printf("Opcao invalida!!\n");	
		}
		getch();//pausa
		system("cls"); // limpa tela
	} while(opcao!=0);
	return 0;
}
