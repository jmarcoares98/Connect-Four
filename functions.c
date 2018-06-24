#include "header.h"

void game_menu()
{
	printf("=========================================\n");
	printf("\nWelcome To Connect Four: Bonus Assignment\n");
	printf("\n=========================================\n\n");
	printf("Game Menu:\n");
	printf("[1] PLAY GAME w/ 2 PLAYERS\n");
	printf("[2] PLAY GAME w/ COMPUTER (NOT AI)\n");
	printf("[3] HOW TO PLAY\n");
	printf("[4] EXIT\n");
}

void game_rules()
{
	printf("\n=========================================\n");
	printf("It is a two player game, in this case you will be playing versus the computer\n");
	printf("You have your own checker and you will choose a column to drop it\n");
	printf("You can play with either another person or with the computer\n");
	printf("To win the game, you will need to have a connecting four in a row\n");
	printf("Ready to play?\n");
	system("pause");
	system("cls");
}

void init_board(Board board[][MAX_COL])
{
	int rows = 0, cols = 0;

	for (rows = 0; rows < MAX_ROW; ++rows)
	{
		for (cols = 0; cols< MAX_COL; ++cols)
		{
			board[rows][cols].symbol = EMPTY;
		}
	}
}

void print_board(Board board[][MAX_COL])
{
	int rows = 0, cols = 0;

	printf("   0  1  2  3  4  5  6\n\n");
	for (rows = 0; rows < MAX_ROW; rows++)
	{
		printf("%d ", rows);
		for (cols = 0; cols < MAX_COL; cols++)
		{
			printf(" %c ", board[rows][cols]);
		}
		putchar('\n');
		putchar('\n');
	}
}

int select_who_starts_first(void)
{
	Player random = You;
	random = (Player)rand() % 2; // 50/50 chance to whover plays first

	if (random == 0)
	{
		printf("You have been selected to play first\n");
	}
	else
	{
		printf("The Computer will make the move first\n");
	}
	system("pause");
	system("cls");
	return random;
}

void drop_down(Board board[][MAX_COL], Cell player)
{
	int row = 0, col = 0, exit = 0;

	printf("======================\n\n");
	print_board(board);
	printf("======================\n");

	while (exit != 1)
	{
		printf("Choose a column to drop down the piece!(0 - 6)\n");
		scanf("%d", &col);

		if (col > MAX_COL)
		{
			printf("INVALID INPUT\n");
			printf("Enter Column Again\n");
			system("pause");
			system("cls");
		}
		for (row = MAX_ROW; row >= 0; row--)
		{
			if (board[row][col].symbol == EMPTY)
			{
				board[row][col].symbol = player.symbol;
				exit = 1;
				break;
			}
		}
	}
}

void drop_down_computer(Board board[][MAX_COL])
{
	int row = 0; int col = 0; int exit = 0;
	int n = MAX_COL;

	printf("======================\n\n");
	print_board(board);
	printf("======================\n");

	while (exit != 1)
	{
		col = (rand() % n);
		for (row = MAX_ROW; row >= 0; row--)
		{
			if (board[row][col].symbol == EMPTY)
			{
				board[row][col].symbol = COMPUTER;
				exit = 1;
				break;
			}
		}
		if (board[row] != EMPTY)
		{
			break;
		}
	}
}

int check_winner_vertical(Board board[][MAX_COL], Cell player)
{
	int winner = 0, check = 0;
	int row = 5, col = 0;
	int i = 0;

	for (col = 6; col >= 0; col--)
	{
		for (row = 5; row >= 2; row--)
		{
			for (i = 0; i < 4; i++)
			{
				if (board[row - i][col].symbol == player.symbol)
				{
					check += 1;
				}
				if (check == 4)
				{
					winner = 1;
					return winner;
				}
			}
			if (check < 4)
			{
				check = 0;
			}
		}
	}
	return 0;
}

int check_winner_horizontal(Board board[][MAX_COL], Cell player)
{
	int winner = 0, check = 0;
	int row = 0, col = 0;
	int i = 0;

	for (row = 5; row >= 0; row--)
	{
		for (col = 6; col >= 3; col--)
		{
			for (i = 0; i < 4; i++)
			{
				if (board[row][col - i].symbol == player.symbol)
				{
					check += 1;
				}
				if (check == 4)
				{
					winner = 1;
					return winner;
				}
			}
			if (check < 4)
			{
				check = 0;
			}
		}
	}

	return 0;
}

int check_winner_diagonal(Board board[][MAX_COL], Cell player)
{
	int winner = 0, check = 0;
	int row = 0, col = 0;
	int i = 0;

	for (col = 0; col <= 3; col++)
	{
		for (row = 5; row > 2; row--)
		{
			for (i = 0; i < 4; i++)
			{
				if (board[row - i][col + i].symbol == player.symbol)
				{
					check += 1;
				}
				if (check == 4)
				{
					winner = 1;
					return winner;
				}

			}
			if (check < 4)
			{
				check = 0;
			}
		}
	}

	for (col = 6; col >= 3; col--)
	{
		for (row = 5; row >= 3; row--)
		{
			for (i = 0; i < 4; i++)
			{
				if (board[row - i][col - i].symbol == player.symbol)
				{
					check += 1;
				}
				if (check == 4)
				{
					winner = 1;
					return winner;
				}

			}
			if (check < 4)
			{
				check = 0;
			}
		}
	}

}
