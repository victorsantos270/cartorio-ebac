#include <stdio.h> //blibioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de spa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // bliblioteca respons�vel por cuidar das string

int registro() //fun��o responsvel por cadastrar os usuarios no sistema
{
	// inicio da criaa��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criaa��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa�oes do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //resposvel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //armazenamento da linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
		
}
	int deletar()
	{
		char cpf[40];
		
		printf("Digite o cpf a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL);
		{
			printf("o usu�rio n�o se encontra no sistema!.\n");
			system("pause");
		}
	}
	
	

int main()
{
	int opcao=0;//definindo vari�vel
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio de menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - sair do sistema\n");
		printf("Opc�o: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls"); //responsalveu por limpar a tela
	
		switch(opcao) //chamada de fun�oes
		{
			case 1:
			registro();//chamada de fun�oes
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
			printf("Essa op��o n�o esta desponivel!\n");
			system("pause");
			break;
			
		} // fim da sele�ao
	
	}
	
	
}
