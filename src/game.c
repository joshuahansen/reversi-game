/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required 
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random 
 * number generator, that kind of thing. 
 *
 * Next, you should set the initial player - the initial player is the player 
 * whose token was set by initialisation to RED. 
 *
 * Next, you will need to manage the game loop in here. In each loop of the 
 * game, you should display the game board, including player scores 
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score 
 * for each player you will calculate their score and store it and then you 
 * will need to swap the current player and other player 
 * using the swap_player() function. 
 * 
 * A game will end when either player presses enter or ctrl-d on a newline. 
 * 
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 **/

struct player * play_game(struct player * first, struct player * second)
{
	game_board board;
	enum cell token, token2;
	struct player * current, *other, *winner, draw, *drawpnt;
	int num;
	
	BOOLEAN move;
	drawpnt = &draw;
	/*generate a random number either 1 or 2 and set the token varable to that value*/
	num = rand() % NUM_COLORS + ONE;
	if(num == ONE)
	{
		token = RED;
		token2 = BLUE;
	}
	else if(num == 2)
	{
		token = BLUE;
		token2 = RED;
	}
	
	/*initilise player one, two and draw*/
	init_game_board(board);
	current = first;
	other = second;
	init_first_player(current, &token);
	init_second_player(other, &token2);
	init_draw_player(drawpnt);
	/*swap current players so player with the RED token always goes first*/
	if((*other).token == RED)
	{
		swap_players(&current, &other);
	}
	/*run a loop while players enter moves and not press the Enter*/
	do
	{
		display_board(board, first, second);
		move = make_move(current, other, board);
		if(move == FALSE)
		{
			break;
		}
		/*calculate each players score at the end of there turn before swapping players*/
		(*current).score = game_score(board, (*current).token);
		(*other).score = game_score(board, (*other).token);
		swap_players(&current, &other);
	}while(move != FALSE);
	/*check for highest score and set winner pointer to that player*/
	if((*first).score > (*second).score)
	{
		printf("Winner is %s with a score of %d\n", (*first).name, (*first).score);
		winner = first;
	}
	else if((*second).score > (*first).score)
	{
		printf("Winnner is %s with a score of %d\n", (*second).name, (*second).score);
		winner = second;
	}
	else
	{
		printf("Game was a draw\n");
		winner = drawpnt;
	}

	return winner;
}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 **/
BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token, enum direction dir, unsigned captured_pieces)
{
	int i;

/*if the direction has been set to a value apply the move to that direction for the number of pieces been captured*/
	if(dir == NORTH)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y--][x] = player_token;
		}
	}
	else if(dir == NORTH_EAST)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y--][x++] = player_token;
		} 
	}
	else if(dir == EAST)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y][x++] = player_token;
		}
	}
	else if(dir == SOUTH_EAST)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y++][x++] = player_token;
		}
	}
	else if(dir == SOUTH)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y++][x] = player_token;
		}
	}
	else if(dir == SOUTH_WEST)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y++][x--] = player_token;
		}
	}
	else if(dir == WEST)
	{	
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y][x--] = player_token;
		}
	}
	else if(dir == NORTH_WEST)
	{
		for(i = ZERO; i < captured_pieces + ONE_CELL; i++)
		{
			board[y--][x--] = player_token;
		}
	}
	
	return TRUE;
}

/**
 * simply count up how many locations contain the player_token 
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token)
{
	int score = ZERO;
	int x, y;
	for(y = ZERO; y < BOARD_HEIGHT; y++)
		for(x = ZERO; x < BOARD_WIDTH; x++)
		{
			if(board[y][x] == player_token)
			{
				score += 1;
			}
		}	
	return score;
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player ** first, struct player ** second)
{
	struct player *temp = *first;
	*first = *second;
	*second = temp;
}
/*Initalise a draw player so if the game is a draw neither players scores get added to the scoreboard*/
BOOLEAN init_draw_player(struct player *drawpnt)
{
	strcpy((*drawpnt).name, "");
	(*drawpnt).score = ZERO;
	(*drawpnt).token = BLANK;
	
	return TRUE;
}
