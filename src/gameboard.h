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
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

/* forwards declaration of a struct player. This means that the compiler knows
 * that such a datastructure will be available but it does not what it contains
 * and so we can have pointers to a player but we don't know how big it is or 
 * what it contains.
 */
struct player;
/* all the directions that we can capture pieces in leaving from this direction
 */
enum direction
{
    NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
};

/* how much space is required to display a column on the game board ? */
#define COLUMN_WIDTH 4
/* how tall is the game board - 8 places high */
#define BOARD_HEIGHT 8
/* how wide is the game board ? */
#define BOARD_WIDTH BOARD_HEIGHT 
/*set border size to 36*/
#define BORDER_SIZE 36
/*y coordinate of the top markers on the default board*/
#define TOP_Y 3
/*x coordinate of the left markers on the default board*/
#define LEFT_X TOP_Y
/*y coordinate of the bottom markers on the default board*/
#define BOTTOM_Y 4
/*x coordinate of the right markers on the defualt board*/
#define RIGHT_X BOTTOM_Y

/* type definition of a game_board. It is just a 2-dimensional array */
typedef enum cell game_board[BOARD_HEIGHT][BOARD_WIDTH];

void init_game_board(game_board board);
void display_board(game_board board, struct player * human,
                   struct player * computer);
void border(void);
void innerBorder(void);
#endif /* ifndef GAMEBOARD_H */
