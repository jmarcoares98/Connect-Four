#include "header.h"

int main(void)
{
	int turn = 0, exit = 0, menu = 0, again = 0, comp = 0, play = 0;
	int player_win = 0, player2_win = 0, comp_win = 0;
	Board game_board[MAX_ROW][MAX_COL] = { '\0' };
	Cell player = { '/0' };
	Cell player2 = { '/0' };
	Cell computer = { '/0' };

	player.symbol = PLAYER;
	player2.symbol = PLAYER2;
	computer.symbol = COMPUTER;


	srand((unsigned int)time(NULL));

	init_board(game_board);
	while (exit != 1)
	{
		game_menu();
		printf("> ");
		scanf("%d", &menu);
		system("cls");
		if (menu == 4)
		{
			printf("Goodbye!\n");
			system("pause");
			system("cls");
			exit = 1;
		}
		if (menu == 3)
		{
			game_menu();
			game_rules();
			printf("> ");
			scanf("%d", &menu);
			system("cls");
		}
		system("cls");
		if (menu == 2)
		{
			printf("CONNECT FOUR\n");
			printf("======================\n\n");
			print_board(game_board);
			printf("======================\n");
			turn = select_who_starts_first();
			while (comp != 1)
			{
				switch (turn)
				{
				case 0:
					printf("PLAYER TURN\n");
					drop_down(game_board, player);
					system("cls");
					printf("PLAYER TURN\n");
					printf("======================\n\n");
					print_board(game_board);
					printf("======================\n");
					printf("The piece has been placed\n");
					system("pause");
					system("cls");
					player_win = check_winner_vertical(game_board, player);
					if (player_win == 1)
					{
						printf("YOU WON!!!\n");
						system("pause");
						break;
					}
					player_win = check_winner_horizontal(game_board, player);
					if (player_win == 1)
					{
						printf("YOU WON!!!\n");
						system("pause");
						break;
					}
					player_win = check_winner_diagonal(game_board, player);
					if (player_win == 1)
					{
						printf("YOU WON!!!\n");
						system("pause");
						break;
					}
					turn = 1;
				case 1:
					printf("COMPUTER TURN\n");
					drop_down_computer(game_board);
					system("cls");
					printf("COMPUTER TURN\n");
					printf("======================\n\n");
					print_board(game_board);
					printf("======================\n");
					printf("Computer's piece has been placed\n");
					system("pause");
					system("cls");
					comp_win = check_winner_vertical(game_board, computer);
					if (comp_win == 1)
					{
						printf("YOU LOSE!!!\n");
						system("pause");
						break;
					}
					comp_win = check_winner_horizontal(game_board, computer);
					if (comp_win == 1)
					{
						printf("YOU LOSE!!!\n");
						system("pause");
						break;
					}
					comp_win = check_winner_diagonal(game_board, computer);
					if (comp_win == 1)
					{
						printf("YOU LOSE!!!\n");
						system("pause");
						break;
					}
					turn = 0;
				}

				if (player_win == 1 || comp_win == 1)
				{
					system("cls");
					printf("Do you want to play again?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");
					printf("> ");
					scanf("%d", &again);
					system("cls");
					if (again == 2)
					{
						comp = 1;
					}
					if (again == 1)
					{
						player_win = 0;
						comp_win = 0;
						init_board(game_board);
						printf("CONNECT FOUR\n");
						printf("======================\n\n");
						print_board(game_board);
						printf("======================\n");
						turn = select_who_starts_first();
					}
				}
			}
		}

		if (menu == 1)
		{
			printf("CONNECT FOUR\n");
			printf("======================\n\n");
			print_board(game_board);
			printf("======================\n");
			printf("Player 1 Starts first\n");
			system("pause");
			system("cls");
			while (play != 1)
			{
				switch (turn)
				{
				case 0:
					printf("PLAYER 1 TURN\n");
					drop_down(game_board, player);
					system("cls");
					printf("PLAYER 1 TURN\n");
					printf("======================\n\n");
					print_board(game_board);
					printf("======================\n");
					printf("Player 1 piece has been placed\n");
					system("pause");
					system("cls");
					player_win = check_winner_vertical(game_board, player);
					if (player_win == 1)
					{
						printf("PLAYER 1 WON!!!\n");
						system("pause");
						break;
					}
					player_win = check_winner_horizontal(game_board, player);
					if (player_win == 1)
					{
						printf("PLAYER 1 WON!!!\n");
						system("pause");
						break;
					}
					player_win = check_winner_diagonal(game_board, player);
					if (player_win == 1)
					{
						printf("PLAYER 1 WON!!!\n");
						system("pause");
						break;
					}
					turn = 1;
				case 1:
					printf("PLAYER 2 TURN\n");
					drop_down(game_board, player2);
					system("cls");
					printf("PLAYER 2 TURN\n");
					printf("======================\n\n");
					print_board(game_board);
					printf("======================\n");
					printf("Player 2 piece has been placed\n");
					system("pause");
					system("cls");
					player2_win = check_winner_vertical(game_board, player2);
					if (player2_win == 1)
					{
						printf("PLAYER 2 WON!!!\n");
						system("pause");
						break;
					}
					player2_win = check_winner_horizontal(game_board, player2);
					if (player2_win == 1)
					{
						printf("PLAYER 2 WON!!!\n");
						system("pause");
						break;
					}
					player2_win = check_winner_diagonal(game_board, player2);
					if (player2_win == 1)
					{
						printf("PLAYER 2 WON!!!\n");
						system("pause");
						break;
					}
					turn = 0;
				}

				if (player_win == 1 || player2_win == 1)
				{
					system("cls");
					printf("Do you want to play again?\n");
					printf("[1] YES\n");
					printf("[2] NO\n");
					printf("> ");
					scanf("%d", &again);
					system("cls");
					if (again == 2)
					{
						play = 1;
					}
					if (again == 1)
					{
						player_win = 0;
						comp_win = 0;
						init_board(game_board);
						printf("CONNECT FOUR\n");
						printf("======================\n\n");
						print_board(game_board);
						printf("======================\n");
						printf("Playing again...\n");
						system("pause");
						system("cls");
					}
				}
			}
		}
	}
	return 0;
}
