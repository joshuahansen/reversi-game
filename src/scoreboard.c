/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "scoreboard.h"
#include "gameboard.h"


/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES])
{
	int count;
	for(count = ZERO; count < MAX_SCORES; count++)
	{
		strcpy(scores[count].name, "");
		scores[count].score = ZERO;
	}
}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score 
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner)
{
	int count;
	score temp[TEMP_SIZE];
/*if the winners score is greater thant the last player in the high scores they are added to the high scores*/
	if((*winner).score > scores[MAX_SCORES - PREVIOUS].score)
	{
		scores[MAX_SCORES - PREVIOUS].score = (*winner).score;
		strcpy(scores[MAX_SCORES - PREVIOUS].name, (*winner).name);
	}
/*loop through the array cheacking the score before the winners to see if its lower. if it is swap the scores and more onto the next one*/
	for(count = MAX_SCORES - SECOND_LAST; count >= ZERO; count--)
	{
		if(scores[count].score < scores[count + NEXT].score)
		{
			temp[FIRST_TEMP].score = scores[count].score;
			strcpy(temp[FIRST_TEMP].name, scores[count].name);
			scores[count].score = scores[count+NEXT].score;
			strcpy(scores[count].name, scores[count+NEXT].name);
			scores[count+NEXT].score = temp[FIRST_TEMP].score;
			strcpy(scores[count+NEXT].name, temp[FIRST_TEMP].name);
		}
		else
		{
			break;
		}
	}
	return TRUE;
}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES])
{
	int count;

	printf("=====================\n");
	printf("Reversi - High Scores\n");
	printf("=====================\n");
	printf("----------------------------\n");
	printf("%-21s%s\n", "Name", "| Score");
	printf("----------------------------\n");
/*display the score bored but dont display the scores of zero as the scoreboard is initiated to a blank string and a score of zero*/
	for(count = ZERO; count < MAX_SCORES; count++)
	{
		if(scores[count].score == ZERO)
		{
			continue;
		}
		else
		{
			printf("%-21s|  %d\n", scores[count].name, scores[count].score);
		}
	}

}

