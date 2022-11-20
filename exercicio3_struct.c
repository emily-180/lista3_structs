//curso. A estrutura deve conter a matricula do aluno, nome, nota da primeira prova, nota da segunda
//prova e nota da terceira prova

#include <stdio.h>
typedef struct{
	char nome[40];
	int matricula;
	float n1;
	float n2;
	float n3;
}taluno;

int qtd=0; 

void addAluno(taluno a[]){
	printf("Nome do aluno: ");
	fflush(stdin);//limpar buffer teclado
	gets(a[qtd].nome);
	printf("Matricula: ");
	scanf("%d", &a[qtd].matricula);
	printf("Nota da prova 1,2  e 3: ");
	scanf("%f%f%f", &a[qtd].n1, &a[qtd].n2, &a[qtd].n3);
	qtd++;
}

void listaAluno(taluno a[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("\n** Aluno %d **\n", i+1);
		printf("Nome: %s\n", a[i].nome);
		printf("Matricula: %d\n", a[i].matricula);
		printf("Nota 01: %.2f\n", a[i].n1);
		printf("Nota 02: %.2f\n", a[i].n2);
		printf("Nota 03: %.2f\n", a[i].n3);	
		printf("____________________________\n");
	}
}

void buscaMatricula(taluno a[], int busca){
	int  i;
	for(i=0;i<qtd;i++){
		if(busca==a[i].matricula){
			printf("\n** Aluno **\n");
			printf("Nome: %s\n", a[i].nome);
			printf("Nota 01: %.2f\n", a[i].n1);
			printf("Nota 02: %.2f\n", a[i].n2);
			printf("Nota 03: %.2f\n", a[i].n3);
			printf("____________________________\n");	
		}	
	}
}

void buscaNome(taluno a[], char busca[40]){
	int  i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux, a[i].nome);
		strupr(nomeAux);
		if(strcmp(busca,nomeAux)==0){
			printf("\n** Aluno **\n");
			printf("Nome: %s\n", a[i].nome);
			printf("Nota 01: %.2f\n", a[i].n1);
			printf("Nota 02: %.2f\n", a[i].n2);
			printf("Nota 03: %.2f\n", a[i].n3);
			printf("____________________________\n");	
		}//fim if	
	}//fim for
}

void mediaGeral(taluno a[], int matricula){
	int i;
	float media=0;
	for(i=0;i<qtd;i++){
		if(a[i].matricula == matricula){
				media =  (a[i].n1 +  a[i].n2 +  a[i].n3) / 3;
				if(media >= 6)
					printf("--> %s foi aprovado com sucesso! Sua media: %.2f\n",  a[i].nome, media);
				else
				printf("--> %s foi reprovado! Sua media: %.2f\n",  a[i].nome, media);
		}
	}
}

void maiorMedia(taluno a[]){
	int i, pos;
	float media=0, mMedia=0;
	for(i=0;i<qtd;i++){
		media =  (a[i].n1 +  a[i].n2 +  a[i].n3) / 3;
		if(media > mMedia){
			mMedia = media;
			pos = i; 
		}
	}
	printf("--> A maior media e: %.2f. \nEla perrtece a %s", mMedia , a[pos].nome);
}

void salvaArquivo(taluno a[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosAlunos.txt","wb");
	fwrite(&a[i],sizeof(taluno),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaArquivo(taluno a[]){
	FILE *arq;
	arq=fopen("dadosAlunos.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&a[qtd],sizeof(taluno),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
int menu(){
	int op;
	printf("*** Sistema de Cadastro de Alunos ***\n");
	printf("1- Cadastrar Aluno\n");
	printf("2- Listar Alunos\n");
	printf("3- Buscar aluno por nome ou mtricula\n");
	printf("4- Reprovados ou Aprovados\n");
	printf("5- Maior media geral\n");
	printf("0- Sair\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

int main(){
	taluno alunos[100];
	char nome[40];
	int opcao, op, matricula;
	carregaArquivo(alunos);
	do{
		opcao = menu();
		switch(opcao){
			case 1: printf("\n** Cadastrar Aluno** \n");
				addAluno(alunos);
				printf("Item cadastrado!");
				break;
			case 2: printf("\n** Listar Alunos** \n");
				listaAluno(alunos);
				break;
			case 3: printf("** Buscar aluno por nome ou mtricula **\n");
				printf("Deseja buscar por matricula ou nome? (1/2) ");
				scanf("%d", &op);
				if(op == 1){
					printf("Digite a matricula: ");
					scanf("%d", &matricula);
					buscaMatricula(alunos, matricula);
				} else if(op == 2){
					printf("Digite o nome: ");
					fflush(stdin);
					gets(nome);
					strupr(nome);	
					buscaNome(alunos, nome);
				}
				else
					printf("Opcao invalida!");
				break;	
			case 4: printf("** Reprovados ou Aprovados **\n");
				printf("Digite a matricula: ");
				scanf("%d", &op);
				mediaGeral(alunos, op);
				break;
			case 5: printf("*** Maior media ***\n");
				maiorMedia(alunos);
				break;
			case 0: printf("Saindo...\n");
				salvaArquivos();
				break;
			default: printf("Opcao invalida!!\n");	
		}
		getch();//pausa
		system("cls"); // limpa tela
	}while(opcao!=0);
	return 0;
}
