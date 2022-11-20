#include <stdio.h>
#include <string.h>
typedef struct{
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
}tbanda;
int qtd=0; // controlar a posicao de cadastro no vetor
//--------------
void addBanda(tbanda b[]){
	printf("Nome da banda:");
	fflush(stdin);// limpa o buffer do teclado
	gets(b[qtd].nome);
	printf("Genero da banda:");
	fflush(stdin);// limpa o buffer do teclado
	gets(b[qtd].genero);
	printf("Qtde de integrantes:");
	scanf("%d",&b[qtd].integrantes);
	printf("Ranking da banda:");
	scanf("%d",&b[qtd].ranking);
	qtd++;
}
//--------------
int listaNome(tbanda b[], char nomeBusca[40]){
	int i;
	char nomeAux[40];
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,b[i].nome);
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("** Banda %d **\n",i+1);
			printf("Nome:%s\n",b[i].nome);
			printf("Genero:%s\n",b[i].genero);
			printf("Integrantes:%d\n",b[i].integrantes);
			printf("Ranking:%d\n",b[i].ranking);
			printf("------------------------\n");
			return i;
		}
	}
	return -1;
}
//---------------------------------------
void removebanda(tbanda b[],char nomeBanda[40]){
	int posicao,res;
	posicao = listaNome(b,nomeBanda);
	if(posicao==-1){
		printf("Banda nao encontrada\n");
		return; 
	}
	printf("certeza que quer remover a banda? [1-sim][2-nao]");
	scanf("%d",&res);
	if(res==1){
		b[posicao] = b[qtd-1];
		qtd--;	
	}
	else
		printf("Operacao cancelada");
}
void listaBandas(tbanda b[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("** Banda %d **\n",i+1);
		printf("Nome:%s\n",b[i].nome);
		printf("Genero:%s\n",b[i].genero);
		printf("Integrantes:%d\n",b[i].integrantes);
		printf("Ranking:%d\n",b[i].ranking);
		printf("------------------------\n");
	}// fim for
}
//-----------------------------
void listaRanking(tbanda b[], int busca){
	int i;
	for(i=0;i<qtd;i++){
		if(busca==b[i].ranking){
			printf("** Banda %d **\n",i+1);
			printf("Nome:%s\n",b[i].nome);
			printf("Genero:%s\n",b[i].genero);
			printf("Integrantes:%d\n",b[i].integrantes);
			printf("Ranking:%d\n",b[i].ranking);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
//--------------------------
void listaGenero(tbanda b[], char generoBusca[40]){
	int i;
	char generoAux[40];
	for(i=0;i<qtd;i++){
		strcpy(generoAux,b[i].genero); // copiando do vetor para aux
		strupr(generoAux);// uppercase
		if(strcmp(generoBusca,generoAux)==0){
			printf("** Banda %d **\n",i+1);
			printf("Nome:%s\n",b[i].nome);
			printf("Genero:%s\n",b[i].genero);
			printf("Integrantes:%d\n",b[i].integrantes);
			printf("Ranking:%d\n",b[i].ranking);
			printf("------------------------\n");
		}// fim if
	}// fim for
}
//--------------------------
void salvaArquivo(tbanda bandas[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosBandas.txt","wb");
	fwrite(&bandas[i],sizeof(tbanda),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaArquivo(tbanda bandas[]){
	FILE *arq;
	arq=fopen("dadosBandas.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	  }// fim if
	 while(fread(&bandas[qtd],sizeof(tbanda),1,arq) >0 )
	      qtd++;  
	 printf("Dados carregados com sucesso !\n");
	fclose(arq);
}
int menu(){
	int opcao;
	printf("*** Sistema de Cadastro Rock4You ***\n");
	printf("1- Cadastrar\n");
	printf("2- Listar\n");
	printf("3- Filtro por ranking\n");
	printf("4- Filtro por genero\n");
	printf("5- Filtro por nome\n");
	printf("6- Remover banda\n");
	printf("0 - Sair\n");
	scanf("%d",&opcao);
	return opcao;
}// fim menu
//------------------
int main(){
	tbanda bandas[100];
	int opcao, busca;
	char generoBusca[40],nome[40];
	carregaArquivo(bandas);
	do{
		opcao= menu();
		switch(opcao){
			case 1: addBanda(bandas);
			 break;
			case 2: listaBandas(bandas);
			 break;
			case 3: printf("Filtro ranking:");
					scanf("%d",&busca);
					listaRanking(bandas,busca);
			 break;
			case 4: printf("Filtro por genero:");
					fflush(stdin);//limpa buffer
					gets(generoBusca);
					strupr(generoBusca);// uppercase
					listaGenero(bandas,generoBusca);
			 break;	
			case 5: printf("Filtro por nome:");
					fflush(stdin);//limpa buffer
					gets(nome);
					strupr(nome);// uppercase
					if(listaNome(bandas,nome)==-1)
						printf("Banda nao encontrada\n");
					else
						printf("Banda encontrada\n");
			 break;	 
			case 6: printf("Remover banda:");
					fflush(stdin);//limpa buffer
					gets(nome);
					strupr(nome);// uppercase
					removebanda(bandas,nome);
			break;
			case 0: printf("Saindo...\n");
					salvaArquivo(bandas);
			 break;
			default: printf("Opcao invalida\n");  
		}// fim switch
	  getch(); // pausa
	  system("cls"); // limpa tela	
	}while(opcao!=0);
	return 0;
	
}// fim main

