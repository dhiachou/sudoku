//============================================================================
// Name        : SUDOKU.cpp
// Author      : Dhaw - Salmouch - Dandoun - Nini
// Version     :
// Copyright   : All rights reserved to II1G
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main() {
	Vector size;
	Arena a , sol;

	/*//Testing create function
	printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);


	a = create(size);

	display_arena(a);
	//testing save function :
	save(a,a);

	//*/



	//Testing load function
	load(&a,&sol);

	display_arena(a);

	printf("\n\nSolution: \n");

	display_arena(sol); //*/
	///TODO : test fill_Arena, test verify
	///TODO : verify all cases (for nini)
	///TODO : Learn SDL


	return 0;
}
