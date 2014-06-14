
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
	Grid grid ;
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

    /**Launching game**/
    grid = main_menu(screen);   //opening main_menu
    game(&grid,screen);         //opening the game window

    /** Shutting down **/
    SDL_Quit();


	return EXIT_SUCCESS;
}
#endif
