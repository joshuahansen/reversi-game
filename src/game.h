/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include <time.h>
#include "shared.h"
#include "player.h"
#include "gameboard.h"


#ifndef GAME_H
#define GAME_H

void init_game_board(game_board board);
void display_board(game_board board, struct player *first, struct player *second);
BOOLEAN init_first_player(struct player *first, enum cell *token);
BOOLEAN init_secoen_player(struct player *computer, enum cell token);
BOOLEAN init_draw_player(struct player *drawpnt);
BOOLEAN make_move(struct player *human, struct player *other, game_board board);
void swap_players(struct player ** first, struct player ** second);
unsigned game_score(game_board board, enum cell player_token);

struct player * play_game(struct player * human, struct player * computer);
BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token, enum direction dir, unsigned capture_pieces);
unsigned game_score(game_board board, enum cell player_token);
void swap_players(struct player ** first, struct player ** second);

#endif /* ifndef GAME_H */
