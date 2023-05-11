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
		 
		  printf("Jogar novamente ? \n 1 - sim \n 2 - Não "); 
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
			  	printf( "\n O jogo de aventura nome do jogo: retrata a história e o personagem principal em uma narrativa interativa,\n"
				"que geralmente envolve exploração e resolução de quebra-cabeças.\n"
			  	"O primeiro jogo de aventura foi o Colossal Cave Adventure, lançado em 1976, enquanto outros títulos notáveis incluem Zork,\n" 
			  	"King's Quest, The Secret of Monkey Island e Myst. Em seguida, é apresentado um jogo de aventura/puzzle com três fases,\n"
				"em que o jogador deve se mover para coletar uma chave e abrir a porta para progredir. São fornecidos os comandos disponíveis,\n"
			   	"bem como os símbolos utilizados, tais como paredes, chaves, portas abertas e fechadas, botões, espinhos,\n" 
			   	"teletransportes e monstros com diferentes níveis de inteligência e movimentação.\n");

				printf( "W: O jogador movimenta uma unidade para cima;");
				printf( "A: O jogador movimenta uma unidade para esquerda;");
				printf( "S: O jogador movimenta uma unidade para baixo;");
				printf( "D: O jogador movimenta uma unidade para direita;");
				printf( "I: O jogador interage com o objeto que está em cima.");

				printf( "&: Símbolo que representa o jogador.\n"
				" *: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.\n"
				" @: Símbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.\n"
				" D: Símbolo que representa a porta fechada.\n"
				" =: Símbolo que representa a porta aberta quando o jogador interage com a chave.\n"
				" O: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.\n"
				" #: Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.\n"
				" >: Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.\n"
				" ¬: Símbolo que representa o monstro nível 1. O mostro tem um movimento aleatório, logo, ele movimenta um bloco para cima ou para direita ou para esquerda ou para baixo. O mostro sempre faz uma movimentação depois do usuário se movimentar ou interagir com um objeto.\n"
				" K: Símbolo que representa o monstro nível 2. O mostro nível dois tem uma inteligência de se movimentar na direção do jogador. O    monstro não precisa saber desviar de obstáculos, ele sempre vai andar em linha reta em direção do jogador.\n"
				" \n");
			  
			 } 
				 break;
		  case 3:
		   printf("É com tristeza que anunciamos que Dungeon Crawler está\nprestes a fechar suas portas. Sabemos que você passou muitas horas explorando \nmasmorras, derrotando monstros e encontrando tesouros incríveis.\nEsperamos que esta experiência tenha proporcionado momentos memoráveis de\nmuita diversão. Ficamos honrados em tê-lo(a) em nossa comunidade\nde aventureiros.");
		  printf("\nAtenciosamente,\nEquipe Dungeon Crawler.\n");
		  printf("\nEncerrando...");
		  
			    break;
			    
		default:
			
		  printf("Opçao Invalida!\n");
				}
				} 
			while (opcao != 3);
				
return 0;
}
