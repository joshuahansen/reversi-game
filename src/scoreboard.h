/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "shared.h"
#include "player.h"
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#define MAX_SCORES 10
/*Size of the temp array*/
#define TEMP_SIZE 1
/*first element of the temp array*/
#define FIRST_TEMP 0
/*previous element in the array*/
#define PREVIOUS 1
/*next element in the array*/
#define NEXT 1
/*use to find the second last element in the array*/
#define SECOND_LAST 2
typedef struct player score;

void init_scoreboard(score scores[MAX_SCORES]);
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner);
void display_scores(score scores[MAX_SCORES]);
#endif /* ifndef SCOREBOARD_H */
