/*
 * interface.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#ifdef USING_CONSOLE
#include "game.h"
#elifdef USING_SDL
#include "SDLgame.h"
#endif // USING_CONSOLE

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"

/**
 *	Creates an Grid with l lines and c columns
 *	@param size : a vector containing the number of lines and columns
 *
 *	returns the newly created grid
 */
Grid create(Size size);

/**
 *  Fills the empty grid a with random numbers from 1 to l*c
 *  @param a : a pointer to an empty Grid
 *	@param size : a vector containing the number of lines and columns
 *
 *	the first parameter will be modified to become filled
 * TODO: write the fill_grid function
 */
void fill_grid(Grid* a,int numero,char * file);

/**
 *  Generates a ready to play grid from a filled grid
 *  @param a : a filled Grid
 *	@param l : lines count
 *	@param c : column count
 *
 *	returns the ready grid
 *	TODO : write the function that allows to create a ready grid
 */
Grid ready_grid(Grid a);

/**
 *  Displays the current grid on console
 *  @param a : Grid
 *  @param l : lines count
 *  @param c : column count
 *
 */
void display_grid(Grid a);

/**
 * CONSOLE TYPE game function
 */
void game(Grid * grid );

/**
 * Saves actual progress into a file
 * Returns true if file correctly written
 * @param a : The actual grid
 * @param solution : The solution grid
 *
 * TODO : write the save function
 */
Boolean save(Grid a);

/**
 * Loads actual progress from a file
 * Returns true if file correctly loaded
 * @param a : Pointer to the actual grid
 * @param solution : Pointer to the solution grid
 *
 *	TODO : write the load function
 */
Boolean load(Grid* a);

Boolean verify(Field ,Grid);

/**
 * Verifies whether the actual grid is a solution to the game
 * Returns true if it is a solution
 * @param a : the actual grid
 * TODO : write this function
 */
Boolean verify_arena(Grid a);

/**
 * returns the square of i
 * @param i : an integer number of which we'll return the square
 */
 #define sqr(i) i*i

 /**
  * Initialises the randomize seed
  */
void init_randomizer();

/**
 * Returns a random number between 0 and n
 */
int randomize(int n);


/**
 * Clears the screen
 **/
void clear();


void delete_grid(Grid * grid);

Grid main_menu();

#endif /* INTERFACE_H_ */
