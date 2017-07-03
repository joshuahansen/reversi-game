/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "gameboard.h"
#include "player.h"


/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens
 **/

void init_game_board(game_board board)
{

	int y, x;
	/*loop through the array setting the middle four cells to defualt starting positions*/ 
	for(y = ZERO; y < BOARD_HEIGHT; y++)
	{
		for( x = ZERO; x < BOARD_WIDTH; x++)
		{
			if(y == TOP_Y && x == LEFT_X)
			{
				board[y][x] = RED;
			}
			else if(y == TOP_Y && x == RIGHT_X)
			{
				board[y][x] = BLUE;
			}
			else if(y == BOTTOM_Y && x == LEFT_X)
			{
				board[y][x] = BLUE;
			}
			else if(y == BOTTOM_Y && x == RIGHT_X)
			{
				board[y][x] = RED;
			}
			else
			{
				board[y][x] = BLANK;
			}

		}
	}
	
}

/**
 * display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification. 
 **/
void display_board(game_board board, struct player * first,
                   struct player * second)
{
	int y, x;
	/*check to see which player has the red token then print the top heading accordanly*/
	if((*first).token == RED)
	{		
		printf("Player One's Details\n");
		printf("--------------------\n");
		printf("Name: %s\tScore:  %d\tToken Color: %s0%s\n",(*first).name, (*first).score, COLOR_RED, COLOR_RESET);
		printf("----------------------------------------------------\n");
		printf("Player Two's Details\n");
		printf("--------------------\n");
		printf("Name: %s\tScore: %d\tToken Color: %s0%s\n", (*second).name, (*second).score, COLOR_BLUE, COLOR_RESET);
		printf("----------------------------------------------------\n");
	}
	else if((*first).token == BLUE)
	{
		printf("Player One's Details\n");
		printf("--------------------\n");
		printf("Name: %s\tScore:  %d\tToken Color: %s0%s\n",(*first).name, (*first).score, COLOR_BLUE, COLOR_RESET);
		printf("----------------------------------------------------\n");
		printf("Player Two's Details\n");
		printf("--------------------\n");
		printf("Name: %s\tScore: %d\tToken Color: %s0%s\n", (*second).name, (*second).score, COLOR_RED, COLOR_RESET);
		printf("----------------------------------------------------\n");
	}

/*print the board to the specified dimentions. changing token colors to RED or BLUE where needed*/
	printf("%-5s%-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", " ", "1", "2", "3", "4", "5", "6", "7", "8");
	border();
	for(y = ZERO; y < BOARD_HEIGHT; y++)
	{
		printf(" %d |", y + ONE);
/*do through the bame board printing out the RED tokens and BLUE tokens leaving any cell with BLANK printed empty*/
		for(x = ZERO; x < BOARD_WIDTH; x++)
		{
			if(board[y][x] == RED)
			{
				printf(" %s%d%s ", COLOR_RED, MARKER, COLOR_RESET);
				printf("|");
			}
			else if(board[y][x] == BLUE)
			{
				printf(" %s%d%s ", COLOR_BLUE, MARKER, COLOR_RESET);
				printf("|");
			}
			else if(board[y][x] == BLANK)
			{
				printf("   |");
			}
		}
		printf("\n");
		innerBorder();
	}
	border();
}
/*Main boarder loop*/
void border(void)
{
	int count;
	for( count = ZERO; count < BORDER_SIZE; count++)
	{
		printf("=");
	}
	printf("\n");
}
/*inner boarder loop. horizontal lines*/
void innerBorder(void)
{
	int count;
	for( count = ZERO; count < BORDER_SIZE; count++)
	{
		printf("-");
	}
	printf("\n");
}
