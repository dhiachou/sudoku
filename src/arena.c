/*
 * arena.c
 *
 *  Created on: Feb 22, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#include "interface.h"

/**
 *	Creates an Arena with the l lines and c columns
 *	@param size : a vector containing the number of lines and columns in a square
 *
 *	returns the newly created arena
 */
Arena create(Vector size){
	Arena A;
	int i=0, j=0;

	//Creating an empty arena with global dimensions : size.l² * size.c²
	A.size.l = size.l*size.l;
	A.size.c = size.c*size.c;

	A.Arena = (Field**)malloc(sizeof (Field*)*A.size.c);
	for (i =0 ; i< A.size.c;i++){
		A.Arena[i] = (Field*)malloc(sizeof(Field)*A.size.l);
	}



	//Initializing each field
	for (i =0; i<A.size.l;i++){
		for (j=0; j<A.size.c; j++){
			//Allocating the value
			A.Arena[i][j].val = (int*)malloc(sizeof(int));
			*(A.Arena[i][j].val) = 0;

			//Affecting the coordinates of the field
			A.Arena[i][j].line = i;
			A.Arena[i][j].column = j;

			//Affecting the number of the square where the field is
			A.Arena[i][j].square.x = (short)i/size.l;
			A.Arena[i][j].square.y = (short)j/size.c;
		}
	}

	return A;
}

void display_arena(Arena a){
	int i,j=0;
	//printf ("Entered display_arena");
	for (i=0;i<a.size.l;i++){
		for (j=0;j<a.size.c;j++){
			printf("___")	;
		}
		printf("\n");
		for (j=0;j<a.size.c;j++){
			printf("|%d|",*(a.Arena[i][j].val))	;
		}

		printf("\n");

	}


}
