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
#include "gameboard.h"
#include "utility.h"

#ifndef PLAYER_H
#define PLAYER_H

/* the maximum length of a player name */
#define NAMELEN 20
/*Maximum length of move input*/
#define MOVELEN 3
/*value returned if move is valid*/
#define VALIDINPUT 0
/*value returned if game wants to be exited*/
#define EXIT 1
/*value returend if the input was incorrect*/
#define ERROR 2

#define NOVALIDMOVE 0
/*left most cell in the array*/
#define LEFT_CELL 0
/*top most value of the array*/
#define TOP_CELL LEFT_CELL
/*right most value of the array*/
#define RIGHT_CELL 7
/*bottom most value of the array*/
#define BOTTOM_CELL RIGHT_CELL
/* what are the attributes of a player? They have a score, a token (either BLUE
 * or RED), and a score
 */
struct player
{
    char name[NAMELEN + 1];
    enum cell token;
    unsigned score;
};

BOOLEAN init_first_player(struct player *human, enum cell *token);
BOOLEAN init_second_player(struct player *computer, enum cell *token);
BOOLEAN make_move(struct player *player, struct player *other, game_board board);

BOOLEAN fgets_name(char *name);
BOOLEAN apply_move(game_board board, unsigned y, unsigned x, enum cell player_token, enum direction dir, unsigned captured_pieces);
int fgets_move(unsigned *xPointer, unsigned *yPointer);

BOOLEAN check_north(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_north_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_south_east(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_south(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_south_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);
BOOLEAN check_north_west(unsigned xCoordinate, unsigned yCoordinate, game_board board, unsigned *captured_pieces_pnt, struct player *current, struct player *other, enum direction *dir);

BOOLEAN check_all(unsigned xCoordinate, unsigned yCoordinate, game_board board, struct player *current, struct player *other);

#endif /* ifndef PLAYER_H */
