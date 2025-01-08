#include <stdio.h> //blibioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de spaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // bliblioteca responsável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
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
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nInformações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
		
}
int deletar()
	{
		printf("Vocé escolheu deletar nome! \n");
		system("pause");
	}
	
	

int main()
{
	int opcao=0;//definindo variável
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //armazenamento da linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio de menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("Opcão: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não esta desponivel!\n");
			system("pause");
			break;
			
		} // fim da seleçao
	
	}
	
	
}
