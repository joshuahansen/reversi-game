/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "player.h"
#include "game.h"


/**
 * These two functions initialise the player structure at the beginning of the 
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player() 
 * function you should then select a color at random for this player using the 
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/

/*initalise first player and set each characteristic of the player struct*/
BOOLEAN init_first_player(struct player *first, enum cell *token)
{
	char firstName[NAMELEN+EXTRACHARS];
	/*while the player's name is not correct keep prompting the player to enter there name*/	
	do
	{
		printf("Enter Player 1's Name: ");
	}while(fgets_name(firstName) != TRUE);
	/*set the first player's details*/
	strcpy((*first).name, firstName);
	(*first).token = *token;
	(*first).score = RESET;
	return TRUE;
}
/*initialise second player and set each characteristic of the player struct*/
BOOLEAN init_second_player(struct player *computer, enum cell *token)
{
	char computerName[NAMELEN + EXTRACHARS];
	
	do
	{	
		printf("Enter Player 2's Name: ");
	}while(fgets_name(computerName) != TRUE);
	
	strcpy((*computer).name, computerName);
	(*computer).token = *token;
	(*computer).score = RESET;
	return TRUE;
	
}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by 
 * surrounding a sequence of one or more enemy pieces with two pieces of our 
 * own: one being the new piece to be placed and the other a piece already 
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player * human, struct player *other, game_board board)
{
	unsigned xCoordinate, yCoordinate, *xPointer, *yPointer;
	int move;
	BOOLEAN valid;
	

	xPointer = &xCoordinate;
	yPointer = &yCoordinate;
	/*while imputs an invalid move and the input is not control-d or enter to exit. loops asking for a x and y coordinate */
	do
	{
		printf("It is %s's turn\n", (*human).name);
		printf("Please enter x and y coordinates separated by a comma: ");
		move = fgets_move(xPointer, yPointer);
		if(move == VALIDINPUT)
		{
			valid = check_all(xCoordinate - ONE_CELL, yCoordinate - ONE_CELL, board, human, other);
		}
	}while(valid != TRUE && move != EXIT);
/*check all returns true if the player has entered a correct move*/
	if(valid == TRUE)
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}

}
/*fgets funtion to check the validation of the input from the user*/
BOOLEAN fgets_name(char *name)
{
	fgets(name, NAMELEN + EXTRACHARS, stdin);

	if(name[strlen(name) - 1] != '\n')
	{
		printf("\n Name was to long. Please enter a shorter name\n");
		read_rest_of_line();
		return FALSE;
	}
	else if(strcmp(name, "\n") == 0)
	{
		printf("Name was to short\n");
		return FALSE;
	}
	else
	{
		name[strlen(name) - 1] = '\0';
		return TRUE;
	}
}
/*read players input and return an int value depending if the move is valid or exit*/
int fgets_move(unsigned *xPointer, unsigned *yPointer)
{
	char move[MOVELEN + EXTRACHARS];
	char *commaToken;
	int count = RESET, i = RESET;
	int moveCoordinates[2];

	if(fgets(move, sizeof(move),stdin) == NULL)
	{
		printf("EXIT GAME\n");
		return EXIT;
	}
	else
	{
		/*if enter is pressed with no input before then the game exits*/
		if(strcmp(move, "\n") == 0)
		{
			printf("EXIT GAME!\n");
			return EXIT;
		}
		/*if more than 2 coordinates seperated by a comma are entered then prompts user move was to long and allows them to try again*/
		else if(move[strlen(move) - 1] != '\n')
		{
			printf("\n Move was to long. Please enter a x and y coordinate seperated by a comma\n");
			read_rest_of_line();
			return ERROR;
		}
		/*tokenize the input and change into integers to all them to be used to set the token position*/
		else
		{
			commaToken = strtok(move, ",");
			while(commaToken != NULL)
			{
				char *pnt;
				i = strtol(commaToken, &pnt, 0);
				moveCoordinates[count] = i;
				count++;
				commaToken = strtok(NULL, ",");
			}
			*xPointer = moveCoordinates[0];
			*yPointer = moveCoordinates[1];
			/*if the coordinates are outside the board size return an error asking the user to enter a correct input*/
			if(*xPointer > 8 || *yPointer > 8 || *xPointer < 1 || *yPointer < 1)
			{
				printf("Move was out of bounds. Please enter a coordinate on the board\n");
				return ERROR;
			}
			/*return valid input if the move can be entered onto the board*/
			else
			{
				return VALIDINPUT;
			}	
		}
	}
}

/*check the cells north of the current position for a valid move. set direction to north and return true if pieces can be captured*/
BOOLEAN check_north(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(yCoordinate == TOP_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate - ONE_CELL][xCoordinate] == (*other).token)
	{
		while(board[yCoordinate - ONE_CELL][xCoordinate] != (*current).token && board[yCoordinate - ONE_CELL][xCoordinate] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate--;
		}
		if(board[yCoordinate - ONE_CELL][xCoordinate] == (*current).token)
		{
			*dir = NORTH;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
/*chech north east for valid move*/
BOOLEAN check_north_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(yCoordinate == TOP_CELL ||  xCoordinate == RIGHT_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate - ONE_CELL][xCoordinate + ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate - ONE_CELL][xCoordinate + ONE_CELL] != (*current).token && board[yCoordinate - ONE_CELL][xCoordinate + ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate--;
			xCoordinate++;
		}
		if(board[yCoordinate - ONE_CELL][xCoordinate + ONE_CELL] == (*current).token)
		{
			*dir = NORTH_EAST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
/*check east of entered coordinates for a valid move*/
BOOLEAN check_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(xCoordinate == RIGHT_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate][xCoordinate + ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate][xCoordinate + ONE_CELL] != (*current).token && board[yCoordinate][xCoordinate + ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			xCoordinate++;
		}
		if(board[yCoordinate][xCoordinate + ONE_CELL] == (*current).token)
		{
			*dir = EAST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*check south east of coordinate for a valid move*/
BOOLEAN check_south_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir) 
{
	if(yCoordinate == BOTTOM_CELL || xCoordinate == RIGHT_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate + ONE_CELL][xCoordinate + ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate + ONE_CELL][xCoordinate + ONE_CELL] != (*current).token && board[yCoordinate + ONE_CELL][xCoordinate + ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate++;
			xCoordinate++;
		}
		if(board[yCoordinate + ONE_CELL][xCoordinate + ONE_CELL] == (*current).token)
		{
			*dir = SOUTH_EAST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*check south for valid moves. count the numbered of captured pieces*/
BOOLEAN check_south(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(yCoordinate == BOTTOM_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate + ONE_CELL][xCoordinate] == (*other).token)
	{
		while(board[yCoordinate + ONE_CELL][xCoordinate] != (*current).token && board[yCoordinate + ONE_CELL][xCoordinate] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate++;
		}
		if(board[yCoordinate + ONE_CELL][xCoordinate] == (*current).token)
		{
			*dir = SOUTH;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*check south west*/
BOOLEAN check_south_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(yCoordinate == BOTTOM_CELL || xCoordinate == LEFT_CELL)
	{
		return FALSE;
	}
	if(board[yCoordinate + ONE_CELL][xCoordinate - ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate + ONE_CELL][xCoordinate - ONE_CELL] != (*current).token && board[yCoordinate + ONE_CELL][xCoordinate - ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate++;
			xCoordinate--;
		}
		if(board[yCoordinate + ONE_CELL][xCoordinate - ONE_CELL] == (*current).token)
		{
			*dir = SOUTH_WEST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*check west for valid moves*/
BOOLEAN check_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if( xCoordinate == LEFT_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate][xCoordinate - ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate][xCoordinate - ONE_CELL] != (*current).token && board[yCoordinate][xCoordinate - ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			xCoordinate--;
		}
		if(board[yCoordinate][xCoordinate - ONE_CELL] == (*current).token)
		{
			*dir = WEST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*check north west for valid move*/
BOOLEAN check_north_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir)
{
	if(yCoordinate == TOP_CELL || xCoordinate == LEFT_CELL)
	{
		return FALSE;
	}
	else if(board[yCoordinate - ONE_CELL][xCoordinate - ONE_CELL] == (*other).token)
	{
		while(board[yCoordinate - ONE_CELL][xCoordinate -ONE_CELL] != (*current).token && board[yCoordinate - ONE_CELL][xCoordinate - ONE_CELL] != BLANK)
		{
			*captured_pieces_pnt += ONE_CELL;
			yCoordinate--;
			xCoordinate--;
		}
		if(board[yCoordinate - ONE_CELL][xCoordinate - ONE_CELL] == (*current).token)
		{
			*dir = NORTH_WEST;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

/*go through all checks to see if and=y moves are okay. apply the move if there is a valid move and add one to the valid move counter. if no valid moves have been made return false otherwise return true*/
BOOLEAN check_all(unsigned xCoordinate, unsigned yCoordinate, game_board board, struct player *current, struct player *other)
{
	int validMove = RESET;
	unsigned captured_pieces = RESET;
	unsigned *captured_pieces_pnt = &captured_pieces;
	enum direction dir;
	enum direction *dir_pnt = &dir;
	
/*check to see if the space on the board is blank. if it is check for moves*/
	if(board[yCoordinate][xCoordinate] != BLANK)
	{
		return FALSE;
	}
	else
	{	
		/*check all the moves for a valid choice then apply the move. after the check reset the captured pieces to 0*/
		if(check_north(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;
	
		if(check_north_east(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;
		
		if(check_east(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;
		
		if(check_south_east(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;
	
		if(check_south(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;

		if(check_south_west(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;

		if(check_west(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;	
	
		if(check_north_west(xCoordinate, yCoordinate, board, captured_pieces_pnt, current, other, dir_pnt) == TRUE)
		{
			apply_move(board, yCoordinate, xCoordinate, (*current).token, dir, captured_pieces);
			validMove += 1;
		}
		captured_pieces = RESET;	

		if(validMove == NOVALIDMOVE)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
}


