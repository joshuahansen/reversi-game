/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "reversi.h"

/**
 * the hear of the program. The main() function in particular should 
 * manage the main menu for the program.
 **/
#define MENU_SELECTION 1


int main(void)
{
	score scrboard[MAX_SCORES];
	struct player human, computer, *winner = NULL;
	struct player *firstpnt = &human, *secondpnt = &computer;
    /* initialise the scoreboard */
	
	int inputNumber;
	init_scoreboard(scrboard);
/*run a loop of the main menu until 3 has been pressed then exit the program*/
	do
	{
		mainMenu();
		fgets_switch(&inputNumber);

		switch(inputNumber)
		{
			case 1:
			{
				printf("\n");
				printf("Play a game\n");
				printf("===========\n");
				winner = play_game(firstpnt, secondpnt);
				add_to_scoreboard(scrboard, winner);
				break;
			}
			case 2:
			{
				display_scores(scrboard);	
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				printf("\n");
				printf("Please enter a correct choice\n");
				break;
			}
		}
	}while(inputNumber != 3);
	
	printf("\n");
	printf("Exit System\n");
    /* in a loop: display the main menu */

    /* get the user's selection from the main menu */

    /* perform the requested task */
            /* play a game and add the winner to the scoreboard */    
        
            /* display scores */
            /* quit the program */
    return EXIT_SUCCESS;
}

/*function to display the main menu options*/
int mainMenu(void)
{
	printf("\n");
	printf("Welcome to Reversi!\n");
	printf("===================\n");
	printf("Select an option:\n");
	printf("1.\tPlay a game\n");
	printf("2.\tDisplay High Scores\n");
	printf("3.\tQuit the program\n");
	printf("Please enter your choice: ");
	
	return 0;
}
/*fgets functon that reads an input and checks to make sure input is valid before returning the integer*/
void fgets_switch(int *inputNumber)
{
	
	char input[MENU_SELECTION + EXTRACHARS];
	char * inputPointer;


	fgets(input, sizeof(input), stdin);

	if(input[strlen(input) - 1] != '\n')
	{
		printf("\nSelection was too long please only select 1, 2 or 3.");
		read_rest_of_line();
	}
	else
	{
		input[strlen(input) - 1] = '\0';
		*inputNumber = strtol(input, &inputPointer, 10);
	}
}
