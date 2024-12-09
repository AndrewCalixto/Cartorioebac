#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblipteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //Função respondavel por cadastrar os usuarios no sistema
{
	//Inicio da criaçaõ de variaveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //Final da criaçaõ de variaveis/string

  printf("Digite o CPF a ser cadastrado:"); //Coletando as informações do usuario
  scanf("%s", cpf); //%s refere-se a string
  
  strcpy(arquivo , cpf); //Respnsalvel por copiar valores das strings
  
 
  
  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
  fprintf(file,cpf); //salvo o valor da variavel
  fclose(file); //fecha o qrquivo
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: "); //Coletando as informações do usuario
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado: "); //Coletando as informações do usuario
  scanf("%s",sobrenome);
  
  file = fopen(arquivo, "a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado: "); //Coletando as informações do usuario
  scanf("%s",cargo);
  
  file = fopen (arquivo, "a");
  fprintf(file,cargo);
  fclose(file);
  system("pause");
  
}

int consulta()
{
   setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
   char cpf[40];
   char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuarios: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;   //definindo varíaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL,"Portuguese"); //definindo a inguagem
	
	printf("### Cartório da EBAC ###\n\n");
	printf ("Escolha a opção de desejada do menu\n\n"); //inicio do menu
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\t4 - Sair do sistema\n");
    printf("Opção: "); //Fim do menu
	
	scanf("%d", &opcao); //armzenando a escolha do usuario
	
	system("cls"); //Responsavel por limpar a tela
	
	switch(opcao) //inicio da seleçãom do menu
	{
		case 1:
	    registro(); //Chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
	    deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema\n");
		return 0;
		break;
		
	
		
		default:
		printf("Essa opção nao está disponivel\n");
		system("pause");
		break;
		//Fim da seleção
		
			
	}
	
	
}
}
