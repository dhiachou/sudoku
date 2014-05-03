//============================================================================
// Name        : SUDOKU.cpp
// Author      : Dhaw - Salmouch - Dandoun - Nini
// Version     :
// Copyright   : All rights reserved to II1G
// Description : The sudoku project
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main() {
	Vector size;
	Grid a , sol;

	/*Testing create function
	printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);

	a = create(size);

	display_grid(a);

	//*/

	/*testing save function :
	save(a,a);
	//*/
	/*Testing load function:
	load(&a,&sol);

	display_grid(a);

	printf("\n\nSolution: \n");

	display_grid(sol);
	//*/


	//*Testing filling grid function:
	printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);

	a = create(size);

    init_randomizer(); //shall be done only once!!
    fill_grid(&a,randomize(20));

    display_grid(a);

    //*/
	///TODO : test fill_Grid, test verify
	///TODO : verify all cases (for nini)
	///TODO : Learn SDL

	///TODO : WE NEED TO FREE RESERVED MEMORY ON CLOSE !!


	return 0;
}
