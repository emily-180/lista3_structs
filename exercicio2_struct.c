#include <stdio.h>
typedef struct{
	char titulo[30];
	char autor[15];
	float ano;
	int prateleira;
}tlivro;

int qtd=0; 

void addLivro(tlivro l[]){
	printf("Titulo: ");
	fflush(stdin);//limpar buffer teclado
	gets(l[qtd].titulo);
	printf("Autor: ");
	fflush(stdin);//limpar buffer teclado
	gets(l[qtd].autor);
	printf("Ano publicacao: ");
	scanf("%d", &l[qtd].ano);
	printf("Prateleira: ");
	scanf("%d", &l[qtd].prateleira);
	qtd++;
}

void listaLivro(tlivro l[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n** Livro %d **\n", i+1);
		printf("Titulo: %s\n", l[i].titulo);
		printf("Autor: %s\n", l[i].autor);
		printf("Ano publicacao: %d\n", l[i].ano);
		printf("Prateleira: %d\n", l[i].prateleira);
		printf("____________________________\n");
	}
}

int procuraTitulo(tlivro l[], char tituloBusca[40]){
	int i;
	char tituloAux[40];
	for(i=0;i<qtd;i++){
		strcpy(tituloAux,l[i].titulo); 
		strupr(tituloAux);
		if(strcmp(tituloBusca,tituloAux)==0){
			printf("\n** Livro %d **\n", i+1);
			printf("Titulo: %s\n", l[i].titulo);
			printf("Prateleira: %d\n", l[i].prateleira);
			return i;
		}
	}
	return -1;
}

void procuraAno(tlivro l[], int ano){
	int i;
	for(i=0;i<qtd;i++){
		if(l[i].ano > ano){
			printf("\n** Livros mais novos **\n");
			printf("Titulo: %s\n", l[i].titulo);
		}	
	}
}

int menu(){
	int op;
	printf("*** Sistema de Cadastro de Livros ***\n");
	printf("1- Cadastrar Livro\n");
	printf("2- Listar Livros\n");
	printf("3- Filtrar por Titulo\n");
	printf("4- Ano de publicacao\n");
	printf("0- Sair\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	tlivro livros[100];
	char titulo[30];
	int opcao, ano;
	do{
		opcao = menu();
		switch(opcao){
			case 1: printf("\n** Cadastrar Livro** \n");
				addLivro(livros);
				printf("Item cadastrado!");
				break;
			case 2: printf("\n** Listar Procedimento** \n");
				listaLivro(livros);
				break;
			case 3:
				printf("Digite o titulo desejado: ");
				fflush(stdin);
				gets(titulo);
				strupr(titulo);
				procuraTitulo(livros, titulo);
				break;
			case 4:
				printf("Digite o ano: ");
				scanf("%d", &ano);
				procuraAno(livros, ano);
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


