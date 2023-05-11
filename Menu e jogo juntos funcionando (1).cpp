#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>

 int main () 
{
	int opcao; 
	int resposta; 	
do{ 
  printf("Menu:\n"); 
  printf(" 1: Jogar\n"); 
  printf(" 2: Tutorial\n"); 
  printf(" 3: Sair\n"); 
  printf("Digite o numero do jogo desejado: "); 
  scanf("%d", &opcao); 
    switch(opcao) 
	{ 
	case 1:
	 do {
	  printf("Jogo selecionado!\n");
	   printf("Deseja inciar o jogo? Digite (1-SIM) OU (2-NAO): "); 
	   scanf("%d", &resposta);
	    if (resposta == 1) 
		{ 
		printf("\nIniciando jogo ...\n");
		
		 // codigo do jogo aqui
		 
		 int maximo = 43;
	int minimo = 0;
	char mapa[maximo][maximo];
	char escolha;
	char auxiliar;
	char auxiliar2;
	int i, j;
	
	for(i = minimo; i < maximo; i++)
	{
		for(j = minimo; j < maximo; j++)
		{
			if(i == 21 && j == 21)
			{
				mapa[i][j] = '&';
			}
			else if(i == minimo || i == maximo-1 || j == minimo || j == maximo-1)
			{
				mapa[i][j] = '*';
			}
			else if(i == 14 && j <= 14 || i <= 14 && i != 6 && i != 7 && j == 14)
			{
				mapa[i][j] = '*';
			}
			else if(i == 14 && j >= 28 || i <= 14 && i != 6 && i != 7 && j == 28)
			{
				mapa[i][j] = '*';
			}
			else if(i == 28 && j <= 14 || i >= 28 && i != 35 && i != 36 && j == 14)
			{
				mapa[i][j] = '*';
			}
			else if(i == 28 && j >= 28 || i >= 28 && i != 35 && i != 36 && j == 28)
			{
				mapa[i][j] = '*';
			}
			else if(i == 6 && j == 28 || i == 7 && j == 28)
			{
				mapa[i][j] = 'D';
			}
			else if(i == 6 && j == 14 || i == 7 && j == 14)
			{
				mapa[i][j] = 'D';
			}
			else if(i == 35 && j == 28 || i == 36 && j == 28)
			{
				mapa[i][j] = ' ';
			}
			else if(i == 35 && j == 14 || i == 36 && j == 14)
			{
				mapa[i][j] = 'D';
			}
			else if(i == 35 && j == 35)
			{
				mapa[i][j] = '@';
			}
			else if(i == 7 && j == 7)
			{
				mapa[i][j] = '@';
			}
			else
			{
				mapa[i][j] = ' ';
			}
		}
	}
	
	for(i = minimo; i < maximo; i++)
	{
		for(j = minimo; j < maximo; j++)
		{
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
	
	for(i = minimo; i < maximo; i++)
	{
		for(j = minimo; j < maximo; j++)
		{
			if(mapa[i][j] == '&')
			{
				printf("\n%d %d\n", i, j);
			}
		}
	}
	
	while(1)
	{	
		escolha = getch();
		
		if(escolha == 'i')
		{
			if(mapa[35][35] == '&')
			{
				mapa[6][14] = ' ';
				mapa[7][14] = ' ';
				mapa[5][13] = '=';
				mapa[8][13] = '=';
			}
			else if(mapa[7][7] == '&')
			{
				system("cls");
				printf("Fase 1 concluida!!!\n\n");
				sleep(1);
				system("pause");
				system("cls");
				printf("Iniciando Fase 2.\n\n");
				sleep(1);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				continue;
			}
		}
		
		if(escolha == 'w')
		{
			for(i = minimo; i < maximo; i++)
			{
				for(j = minimo; j < maximo; j++)
				{
					if(mapa[i][j] == '&')
					{
						if(mapa[i-1][j] == '*' || mapa[i-1][j] == 'D' || mapa[i-1][j] == '=')
						{
							continue;
						}
						else if(mapa[i-1][j] == '@')
						{
							auxiliar2 = mapa[i-1][j];
							mapa[i-1][j] = ' ';
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i-1][j];
							mapa[i-1][j] = auxiliar;
						}
						else if(auxiliar2 == '@')
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = auxiliar2;
							mapa[i-1][j] = auxiliar;
							auxiliar2 = ' ';
						}
						else
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i-1][j];
							mapa[i-1][j] = auxiliar;
						}
					}
				}
			}
		}
		
		if(escolha == 'a')
		{
			for(i = minimo; i < maximo; i++)
			{
				for(j = minimo; j < maximo; j++)
				{
					if(mapa[i][j] == '&')
					{
						if(mapa[i][j-1] == '*' || mapa[i][j-1] == 'D' || mapa[i][j-1] == '=')
						{
							continue;
						}
						else if(mapa[i][j-1] == '@')
						{
							auxiliar2 = mapa[i][j-1];
							mapa[i][j-1] = ' ';
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i][j-1];
							mapa[i][j-1] = auxiliar;
						}
						else if(auxiliar2 == '@')
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = auxiliar2;
							mapa[i][j-1] = auxiliar;
							auxiliar2 = ' ';
						}
						else
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i][j-1];
							mapa[i][j-1] = auxiliar;
						}
					}
				}
			}
		}
		
		if(escolha == 's')
		{
			for(i = maximo-1; i > minimo; i--)
			{
				for(j = maximo-1; j > minimo; j--)
				{
					if(mapa[i][j] == '&')
					{
						if(mapa[i+1][j] == '*' || mapa[i+1][j] == 'D' || mapa[i+1][j] == '=')
						{
							continue;
						}
						else if(mapa[i+1][j] == '@')
						{
							auxiliar2 = mapa[i+1][j];
							mapa[i+1][j] = ' ';
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i+1][j];
							mapa[i+1][j] = auxiliar;
						}
						else if(auxiliar2 == '@')
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = auxiliar2;
							mapa[i+1][j] = auxiliar;
							auxiliar2 = ' ';
						}
						else
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i+1][j];
							mapa[i+1][j] = auxiliar;
						}
					}
				}
			}
		}
		
		if(escolha == 'd')
		{
			for(i = maximo-1; i > minimo; i--)
			{
				for(j = maximo-1; j > minimo; j--)
				{
					if(mapa[i][j] == '&')
					{
						if(mapa[i][j+1] == '*' || mapa[i][j+1] == 'D' || mapa[i][j+1] == '=')
						{
							continue;
						}
						else if(mapa[i][j+1] == '@')
						{
							auxiliar2 = mapa[i][j+1];
							mapa[i][j+1] = ' ';
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i][j+1];
							mapa[i][j+1] = auxiliar;
						}
						else if(auxiliar2 == '@')
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = auxiliar2;
							mapa[i][j+1] = auxiliar;
							auxiliar2 = ' ';
						}
						else
						{
							auxiliar = mapa[i][j];
							mapa[i][j] = mapa[i][j+1];
							mapa[i][j+1] = auxiliar;
						}
					}
				}
			}
		}
		
		system("cls");
		
		for(i = minimo; i < maximo; i++)
		{
			for(j = minimo; j < maximo; j++)
			{
				printf("%c ", mapa[i][j]);
			}
			printf("\n");
		}
		
		for(i = minimo; i < maximo; i++)
		{
			for(j = minimo; j < maximo; j++)
			{
				if(mapa[i][j] == '&')
				{
					printf("\n%d %d\n\n", i, j);
				}
			}
		}
		
		if(auxiliar2 == '@')
		{
			printf("auxiliar2 = '@'\n\n");
		}
		else
		{
			printf("auxiliar2 = ' '\n\n");
		}
	}
		 
		  printf("Jogar novamente ? \n 1 - sim \n 2 - N�o "); 
		  scanf("%d", &resposta);
		  }
		  }
		  while(resposta == 1);
		  break;
		  
	case 2: printf(" Tutorial selecionado!\n"); 
			printf("Deseja abrir o tutorial? Digite (1-SIM) OU (2-NAO): "); 
			scanf("%dp", &resposta);
			 if (resposta == 1)
			  { 
			  	printf( "\n O jogo de aventura nome do jogo: retrata a hist�ria e o personagem principal em uma narrativa interativa,\n"
				"que geralmente envolve explora��o e resolu��o de quebra-cabe�as.\n"
			  	"O primeiro jogo de aventura foi o Colossal Cave Adventure, lan�ado em 1976, enquanto outros t�tulos not�veis incluem Zork,\n" 
			  	"King's Quest, The Secret of Monkey Island e Myst. Em seguida, � apresentado um jogo de aventura/puzzle com tr�s fases,\n"
				"em que o jogador deve se mover para coletar uma chave e abrir a porta para progredir. S�o fornecidos os comandos dispon�veis,\n"
			   	"bem como os s�mbolos utilizados, tais como paredes, chaves, portas abertas e fechadas, bot�es, espinhos,\n" 
			   	"teletransportes e monstros com diferentes n�veis de intelig�ncia e movimenta��o.\n");

				printf( "W: O jogador movimenta uma unidade para cima;");
				printf( "A: O jogador movimenta uma unidade para esquerda;");
				printf( "S: O jogador movimenta uma unidade para baixo;");
				printf( "D: O jogador movimenta uma unidade para direita;");
				printf( "I: O jogador interage com o objeto que est� em cima.");

				printf( "&: S�mbolo que representa o jogador.\n"
				" *: S�mbolo que representa uma parede, o jogador ao se movimentar n�o pode passar pela parede.\n"
				" @: S�mbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\n"
				" D: S�mbolo que representa a porta fechada.\n"
				" =: S�mbolo que representa a porta aberta quando o jogador interage com a chave.\n"
				" O: S�mbolo que representa um bot�o que o usu�rio pode interagir, o bot�o fica no ch�o e o jogador deve ficar em cima dele para poder interagir.\n"
				" #: S�mbolo que representa um espinho. A fase � reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada tr�s vezes, o jogo volta para o menu principal.\n"
				" >: S�mbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele � transportado para o outro e vice-versa.\n"
				" �: S�mbolo que representa o monstro n�vel 1. O mostro tem um movimento aleat�rio, logo, ele movimenta um bloco para cima ou para direita ou para esquerda ou para baixo. O mostro sempre faz uma movimenta��o depois do usu�rio se movimentar ou interagir com um objeto.\n"
				" K: S�mbolo que representa o monstro n�vel 2. O mostro n�vel dois tem uma intelig�ncia de se movimentar na dire��o do jogador. O    monstro n�o precisa saber desviar de obst�culos, ele sempre vai andar em linha reta em dire��o do jogador.\n"
				" \n");
			  
			 } 
				 break;
		  case 3:
		  printf(" Encerrando...\n");
		  
			    break;
			    
		default:
			
		  printf("Op�ao Invalida!\n");
				}
				} 
			while (opcao != 3);
				
return 0;
}
