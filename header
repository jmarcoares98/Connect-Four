#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define MAX_ROW 6
#define MAX_COL 7
#define PLAYER 'X'
#define PLAYER2 'O'
#define COMPUTER '0'
#define EMPTY '='

typedef enum player
{
	You = 0,
	Bot = 1
}Player;

typedef struct cell
{
	char symbol;
	int row;
	int col;
} Cell;


typedef struct board
{
	char symbol;
	int row;
	int col;
}Board;

void game_menu();
void game_rules();
void init_board(Board board[][MAX_COL]);
void print_board(Board board[][MAX_COL]);
int select_who_starts_first(void);
void drop_down(Board board[][MAX_COL], Cell player);
void drop_down_computer(Board board[][MAX_COL]);
int check_winner_vertical(Board board[][MAX_COL], Cell player);
int check_winner_horizontal(Board board[][MAX_COL], Cell player);
int check_winner_vertical(Board board[][MAX_COL], Cell player);
int check_winner_diagonal(Board board[][MAX_COL], Cell player);
