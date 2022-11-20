#include <stdio.h>
typedef struct{
	char npessoa[30];
	char emprestado;
	char data[15];	
}tdata;

typedef struct{
	char titulo[30];
	char console[15];
	int ano;
	int ranking;
	tdata tdata;
}tjogo;

int qtd=0; 

void addJogo(tjogo j[]){
	printf("Titulo: ");
	fflush(stdin);//limpar buffer teclado
	gets(j[qtd].titulo);
	printf("Console: ");
	fflush(stdin);//limpar buffer teclado
	gets(j[qtd].console);
	printf("Ano: ");
	scanf("%d", &j[qtd].ano);
	printf("Ranking: ");
	scanf("%d", &j[qtd].ranking);
	qtd++;
}

int buscaNome(tjogo j[], char nomeBusca[40]){
	int i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,j[i].titulo); 
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("\n** Jogo **\n");
			printf("Nome: %s\n", j[i].titulo);
			printf("Console: %s\n", j[i].console);
			printf("Valor: %d\n", j[i].ano);
			printf("Ranking: %d\n", j[i].ranking);
			return i;
		}
	}
	return -1;
}

void buscaConsole(tjogo j[], char consoleBusca[40]){
	int i;
	char consoleAux[40];
	for(i=0;i<qtd;i++){
		strcpy(consoleAux,j[i].console); 
		strupr(consoleAux);
		if(strcmp(consoleBusca,consoleAux)==0){
			printf("\n** Jogo **\n");
			printf("Nome: %s\n", j[i].titulo);
			printf("Console: %s\n", j[i].console);
			printf("Valor: %d\n", j[i].ano);
			printf("Ranking: %d\n", j[i].ranking);			
		}
	}
}

void emprestar(tjogo j[], char nomeBusca[40]){
	int i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,j[i].titulo); 
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("Digite seu nome: ");
			fflush(stdin);
			gets(j[i].tdata.npessoa);
			printf("Data de emprestimo: ");
			fflush(stdin);
			gets(j[i].tdata.data);
			j[i].tdata.emprestado = 'S';
			printf("Emprestimo realizado com sucesso!");
		}
	}
}

void devolver(tjogo j[], char nomeBusca[40]){
	int i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,j[i].titulo); 
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			j[i].tdata.emprestado = 'N';
			printf("Livro devolvido com sucesso!");
		}
	}
}

void listarEmprestimos(tjogo j[]){
	int i;
	for(i=0;i<qtd;i++){
		if(strcmp(j[i].tdata.emprestado, 'S')==0)
			printf("--> O jogo %s , esta emprestado para %s\n", j[i].titulo, j[i].tdata.npessoa );
 	}
}
void salvaArquivo(tjogo j[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosJogo.txt","wb");
	fwrite(&j[i],sizeof(tjogo),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaArquivo(tjogo j[]){
	FILE *arq;
	arq=fopen("dadosJogo.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&j[qtd],sizeof(tjogo),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
int menu(){
	int op;
	printf("*** Sistema de Cadastro de Jogos ***\n");
	printf("1- Cadastrar Jogo\n");
	printf("2- Buscar jogo\n");
	printf("3- Buscar console\n");
	printf("4- Emprestimo\n");
	printf("5- Devoolucao\n");
	printf("6- Listar emprestimos\n");
	printf("0- Sair\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	tjogo jogos[100];
	char nome[30];
	int opcao;
	carregaArquivo(jogos);
	do{
		opcao = menu();
		switch(opcao){
			case 1: printf("\n** Cadastrar Jogo** \n");
				addJogo(jogos);
				printf("Item cadastrado!");
				break;
			case 2: printf("\n** Buscar jogo ** \n");
				printf("Digite  o nome do jogo:");
			 	fflush(stdin);
				gets(nome);
				strupr(nome);
				buscaNome(jogos, nome);
				break;
			case 3: printf("** Buscar console **\n");
				printf("Digite  o console:");
			 	fflush(stdin);
				gets(nome);
				strupr(nome);
				buscaConsole(jogos, nome);
				break;	
			case 4: printf("** Emprestar **\n");
				printf("Digite  o nome  do jogo:");
			 	fflush(stdin);
				gets(nome);
				strupr(nome);
				emprestar(jogos, nome);
				break;
			case 5: printf("** Devolver **\n");
				printf("Digite  o nome do jogo:");
			 	fflush(stdin);
				gets(nome);
				strupr(nome);
				devolver(jogos, nome);
				break;
			case 6: printf("** Listar Emprestimos **\n");
				listarEmprestimos(jogos);
				break;
			case 0: printf("Saindo...\n");
				salvaArquivo(jogos);
				break;
			default: printf("Opcao invalida!!\n");	
		}
		getch();//pausa
		system("cls"); // limpa tela
	}while(opcao!=0);
	return 0;
}
