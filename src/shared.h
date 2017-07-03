/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : Joshua Hansen
 * Student Number   : s3589185
 * Course Code      : BP094
 * Program Code     : COSC1076
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#ifndef SHARED_H
#define SHARED_H

/* definition of the boolean type */
typedef enum
{
        FALSE, TRUE
} BOOLEAN;

/* how many colors are their in the game? required by the random number 
 * generation
 */
#define NUM_COLORS 2

/* what values could be contained in a cell on the board? */
enum cell
{
        BLANK, RED, BLUE
};

/* color codes required to display the tokens on the board */
#define COLOR_RED     "\33[31m"
#define COLOR_BLUE    "\33[34m"
#define COLOR_RESET   "\33[0m"

/*set to zero*/
#define ZERO 0
/*set value to one*/
#define ONE 1
/*set marker value to 0*/
#define MARKER 0
/*adjust coordinate by one cell*/
#define ONE_CELL 1
/*reset the counter*/
#define RESET 0

#endif /* defined SHARED_H */
