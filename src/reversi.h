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
#include "game.h"
#include "scoreboard.h"
#include "utility.h"

#ifndef REVERSI_H
#define REVERSI_H

int mainMenu();
int highScores();
void fgets_switch(int *inputNumber);
void read_rest_of_line(void);
void init_scoreboard(score scores[MAX_SCORES]);
void display_scores(score scores[MAX_SCORES]);
struct player *play_game(struct player *first, struct player *second);
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player *winner);

#endif
