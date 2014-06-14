
#ifdef USING_SDL
//============================================================================
// Name        : SDLmain.cpp
// Author      : Dhaw - Salmouch - Dandoun - Nini
// Version     :
// Copyright   : All rights reserved to II1G
// Description : The sudoku project
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main() {
	Grid a ;
    TTF_Init();

    SDL_Surface *screen;
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO)==-1)
    {
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /** Opening window**/
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);  ///Load the window
    SDL_WM_SetCaption("Sudoku" , NULL);


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


	/*//Testing filling grid function:
	printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);

	a = create(size);

    init_randomizer(); //shall be done only once!!
    fill_grid(&a,randomize(20),"ressources/easy");

    display_grid(a);//*/

    /*// TESTING THE GAME FUNCTION
    printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);
    a = create(size),
    game(&a);

    //*/

    a = main_menu(screen);
    game(&a,screen);

    SDL_Quit();


	return 0;
}
#endif
