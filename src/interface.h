/*
 * interface.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"

/**
 *	Creates an Arena with l lines and c columns
 *	@param size : a vector containing the number of lines and columns
 *
 *	returns the newly created arena
 */
Arena create(Vector size);

/**
 *  Fills the empty arena a with random numbers from 1 to l*c
 *  @param a : a pointer to an empty Arena
 *	@param size : a vector containing the number of lines and columns
 *
 *	the first parameter will be modified to become filled
 * TODO: write the fill_arena function
 */
void fill_arena(Arena* a,int numero);

/**
 *  Generates a ready to play arena from a filled arena
 *  @param a : a filled Arena
 *	@param l : lines count
 *	@param c : column count
 *
 *	returns the ready arena
 *	TODO : write the function that allows to create a ready arena
 */
Arena ready_arena(Arena a);

/**
 *  Displays the current arena
 *  @param a : Arena
 *  @param l : lines count
 *  @param c : column count
 *  TODO : make this function with SDL2
 */
void display_arena(Arena a);

/**
 *
 */
/*void game(...TODO )*/

/**
 * Saves actual progress into a file
 * Returns true if file correctly written
 * @param a : The actual arena
 * @param solution : The solution arena
 *
 * TODO : write the save function
 */
Boolean save(Arena a, Arena solution);

/**
 * Loads actual progress from a file
 * Returns true if file correctly loaded
 * @param a : Pointer to the actual arena
 * @param solution : Pointer to the solution arena
 *
 *	TODO : write the load function
 */
Boolean load(Arena* a, Arena* solution);

/**
 * Verifies whether the actual arena is a solution to the game
 * Returns true if it is a solution
 * @param a : the actual arena
 * TODO : write this function
 */
Boolean verify_result(Arena a);

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

#endif /* INTERFACE_H_ */
