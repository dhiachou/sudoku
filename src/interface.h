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
 *	Creates an Arena with the l lines and c columns
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
 */
void fill_arena(Arena* a);

/**
 *  Generates a ready to play arena from a filled arena
 *  @param a : a filled Arena
 *	@param l : lines count
 *	@param c : column count
 *
 *	returns the ready arena
 */
Arena ready_arena(Arena a);

/**
 *  Displays the current arena
 *  @param a : Arena
 *  @param l : lines count
 *  @param c : column count
 */
void display_arena(Arena a);

/**
 *
 */
//void game(.../*TO DO */);

/**
 *
 */
Boolean save(Arena a, Arena solution);

/**
 *
 */
Boolean load(Arena* a, Arena* solution);

Boolean verify_result(Arena a);


#endif /* INTERFACE_H_ */
